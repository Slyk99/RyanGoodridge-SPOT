% rotm2Axang - Convert Rotation Matrix to Axis-Angle Representation
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a 3x3 rotation matrix to its axis-angle 
%   representation. The axis-angle representation is a 4x1 vector where 
%   the first three elements represent the rotation axis and the fourth 
%   element represents the rotation angle in radians.
% 
% Inputs:
%   R (3x3): The input rotation matrix.
% 
% Output:
%   a (4x1): The axis-angle representation vector.
%              a(1:3) - The rotation axis vector.
%              a(4)    - The rotation angle in radians.
% 
function a = rotm2Axang(R)
    % Check if R is a valid 3x3 rotation matrix
    if size(R,1) ~= 3 || size(R,2) ~= 3 || abs(det(R) - 1) > 1e-6 || norm(R * R' - eye(3)) > 1e-6
        error('Input must be a valid 3x3 rotation matrix');
    end
    
    % Compute the angle
    angle = acos((trace(R) - 1) / 2);
    
    % Compute the axis
    if angle > 1e-6
        % Non-zero angle case
        axis = [R(3,2) - R(2,3);
                R(1,3) - R(3,1);
                R(2,1) - R(1,2)] / (2 * sin(angle));
    else
        % Zero angle case (identity matrix, arbitrary axis)
        axis = [1; 0; 0];
    end

    a = [axis; angle];
end
