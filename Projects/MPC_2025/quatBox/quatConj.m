% Quaternion Conjugate
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
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
%   q_con (4x1): The quaternion conjugate.
%
function q_con = quatConj(q, representation)
    % Validate input dimensions
    if ~isvector(q) || length(q) ~= 4
        error('Input quaternion q must be a 4x1 vector.');
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
    switch representation
        case 'scalarFirst'
            % For scalar-first: q = [scalar; vector]
            scalar = q(1);
            vector = [q(2); q(3); q(4)];
            q_con = [scalar; -vector;];
        case 'scalarLast'
            % For scalar-second: q = [vector; scalar]
            vector = [q(1); q(2); q(3)];
            scalar = q(4);
            q_con = [-vector; scalar];
        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
