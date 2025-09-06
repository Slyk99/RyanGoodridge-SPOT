% costFunctionMatrices.m
% Constructs the quadratic cost matrices for MPC using quadprog,
% allowing distinct terminal weighting.
%
% Syntax:
%   [H, f] = GradientMatrices(x_ref, u_ref, H0, N)
%
% Description:
%   Builds the Hessian H and gradient f for the cost
%       J = \sum_{i=0}^{N-2} [(x_i - x_ref)' Q (x_i - x_ref) + u_i' R u_i]
%           + (x_{N-1} - x_ref)' Qf (x_{N-1} - x_ref)
%   i.e., the last state stage uses terminal weight Qf instead of Q.
%   The decision variable z = [u0;...;u_{N-1}; x0;...;x_{N-1}].
%
% Inputs:
%   x_ref  : Reference state vector (n×1)
%   u_ref  : Reference input vector (m×1)
%   N      : Horizon length (number of stages)
%   H0     : Hessian matrix ((m+n)N × (m+n)N)
%
% Outputs:
%   H      : Hessian matrix for quadprog of size ((m+n)N × (m+n)N)
%   f      : Gradient vector for quadprog of length (m+n)N
%
function [H, f] = GradientMatrices(x_ref, u_ref, H0, n, m, N)

% Preallocate fixed-size reference vector
z_ref_full = zeros(N*(m + n), 1);

% Fill u_ref part (first N*m entries)
for i = 1:N
    z_ref_full((i-1)*m + (1:m)) = u_ref((m*(i-1) + 1: m*(i)),1);
end

% Fill state part
for i = 1:N
    z_ref_full(N*m + (i-1)*n + (1:n)) = x_ref((n*(i-1) + 1: n*(i)),1);
end

% Form QP Hessian and gradient
H = 2 * H0;
f = (-2.*z_ref_full'*H0)';

end


