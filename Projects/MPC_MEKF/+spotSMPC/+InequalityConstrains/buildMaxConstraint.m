% buildMaxConstraint.m
%
% Constructs inequality constraint matrices for SMPC with chance constraints:
%     Pr(H * x_k <= x_max) >= 1 - epsilon   for each constrained state
%
% Inputs:
%   x_max   - (nc x 1) max values for each constrained state
%   Pstack  - (nx x nx x N) predicted state covariance matrices
%   H       - (nc x nx) selects the constrained states
%   m       - control input dimension
%   N       - horizon length
%   epsilon - (scalar or nc x 1) allowed violation probability (per state)
%
% Outputs:
%   Aineq   - Inequality constraint matrix [zeros | kron]
%   bineq   - Right-hand side tightened with std devs
%
function [Aineq, bineq] = buildMaxConstraint(x_max, Pstack, H, m, N, epsilon)
    nc = size(H, 1);   % number of constrained states
    nx = size(Pstack, 1);

    % Allocate
    A_state = kron(eye(N), H);                     % (N*nc x N*nx)
    A_input = zeros(N * nc, N * m);                % (N*nc x N*nu)
    Aineq   = [A_input, A_state];                  % full constraint matrix
    bineq   = zeros(N * nc, 1);                    % tightened bounds

    % Ensure epsilon is a vector of size nc
    if isscalar(epsilon)
        epsilon_vec = epsilon * ones(nc, 1);
    else
        epsilon_vec = epsilon;
    end

    % Compute quantile from Gaussian inverse CDF
    z_epsilon = norminv(1 - epsilon_vec);   % nc x 1

    % Compute tightened bounds at each horizon step
    for k = 1:N
        Pk = Pstack(:, :, k);               % nx x nx
        Sigma_k = H * Pk * H';              % nc x nc

        std_k = sqrt(diag(Sigma_k));        % nc x 1

        % b_k = x_max - z_epsilon .* std_k
        bineq((k-1)*nc + 1 : k*nc) = x_max - z_epsilon .* std_k;
    end
end

