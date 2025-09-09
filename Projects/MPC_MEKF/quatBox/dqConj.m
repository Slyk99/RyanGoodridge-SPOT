% Dual Quaternion Conjugate
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes a conjugate of a dual quaternion according to one of three types.
%
%   A dual quaternion is represented as a 4x2 matrix:
%       dq = [q_r, q_d]
%   where q_r is the rotation (real) quaternion and q_d is the dual (translation) quaternion.
%
%   The three conjugates are defined as:
%
%   1. Classic conjugate (default):
%          dq^* = q_r^* + q_d^* 
%      which in terms of scalar and vector parts is:
%          [ q_r0 + q_d0 ; 
%           -q_rvec - q_dvec ]
%
%   2. Dual conjugate:
%          dq^• = q_r - q_d 
%      which is:
%          [ q_r0 - q_d0 ; 
%            q_rvec - q_dvec ]
%
%   3. Real conjugate:
%          dq^⋄ = q_r^* - q_d^* 
%      which is:
%          [ q_r0 - q_d0 ; 
%           -q_rvec + q_dvec ]
%
%   The input 'representation' specifies whether the input dual quaternion uses
%   'scalarLast' (default) or 'scalarFirst' conventions. In scalarLast, each quaternion is
%   [v; s] (vector part then scalar); in scalarFirst, it is [s; v].
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   type           - (Optional) A string specifying the type of conjugate.
%                    Options: 'classic' (default), 'dual', or 'real'.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   q_out          - A 4x1 quaternion computed from dq according to the specified conjugate.
%
function q_out = dqConj(dq, type, representation)
    %% Input Validation
    if nargin < 1
        error('At least one input (dq) is required.');
    end
    if nargin < 2 || isempty(type)
        type = 'classic';
    end
    if nargin < 3 || isempty(representation)
        representation = 'scalarLast';
    end
    
    validTypes = {'classic', 'dual', 'real'};
    if ~any(strcmp(type, validTypes))
        error('Invalid type. Choose ''classic'', ''dual'', or ''real''.');
    end
    
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose ''scalarFirst'' or ''scalarLast''.');
    end
    
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end

    %% Extract the rotation (q_r) and dual (q_d) quaternions.
    q_r = dq(:,1);
    q_d = dq(:,2);
    
    %% Based on representation, extract scalar and vector parts.
    switch representation
        case 'scalarFirst'
            % q = [s; v]
            s_r = q_r(1);
            v_r = q_r(2:4);
            s_d = q_d(1);
            v_d = q_d(2:4);
        case 'scalarLast'
            % q = [v; s]
            s_r = q_r(4);
            v_r = q_r(1:3);
            s_d = q_d(4);
            v_d = q_d(1:3);
        otherwise
            error('Unexpected representation.');
    end

    %% Compute the output scalar and vector parts based on the chosen type.
    switch type
        case 'classic'
            % dq^* = [ q_r0 + q_d0 ; -q_rvec - q_dvec ]
            s_out = [s_r, s_d];
            v_out = [-v_r, - v_d];
        case 'dual'
            % dq^• = [ q_r0 - q_d0 ; q_rvec - q_dvec ]
            s_out = [s_r, - s_d];
            v_out = [v_r, - v_d];
        case 'real'
            % dq^⋄ = [ q_r0 - q_d0 ; -q_rvec + q_dvec ]
            s_out = [s_r, - s_d];
            v_out = [-v_r, + v_d];
        otherwise
            error('Unexpected type.');
    end

    %% Reassemble the output quaternion in the same representation as the input.
    switch representation
        case 'scalarFirst'
            q_out = [s_out; v_out];
        case 'scalarLast'
            q_out = [v_out; s_out];
    end
end
