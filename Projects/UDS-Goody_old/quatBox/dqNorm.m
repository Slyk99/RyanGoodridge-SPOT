% Dual Quaternion Norm
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes the norm of a dual quaternion. The norm is defined as:
%       ||dq|| = sqrt(q_r . q_r)
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   norm_dq        - The scalar norm of the dual quaternion.
%
function norm_dq = dqNorm(dq, representation)
    %% Input Validation
    if nargin < 1
        error('At least one input (dq) is required.');
    end
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end

    %% Compute Norm
    q_r = dq(:,1);  % Extract the real part of the dual quaternion
    norm_dq = sqrt(sum(q_r.^2)); % Compute Euclidean norm of the real part
end
