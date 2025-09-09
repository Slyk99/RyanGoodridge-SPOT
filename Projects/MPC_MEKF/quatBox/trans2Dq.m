% Translation to Dual Quaterion 
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function creates a 4x2 Dual Quaternion from a 
%   3D translation vector.
% 
% Inputs:
%   t (3x1): The input translation vector.
% 
% Output:
%   dq: A 4 by 2 array representing the Dual Quaternion. 
%      The first 4 elements represent the real part (rotation quaternion), 
%      and the last 4 elements represent the dual part (translation quaternion).
%      The order of scalar and vector components within each quaternion 
%      follows the specified 'representation'.
% 
function dq = trans2Dq(t,representation)

    % Check if the axis is a 4x1 vector
    if size(t,1) ~= 3 && size(t,2) ~= 1 || size(t,2) ~= 3 && size(t,1) ~= 1 
        error('Axis must be a 4x1 vector');
    end

    % Ensure vector is column vector
    if size(t,2) == 3
        t = t';
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

    % Compute quaternion conjugate based on representation
    switch representation
        case 'scalarFirst'
            % Pure Part of the Dual Quaternion
            qr = [1;0;0;0]; % Scalar First
            
            % Dual Part of the Dual Quaternion
            v = t/2;
            qd_scalar = -dot(qr(2:4),v);
            qd_vector = v.*qr(1) - skew(qr(2:4))*v;
            qd = [qd_scalar; qd_vector];

        case 'scalarLast'
            % Pure Part of the Dual Quaternion
            qr = [0;0;0;1]; % Scalar First
            
            % Dual Part of the Dual Quaternion
            v = t/2;
            qd_scalar = -dot(qr(1:3),v);
            qd_vector = v.*qr(4) - skew(qr(1:3))*v;
            qd = [qd_vector; qd_scalar];           

        otherwise
            error('Unexpected representation. This should not occur.');
    end
    
    % Assemble the Dual Quaternion
    dq = [qr,qd];
end