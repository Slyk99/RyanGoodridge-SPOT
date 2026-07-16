%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File name: fmincon_solver_v65_ultrafast.m
% Author: Aaron vandenEnden
% Version: 6.5-ultrafast
% Last updated: May 15th 2026
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Version 6.5-ultrafast updates:
% - Optional move-blocked controls to reduce fmincon decision variables
% - Optional constraint stride for cheaper safety checks during early tuning
% - Optional RK4 / midpoint / Euler integrator choice
% - Optional parallel finite differences when a parallel pool is already open
% - Keeps the v6.4 shared rollout cache and vectorized constraints


function [X, U, info] = fmincon_solver_v65_ultrafast(qin, dqin, xgoal, N, Ndt, obs1, useCollision1, fastOpts)
% fmincon_solver_taskspace
% Task-space (Cartesian) NMPC for a free-floating planar base + 3R arm
% State:  x = [q(6); dq(6)]  = 12x1
% Control: u = tau_arm(3) applied to joints 4:6 (base unactuated)
%
% Inputs:
%   qin   (6x1)  = [x_base; y_base; theta_base; q1; q2; q3]
%   dqin  (6x1)
%   xgoal (3x1)  = [x_ee_des; y_ee_des; phi_ee_des]
%   N            = horizon steps
%   Ndt          = sample time (seconds) per step
%   obs1         Series of vertices to describe obstacle 1 [x,y; ...]
%
% Outputs:
%   X (12x(N+1)) rolled-out optimal predicted state trajectory
%   U (3xN)      optimal torque sequence for joints 4:6
%   info         diagnostics from fmincon and rollout cache


dt = Ndt;

% Optional speed/quality controls.  The default preset is intentionally a
% little more aggressive than v6.4: it keeps RK4 and all stage constraints,
% but uses move-blocked controls and fewer SQP iterations.  For exact v6.4
% behavior, call with fastOpts.speedPreset = 'safe' or set
% fastOpts.controlBlockSize = 1.
if nargin < 8 || isempty(fastOpts)
    fastOpts = struct();
end

speedPreset = lower(char(getFastOpt(fastOpts, 'speedPreset', 'faster')));
switch speedPreset
    case 'safe'
        defaultControlBlockSize = 1;
        defaultConstraintStride = 1;
        defaultIntegrator = 'rk4';
        defaultMaxIterations = 120;
        defaultConstraintTolerance = 1e-6;
        defaultStepTolerance = 1e-6;
        defaultOptimalityTolerance = 1e-6;
        defaultFunctionTolerance = 1e-6;
    case 'max'
        % Maximum speed preset.  This changes the numerical transcription:
        % fewer control moves, fewer checked constraint nodes, and midpoint
        % integration.  Use after verifying on your robot/sim cases.
        defaultControlBlockSize = 3;
        defaultConstraintStride = 2;
        defaultIntegrator = 'midpoint';
        defaultMaxIterations = 50;
        defaultConstraintTolerance = 1e-4;
        defaultStepTolerance = 1e-4;
        defaultOptimalityTolerance = 1e-3;
        defaultFunctionTolerance = 1e-4;
    otherwise
        % Good real-time compromise: same RK4 dynamics and every-stage
        % constraints, but approximately half as many optimization variables.
        defaultControlBlockSize = 2;
        defaultConstraintStride = 1;
        defaultIntegrator = 'rk4';
        defaultMaxIterations = 80;
        defaultConstraintTolerance = 1e-5;
        defaultStepTolerance = 1e-5;
        defaultOptimalityTolerance = 1e-4;
        defaultFunctionTolerance = 1e-5;
end

controlBlockSize = round(getFastOpt(fastOpts, 'controlBlockSize', defaultControlBlockSize));
controlBlockSize = max(1, min(N, controlBlockSize));
nB = ceil(N/controlBlockSize);                    % number of optimized control blocks
blockIdx = ceil((1:N)/controlBlockSize);          % map each horizon step to a block
blockIdx(blockIdx > nB) = nB;
blockStartIdx = 1 + (0:nB-1)*controlBlockSize;    % stages used for warm-start compression
blockStartIdx(blockStartIdx > N) = N;

constraintStride = round(getFastOpt(fastOpts, 'constraintStride', defaultConstraintStride));
constraintStride = max(1, min(N, constraintStride));
constraintIdx = unique([1:constraintStride:N, N]);
nConstraintStages = numel(constraintIdx);

integrationMethod = lower(char(getFastOpt(fastOpts, 'integrationMethod', defaultIntegrator)));
maxIterations = getFastOpt(fastOpts, 'maxIterations', defaultMaxIterations);
constraintTolerance = getFastOpt(fastOpts, 'ConstraintTolerance', defaultConstraintTolerance);
stepTolerance = getFastOpt(fastOpts, 'StepTolerance', defaultStepTolerance);
optimalityTolerance = getFastOpt(fastOpts, 'OptimalityTolerance', defaultOptimalityTolerance);
functionTolerance = getFastOpt(fastOpts, 'FunctionTolerance', defaultFunctionTolerance);
useParallelFD = resolveUseParallel(getFastOpt(fastOpts, 'UseParallel', false));

% Unpack obstacle and prepare polygon edges once.  The old code rebuilt
% edge geometry inside every nonlinear-constraint evaluation.
obsX = obs1(1:2:end);
obsY = obs1(2:2:end);
obsX = obsX(:);
obsY = obsY(:);
if useCollision1 && numel(obsX) >= 2
    if obsX(1) ~= obsX(end) || obsY(1) ~= obsY(end)
        obsXc = [obsX; obsX(1)];
        obsYc = [obsY; obsY(1)];
    else
        obsXc = obsX;
        obsYc = obsY;
    end
    edgeX1 = obsXc(1:end-1).';
    edgeY1 = obsYc(1:end-1).';
    edgeVX = (obsXc(2:end) - obsXc(1:end-1)).';
    edgeVY = (obsYc(2:end) - obsYc(1:end-1)).';
    edgeVV = edgeVX.^2 + edgeVY.^2;
else
    obsXc = obsX;
    obsYc = obsY;
    edgeX1 = zeros(1,0);
    edgeY1 = zeros(1,0);
    edgeVX = zeros(1,0);
    edgeVY = zeros(1,0);
    edgeVV = zeros(1,0);
end

nx = 12;
nu = 3;
nU = nu*nB;     % optimized variables after move-blocking

% Limits
servotorque = 0.1; % N*m, servo max is 1
uMax = servotorque * ones(nu,1);
uMin = -uMax;

useJointLimits = true;

phid = 68.2840;

qMin = deg2rad([-phid; -90; -90]);     % joints 4:6
qMax = deg2rad([180-phid;  90;  90]);
dqMaxJ = deg2rad([40; 40; 40]);        % joints 4:6, default 120 deg/s

useDqLimits = true;
%useCollision1=true;

% Weights
angleErr = @(des, act) atan2(sin(des-act), cos(des-act)); % desired - actual

Qx    = 1*diag([200, 200,  200]);          % running EE pose error
Qdx   = 2*diag([  5,   5,   2]);          % running EE velocity error
Qf_x  = 100*diag([200,200,200]);         % terminal EE pose error
Qf_dx = 10000*diag([ 100, 100, 20]);          % terminal EE velocity error

R     = 0.02 * eye(nu);                 % torque effort
Rdu   = 0.20 * eye(nu);                 % smoothing on delta-u

% Light regularization (optional, helps numerics)
Qdq_arm = 0*0.2 * eye(3);                % penalize dq(4:6) a bit
Qq_arm  = 0.00 * eye(3);                % (usually keep 0 in task-space MPC)

% Dynamics/model constants captured by nested functions.  Keeping these at
% solver scope avoids reassigning them thousands of times inside ddq_from_MC.
phi=68.2840*pi/180;
m0=16.9478; m1=0.3377; m2=0.3281; m3=0.0111;
a0=0; a1=0.1933; a2=0.1933; a3=0.0621; %#ok<NASGU>
b0=0.2304; b1=0.1117; b2=0.1057;  b3=0.0159; %#ok<NASGU>
I0=0.2873; I1=0.004171; I2=0.003967; I3=0.00006722*10;
eye6 = eye(6);
massMatrixRegularization = 1e-6;
% Fast mode skips rcond(M) on every RK4 sub-step.  If you ever see NaNs or
% warnings from near-singular states, set this true to recover v6.3 behavior.
checkMassMatrixCondition = false;

% Initial state
x0 = [qin(:); dqin(:)];                 % 12x1

% Reference
xref    = xgoal(:);
xdotref = [0;0;0];

% Warm-start (shift last solution)
persistent lastU
if isempty(lastU) || any(size(lastU) ~= [nu, N])
    lastU = zeros(nu, N);
end

% Shift previous solution one step
U0 = [lastU(:,2:end), lastU(:,end)];

% If warm start is basically zeros, build a cheap task-space PD guess
if norm(U0(:),2) < 1e-8
    U0 = build_taskspace_PD_seed(x0, xref, xdotref, N, dt, uMin, uMax);
end

% Decision vector is move-blocked controls only.  The full N-step control
% sequence is expanded inside rollout_from_z.  controlBlockSize=1 recovers
% the original full-control transcription.
Ub0 = U0(:, blockStartIdx);
z0 = reshape(Ub0, nU, 1);

% Decision variable bounds, one 3-torque vector per block.
lb = repmat(uMin, nB, 1);
ub = repmat(uMax, nB, 1);

% Shared rollout cache.  fmincon commonly evaluates the objective and
% nonlinear constraints at the same z while estimating finite differences.
% Caching prevents a second full RK4 rollout at each repeated z.
cacheZ = [];
cacheU = [];
cacheX = [];
cacheHits = 0;
cacheMisses = 0;

% Setup and run fmincon
% Display='none' removes command-window overhead during real-time MPC calls.
% Change to 'iter' while tuning/debugging.
opts = optimoptions('fmincon', ...
    'Algorithm','sqp', ...
    'Display','none', ...
    'MaxIterations', maxIterations, ...
    'MaxFunctionEvaluations', 2e5, ...
    'ConstraintTolerance', constraintTolerance, ...
    'StepTolerance', stepTolerance, ...
    'OptimalityTolerance', optimalityTolerance, ...
    'FunctionTolerance', functionTolerance, ...
    'FiniteDifferenceType', 'forward', ...
    'UseParallel', useParallelFD);

tSolve = tic;
[zstar, fval, exitflag, output] = fmincon(@cost_fun, z0, [],[],[],[], lb, ub, @nonlcon_fun, opts);
elapsed = toc(tSolve);

UblockStar = reshape(zstar, nu, nB);
U = UblockStar(:, blockIdx);
lastU = U;

% Optimal output trajectory rollout.  This often hits the same cache entry
% left by fmincon's final objective/constraint evaluation.
[X,~] = rollout_from_z(zstar);

info = struct();
info.elapsed = elapsed;
info.fval = fval;
info.exitflag = exitflag;
info.output = output;
info.rollout_cache_hits = cacheHits;
info.rollout_cache_misses = cacheMisses;
info.speed_preset = speedPreset;
info.control_block_size = controlBlockSize;
info.num_control_blocks = nB;
info.num_decision_variables = nU;
info.full_horizon_steps = N;
info.constraint_stride = constraintStride;
info.num_constraint_stages = nConstraintStages;
info.integration_method = integrationMethod;
info.use_parallel_finite_difference = useParallelFD;

%%%%%%%%%%%%%%%%%%%%
% Helper functions %
%%%%%%%%%%%%%%%%%%%%

    function J = cost_fun(z)
        [Xloc, Uloc] = rollout_from_z(z);

        % Vectorized EE pose/velocity for all N+1 trajectory nodes.
        qAll  = Xloc(1:6,:);
        dqAll = Xloc(7:12,:);

        x_base = qAll(1,:);
        y_base = qAll(2,:);
        th0    = qAll(3,:);
        q1     = qAll(4,:);
        q2     = qAll(5,:);
        q3     = qAll(6,:);

        b0  = 0.2304;
        phi = 68.2840*pi/180;
        L1  = 0.1933 + 0.1117;
        L2  = 0.1933 + 0.1057;
        L3  = 0.0621 + 0.0159;

        th1 = th0 + q1 + phi;
        th2 = th1 + q2;
        th3 = th2 + q3;

        xeeAll = [x_base + b0*cos(th0 + phi) + L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
                  y_base + b0*sin(th0 + phi) + L1*sin(th1) + L2*sin(th2) + L3*sin(th3);
                  th3];

        % Vectorized version of Jee*dq using the existing ee_jacobian terms.
        % Note: dxe_root/dye_root intentionally match ee_jacobian exactly.
        dxe_root = -b0*sin(th0);
        dye_root =  b0*cos(th0);

        dxe_arm = -L1*sin(th1) - L2*sin(th2) - L3*sin(th3);
        dye_arm =  L1*cos(th1) + L2*cos(th2) + L3*cos(th3);

        dxe_dth0 = dxe_root + dxe_arm;
        dye_dth0 = dye_root + dye_arm;

        dxe_dq1 = dxe_dth0;
        dye_dq1 = dye_dth0;
        dxe_dq2 = -L2*sin(th2) - L3*sin(th3);
        dye_dq2 =  L2*cos(th2) + L3*cos(th3);
        dxe_dq3 = -L3*sin(th3);
        dye_dq3 =  L3*cos(th3);

        xdotAll = [dqAll(1,:) + dxe_dth0.*dqAll(3,:) + dxe_dq1.*dqAll(4,:) + dxe_dq2.*dqAll(5,:) + dxe_dq3.*dqAll(6,:);
                   dqAll(2,:) + dye_dth0.*dqAll(3,:) + dye_dq1.*dqAll(4,:) + dye_dq2.*dqAll(5,:) + dye_dq3.*dqAll(6,:);
                   dqAll(3,:) + dqAll(4,:) + dqAll(5,:) + dqAll(6,:)];

        % Running cost uses pre-control stage states X(:,1:N), matching the
        % old single-shooting loop before propagation.
        xeeStage  = xeeAll(:,1:N);
        xdotStage = xdotAll(:,1:N);

        ex = xeeStage - repmat(xref, 1, N);
        ex(3,:) = angleErr(xref(3), xeeStage(3,:));
        exdot = xdotStage - repmat(xdotref, 1, N);

%        q_arm  = Xloc(4:6,1:N);
%        dq_arm = Xloc(10:12,1:N);

        % Same smoothing convention as v5.1: first delta-u is zero because
        % u_prev is initialized as U(:,1) inside the old loop.
%        dU = [zeros(nu,1), diff(Uloc,1,2)];

%        margin = deg2rad(8);
%        wlim   = 50;  % tune 10-500

        J = 0;
        J = J + sum(sum(ex    .* (Qx      * ex)));
        J = J + sum(sum(exdot .* (Qdx     * exdot)));
%        J = J + sum(sum(Uloc  .* (R       * Uloc)));
%        J = J + sum(sum(dU    .* (Rdu     * dU)));
%        J = J + sum(sum(dq_arm.* (Qdq_arm * dq_arm)));
%        J = J + sum(sum(q_arm .* (Qq_arm  * q_arm)));
%        J = J + wlim * joint_limit_barrier(q_arm, qMin, qMax, margin);

        % Terminal cost at X(:,N+1).
        eN = xeeAll(:,end) - xref;
        eN(3) = angleErr(xref(3), xeeAll(3,end));
        edN = xdotAll(:,end) - xdotref;

        J = J + eN.'*Qf_x*eN + edN.'*Qf_dx*edN;

        % % Anti-drift posture regulation
        % q_arm0 = x0(4:6);             % current arm posture at solve time
        % Wdrift = diag([0.0005 0.050 0.0005]);  % small
        % J = J + (q_arm - q_arm0).'*Wdrift*(q_arm - q_arm0);
    end

    function [c, ceq] = nonlcon_fun(z)
        % Enforce joint/dq/collision limits along the predicted rollout.
        % c <= 0, ceq == 0
        ceq = zeros(0,1);

        if ~(useJointLimits || useDqLimits || useCollision1)
            c = zeros(0,1);
            return;
        end

        % Reuse the same predicted trajectory computed by the objective when
        % fmincon calls cost_fun/nonlcon_fun at the same decision vector.
        Xloc = rollout_from_z(z);

        % Preallocate one flat constraint vector instead of repeatedly
        % growing c with c=[c; newBlock].
        nC = 0;
        if useCollision1,  nC = nC + nConstraintStages;      end
        if useJointLimits, nC = nC + 6*nConstraintStages;    end
        if useDqLimits,    nC = nC + 6*nConstraintStages;    end
        c = zeros(nC,1);
        ci = 1;
        Xstage = Xloc(:,constraintIdx);

        if useCollision1
            qStage = Xstage(1:6,:);

            x_base = qStage(1,:);
            y_base = qStage(2,:);
            th0    = qStage(3,:);
            q1     = qStage(4,:);
            q2     = qStage(5,:);
            q3     = qStage(6,:);

            b0  = 0.2304;
            phi = 68.2840*pi/180;
            L1 = 0.305;% 0.1933 + 0.1117;
            L2 = 0.300;%0.1933 + 0.1057;
            L3 = 0.088;%0.0621 + 0.0159;

            th1 = th0 + q1 + phi;
            th2 = th1 + q2;
            th3 = th2 + q3;

            xpt = x_base + b0*cos(th0 + phi) + L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
            ypt = y_base + b0*sin(th0 + phi) + L1*sin(th1) + L2*sin(th2) + L3*sin(th3);

            marginCollision = 0.0;  % meters
            sd = signedDistPointPolygonPrepared(xpt(:), ypt(:));  % + outside, 0 boundary, - inside

            % enforce sd >= margin  <=>  margin - sd <= 0
            c(ci:ci+nConstraintStages-1) = marginCollision - sd(:);
            ci = ci + nConstraintStages;
        end

        if useJointLimits
            q_arm = Xstage(4:6,:);
            nBlock = 3*nConstraintStages;
            c(ci:ci+nBlock-1) = reshape(bsxfun(@minus, q_arm, qMax), [], 1);
            ci = ci + nBlock;
            c(ci:ci+nBlock-1) = reshape(bsxfun(@minus, qMin, q_arm), [], 1);
            ci = ci + nBlock;
        end

        if useDqLimits
            dq_arm = Xstage(10:12,:);
            nBlock = 3*nConstraintStages;
            c(ci:ci+nBlock-1) = reshape(bsxfun(@minus, dq_arm, dqMaxJ), [], 1);
            ci = ci + nBlock;
            c(ci:ci+nBlock-1) = reshape(bsxfun(@minus, -dq_arm, dqMaxJ), [], 1);
            ci = ci + nBlock; %#ok<NASGU>
        end
    end

    function [Xloc, Uloc] = rollout_from_z(z)
        % Shared single-shooting rollout cache.  The dynamics remain
        % recursive, so this loop cannot be fully vectorized across time,
        % but it should only run once per unique z.
        if ~isempty(cacheZ) && isequal(z, cacheZ)
            Xloc = cacheX;
            Uloc = cacheU;
            cacheHits = cacheHits + 1;
            return;
        end

        Ublock = reshape(z, nu, nB);
        Uloc = Ublock(:, blockIdx);
        Xloc = zeros(nx, N+1);
        Xloc(:,1) = x0;
        xk_loc = x0;
        for kk = 1:N
            xk_loc = rk4_step(xk_loc, Uloc(:,kk), dt);
            Xloc(:,kk+1) = xk_loc;
        end

        cacheZ = z;
        cacheU = Uloc;
        cacheX = Xloc;
        cacheMisses = cacheMisses + 1;
    end

    function Useed = build_taskspace_PD_seed(xstart, xref_loc, xdotref_loc, Nloc, h, uMinLoc, uMaxLoc)
        % Simple task-space PD seed mapped to arm torques via J^T.
        % This remains sequential because each seed state depends on the
        % previous RK4 propagation.
        Useed = zeros(nu, Nloc);

        % Gains for seed only (not the MPC weights)
        Kp_x = diag([200, 200, 40]);
        Kd_x = diag([ 30,  30, 10]);

        xk_loc = xstart;
        for kk = 1:Nloc
            q  = xk_loc(1:6);
            dq = xk_loc(7:12);

            xee  = ee_fk(q);
            Jee  = ee_jacobian(q);
            xdot = Jee * dq;

            ex = xref_loc - xee;
            ex(3) = angleErr(xref_loc(3), xee(3)); % desired - actual
            exdot = xdotref_loc - xdot;

            F = Kp_x*ex + Kd_x*exdot;

            Jee_act = Jee(:,4:6);
            tau = Jee_act.' * F; % 3x1

            % saturate
            tau = min(max(tau, uMinLoc), uMaxLoc);

            Useed(:,kk) = tau;

            xk_loc = rk4_step(xk_loc, tau, h);
        end
    end

    function xnext = rk4_step(x, tau_arm, h)
        % Control vector is tau on joints 4:6; pack into u6.  The function
        % name is kept for compatibility with older helper code, but the
        % integration scheme can be changed with fastOpts.integrationMethod.
        u6 = [0;0;0; tau_arm(:)];

        switch integrationMethod
            case 'euler'
                k1 = dynamics(x(1:6), x(7:12), u6);
                xnext = x + h*k1;

            case {'midpoint','rk2'}
                k1 = dynamics(x(1:6), x(7:12), u6);
                k2 = dynamics(x(1:6) + 0.5*h*k1(1:6),  x(7:12) + 0.5*h*k1(7:12),  u6);
                xnext = x + h*k2;

            otherwise
                k1 = dynamics(x(1:6), x(7:12), u6);
                k2 = dynamics(x(1:6) + 0.5*h*k1(1:6),  x(7:12) + 0.5*h*k1(7:12),  u6);
                k3 = dynamics(x(1:6) + 0.5*h*k2(1:6),  x(7:12) + 0.5*h*k2(7:12),  u6);
                k4 = dynamics(x(1:6) +     h*k3(1:6),  x(7:12) +     h*k3(7:12),  u6);
                xnext = x + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
        end

        % (optional) clip extremely large dq to avoid numeric explosions
        dq_clip = 200; % rad/s hard safety clip
        xnext(7:12) = min(max(xnext(7:12), -dq_clip), dq_clip);
    end

    function dx = dynamics(q, dq, u6)
        ddq = ddq_from_MC(q, dq, u6);
        dx = [dq; ddq];
    end


% Model functions %
%%%%%%%%%%%%%%%%%%%

    % Nested: ddq_from_MC (fixed-size output)
    function ddq = ddq_from_MC(q,dq,u)

        q0=q(3); q1=q(4); q2=q(5); q3=q(6);
        dq0=dq(3); dq1=dq(4); dq2=dq(5); dq3=dq(6);

        % Inertia Matrix M
        M11 = m0 + m1 + m2 + m3;
        M12 = 0;
        M13 = (-a1 *m1 - m2* (a1 + b1) - m3* (a1 + b1))* cos(q0 + q1) + (-a2* m2 - m3 *(a2 + b2))* cos(q0 + q1 + q2)+ (-a3* m3) *cos(q0 + q1 + q2 + q3) + (-b0 *m1 - b0* m2 - b0* m3)* sin(phi + q0);
        M14 = (-a1 *m1 - m2* (a1 + b1) - m3* (a1 + b1)) *cos(q0 + q1) + (-a2* m2 - m3 *(a2 + b2)) *cos(q0 + q1 + q2)+ (-a3* m3)* cos(q0 + q1 + q2 + q3);
        M15 = (-a2 *m2 - a2 *m3 - b2 *m3) *cos(q0 + q1 + q2) + (-a3 *m3) *cos(q0 + q1 + q2 + q3);
        M16 = (-a3* m3) *cos(q0 + q1 + q2 + q3);
        M21 = 0;
        M22 = m0 + m1 + m2 + m3;
        M23 = (b0 *m1 + b0* m2 + b0 *m3)* cos(phi + q0) + (-a1* m1 - m2 *(a1 + b1) - m3 *(a1 + b1)) *sin(q0 + q1)+ (-a2 *m2 - m3 *(a2 + b2)) *sin(q0 + q1 + q2) + (-a3 *m3) *sin(q0 + q1 + q2 + q3);
        M24 = (-a1* m1 - m2 *(a1 + b1) - m3* (a1 + b1)) *sin(q0 + q1) + (-a2* m2 - m3* (a2 + b2))* sin(q0 + q1 + q2)+ (-a3 *m3) *sin(q0 + q1 + q2 + q3);
        M25 = (-a2 *m2 - a2 *m3 - b2* m3)* sin(q0 + q1 + q2) + (-a3 *m3) *sin(q0 + q1 + q2 + q3);
        M26 = (-a3* m3)* sin(q0 + q1 + q2 + q3);
        M31 = M13;
        M32 = M23;
        M33 = (2 *a1* a2* m2 + 2 *a1 *a2* m3 + 2 *a2* b1* m2 + 2 *a1* b2* m3 + 2* a2* b1* m3 + 2* b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2* a3* b2* m3)* cos(q3) + (2* a1* a3* m3 + 2* a3* b1* m3)* cos(q2 + q3)+ (2* a1* b0 *m1 + 2 *a1* b0* m2 + 2 *a1* b0* m3 + 2* b0* b1* m2 + 2* b0 *b1 *m3)* sin(phi - q1)+ (-2 *a2* b0* m2 - 2 *a2* b0* m3 - 2* b0* b2* m3)* sin(q1 - phi + q2) + (-2 *a3* b0* m3)* sin(q1 - phi + q2 + q3)+ I0 + I1 + I2 + I3 + a1^2* m1 + a1^2* m2 + a1^2* m3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b0^2* m1 + b0^2* m2+ b0^2 *m3 + b1^2 *m2 + b1^2* m3 + b2^2 *m3 + 2 *a1* b1 *m2 + 2 *a1* b1* m3 + 2 *a2 *b2* m3;
        M34 = (2* a1* a2* m2 + 2* a1 *a2* m3 + 2* a2* b1* m2 + 2 *a1* b2* m3 + 2 *a2 *b1 *m3 + 2* b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2* a3* b2* m3)* cos(q3) + (2* a1* a3* m3 + 2* a3* b1* m3)* cos(q2 + q3)+ (a1* b0* m1 + a1* b0* m2 + a1* b0* m3 + b0* b1* m2 + b0* b1* m3)* sin(phi - q1)+ (-1*a2* b0* m2 - a2* b0* m3 - b0* b2* m3)* sin(q1 - phi + q2) + (-a3* b0* m3)* sin(q1 - phi + q2 + q3)+ I1 + I2 + I3 + a1^2* m1 + a1^2* m2 + a1^2* m3 + a2^2* m2 + a2^2 *m3 + a3^2 *m3 + b1^2* m2 + b1^2 *m3 + b2^2* m3+ 2* a1* b1* m2 + 2* a1 *b1* m3 + 2 *a2 *b2* m3;
        M35 = (a1* a2* m2 + a1* a2 *m3 + a2* b1* m2 + a1* b2* m3 + a2* b1* m3 + b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2 *a3 *b2* m3) *cos(q3) + (a1 *a3* m3 + a3* b1* m3) *cos(q2 + q3)+ (-a2* b0* m2 - a2* b0* m3 - b0* b2* m3) *sin(q1 - phi + q2) + (-a3* b0* m3)* sin(q1 - phi + q2 + q3)+ I2 + I3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b2^2* m3 + 2* a2* b2* m3;
        M36 = (a2* a3* m3 + a3* b2* m3)* cos(q3) + (a1* a3* m3 + a3 *b1 *m3)* cos(q2 + q3)+ (-a3* b0* m3) *sin(q1 - phi + q2 + q3) + m3 *a3^2 + I3;
        M41 = M14;
        M42 = M24;
        M43 = M34;
        M44 = (2 *a1 *a2 *m2 + 2* a1* a2* m3 + 2* a2 *b1* m2 + 2* a1* b2* m3 + 2* a2* b1* m3 + 2 *b1 *b2 *m3)* cos(q2)+ (2* a2* a3* m3 + 2 *a3 *b2* m3)* cos(q3) + (2* a1* a3* m3 + 2* a3* b1* m3)* cos(q2 + q3) + I1 + I2 + I3 + a1^2* m1+ a1^2* m2 + a1^2* m3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b1^2* m2 + b1^2* m3 + b2^2 *m3 + 2 *a1* b1* m2 + 2 *a1* b1* m3+ 2* a2* b2* m3;
        M45 = (a1* a2* m2 + a1* a2* m3 + a2* b1* m2 + a1* b2* m3 + a2* b1* m3 + b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2* a3* b2 *m3) *cos(q3) + (a1 *a3* m3 + a3* b1* m3)* cos(q2 + q3) + I2 + I3 + a2^2* m2 + a2^2 *m3+ a3^2 *m3 + b2^2 *m3 + 2 *a2* b2 *m3;
        M46 = (a2* a3 *m3 + a3* b2* m3) *cos(q3) + (a1 *a3* m3 + a3 *b1 *m3) *cos(q2 + q3) + m3* a3^2 + I3;
        M51 = M15;
        M52 = M25;
        M53 = M35;
        M54 = M45;
        M55 = (2* a2* a3* m3 + 2* a3 *b2* m3) *cos(q3) + I2 + I3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b2^2* m3 + 2 *a2 *b2 *m3;
        M56 = (a2 *a3 *m3 + a3 *b2 *m3) *cos(q3) + m3 *a3^2 + I3;
        M61 = M16;
        M62 = M26;
        M63 = M36;
        M64 = M46;
        M65 = M56;
        M66 = m3* a3^2 + I3;
        M=[M11,M12,M13,M14,M15,M16;M21,M22,M23,M24,M25,M26;M31,M32,M33,M34,M35,M36;M41,M42,M43,M44,M45,M46;M51,M52,M53,M54,M55,M56;M61,M62,M63,M64,M65,M66];


            C13 = (-dq0*(b0*m1 + b0*m2 + b0*m3)) * cos(q(5) + q0) ...
                + (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * cos(q0 + q1 + pi/2) ...
                + (-dq0*(a2*m2 + m3*(a1 + b1)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * cos(q0 + q1 + q2 + pi/2) ...
                + (-a3*m3*dq0 - a2*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * cos(q0 + q1 + q2 + q3 + pi/2);

            C14 = (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * cos(q0 + q1 + pi/2) ...
                + (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * cos(q0 + q1 + q2 + pi/2) ...
                + (-a2*m3*dq0 - a2*m3*dq1 - a2*m3*dq2 - a2*m3*dq3) * cos(q0 + q1 + q2 + q3 + pi/2);

            C15 = (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * cos(q0 + q1 + q2 + pi/2) ...
                + (-a3*m3*(dq0+dq1+dq2+dq3)) * cos(q0 + q1 + q2 + q3 + pi/2);

            C16 = (a3*m3*(dq0 + dq1 + dq2 + dq3)) * sin(q0 + q1 + q2 + q3);

            C23 = (-dq0*(b0*m1 + b0*m2 + b0*m3)) * sin(q(5) + q0) ...
                + (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * sin(q0 + q1 + pi/2) ...
                + (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * sin(q0 + q1 + q2 + pi/2) ...
                + (-a3*m3*dq0 - a3*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * sin(q0 + q1 + q2 + q3 + pi/2);

        C24 = (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * sin(q0 + q1 + pi/2) ...
            + (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * sin(q0 + q1 + q2 + pi/2) ...
            + (-a3*m3*dq0 - a3*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * sin(q0 + q1 + q2 + q3 + pi/2);

        C25 = (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * sin(q0 + q1 + q2 + pi/2) ...
            + (-a3*m3*dq0 - a3*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * sin(q0 + q1 + q2 + q3 + pi/2);

        C26 = (-a3*m3*(dq0 + dq1 + dq2 + dq3)) * cos(q0 + q1 + q2 + q3);

        C33 = (-a1*b0*m1*dq1 - a1*b0*m2*dq1 - a1*b0*m3*dq1 - b0*b1*m3*dq1 - b0*b1*m3*dq1) * cos(q0 - q1) ...
            + (-a2*b0*m2*dq1 - a2*b0*m2*dq2 - a2*b0*m3*dq1 - a2*b0*m3*dq2 - b0*b2*m3*dq1 - b0*b2*m3*dq2) * cos(q1 - q0 + q2) ...
            + (-a3*b0*m3*dq1 - a3*b0*m3*dq2 - a3*b0*m3*dq3) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);

        C34 = (-a1*b0*m1*dq0 - a1*b0*m1*dq1 - a1*b0*m2*dq0 - a1*b0*m2*dq1 - a1*b0*m3*dq0 - a1*b0*m3*dq1 ...
            - b0*b1*m2*dq0 - b0*b1*m2*dq1 - b0*b1*m3*dq0 - b0*b1*m3*dq1) * cos(q0 - q1) ...
            + (-a2*b0*m2*dq0 - a2*b0*m2*dq1 - a2*b0*m3*dq0 - a2*b0*m2*dq2 - a2*b0*m3*dq1 - a2*b0*m3*dq2 ...
            - b0*b2*m3*dq0 - b0*b2*m3*dq1 - b0*b2*m3*dq2) * cos(q1 - q0 + q2) ...
            + (-a3*b0*m3*dq0 - a3*b0*m3*dq1 - a3*b0*m3*dq2 - a3*b0*m3*dq3) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a3*a1*m3*dq3) * sin(q2 + q3);

        C35 = (-a2*b0*m2*dq0 - a2*b0*m2*dq1 - a2*b0*m3*dq0 - a2*b0*m2*dq2 - a2*b0*m3*dq1 - a2*b0*m3*dq2 ...
            - b0*b2*m3*dq0 - b0*b2*m3*dq1 - b0*b2*m3*dq2) * cos(q1 - q0 + q2) ...
            + (-a3*b0*m3*dq0 - a3*b0*m3*dq1 - a3*b0*m3*dq2 - a3*b0*m3*dq3) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq0 - a1*b2*m3*dq0 - a2*b1*m2*dq1 - a2*b1*m3*dq0 - a1*b2*m3*dq1 - a2*b1*m2*dq2 ...
            - a2*b1*m3*dq1 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq0) * sin(q2) ...
            + (-b1*b2*m3*dq1 - b1*b2*m3*dq2 - a1*a2*m2*dq0 - a1*a2*m2*dq1 - a1*a2*m3*dq0 - a1*a2*m2*dq2 ...
            - a1*a2*m3*dq1 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq0 - a3*b1*m3*dq1 - a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq0 - a1*a3*m3*dq1 ...
            - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);

        C36 = (-a3*b0*m3*(dq0 + dq1 + dq2 + dq3)) * cos(q1 - q0 + q2 + q3) ...
            + (-a3*m3*(a2 + b2)*(dq0 + dq1 + dq2 + dq3)) * sin(q3) ...
            + (-a3*m3*(a1 + b1)*(dq0 + dq1 + dq2 + dq3)) * sin(q2 + q3);

        C43 = (a1*b0*m1*dq0 + a1*b0*m2*dq0 + a1*b0*m3*dq0 + b0*b1*m2*dq0 + b0*b1*m3*dq0) * cos(q0 - q1) ...
            + (a2*b0*m2*dq0 + a2*b0*m3*dq0 + b0*b2*m3*dq0) * cos(q1 - q0 + q2) ...
            + (a3*b0*m3*dq0) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);


        C44 = (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);

        C45 = (-a2*b1*m2*dq0 - a1*b2*m3*dq0 - a2*b1*m2*dq1 - a2*b1*m3*dq0 - a1*b2*m3*dq1 - a2*b1*m2*dq2 ...
            - a2*b1*m3*dq1 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq0) * sin(q2) ...
            + (-b1*b2*m3*dq1 - b1*b2*m3*dq2 - a1*a2*m2*dq0 - a1*a2*m2*dq1 - a1*a2*m3*dq0 ...
            - a1*a2*m2*dq2 - a1*a2*m3*dq1 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq0 - a3*b1*m3*dq1 - a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq0 ...
            - a1*a3*m3*dq1 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);

        C46 = (-a3*m3*(a2 + b2)*(dq0 + dq1 + dq2 + dq3)) * sin(q3) ...
            + (-a3*m3*(a1 + b1)*(dq0 + dq1 + dq2 + dq3)) * sin(q2 + q3);

        C53 = (a2*b0*m2*dq0 + a2*b0*m3*dq0 + b0*b2*m3*dq0) * cos(q1 - q0 + q2) ...
            + (a3*b0*m3*dq0) * cos(q1 - q0 + q2 + q3) ...
            + (a2*b1*m2*dq0 + a1*b2*m3*dq0 + a2*b1*m2*dq1 + a2*b1*m3*dq0 + a1*b2*m3*dq1 + a2*b1*m3*dq1 ...
            + b1*b2*m3*dq0 + b1*b2*m3*dq1 + a1*a2*m2*dq0 + a1*a2*m2*dq1 + a1*a2*m3*dq0 + a1*a2*m3*dq1) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (a3*b1*m3*dq0 + a3*b1*m3*dq1 + a1*a3*m3*dq0 + a1*a3*m3*dq1) * sin(q2 + q3);

        C54 = (a2*b1*m2*dq0 + a1*b2*m3*dq0 + a2*b1*m2*dq1 + a2*b1*m3*dq0 + a1*b2*m3*dq1 + a2*b1*m3*dq1 ...
            + b1*b2*m3*dq0 + b1*b2*m3*dq1 + a1*a2*m2*dq0 + a1*a2*m2*dq1 + a1*a2*m3*dq0 + a1*a2*m3*dq1) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (a3*b1*m3*dq0 + a3*b1*m3*dq1 + a1*a3*m3*dq0 + a1*a3*m3*dq1) * sin(q2 + q3);

        C55 = (-a3*m3*dq3*(a2 + b2)) * sin(q3);

        C56 = (-a3*m3*(a2 + b2)*(dq0 + dq1 + dq2 + dq3)) * sin(q3);

        C63 = (a3*b0*m3*dq0) * cos(q1 - q0 + q2 + q3) ...
            + (a3*m3*(a2*dq0 + a2*dq1 + a2*dq2 + b2*dq0 + b2*dq1 + b2*dq2)) * sin(q3) ...
            + (a3*m3*(a1*dq0 + a1*dq1 + b1*dq0 + b1*dq1)) * sin(q2 + q3);

        C64 = (a3*m3*(a2*dq0 + a2*dq1 + a2*dq2 + b2*dq0 + b2*dq1 + b2*dq2)) * sin(q3) ...
            + (a3*m3*(a1*dq0 + a1*dq1 + b1*dq0 + b1*dq1)) * sin(q2 + q3);

        C65 = (a3* m3 *(a2 + b2)* ( dq0 + dq1 + dq2))*sin(q3);    

        C = [0, 0, C13, C14, C15, C16;
             0, 0, C23, C24, C25, C26;
             0, 0, C33, C34, C35, C36;
             0, 0, C43, C44, C45, C46;
             0, 0, C53, C54, C55, C56;
             0, 0, C63, C64, C65, 0];

        ddq2=u-C*dq;    

        if checkMassMatrixCondition
            rc = rcond(M);
            if ~(isfinite(rc)) || rc < 1e-9
                M = M + massMatrixRegularization*eye6;
            end
            ddq = M\ddq2;
        else
            ddq = M\ddq2;
            if any(~isfinite(ddq))
                ddq = (M + massMatrixRegularization*eye6)\ddq2;
            end
        end
        % % Saturate joint limits
        % fric=[0;0;0;1;1;1];
        % xlim=[0;0;0;pi/2;pi/2;pi/2];
        % 
        % for r=4:6
        %     if abs(q(r))>=xlim(r)
        %         % Fric
        %         ddq(r)=ddq(r)-fric(r)*dq(r);
        %         % Displacement
        %         ddq(r)=ddq(r)-fric(r)*(q(r)-xlim(r));
        %     end
        % end

    end

    function xee = ee_fk(q)
        x_base = q(1); y_base = q(2); th0 = q(3);
        q1 = q(4); q2 = q(5); q3 = q(6);
        phi=68.2840*pi/180;


        b0=0.2304;
        R0 = [cos(th0) -sin(th0);
              sin(th0)  cos(th0)];

        % Arm length geometric model
        L1 = 0.305;% 0.1933 + 0.1117;
        L2 = 0.300;%0.1933 + 0.1057;
        L3 = 0.088;%0.0621 + 0.0159;

        th1 = th0 + q1 + phi;
        th2 = th1 + q2;
        th3 = th2 + q3;

        p_root = [x_base; y_base] + R0*[b0*cos(phi); b0*sin(phi)];
        p_arm  = [ L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
                   L1*sin(th1) + L2*sin(th2) + L3*sin(th3) ];

        x_e = p_root(1) + p_arm(1);
        y_e = p_root(2) + p_arm(2);

        xee = [x_e; y_e; th3];
    end


    function Jee = ee_jacobian(q)
        %#codegen
        a0=0.15;
        b0=0.2304;
        phi=68.2840*pi/180;
        th0 = q(3);
        q1  = q(4);
        q2  = q(5);
        q3  = q(6);

        L1 = 0.305;% 0.1933 + 0.1117;
        L2 = 0.300;%0.1933 + 0.1057;
        L3 = 0.088;%0.0621 + 0.0159;


        th1 = th0 + q1 + phi;
        th2 = th1 + q2;
        th3 = th2 + q3;

        % d[x;y] wrt base x,y
        J_pos_base = [1,0;
                      0,1];

        % d[x;y] wrt th0,q1,q2,q3


        dxe_root = -b0*sin(th0);
        dye_root =  b0*cos(th0);

        dxe_arm  = -L1*sin(th1) - L2*sin(th2) - L3*sin(th3);
        dye_arm  =  L1*cos(th1) + L2*cos(th2) + L3*cos(th3);

        dxe_dth0 = dxe_root + dxe_arm;
        dye_dth0 = dye_root + dye_arm;


        %dxe_dth0 = -L1*sin(th1) - L2*sin(th2) - L3*sin(th3);
        dxe_dq1  = dxe_dth0;
        dxe_dq2  = -L2*sin(th2) - L3*sin(th3);
        dxe_dq3  = -L3*sin(th3);

        %dye_dth0 =  L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
        dye_dq1  = dye_dth0;
        dye_dq2  =  L2*cos(th2) + L3*cos(th3);
        dye_dq3  =  L3*cos(th3);

        J_pos_angles = [dxe_dth0, dxe_dq1, dxe_dq2, dxe_dq3;
                        dye_dth0, dye_dq1, dye_dq2, dye_dq3];

        % phi = th0+q1+q2+q3  => phi_dot = [0 0 1 1 1 1] * dq
        J_phi = [0 0 1 1 1 1];

        Jee = [J_pos_base, J_pos_angles;
               J_phi];
    end


    % Cost function - avoid limits (added for debugging)
    function Jlim = joint_limit_barrier(q, qMinLoc, qMaxLoc, margin)
        % Vectorized soft barrier. q may be 3x1 or 3xN.
        q = reshape(q, 3, []);
        nCols = size(q,2);

        qLo = repmat(qMinLoc(:) + margin, 1, nCols);
        qHi = repmat(qMaxLoc(:) - margin, 1, nCols);

        dLo = q - qLo;
        dHi = qHi - q;

        lowViolation  = min(dLo, 0);
        highViolation = min(dHi, 0);

        Jlim = sum(sum((lowViolation./margin).^2 + (highViolation./margin).^2));
    end



    function sd = signedDistPointPolygonPrepared(x, y)
        % signed distance: positive outside, 0 on boundary, negative inside.
        % Obstacle vertices and edge vectors are prepared once at solver setup.
        originalSize = size(x);
        x = x(:);
        y = y(:);

        [in, on] = inpolygon(x, y, obsXc, obsYc);
        d = distPointToPreparedEdges(x, y);  % >= 0

        sd = d;
        insideOrOn = in | on;
        sd(insideOrOn) = -d(insideOrOn);
        sd = reshape(sd, originalSize);
    end

    function dmin = distPointToPreparedEdges(px, py)
        % Vectorized point-to-all-polygon-edges distance using the prepared
        % edge matrices.  This avoids a MATLAB loop over obstacle edges in
        % every constraint evaluation.
        px = px(:);
        py = py(:);

        if isempty(edgeX1)
            dmin = inf(size(px));
            return;
        end

        wx = bsxfun(@minus, px, edgeX1);
        wy = bsxfun(@minus, py, edgeY1);

        vv = edgeVV;
        vvSafe = vv;
        vvSafe(vvSafe < 1e-12) = 1;

        numer = bsxfun(@times, wx, edgeVX) + bsxfun(@times, wy, edgeVY);
        t = bsxfun(@rdivide, numer, vvSafe);
        t = min(1, max(0, t));

        projx = bsxfun(@plus, edgeX1, bsxfun(@times, t, edgeVX));
        projy = bsxfun(@plus, edgeY1, bsxfun(@times, t, edgeVY));

        dx = bsxfun(@minus, px, projx);
        dy = bsxfun(@minus, py, projy);
        dAll = sqrt(dx.*dx + dy.*dy);

        % Degenerate edges, if any.
        degenerate = vv < 1e-12;
        if any(degenerate)
            dAll(:,degenerate) = sqrt(bsxfun(@minus, px, edgeX1(degenerate)).^2 + ...
                                      bsxfun(@minus, py, edgeY1(degenerate)).^2);
        end

        dmin = min(dAll, [], 2);
    end

    function d = distPointToSegment(px, py, x1, y1, x2, y2)
        % distance from point(s) P to segment AB. px/py may be vectors.
        vx = x2 - x1;
        vy = y2 - y1;
        wx = px - x1;
        wy = py - y1;

        vv = vx*vx + vy*vy;
        if vv < 1e-12
            % degenerate segment
            dx = px - x1;
            dy = py - y1;
            d = sqrt(dx.*dx + dy.*dy);
            return;
        end

        t = (wx.*vx + wy.*vy) ./ vv;
        t = min(1, max(0, t));

        projx = x1 + t.*vx;
        projy = y1 + t.*vy;

        dx = px - projx;
        dy = py - projy;
        d = sqrt(dx.*dx + dy.*dy);
    end





    function val = getFastOpt(sopt, name, defaultVal)
        if isstruct(sopt) && isfield(sopt, name) && ~isempty(sopt.(name))
            val = sopt.(name);
        else
            val = defaultVal;
        end
    end

    function tf = resolveUseParallel(v)
        % Safe parallel default: only use parallel finite differences when
        % explicitly requested or when 'auto' is requested and a pool is
        % already open.  This avoids spending time launching workers inside
        % a real-time MPC loop.
        if islogical(v)
            tf = v;
            return;
        end
        if isnumeric(v)
            tf = (v ~= 0);
            return;
        end
        vchar = lower(char(v));
        if strcmp(vchar, 'auto')
            tf = false;
            try
                pool = gcp('nocreate'); %#ok<GCPCT>
                tf = ~isempty(pool);
            catch
                tf = false;
            end
        else
            tf = any(strcmp(vchar, {'true','on','yes','1'}));
        end
    end

end
