% Axis Angle to Quaternion
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a 4-element axis-angle representation of a rotation
%   to a quaternion. The axis-angle representation consists of a unit vector
%   (the axis of rotation) and an angle (the amount of rotation about that axis).
%   The output quaternion can be represented with either a scalar element 
%   as the first element (scalar first) or the last element (scalar last).
% 
% Inputs:
%   a (4x1): The axis-angle representation, where the first three elements
%            represent the axis of rotation and the fourth element represents
%            the angle of rotation.
%   representation (optional, string): The desired output format of the
%            quaternion. Valid options are 'scalarFirst' (default) or
%            'scalarLast'.
%
% Outputs:
%   q (4x1): The quaternion representing the rotation.
%
function q = axang2Quat(a,representation) 
    % Check if the axis is a 4x1 vector
    if numel(a) ~= 4 || ~isvector(a)
        error('Axis must be a 4x1 vector');
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
    axis = [a(1); a(2); a(3)];
    angle = a(4);

    % Normalize the axis vector
    axis = axis / norm(axis);
    
    % Compute the quaternion
    qw = cos(angle / 2);
    qx = axis(1) * sin(angle / 2);
    qy = axis(2) * sin(angle / 2);
    qz = axis(3) * sin(angle / 2);

    switch representation
        case 'scalarFirst'
            % Assign to the output quaternion
            q = [qw; qx; qy; qz];

        case 'scalarLast'
            % Assign to the output quaternion
            q = [qx; qy; qz; qw];

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end