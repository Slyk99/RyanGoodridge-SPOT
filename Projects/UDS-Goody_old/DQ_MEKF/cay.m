function dq_out = cay(omega, v, representation)
% cay computes the Cayley transform of a twist.
% Given the angular part omega (3×1) and linear part v (3×1), define:
%   u_r = omega,  u_d = v.
% Then the dual quaternion is approximated by:
%   dq = [ cay(u_r),  2*(1 - [0; u_r])^{-1} ⊗ [0; u_d] ⊗ (1 - [0; u_r])^{-1} ]
%
% Here, the Cayley transform for the rotation is:
%   cay(u_r) = (1 + [0; u_r]) ⊗ quatInv(1 - [0; u_r])
%
% Inputs:
%   omega - 3×1 angular vector.
%   v     - 3×1 linear vector.
%   representation - string (e.g., 'scalarFirst')
%
% Output:
%   dq_out - 4×2 dual quaternion.
%
% Note: This implementation assumes small angles.

    % Build pure quaternions for the angular and linear parts.
    % Here [1; 0; 0; 0] is the identity quaternion.
    one = [1; 0; 0; 0];
    % Form q_plus = 1 + [0; omega] and q_minus = 1 - [0; omega]
    q_plus  = one + [0; omega];
    q_minus = one - [0; omega];
    
    % Inverse of q_minus:
    q_minus_inv = quatInv(q_minus, representation);
    
    % Cayley transform for the rotation part:
    q_r = quatMultiply(q_plus, q_minus_inv, representation);
    
    % For the dual part:
    % Create a pure quaternion for the translation: [0; v]
    v_quat = [0; v];
    % Compute: q_d = 2 * (q_minus_inv ⊗ v_quat ⊗ q_minus_inv)
    temp = quatMultiply(q_minus_inv, v_quat, representation);
    q_d = quatMultiply(temp, q_minus_inv, representation);
    q_d = 2 * q_d;
    
    dq_out = [q_r, q_d];
end