% initialGuess.m
% Generates an initial guess for quadprog by shifting previous controls
% and then propagating the dynamics to compute a feasible state trajectory.
%
% z0 = initialGuess(z_prev, x0, dt, mass, Inertia, n, m, M, N)
%
% Inputs:
%   z_prev  : previous optimal solution vector [u0;...;u_{N-1}; x1;...;x_N]
%   x0      : Current state
%   x_ref   : Desired State
%   P0      : Initial state covariance (nx x nx)
%   dt      : sampling time
%   Ad      : Discretized State Transition Matrix
%   Bd      : Discretized State Input Matrix 
%   K       : Optimal Control Gain (LQR)
%   Q       : Process noise covariance (nx x nx)
%   n       : Number of states
%   m       : Number of inputs
%   N       : Prediction Horizon
%   M       : Control Horizon
%
% Output:
%   z0     : Initial condition for the solver
%
function [z0,Pstack] = initialGuess(z_prev, x0, P0, x_ref, Ad, Bd, K, Q, n, m, N, M)

% Partition previous solution
U_prev = z_prev(1 : m*N);

% Shift controls by M steps (ensure fixed size)
U_shift = zeros(m*N,1);
if M <= N
    U_shift(1:end - m*M) = U_prev(m*M+1:end);
end
U0 = U_shift;

% Propagate state trajectory for next N steps using shifted control
X0 = zeros(n*N,1);
Pstack = zeros(n,n,N);
x = x0;
for i = 1:N
    % State Propagation
    if i < (N-M)
        u_i = U0((i-1)*m + (1:m));
    else
        u_i = zeros(3,1); % K*(x_ref((i-1)*n + (1:n)) - x);
        U0((i-1)*m + (1:m)) = u_i;
    end
    x = Ad*x + Bd*u_i;
    X0((i-1)*n + (1:n)) = x;

    % Covar Propagation
    P0 = Ad*P0*Ad' + Bd*Q*Bd';
    Pstack(:,:,i) = P0;
end

% Preallocate and assign z0 (fixed-size output)
z0 = z_prev;
z0(1:m*N) = U0;
z0(m*N+1:end) = X0;

end