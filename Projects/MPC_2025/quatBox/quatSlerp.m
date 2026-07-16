% quatSlerp - Spherical Linear Interpolation between two quaternions
% Ryan Goodridge
% 1/08/2025 (Updated: 2/06/2025)
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function performs spherical linear interpolation (SLERP) between two 
%   quaternions, providing a smooth interpolation between the rotations 
%   represented by the quaternions.
%
% Inputs:
%   q             - Start quaternion [4x1 vector: w, x, y, z] or [x, y, z, w]
%   p             - End quaternion [4x1 vector: w, x, y, z] or [x, y, z, w]
%   f             - Interpolation factor (0 <= f <= 1)
%   representation - (Optional) 'scalarFirst' or 'scalarLast' (default: 'scalarLast')
% 
% Output:
%   result - Interpolated quaternion [4x1 vector: w, x, y, z] or [x, y, z, w]
%
function result = quatSlerp(q, p, f, representation)

    %% Input Validation
    if nargin < 3
        error('At least three inputs (q, p, f) are required.');
    end
    if nargin < 4 || isempty(representation)
        representation = 'scalarLast'; % Default representation
    end
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end

    %% Convert to Scalar-First if Necessary
    if strcmp(representation, 'scalarLast')
        q = [q(4); q(1:3)]; % Convert to [w, x, y, z]
        p = [p(4); p(1:3)];
    end

    %% Normalize input quaternions to ensure valid rotation
    q = q / norm(q);
    p = p / norm(p);

    %% Compute the dot product (cosine of the angle between q and p)
    dot_product = dot(q, p);

    % Handle the case where quaternions are in opposite hemispheres
    if dot_product < 0
        % Negate one quaternion to take the shorter path
        p = -p;
        dot_product = -dot_product;
    end

    % Clamp dot_product to avoid numerical issues with acos
    dot_product = max(min(dot_product, 1), -1);

    % Compute the angle (theta) between the quaternions
    theta = acos(dot_product);

    % If the angle is very small, use linear interpolation to avoid division by 0
    if abs(theta) < 1e-6
        result = (1 - f) * q + f * p;
    else
        % Spherical linear interpolation formula
        sin_theta = sin(theta);
        result = (sin((1 - f) * theta) / sin_theta) * q + (sin(f * theta) / sin_theta) * p;
    end

    %% Normalize the result to ensure it's a valid quaternion
    result = result / norm(result);

    %% Convert Back to Scalar-Last if Needed
    if strcmp(representation, 'scalarLast')
        result = [result(2:4); result(1)];
    end

end
