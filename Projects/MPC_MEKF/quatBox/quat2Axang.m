% Quaternion Conjugate
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function computes the quaternion conjugate of a given quaternion.
%   The quaternion conjugate is mathematically equivalent to the mirror image
%   of the quaternion with respect to the origin.
% 
% Inputs:
%   q (4x1): The quaternion to compute the conjugate of, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Outputs:
%   q_conj (4x1): The quaternion conjugate.
%
function a = quat2Axang(q,representation) 
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
            angle = 2*acos(q(1));
            den = sin(angle/2);
            a = [q(2)/den;
                q(3)/den;
                q(4)/den;
                angle];

        case 'scalarLast'
            angle = 2*acos(q(4));
            den = sin(angle/2);
            a = [q(1)/den;
                q(2)/den;
                q(3)/den;
                angle];

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
