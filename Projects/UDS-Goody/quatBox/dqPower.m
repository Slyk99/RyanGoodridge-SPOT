% Dual Quaternion Power
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes the power of a dual quaternion using the formula:
%       dq^p = exp(p * log(dq))
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   p              - A scalar exponent.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   dq_power       - The result of dq^p as a 4x2 dual quaternion.
%
function dq_power = dqPower(dq, p, representation)
    %% Input Validation
    if nargin < 2
        error('At least two inputs (dq and p) are required.');
    end
    if nargin < 3 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end
    if ~isscalar(p)
        error('Exponent p must be a scalar.');
    end

    %% Compute Power
    dq_log = dqLog(dq, representation);
    dq_scaled_log = p * dq_log; % Element-wise scaling
    dq_power = dqExp(dq_scaled_log, representation);
end
