% Quaternion Inverse
% Ryan Goodridge
% 3/27/2023
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes the quaternion inverse, which represents the
%   rotation that undoes the rotation represented by the original quaternion.
% 
% Inputs:
%   q (4x1): The quaternion to invert, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Outputs:
%   q_inv (4x1): The quaternion inverse.
%
% Note:
%   - For unit quaternions (quaternions with a norm of 1), the inverse is
%     the same as the conjugate.
%
function q_inv = quatInv(q, representation)
    % Validate input dimensions for quaternion
    if ~isvector(q) || length(q) ~= 4
        error('Input quaternion q must be a 4-element vector.');
    end
    % Set default representation if not provided
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end
    % Validate representation input
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end

    % Compute quaternion conjugate based on representation
    q_con = quatConj(q, representation);

    % Compute quaternion norm (magnitude)
    q_mag = quatNorm(q);

    % Check for zero norm (singular quaternion)
    if abs(q_mag) < eps
        error('Input quaternion has a magnitude of zero. Quaternion inverse is undefined for singular quaternions.')
    end

    % Compute quaternion inverse using conjugate and norm squared
    q_inv = q_con / (q_mag * q_mag);
end

