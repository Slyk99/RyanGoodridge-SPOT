% Quaternion to Euler Angles (3-2-1 Rotation Sequence)
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function computes the Euler angles (yaw, pitch, and roll) from a 
%   quaternion representation of orientation. The function assumes a 
%   3-2-1 rotation sequence, which involves the following steps:
%       1. A principal rotation of yaw (\u03c8) about the z-axis.
%       2. A principal rotation of pitch (\u03b8) about the intermediate y'-axis.
%       3. A principal rotation of roll (\u03c6) about the final x''-axis.
% 
% Inputs:
%   q              - A 4x1 quaternion represented as a column vector.
%   representation - (Optional) A string specifying the representation
%                    ('scalarFirst' or 'scalarLast'). Default is 'scalarLast'.
% 
% Outputs:
%   roll  (\u03c6) - Rotation angle about the x''-axis in radians.
%   pitch (\u03b8) - Rotation angle about the y'-axis in radians.
%   yaw   (\u03c8) - Rotation angle about the z-axis in radians.
% 
% Notes:
%   - Ensure the quaternion is normalized before using this function.
%   - The output Euler angles follow the 3-2-1 (yaw-pitch-roll) sequence.
%
function [roll, pitch, yaw] = quat2Euler(q, representation)
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

    % Normalize the quaternion to avoid scaling issues
    q = q / norm(q);

    % Extract quaternion components based on the representation
    switch representation
        case 'scalarFirst'
            w = q(1); x = q(2); y = q(3); z = q(4);
        case 'scalarLast'
            w = q(4); x = q(1); y = q(2); z = q(3);
        otherwise
            error('Unexpected representation. This should not occur.');
    end

    % Compute the elements of the rotation matrix from the quaternion
    C = [
        1 - 2*(y^2 + z^2),     2*(x*y - z*w),         2*(x*z + y*w);
        2*(x*y + z*w),         1 - 2*(x^2 + z^2),     2*(y*z - x*w);
        2*(x*z - y*w),         2*(y*z + x*w),         1 - 2*(x^2 + y^2)
    ];

    % Compute yaw (\u03c8), pitch (\u03b8), and roll (\u03c6) from the rotation matrix
    yaw = atan2(C(2,1), C(1,1));         % Rotation about the z-axis
    pitch = asin(-C(3,1));               % Rotation about the intermediate y'-axis
    roll = atan2(C(3,2), C(3,3));        % Rotation about the final x''-axis
end

