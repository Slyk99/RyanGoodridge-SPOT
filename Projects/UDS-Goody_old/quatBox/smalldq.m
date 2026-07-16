% SMALLDUALQUAT: Find the minimal (shortest rotation) dual quaternion.
% Ryan Goodridge
% 02/16/2025
% ryangoodridge@cmail.carleton.ca
%
%   dq_small = smallDualQuat(dq, representation)
%
% Description:
%   Given a dual quaternion representing a rigid transformation,
%   this function returns an equivalent dual quaternion where the
%   rotation part has been “smallified” (i.e. reparameterized to the
%   shortest rotation) using smallQuat. The dual part is updated so that
%   the transformation (rotation and translation) is preserved.
%
% Inputs:
%   dq              - (8x1 or 1x8 vector) Dual quaternion [q_r; q_d],
%                     where q_r is the rotation (real) part and q_d is the
%                     dual part.
%   representation  - (optional string) Either 'scalarFirst' or 'scalarLast'
%                     (default: 'scalarLast') indicating the quaternion
%                     ordering.
%
% Output:
%   dq_small        - Dual quaternion with minimal rotation representation.
%

function dq_small = smalldq(dq, representation)
    if nargin < 1
        error('At least one input (dq) is required.');
    end
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end

    [q_rot, t] = dq2quat(dq, representation);
    q_rot = smallQuat(q_rot,representation);

    % Construct the dual part of the dual quaternion
    q_t = 0.5 * [0; t']; % Extend translation vector to a 4x1 pure quaternion
    q_dual = quatMultiply(q_t, q_rot,'scalarFirst'); % Compute dual part

    dq_small = [q_rot, q_dual];

end
