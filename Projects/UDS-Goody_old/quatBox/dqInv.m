% Dual Quaternion Inverse
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Computes the inverse of a dual quaternion. A dual quaternion is represented as
%       dq = [q_r, q_d]
%   where q_r is the real (rotation) quaternion and q_d is the dual (translation) quaternion.
%
%   For dq = q_r + ε*q_d, the inverse is given by:
%       dq_inv = q_r_inv - ε*(q_r_inv * q_d * q_r_inv)
%
%   The inverse of q_r is computed as:
%       q_r_inv = quatConj(q_r) / (norm(q_r)^2)
%
%   Inputs:
%       dq             - A 4x2 dual quaternion matrix.
%       representation - (Optional) A string specifying the quaternion representation.
%                        Options: 'scalarLast' (default) or 'scalarFirst'.
%
%   Output:
%       dq_inv         - The inverse dual quaternion as a 4x2 matrix.
%
function dq_inv = dqInv(dq, representation)
    %% Input Validation
    if nargin < 1
        error('At least one input (dq) is required.');
    end
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst','scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end

    %% Extract the real and dual parts of the dual quaternion
    q_r = dq(:,1);
    q_d = dq(:,2);
    
    %% Compute the inverse of the rotation quaternion q_r.
    % q_r_inv = quatConj(q_r) / (norm(q_r)^2)
    switch representation
        case 'scalarLast'
            % q_r = [v; s]
            v_r = q_r(1:3);
            s_r = q_r(4);
            n2 = sum(q_r.^2);
            % Conjugate: flip sign of the vector part
            q_r_inv = [ -v_r; s_r ] / n2;
        case 'scalarFirst'
            % q_r = [s; v]
            s_r = q_r(1);
            v_r = q_r(2:4);
            n2 = sum(q_r.^2);
            % Conjugate: flip sign of the vector part
            q_r_inv = [ s_r; -v_r ] / n2;
        otherwise
            error('Unexpected representation.');
    end
    
    %% Compute the dual part of the inverse.
    % According to:
    %   dq_inv = q_r_inv - ε*(q_r_inv * q_d * q_r_inv)
    % We compute the product q_r_inv * q_d * q_r_inv using our quaternion multiplication
    % function (which must be available and follow the same representation convention).
    temp = quatMultiply(q_r_inv, q_d, representation);
    temp2 = quatMultiply(temp, q_r_inv, representation);
    q_d_inv = -temp2;
    
    %% Assemble the inverse dual quaternion.
    dq_inv = [q_r_inv, q_d_inv];
end
