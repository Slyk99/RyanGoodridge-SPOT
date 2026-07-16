% fovConstraints  Build linearized FOV inequality rows for a horizon
%  Designed for MPC that optimizes only chaser states (n per step, typically n=3).
%
% Signature assumptions:
%   z0 contains control sequence first (m*N entries) then chaser states stacked
%   per step: [pcx; pcy; thc] for each step (so reshape below is valid).
%
% Inputs:
%   z0            - decision vector containing [u_stack; xC_stack]
%   PCStack       - chaser covariance stack (3x3xN)
%   xTStack       - target state stack (rows: [ptx; pty], cols: 1..N) (2xN)
%   PTStack       - target covariance stack (2x2xN)
%   Camera_FOV    - full horizontal FOV angle (radians)
%   Camera_Offset - [ox; oy; theta_off] (3x1) expected
%   m             - control dimension (per step)
%   n             - chaser state dimension (per step), typically 3
%   N             - horizon length
%   epsilon       - total risk (used only if stochastic tightening enabled)
%
% Outputs:
%   Aineq, bineq  - Aineq * z_chaser <= bineq
%                   where z_chaser is the stacked chaser states only (n*N x 1)
%
% NOTE: This implements deterministic linearization. See commented section
% below to enable stochastic tightening using PCStack and PTStack.
%
function [Aineq, bineq] = fovConstraints(z0, PCStack, xTStack, PTStack, xRef, Camera_FOV, Camera_Offset, m, n, N, epsilon)
% Extract chaser states from z0.
% Assumes z0 = [u_stack; xC_stack] where u_stack has m*N entries.
xCStack = reshape(z0(m*N+1:end), n, N);  % n x N

% Preallocate inequalities: 2 rows per step (left/right FOV)
Aineq = zeros(2*N, (m+n)*N);  % chaser-only decision columns
bineq  = zeros(2*N, 1);

% unpack camera offset
o = Camera_Offset(1:2);
theta_off = Camera_Offset(3);


J = [0, -1; 1, 0];  % skew / rotation derivative helper

row = 1;
alpha = Camera_FOV;

for i = 1:N
    % Nominal chaser (from decision vector) and target (predicted)
    pc  = xCStack(1:2, i);   % [pcx; pcy]
    thc = xCStack(3,   i);   % theta_c
    pt  = xTStack(1:2, i);   % [ptx; pty]
    
    % Rotations
    R_c = [cos(thc), -sin(thc); sin(thc), cos(thc)];
    theta_cam = thc + theta_off;
    R_cam = [cos(theta_cam), -sin(theta_cam); sin(theta_cam), cos(theta_cam)];
    R_camT = R_cam';
    
    % relative vector s = p_t - p_c - R_c * o
    s = pt - pc - R_c * o;
    
    % target in camera frame
    p_rel = R_camT * s;    % [x_rel; y_rel]
    x_rel = p_rel(1);
    y_rel = p_rel(2);
    
    % nominal angle
    phi_nom = wrapToPi( xRef((i-1)*n + 3) );
    
    % gradient wrt p_rel
    den = x_rel^2 + y_rel^2;
    if den < 1e-12
        den = 1e-12; 
    end

    grad_prel_phi = (1/den) * [-y_rel; x_rel];   % 2x1
    
    % Jacobians wrt chaser states
    dp_dpc = - R_camT;    % 2x2
    dp_dthc = - J * R_camT * s  -  R_camT * (R_c * J * o); % 2x1
    
    dpdx_chaser = [ dp_dpc, dp_dthc ];   % 2x3
    H_phi_chaser = (grad_prel_phi') * dpdx_chaser;  % 1x3
    
    % Build deterministic inequality rows for chaser-only vector x_c = [pc; thc]
    x_c_nom = [pc; thc];  % 3x1
    H_up  = H_phi_chaser;  
    b_up  = (alpha/2) - phi_nom + H_phi_chaser * x_c_nom;

    H_low = -H_phi_chaser; 
    b_low = (alpha/2) + phi_nom - H_phi_chaser * x_c_nom;
    
    % Place into Aineq/bineq at chaser indices
    idx = (i-1)*n + (1:n);  % indices of this step in the chaser-only decision vector
    Aineq(row, idx + m*N) = [H_up,zeros(1,3)];
    bineq(row)     = b_up;
    row = row + 1;
    
    Aineq(row, idx + m*N) = [H_low,zeros(1,3)];
    bineq(row)     = b_low;
    row = row + 1;
    
    % ------- stochastic tightening -------
    % To enable stochastic chance constraints you must compute the variance
    % of phi using the full Jacobian w.r.t. [p_c; theta_c; p_t] (1x5), then
    % compute sigma_phi = sqrt(H_full * P_full * H_full') and tighten b:

    dp_dpt = R_camT;                     % 2x2
    dpdx_full = [dp_dpc, dp_dthc, dp_dpt];   % 2x5
    H_phi_full = (grad_prel_phi') * dpdx_full; % 1x5

    % Assemble joint covariance P_full (5x5) from PCStack and PTStack:
    Pch = PCStack(1:3,1:3,i);    % 3x3 (chaser cov)
    Pt  = PTStack(1:2,1:2,i);    % 2x2 (target cov)

    % If cross-covariances are unknown/assumed zero:
    P_full = blkdiag(Pch,Pt);

    sigma_phi = sqrt( H_phi_full * P_full * H_phi_full' ); % scalar
    zval = norminv(1 - epsilon/2); % split risk for two-sided angle bounds

    % Tighten RHS (subtract the safety margin)
    bineq(row-2) = bineq(row-2) - zval * sigma_phi;
    bineq(row-1) = bineq(row-1) - zval * sigma_phi;

end

end

