% Quaternion 2 Xi
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes Xi (Ξ) matrix of a quaternion to satisfy the
%   equation q_dot = -dt/2 * Xi * w 
% 
% Inputs:
%   q (4x1): The quaternion, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Output:
%   Xi (4x3): The Xi (Ξ) matrix.
%
function Xi = quat2Xi(q,representation) 
    % Validate input dimensions
    if ~isvector(q) || numel(q) ~= 4
        error('Input quaternion q must be a 4-element vector.');
    end

    % Set default representation if not provided
    if nargin < 1 || isempty(representation)
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
            scalar = q(1);
            vecter = [q(2); q(3); q(4)];

        case 'scalarLast'
            scalar = q(4);
            vecter = [q(1); q(2); q(3)];

        otherwise
            error('Unexpected representation. This should not occur.');
    end

    I = scalar*eye(3);
    Xi = [-1*vector';
           I + skew(vecter)];
end
