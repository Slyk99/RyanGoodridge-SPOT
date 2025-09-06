% skew - Create a Skew-Symmetric Matrix from a 3D Vector
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function creates a 3x3 skew-symmetric matrix from a 3D input vector. 
%   Skew-symmetric matrices are useful in representing cross products 
%   and manipulating rotations.
% 
% Inputs:
%   v (3x1): The input 3D vector.
% 
% Outputs:
%   S (3x3): The 3x3 skew-symmetric matrix.
% 
function S = skew(v)
    % Check if the input is a 3-element vector
    if length(v) ~= 3
        error('Input must be a 3-element vector.');
    end
    
    % Define the skew-symmetric matrix
    S = [  0   -v(3)  v(2);
          v(3)   0   -v(1);
         -v(2)  v(1)   0  ];
end