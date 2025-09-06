% Quaternion Normalize
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function normalizes a quaternion representation of a rotation.
%   Normalization ensures the quaternion has a unit norm (magnitude of 1).
% 
% Inputs:
%   q (4x1): The quaternion to normalize, represented as a column vector.
%   representation (optional, string): The desired input format of the
%            quaternion. Valid options are 'scalarFirst' (default) or
%            'scalarLast'.
% 
% Outputs:
%   q_norm (4x1): The normalized quaternion.
%
function q_norm = normalizeQuat(q,representation) 
    % Validate input dimensions
    if ~isvector(q) || numel(q) ~= 4
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

    switch representation
        case 'scalarFirst'
            norm = quatNorm(q);
            q_norm = q./norm;

        case 'scalarLast'
            norm = quatNorm(q);
            q_norm = q./norm;

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
