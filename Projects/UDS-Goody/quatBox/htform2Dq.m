% Homogeneous Transformation to Dual Quaternion
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
% 
% Homogeneous Transformation to Dual Quaternion
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
% This function converts a 4x4 Homogeneous Transformation matrix (HTM) 
% representing a rigid body transformation (rotation and translation) 
% into a Dual Quaternion.
% 
% Inputs:
%   T: 4x4 Homogeneous Transformation matrix. 
%      Must be a valid HTM with a rotation matrix in the top-left 3x3 block.
%   representation (optional, string): The representation of the quaternion 
%                                     ('scalarFirst' or 'scalarLast'). 
%                                     Defaults to 'scalarLast'.
% 
% Outputs:
%   dq: A 4 by 2 array representing the Dual Quaternion. 
%      The first 4 elements represent the real part (rotation quaternion), 
%      and the last 4 elements represent the dual part (translation quaternion).
%      The order of scalar and vector components within each quaternion 
%      follows the specified 'representation'.
% 
function dq = htform2Dq(T,representation)
    C = T(1:3,1:3);
    % Check if R is a valid 3x3 rotation matrix
    if size(T,1) ~= 4 || size(T,2) ~= 4 || abs(det(C) - 1) > 1e-6 || norm(C * C' - eye(3)) > 1e-6
        error('Input must be a valid 4x4 Homogeneous Transformation matrix');
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

    % Pure Part of the Dual Quaternion
    qr = rotm2Quat(T(1:3,1:3),representation);
    
    % Dual Part of the Dual Quaternion
    v = T(1:3,4)/2;
    qd_scalar = -dot(qr(2:4),v);
    qd_vector = v.*qr(1) - skew(qr(2:4))*v;

    switch representation
        case 'scalarFirst'
            qd = [qd_scalar; qd_vector];
    
        case 'scalarLast'
            qd = [qd_vector; qd_scalar];

            otherwise
            error('Unexpected representation. This should not occur.');
    end

    % Assemble the Dual Quaternion
    dq = [qr,qd];
end