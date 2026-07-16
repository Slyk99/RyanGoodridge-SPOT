% htformInverse
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
% Computes the inverse of a homogeneous transformation matrix.
% Inputs:
% T - 4x4 homogeneous transformation matrix.
%
% Outputs:
% T_inv - 4x4 inverse homogeneous transformation matrix.
function T_inv = htformInverse(T)

    % Extract rotation (C) and translation (t) from T
    C = T(1:3, 1:3); % 3x3 rotation matrix
    t = T(1:3, 4);   % 3x1 translation vector

    % Compute the inverse
    C_inv = C';                % Inverse of a rotation matrix is its transpose
    t_inv = -C_inv * t;        % Transformed translation

    % Assemble the inverse transformation matrix
    T_inv = [C_inv, t_inv; 
             0, 0, 0, 1];      % Add homogeneous row
end
