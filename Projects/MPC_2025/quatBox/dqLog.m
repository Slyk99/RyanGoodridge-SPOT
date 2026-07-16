% Dual Quaternion Logarithm
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes the logarithm of a dual quaternion using the formula:
%       log(dq) = [log(q_r), q_d * q_r_inv]
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   dq_log         - The logarithm of the dual quaternion (4x2 matrix).
%
function dq_log = dqLog(dq, representation)
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

    %% Compute Logarithm
    q_r = dq(:,1); % Real part
    q_d = dq(:,2); % Dual part

    q_r_log = quatLog(q_r, representation); % Compute quaternion logarithm
    q_r_inv = dqInv([q_r, zeros(4,1)], representation); % Inverse of real part
    q_d_new = quatMultiply(q_d, q_r_inv(:,1), representation);

    dq_log = [q_r_log, q_d_new];
end
