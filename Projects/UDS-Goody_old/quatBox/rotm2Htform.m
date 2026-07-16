% rotm2Htform - Convert Rotation Matrix to Homogeneous Transformation Matrix
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a 3x3 rotation matrix to a 4x4 homogeneous 
%   transformation matrix. A homogeneous transformation matrix combines both 
%   rotation and translation information into a single matrix for efficient 
%   geometric transformations.
% 
% Inputs:
%   C (3x3): The input rotation matrix.
% 
% Output:
%   T (4x4): The homogeneous transformation matrix.
%              T(1:3,1:3) - The rotation matrix.
%              T(1:3,4)   - The translation vector (zeros by default).
%              T(4,4)     - The scaling factor (always 1).
%
function T = rotm2Htform(C)
    % Check if R is a valid 3x3 rotation matrix
    if size(C,1) ~= 3 || size(C,2) ~= 3 || abs(det(C) - 1) > 1e-6 || norm(C * C' - eye(3)) > 1e-6
        error('Input must be a valid 3x3 rotation matrix');
    end
    
    t = zeros(3,1);
    T = [C, t; t', 1];
    
end