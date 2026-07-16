% MPCsolve.m
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