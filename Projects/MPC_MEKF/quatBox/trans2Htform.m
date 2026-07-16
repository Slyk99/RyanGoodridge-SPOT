% trans2Htform - Convert Translation Vector to Homogeneous Transformation Matrix
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function creates a 4x4 homogeneous transformation matrix from a 
%   3D translation vector. Homogeneous transformation matrices combine 
%   translation information with a rotation (which defaults to identity 
%   in this case) into a single matrix for efficient geometric transformations.
% 
% Inputs:
%   t (3x1): The input translation vector.
% 
% Output:
%   T (4x4): The homogeneous transformation matrix.
%              T(1:3,1:3) - The rotation matrix (identity in this case).
%              T(1:3,4)   - The translation vector.
%              T(4,4)     - The scaling factor (always 1).
% 
function T = trans2Htform(t)
    T = [eye(3), t; zeros(1,3), 1];
    
end