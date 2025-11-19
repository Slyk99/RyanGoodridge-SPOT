function allConstraints = runMPC_postProcess(dataClass, spotFilterData, MPCdata, mpcConfig, navOpts, M, Phase2_End)
% Reconstruct plotting geometry for MPC constraints (ellipses / lines).
% Does NOT trim or modify spotFilterData or MPCdata (they are assumed to
% already be in the desired timeseries window). Phase2_End is only used
% for a consistency check against dataClass.Time_s, it does NOT cause
% re-trimming of spotFilterData or MPCdata.

if nargin < 7
    Phase2_End = 0;
end

%% -------------------------
% Load & sanity-check inputs
% --------------------------
time_full   = dataClass.Time_s.Data(:);   % original full time vector (col)
Results     = MPCdata.Results;            % already zoh-trimmed from loadMPCData
u_opt       = MPCdata.optimalInputs;      % 3 x N x numSteps (already trimmed if loadMPCData did)
x_opt       = MPCdata.optimalStates;     % 6 x N x numSteps
% The spotFilterData fields are not to be trimmed here:
xc_log      = spotFilterData.estimated_States.RED(1:6,:);    % 6 x T' (assumed aligned)
xt_log      = spotFilterData.estimated_States.BLACK(1:6,:);  % 6 x T'
xo_log      = spotFilterData.estimated_States.BLUE(1:6,:);   % 6 x T'
Pc_log      = spotFilterData.estimated_Cov.RED;    % 6 x 6 x T'
Pt_log      = spotFilterData.estimated_Cov.BLACK;  % 6 x 6 x T'
Po_log      = spotFilterData.estimated_Cov.BLUE;   % 6 x 6 x T'

Q           = navOpts.kfChaser.Q;  % process noise (unused here but kept)
[~, N, numSteps] = size(u_opt);

%% If MPCdata contains a time field, do a consistency check
if isfield(MPCdata, 'Time')
    t_mpc = MPCdata.Time(:);
    if Phase2_End > 0
        % Find first time > Phase2_End in the full log (original)
        idxStart = find(time_full > Phase2_End, 1, 'first');
        if ~isempty(idxStart)
            t_expected = time_full(idxStart:(idxStart + length(t_mpc)-1));
            if length(t_expected) ~= length(t_mpc) || any(abs(t_expected - t_mpc) > 1e-6)
                warning('runMPC_postProcess:TimeMismatch', ...
                    'MPCdata.Time does not align with dataClass.Time_s at Phase2_End. Using MPCdata and spotFilterData as-is.');
            end
        end
    end
end

%% -------------------------
% MPC & model setup
% --------------------------
n = size(mpcConfig.A,1);
m = size(mpcConfig.B,2);

Ad = eye(n) + mpcConfig.dt * mpcConfig.A;
Bd =           mpcConfig.dt * mpcConfig.B;

[Qf, K] = spotSMPC.Gradient.dare_iterative(Ad, Bd, mpcConfig.Q, mpcConfig.R, 10000, 1e-5);

r_hold = mpcConfig.holding_radius;
proximity = false;

%% -------------------------
% Preallocate output arrays (same shape you requested)
% Note: first dimension 100 is the number of ellipse points
% --------------------------
numPoints = 100;

allConstraints = struct();
allConstraints.max_states        = zeros(numPoints, 2, N, numSteps);
allConstraints.Smax_states       = zeros(numPoints, 2, N, numSteps);
allConstraints.min_states        = zeros(numPoints, 2, N, numSteps);
allConstraints.Smin_states       = zeros(numPoints, 2, N, numSteps);
allConstraints.target_ellipse    = zeros(numPoints, 2, N, numSteps);
allConstraints.target_line       = zeros(2, 2, N, numSteps);
allConstraints.Starget_ellipse   = zeros(numPoints, 2, N, numSteps);
allConstraints.Starget_line      = zeros(2, 2, N, numSteps);
allConstraints.obstacle_ellipse  = zeros(numPoints, 2, N, numSteps);
allConstraints.obstacle_line     = zeros(2, 2, N, numSteps);
allConstraints.Sobstacle_ellipse = zeros(numPoints, 2, N, numSteps);
allConstraints.Sobstacle_line    = zeros(2, 2, N, numSteps);

%% -------------------------
% Loop over MPC timesteps (use indices of MPCdata)
% --------------------------
prev = 0;
for k = 1:numSteps

    %% Reconstruct z0 from MPCdata (DO NOT use dataClass.MPC_z)
    % u_opt: 3 x N x numSteps (rows are [ux;uy;uz], columns are horizon steps)
    % x_opt: 6 x N x numSteps (rows are [x;y;theta;dx;dy;dtheta])
    u_k = reshape(u_opt(:,:,k), 3*N, 1);     % column: [3*N x 1]
    x_k = reshape(x_opt(:,:,k), 6*N, 1);     % column: [6*N x 1]
    z0  = [u_k; x_k];                        % 9*N x 1

    %% Pull filter data for this time index k (these structures are assumed aligned to MPCdata)
    % NOTE: spotFilterData was not trimmed here; we expect its length to match numSteps.
    xc_k = xc_log(:, k);       % chaser state 6x1
    xt_k = xt_log(:, k);       % target state 6x1
    xo_k = xo_log(:, k);       % obstacle state 6x1

    Pc_k = Pc_log(:, :, k);    % 6x6
    Pt_k = Pt_log(:, :, k);
    Po_k = Po_log(:, :, k);

    %% Propagate target/obstacle stacks (uses same functions as runMPC)
    [xTstack, PTstack] = spotSMPC.InitialConditions.propTarget(xt_k, Pt_k, Ad, Bd, Q, n, N);
    [xOstack, POstack] = spotSMPC.InitialConditions.propTarget(xo_k, Po_k, Ad, Bd, Q, n, N);

    %% Compute initial guess / PChaser
    [z0_check, PChaser] = spotSMPC.InitialConditions.initialGuess(z0, xc_k, Pc_k, [], Ad, Bd, 0*K, Q, n, m, N, M);
    % z0_check should be close to z0; we use z0 produced above for consistency

    %% Docking port & reference
    [DockingPort, DockingRadius] = spotSMPC.InitialConditions.dockingLocation(xTstack, mpcConfig.docking_Offset, N);
    [x_ref, u_ref] = spotSMPC.InitialConditions.genReference(z0, xTstack, DockingPort, DockingRadius, m, n, N, mpcConfig.dt, mpcConfig.Camera_Offset);

    if proximity
        x_ref = spotSMPC.InitialConditions.updateAngle(x_ref, mpcConfig.docking_Offset(3), n, N);
    end

    %% Holding radius update (uses chaser actual state at this k)
    [r_hold, proximity] = spotSMPC.InequalityConstrains.calcHoldingDist(r_hold, proximity, x_ref, xc_k, ...
                                             mpcConfig.eta, mpcConfig.zeta, mpcConfig.gamma, mpcConfig.r_hold_min);

    %% Build plotting geometry (your helper functions)
    [max_states, Smax_states] = buildMaxConstraintPoints(mpcConfig.x_max, PChaser, mpcConfig.H_max, N, mpcConfig.epsilon, numPoints);
    [min_states, Smin_states] = buildMaxConstraintPoints(-1 * mpcConfig.x_min, PChaser, -1 * mpcConfig.H_min, N, mpcConfig.epsilon, numPoints);

    [target_ellipse, target_line, Starget_ellipse, Starget_line] = ...
        StochasticHoldingRadiusPoints(r_hold, z0, xTstack, PTstack, mpcConfig.BlackOffset, N, mpcConfig.epsilon, numPoints);

    [obstacle_ellipse, obstacle_line, Sobstacle_ellipse, Sobstacle_line] = ...
        StochasticHoldingRadiusPoints(mpcConfig.ObsHold, z0, xOstack, POstack, mpcConfig.BlueOffset, N, mpcConfig.epsilon, numPoints);

    %% Store into 3-D arrays at slice k
    allConstraints.max_states(:,:,:,k)        = max_states;        % numPoints x 2 x N
    allConstraints.Smax_states(:,:,:,k)       = Smax_states;
    allConstraints.min_states(:,:,:,k)        = min_states;
    allConstraints.Smin_states(:,:,:,k)       = Smin_states;
    allConstraints.target_ellipse(:,:,:,k)    = target_ellipse;
    allConstraints.target_line(:,:,:,k)       = target_line;
    allConstraints.Starget_ellipse(:,:,:,k)   = Starget_ellipse;
    allConstraints.Starget_line(:,:,:,k)      = Starget_line;
    allConstraints.obstacle_ellipse(:,:,:,k)  = obstacle_ellipse;
    allConstraints.obstacle_line(:,:,:,k)     = obstacle_line;
    allConstraints.Sobstacle_ellipse(:,:,:,k) = Sobstacle_ellipse;
    allConstraints.Sobstacle_line(:,:,:,k)    = Sobstacle_line;

    % update prev id so we skip subsequent ZOH rows that repeated the same solver id
    prev = Results(k,1);
end

end


%% Helper Functions
function [pts, Spts] = buildMaxConstraintPoints(x_max, Pstack, H, N, epsilon, numPoints)
% Return geometry points for max constraint Hx <= xmax
% pts:   [numPoints x 2 x N]
% Spts:  [numPoints x 2 x N]

nc = size(H,1); 
pts  = nan(numPoints, 2, N);
Spts = nan(numPoints, 2, N);

% In 2-D we assume only first two states are constrained for plotting.
% You can adjust if H has a different interpretation.
Z = norminv(1-epsilon);

for k = 1:N
    % covariance at step k
    Pk = Pstack(:,:,k);

    % Bound tightening
    Sigma = H*Pk*H';          % nc x nc
    std_k = sqrt(diag(Sigma));  % nc x 1

    xmax_det = x_max;              % deterministic
    xmax_sto = x_max - Z.*std_k;   % stochastic

    % Produce vertical/horizontal line segment in xy-plane
    % ==============================
    % Deterministic line: H x = xmax_det
    % Stochastic line:    H x = xmax_sto
    % ==============================
    %
    % Assume H selects [x;y] form as:
    %   H = [1 0 ...]
    % or  H = [0 1 ...]
    %
    % For generality: take only the first row of H.

    h = H(1,1:2);   % 1x2
    if abs(h(2)) < 1e-12
        % vertical line: x = xmax(h)
        xval_det = xmax_det(1)/h(1);
        xval_sto = xmax_sto(1)/h(1);

        yvec = linspace(-5,5,numPoints)'; % arbitrary bounds for plotting
        pts(:,1,k)  = xval_det;
        pts(:,2,k)  = yvec;

        Spts(:,1,k) = xval_sto;
        Spts(:,2,k) = yvec;

    else
        % general line: h1*x + h2*y = xmax
        yvec = linspace(-5,5,numPoints)';  
        x_det = (xmax_det(1) - h(2)*yvec)/h(1);
        x_sto = (xmax_sto(1) - h(2)*yvec)/h(1);

        pts(:,1,k)  = x_det;
        pts(:,2,k)  = yvec;

        Spts(:,1,k) = x_sto;
        Spts(:,2,k) = yvec;
    end
end
end


function [ellipsePts, linePts, SellipsePts, SlinePts] = ...
    StochasticHoldingRadiusPoints(rhold, z0, xTstack, PTstack, Offset, N, epsilon, numPoints)

% Outputs:
% ellipsePts   [numPoints x 2 x N]
% linePts      [2 x 2 x N]         % endpoints of tangent line
% SellipsePts  [numPoints x 2 x N]
% SlinePts     [2 x 2 x N]

ellipsePts  = nan(numPoints,2,N);
SellipsePts = nan(numPoints,2,N);
linePts     = nan(2,2,N);
SlinePts    = nan(2,2,N);

H = [eye(2), zeros(2,4)];
Z = norminv(1-epsilon);

% Predict chaser states
n = size(z0,1)/N;
Xc = reshape(z0, n, N);

phi = linspace(0,2*pi,numPoints);
ab  = rhold(:);

for i = 1:N

    %% Target state
    tar = xTstack(:,i);
    pT  = tar(1:2);
    th  = tar(3);
    c = cos(th); s = sin(th);
    R = [c -s; s c];

    % ellipse center in world frame
    C = pT + R*Offset;

    %% Deterministic ellipse
    a = ab(1); b = ab(2);
    e_body = [a*cos(phi); b*sin(phi)];
    e_world = R*e_body + C;        % 2 x numPoints
    ellipsePts(:,:,i) = e_world.'; % numPoints x 2

    %% Tangent point (closest direction to chaser)
    pC = Xc(1:2,i);
    u  = pC - C;
    d  = norm(u);
    if d < 1e-12, u = [1;0]; else, u=u/d; end

    % angle in ellipse frame
    theta_e = atan2(u(2),u(1));
    denom = sqrt((a*sin(theta_e))^2 + (b*cos(theta_e))^2);
    r_e = a*b/denom;

    r0 = C + r_e*u;           % tangent point

    % gradient E for linearization
    S = diag(1./(ab.^2));
    M = R*S*R.';
    E = (r0 - C)'*M;          % 1x2 gradient direction
    g = -2*E.';               % normal vector

    % Tangent line direction
    tDir = [-g(2); g(1)];
    tDir = tDir/norm(tDir);
    L = max(ab)*2;
    linePts(:,:,i) = [r0 - L*tDir,  r0 + L*tDir].';

    %% Stochastic inflation
    Pk = PTstack(:,:,i);
    Sigma = H*Pk*H.';
    sig = sqrt(E*Sigma*E');

    aS = a + Z*sig;   % inflate semi-axes
    bS = b + Z*sig;

    eS_body  = [aS*cos(phi); bS*sin(phi)];
    eS_world = R*eS_body + C;
    SellipsePts(:,:,i) = eS_world.';

    % Stochastic tangent point
    denomS = sqrt((aS*sin(theta_e))^2 + (bS*cos(theta_e))^2);
    rS = aS*bS/denomS;
    r0S = C + rS*u;

    SlinePts(:,:,i) = [r0S - L*tDir,  r0S + L*tDir].';

end
end
