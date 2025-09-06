% inputConstraints.m
% Constructs inequality constraints Aineq*z <= bineq for MPC inputs only (max force).
%
% [Aineq, bineq] = inputConstraints(umax, n, m, N)
%
% Inputs:
%   umax : scalar maximum absolute force
%   n    : Number of states
%   m    : Number of inputs
%   N    : Prediction Horizon
%
% Outputs:
%   Aineq : inequality constraint matrix for quadprog
%   bineq : RHS vector for inequality constraints
%
function [Aineq, bineq] = inputConstraints(umax, n, m, N)
% Build block for inputs: +u_i <= umax and -u_i <= umax
% A_u will be (2*m*N) x (m*N)
Iu = eye(m*N);
A_u = [ Iu;   % +u <= umax
       -Iu]; % -u <= umax

% Zero columns for state variables
A_x = zeros(2*m*N, n*N);

% Combine to full Aineq: [A_u, A_x]
Aineq = [A_u, A_x];

% Build bineq: vector of length 2*m*N, all entries = umax
bineq = repmat([umax; umax], N, 1);  % size: 2*m*N × 1
end