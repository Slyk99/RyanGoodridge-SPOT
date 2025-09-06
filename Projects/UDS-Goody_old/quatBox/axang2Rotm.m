% Axis Angle to Rotation Matrix
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   This function converts a 4-element axis-angle representation of a rotation
%   to a rotation matrix. The axis-angle representation consists of a unit
%   vector (the axis of rotation) and an angle (the amount of rotation
%   about that axis).
%
% Inputs:
%   a (4x1): The axis-angle representation, where the first three elements
%            represent the axis of rotation and the fourth element represents
%            the angle of rotation.
%
% Outputs:
%   C (3x3): The rotation matrix.
%
function C = axang2Rotm(a)
    axis = a(1:3);
    angle = a(4);

    % Check if the axis is a 3x1 vector
    if numel(axis) ~= 3 || ~isvector(axis)
        error('Axis must be a 3x1 vector');
    end

    % Normalize the axis vector
    axis = axis / norm(axis);
    
    % Extract components of the normalized axis
    x = axis(1);
    y = axis(2);
    z = axis(3);
    
    % Compute trigonometric values
    c = cos(angle);
    s = sin(angle);
    t = 1 - c;
    
    % Compute the rotation matrix
    C = [t*x^2 + c,    t*x*y - s*z,  t*x*z + s*y;
         t*x*y + s*z,  t*y^2 + c,    t*y*z - s*x;
         t*x*z - s*y,  t*y*z + s*x,  t*z^2 + c];
end
