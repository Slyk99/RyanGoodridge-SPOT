% Quaternion to Rotation Matrix
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a quaternion representation of a rotation to a
%   rotation matrix. The rotation matrix represents the linear part of the
%   homogeneous transformation matrix, excluding translation.
% 
% Inputs:
%   q (4x1): The quaternion to convert, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Outputs:
%   C (3x3): The rotation matrix.
%
function C = quat2Rotm(q, representation)
    % Validate input dimensions
    if ~isvector(q) || numel(q) ~= 4
        error('Input quaternion q must be a 4-element vector.');
    end
    
    % Reshape to 4x1 if it is 1x4
    if size(q, 1) == 1 && size(q, 2) == 4
        q = q'; % Transpose to make it 4x1
    elseif size(q, 1) ~= 4 || size(q, 2) ~= 1
        error('Input quaternion q must be a 4x1 or 1x4 vector.');
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

            I = eye(3);
            C = (scalar^2 - vector'*vector)*I + 2*vector*vector' + 2*scalar*skew(vector);

        case 'scalarLast'
            % For scalar-second: q = [vector; scalar]
            vector = [q(1); q(2); q(3)];
            scalar = q(4);

            I = eye(3);
            C = (scalar^2 - vector'*vector)*I + 2*(vector)*vector' -2*scalar*skew(vector);

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
