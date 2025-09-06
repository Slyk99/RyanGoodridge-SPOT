function [u, P, Y] = UTC_Nstep(dt, x_ref, x_act, P, W0, Q, R, m, N, CTLHndle, DynHndle, Params)
% UTC_Nstep  N-step Unscented Transform Controller (exact nonlinear propagation)
%
% Inputs:
%   dt        - time step for DynHndle
%   x_ref     - reference output/state (nx x 1)
%   x_act     - current actual state (nx x 1)
%   P         - control covariance (m x m)
%   W0        - first sigma weight (scalar)
%   Q         - process noise on control (m x m)
%   R         - measurement noise on output/state (nx x nx)
%   m         - control dimension (length(u))
%   N         - number of steps to propagate each sigma (positive integer)
%   CTLHndle  - function handle: u_center = CTLHndle(x_ref, x_act, Params)
%   DynHndle  - function handle: x_next = DynHndle(x, u, dt, Params)
%   Params    - additional params passed to CTLHndle/DynHndle
%
% Outputs:
%   u         - updated control (m x 1)
%   P         - updated control covariance (m x m)
%   Y         - predicted outputs/states for each sigma (nx x (2*m+1))
%
% Citation: 
% Analysis of the Unscented Transform Controller for Systems with Bounded
% Nonlinearities
%
% The Unscented Transform Controller: a new model predictive control law 
% for highly nonlinear systems
%
% Unscented Predictive Control for Battery Energy Storage Systems 
% in Networked Microgrids
%

%% --- predict center control and build weights ----------------------------
u_center = CTLHndle(x_ref, x_act, Params);   % m x 1

% weights for 2m+1 sigma points
W = [W0; ones(2*m,1) * (1 - W0) / (2*m)];    % (2*m+1) x 1

%% --- generate sigma points around control mean ---------------------------
% scale and cholesky (consistent with earlier corrected code)
L = chol(P * (m / (1 - W0)))';               % m x m
U = [u_center, bsxfun(@plus, u_center, L), bsxfun(@minus, u_center, L)]; 
% U is m x (2*m+1)

%% --- propagate each sigma constant-control forward N steps -------------
nx = length(x_act);
nsig = 2*m + 1;
Y = zeros(nx, nsig);

for i = 1:nsig
    x = x_act;
    % hold sigma input U(:,i) constant for N steps
    for step = 1:N
        x = DynHndle(x, U(:,i), dt, Params);
    end
    Y(:,i) = x;   % predicted state after N steps for sigma i
end

%% --- compute predicted means and cross-covariances -----------------------
u_bar = U * W;     % m x 1  (predicted input mean)
y_bar = Y * W;     % nx x 1 (predicted state mean)

U_diff = U - u_bar;        % m x nsig
Y_diff = Y - y_bar;        % nx x nsig

P_bar = U_diff * diag(W) * U_diff' + Q;     % m x m  (predicted control cov)
P_yy  = Y_diff * diag(W) * Y_diff' + R;     % nx x nx (predicted state cov)
P_uy  = U_diff * diag(W) * Y_diff';         % m x nx (cross-covariance)

%% --- Kalman-style update for control given desired x_ref -----------------
% Solve for K such that K * P_yy = P_uy -> K = P_uy / P_yy  (m x nx)
K = P_uy / P_yy;

% innovation is state-space (x_ref - y_bar)
u = u_bar + K * (x_ref - y_bar);

% covariance update (note minus sign)
P = P_bar - K * P_yy * K';

end
