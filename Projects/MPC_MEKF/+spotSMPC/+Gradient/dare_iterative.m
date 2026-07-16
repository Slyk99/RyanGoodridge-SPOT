function [P, K] = dare_iterative(A, B, Q, R, maxIter, tol)
%DARE_ITERATIVE   Solves the discrete-time algebraic Riccati equation via iteration
%
% Inputs:
%   A, B, Q, R  - Discrete system matrices
%   maxIter     - Maximum iterations (e.g., 1000)
%   tol         - Convergence tolerance (e.g., 1e-8)
%
% Outputs:
%   P           - Stabilizing solution to the DARE
%   K           - Corresponding LQR gain

    %#codegen
    n = size(A,1);
    P = Q;  % Initial guess
    
    for k = 1:maxIter
        P_prev = P;

        % Calculate gain
        S = R + B' * P * B;
        F = B' * P * A;
        K = S \ F;  % Equivalent to inv(S)*F but numerically safer

        % Riccati iteration
        P = Q + A' * P * A - A' * P * B * K;

        % Check convergence
        if norm(P - P_prev, 'fro') < tol
            break;
        end
    end
end
