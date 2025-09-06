% Axis Angle to Homogeneous Transform
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a 4-element axis-angle representation of a rotation
%   to a homogeneous transformation matrix. The axis-angle representation
%   consists of a unit vector (the axis of rotation) and an angle (the amount
%   of rotation about that axis).
% 
% Inputs:
%   a (4x1): The vector representing the rotation, where the first three
%            elements represent the axis of rotation and the fourth element
%            represents the angle of rotation.
%
% Outputs:
%   T (4x4): The homogeneous transformation matrix.
%
function T = axang2Htform(a)
    if ~isvector(a) || numel(a) ~= 4
        error('Input vector a must be a 4-element vector.');
    end
    if size(a, 1) == 1 && size(a, 2) == 4
        a = a'; 
    elseif size(a, 1) ~= 4 || size(a, 2) ~= 1
        error('Input vector  must be a 4x1 or 1x4 vector.');
    end
    C = axang2Rotm(a); % Assuming axang2Rotm is a function that converts axis-angle to rotation matrix
    t = zeros(3,1);
    T = [C,t; t',1];
end