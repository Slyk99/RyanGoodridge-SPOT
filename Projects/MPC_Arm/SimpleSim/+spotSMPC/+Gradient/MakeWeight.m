% MakeWeight.m
% Constructs the quadratic cost matrices for MPC using quadprog,
% allowing distinct terminal weighting.
%
% Syntax:
%   H0 = MakeWeight(Q,R,A,B,n,N)
%
% Description:
%   Builds the Hessian H to satisfy
%       - H = 2 * H0;
%       - f = -2 * (H0 * z_ref_full);
%
% Inputs:
%   Ad     : Discretized State Transition Matrix
%   Bd     : Discretized State Input Matrix
%   Q      : State weighting matrix for stages 0..N-2 (n×n)
%   R      : Input weighting matrix for all stages (m×m)
%   N      : Prediction Horizon
%
% Outputs:
%   H0      : Hessian matrix ((m+n)N × (m+n)N)
%
function H0 = MakeWeight(Q, Qf, R, N)
    % Build block-diagonal for inputs: R repeated N times
    R_blk = kron(eye(N), R);
    
    % Build block-diagonal for states: Q for first N-1, Qf for last
    Q_blk = kron(eye(N-1), Q);   % nN × nN
    Q_blk = blkdiag(Q_blk, Qf);
    
    % Base Hessian
    H0 = blkdiag(R_blk, Q_blk);

end