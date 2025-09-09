% rotm2Quat - Convert Rotation Matrix to Quaternion
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a 3x3 rotation matrix to its equivalent 
%   unit quaternion representation. A quaternion is a 4D number 
%   commonly used to represent rotations in 3D space.
% 
% Inputs:
%   C (3x3): The input rotation matrix.
% 
% Outputs:
%   q (4x1): The quaternion representation, represented as a column vector.
%              q(1) - The scalar part (w).
%              q(2:4) - The vector part (x, y, z).
%   representation (optional, string): The representation of the quaternion 
%                                     ('scalarFirst' or 'scalarLast'). 
%                                     Defaults to 'scalarLast'.
% 
function q = rotm2Quat(C,representation) 
    % Check if R is a valid 3x3 rotation matrix
    if size(C,1) ~= 3 || size(C,2) ~= 3 || abs(det(C) - 1) > 1e-6 || norm(C * C' - eye(3)) > 1e-6
        error('Input must be a valid 3x3 rotation matrix');
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

    % Preallocate quaternion
    q = zeros(4,1);
    
    % Compute the trace of the matrix
    trace_R = trace(C);
    
    if trace_R > 0
        % Case 1: Trace is positive
        S = sqrt(trace_R + 1.0) * 2; % S = 4 * qw
        qw = 0.25 * S;
        qx = (C(3,2) - C(2,3)) / S;
        qy = (C(1,3) - C(3,1)) / S;
        qz = (C(2,1) - C(1,2)) / S;
    elseif (C(1,1) > C(2,2)) && (C(1,1) > C(3,3))
        % Case 2: R(1,1) is the largest diagonal element
        S = sqrt(1.0 + C(1,1) - C(2,2) - C(3,3)) * 2; % S = 4 * qx
        qw = (C(3,2) - C(2,3)) / S;
        qx = 0.25 * S;
        qy = (C(1,2) + C(2,1)) / S;
        qz = (C(1,3) + C(3,1)) / S;
    elseif C(2,2) > C(3,3)
        % Case 3: R(2,2) is the largest diagonal element
        S = sqrt(1.0 + C(2,2) - C(1,1) - C(3,3)) * 2; % S = 4 * qy
        qw = (C(1,3) - C(3,1)) / S;
        qx = (C(1,2) + C(2,1)) / S;
        qy = 0.25 * S;
        qz = (C(2,3) + C(3,2)) / S;
    else
        % Case 4: R(3,3) is the largest diagonal element
        S = sqrt(1.0 + C(3,3) - C(1,1) - C(2,2)) * 2; % S = 4 * qz
        qw = (C(2,1) - C(1,2)) / S;
        qx = (C(1,3) + C(3,1)) / S;
        qy = (C(2,3) + C(3,2)) / S;
        qz = 0.25 * S;
    end

    % Compute quaternion conjugate based on representation
    switch representation
        case 'scalarFirst'
            % Assign values to the quaternion
            q(1) = qw; % w
            q(2) = qx; % x
            q(3) = qy; % y
            q(4) = qz; % z

        case 'scalarLast'
            % Assign values to the quaternion
            q(4) = qw; % w
            q(2) = qx; % x
            q(3) = qy; % y
            q(1) = qz; % z            

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
