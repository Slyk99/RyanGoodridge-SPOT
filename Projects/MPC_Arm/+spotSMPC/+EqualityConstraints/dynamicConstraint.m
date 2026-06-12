% dynamicConstraint.m
% Constructs the equality constraints for an MPC using quadprog,
% based on discrete-time Euler dynamics of a double-mass spring system.
%
% [Aeq, beq] = dynamicConstraint(dt, x0, mass, Inertia, n, m, N)
% 
% Inputs:
%   x0      : current state [x, y, z, dx, dy, dz]
%   mass    : Mass
%   Inertia : Inertia
%   n       : Number of states
%   m       : Number of inputs
%   N       : Prediction Horizon
%
% Outputs:
%   Aeq : equality constraint matrix for quadprog
%   beq : equality RHS vector for quadprog
%
function [Aeq, beq] = dynamicConstraint(x0, Ad, Bd, n, m, N)

% Construct block diagonal matrix for input dynamics (-Bd)
BigU = kron(eye(N), -Bd);

% Construct state transition constraint matrix
BigX = zeros(n*N);
I = eye(n);
for i = 1:N-1
    row_idx = (i*n+1):(i*n+n);
    col_idx_prev = ((i-1)*n+1):(i*n);
    col_idx_curr = (i*n+1):(i*n+n);
    BigX(row_idx, col_idx_prev) = -Ad;
    BigX(row_idx, col_idx_curr) = I;
end

% First row (initial condition)
BigX(1:n,1:n) = I;

% Pre‑compute sizes
nX = n * N;   % total number of state rows
nU = m * N;   % total number of input cols

% Combine constraint matrices
Aeq = zeros(n*N, (m + n)*N);
Aeq(:, 1:nU      ) = BigU;
Aeq(:, nU + (1:nX)) = BigX;

% Construct beq
beq = zeros(n*N, 1);
beq(1:n,1) = Ad * x0;

end
