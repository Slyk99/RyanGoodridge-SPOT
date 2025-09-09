% Quaternion Rotate
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   Rotates a 3D vector using a quaternion.
%
% Inputs:
%   q (4x1): The rotation quaternion, represented as a column vector.
%   v (3x1): The vector to be rotated, represented as a column vector.
%   representation (optional, string): The representation of the quaternion, 
%                                     'scalarFirst' or 'scalarLast'. 
%                                     Defaults to 'scalarLast'.
%
% Outputs:
%   v_rotated (3x1): The rotated vector, represented as a column vector.
%
function v_rotated = quatRotate(q,v,representation) 
    % Validate input dimensions
    if ~isvector(q) || numel(q) ~= 4
        error('Input quaternion q must be a 4-element vector.');
    end

    % Set default representation if not provided
    if nargin < 3 || isempty(representation)
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
            % Step 1: Convert v to a quaternion-like form
            v_quat = [0; v];
            
            % Step 2: Compute the inverse of quaternion q
            q_inv = quatInv(q','scalarFirst');
            
            % Step 3: Rotate the vector using the quaternion
            v_rotated_quat = quatMultiply(quatMultiply(q, v_quat,'scalarFirst'), q_inv,'scalarFirst');
            
            % Step 4: Extract the rotated vector (ignore the scalar part)
            v_rotated = v_rotated_quat(2:4);

        case 'scalarLast'
            % Step 1: Convert v to a quaternion-like form
            v_quat = [v; 0;];
            
            % Step 2: Compute the inverse of quaternion q
            q_inv = quatInv(q,'scalarLast');
            
            % Step 3: Rotate the vector using the quaternion
            v_rotated_quat = quatMultiply(quatMultiply(q, v_quat,'scalarLast'), q_inv,'scalarLast');
            
            % Step 4: Extract the rotated vector (ignore the scalar part)
            v_rotated = v_rotated_quat(1:3);


        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
