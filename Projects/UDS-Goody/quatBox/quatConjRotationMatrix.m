% Quaternion Conjugation Rotation Matrix
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail_carleton.ca
%
% Description:
%   This function computes a 4×4 matrix that represents the operation of 
%   quaternion conjugation applied to a pure–quaternion v_q, i.e.:
%
%       q * v_q * q^{-1}
%
%   For a unit quaternion q, this is equivalent to rotating the 3D vector embedded 
%   in v_q. The matrix is computed as the product of the left–multiplication matrix
%   of q and the right–multiplication matrix of q^{-1}:
%
%       M = L(q) * R(q^{-1})
%
%   The quaternion can be provided in two representations:
%       'scalarLast'  : q = [v; s] (default)
%       'scalarFirst' : q = [s; v]
%
%   Note: It is assumed that q is a unit quaternion. For non–unit quaternions, 
%         q^{-1} must be computed as the conjugate divided by the squared norm.
%
% Inputs:
%   q (4×1): The quaternion (unit quaternion for rotations).
%   representation (optional, string): 'scalarLast' (default) or 'scalarFirst'.
%
% Outputs:
%   M (4×4): The matrix corresponding to the operation q * v_q * q^{-1}.
%
function M = quatConjRotationMatrix(q, representation)
    % Validate input dimensions
    if ~isvector(q) || numel(q) ~= 4
        error('Input quaternion q must be a 4-element vector.');
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

    % Compute the inverse (for unit quaternions, the inverse is the conjugate)
    % The conjugate depends on the representation.
    switch representation
        case 'scalarLast'
            % q = [v; s]  =>  q_inv = [-v; s]
            v = q(1:3);
            s = q(4);
            q_inv = [-v; s];
        case 'scalarFirst'
            % q = [s; v]  =>  q_inv = [s; -v]
            s = q(1);
            v = q(2:4);
            q_inv = [s; -v];
        otherwise
            error('Unexpected representation.');
    end

    % Compute left–multiplication matrix for q and right–multiplication matrix for q_inv.
    Lq = quatLeftMultMatrix(q, representation);
    Rq_inv = quatRightMultMatrix(q_inv, representation);
    
    % The composite matrix performs the rotation via quaternion conjugation:
    %   q * v_q * q^{-1} = L(q) * R(q^{-1}) * v_q
    M = Lq * Rq_inv;
end
