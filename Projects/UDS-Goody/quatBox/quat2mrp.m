% Quaternion Conjugate
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   - q_con = quatCon(q) computes the conjugate of a quaternion
%     assuming scalar-second representation (default).
% 
%   - q_con = quatCon(q, representation) computes the conjugate
%     of a quaternion with the specified representation:
%     - 'scalarSecond' (default): [vector; scalar]
%     - 'scalarFirst': [scalar; vector]
% 
% Inputs:
%   q              - A 4x1 quaternion represented as a column vector.
%   representation - (Optional) A string specifying the representation
%                    ('scalarFirst' or 'scalarLast'). Default is 'scalarLast'.
% 
% Output:
%   q_con          - The conjugate of the quaternion, represented
%                    in the same order as the input representation.
%

function mrp = quat2mrp(q, a, f, representation)
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
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarSecond''.');
    end

    mrp = zeros(3,1);
    vector = mrp;
    
    % Compute quaternion conjugate based on representation
    switch representation
        case 'scalarFirst'
            % For scalar-first: q = [scalar; vector]
            scalar = q(1);
            vector = [q(2); q(3); q(4)];
            
        case 'scalarLast'
            % For scalar-second: q = [vector; scalar]
            scalar = q(4);
            vector = [q(1); q(2); q(3)];

        otherwise
            error('Unexpected representation. This should not occur.');
    end

    mrp = (vector.*f)/(a + scalar);
end
