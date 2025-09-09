% Dual Quaternion Exponential
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes the exponential of a dual quaternion using the formula:
%       exp(dq) = [exp(q_r), exp(q_r) * q_d]
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   dq_exp         - The exponential of the dual quaternion (4x2 matrix).
%
function dq_exp = dqExp(dq, representation)
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

    %% Compute Exponential
    q_r = dq(:,1); % Real part
    q_d = dq(:,2); % Dual part

    q_r_exp = quatExp(q_r, representation); % Compute quaternion exponential
    dq_exp = [q_r_exp, quatMultiply(q_r_exp, q_d, representation)];
end
