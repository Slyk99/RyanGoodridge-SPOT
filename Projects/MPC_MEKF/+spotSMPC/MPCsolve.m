% SMPCsolve.m
% =========================================================================
% Chance-Constrained Stochastic MPC Setup
%
% This implementation realizes a chance-constrained Stochastic Model
% Predictive Control (SMPC) formulation following the methodology in:
%   Edwin Alonso González Querubín (2025), 
%   “Stochastic Model Predictive Control Toolbox,” 
%   MATLAB Central File Exchange, 
%   https://www.mathworks.com/matlabcentral/fileexchange/75803-stochastic-model-predictive-control-toolbox, 
%   Retrieved August 1, 2025.
%
% Core features:
%   • Predicts state-covariance propagation over the MPC horizon via
%     Σₖ₊₁ = A_cl Σₖ A_clᵀ + G Qw Gᵀ
%   • Translates probabilistic state bounds
%        Pr[ H xₖ ≤ x_max ] ≥ 1 – ε
%     into deterministic, tightened linear constraints
%        H x̂ₖ + zₑ·σₖ ≤ x_max
%     where zₑ = Φ⁻¹(1–ε) and σₖ = √diag(H Σₖ Hᵀ).
%   • Builds Aineq and bineq matrices that apply uniformly over all
%     constrained states and all prediction steps.
%   • Supports both upper (x ≤ x_max) and lower (x ≥ x_min) bounds
%     via sign-inversion of H and x_max/x_min.
%
% =========================================================================
% Solver Functionality
% [z, u, result, k] = fcn(z_0, Aineq, bineq, H, f, Aeq, beq, k, M)
%
% Inputs:
%   z_0    : previous solution vector
% Aineq, bineq, H, f, Aeq, beq: QP matrices for quadprog
%   minimize    (1/2)*x'*H*x + f'*x
%   subject to  Aineq*x ≤ bineq
%               Aeq*x = beq
%   k      : current step counter since last solve
%   M      : Control Horizon
%
% Outputs:
%   z      : QP solution vector
%   u      : control to apply (first m entries of z)
%   result : solver result [exitflag, iterations, cputime] or [] if skipped
%   k      : updated counter (reset to 1 after solve)
%
function [z, u, results] = MPCsolve(H, f, Aineq, bineq, Aeq, beq, z_0, m)
% run quadprog and reset counter
options = optimoptions('quadprog', 'Algorithm', 'active-set', 'MaxIterations', 300);

tic;
[z, ~, exitflag, output] = quadprog(H, f, Aineq, bineq, Aeq, beq, [], [], z_0, options);
cputime = toc;

% Extract first control block (k = 1 after solve)
u = z(1:m);

% Solver result: [exitflag, iterations, cputime]
results = [exitflag, output.iterations, cputime];

end