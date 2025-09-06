% Dual Quaternion Spherical Linear Interpolation (SCLERP)
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes the spherical linear interpolation (SCLERP) between two dual quaternions.
%
% Inputs:
%   dq1           - The starting dual quaternion (4x2 matrix).
%   dq2           - The ending dual quaternion (4x2 matrix).
%   t             - Interpolation factor (0 ≤ t ≤ 1).
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   dq_interp     - The interpolated dual quaternion (4x2 matrix).
%
function dq_interp = dqSclerp(dq1, dq2, t, representation)
    %% Input Validation
    if nargin < 3
        error('At least three inputs (dq1, dq2, t) are required.');
    end
    if nargin < 4 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq1) || any(size(dq1) ~= [4,2]) || ~ismatrix(dq2) || any(size(dq2) ~= [4,2])
        error('Both dq1 and dq2 must be 4x2 matrices representing dual quaternions.');
    end
    if ~isscalar(t) || t < 0 || t > 1
        error('Interpolation factor t must be a scalar in the range [0,1].');
    end

    %% Compute SCLERP
    dq1_inv = dqInv(dq1, representation);            % Inverse of dq1
    dq1_to_dq2 = dqMultiply(dq1_inv, dq2, representation); % Relative transformation
    dq_interp = dqMultiply(dq1, dqPower(dq1_to_dq2, t, representation), representation);
end
