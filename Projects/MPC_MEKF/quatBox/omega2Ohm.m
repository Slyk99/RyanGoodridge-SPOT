% omega 2 Ohm
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes Ohm (Ω) matrix of a the angular velocity to satisfy the
%   equation q_dot = -dt/2 * Ω * q. This also means that the representation
%   of the quaternion is important, because Ohm (Ω) will change.
% 
% Inputs:
%   w (3x1): The angular velocity, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Output:
%   Ohm (4x3): The Ohm (Ω) matrix.
%
function Ohm = omega2Ohm(w,representation) 
    % Validate input dimensions
    if ~isvector(w) || numel(w) ~= 3
        error('Input angular velocity must be a 3-element vector.');
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
            Ohm = [0 -w';
                   w, -1*skew(w)];

        case 'scalarLast'
            Ohm = [-1*skew(w) w;
                   -w', -0];

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
