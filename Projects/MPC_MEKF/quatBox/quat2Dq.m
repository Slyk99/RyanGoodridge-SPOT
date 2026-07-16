% Quaternion to Dual Quaternion
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
% This function converts a 4-element quaternion representing a pure rotation 
% into an 8-element dual quaternion, where the dual part is zero. 
% A dual quaternion can represent both rotation and translation.
% 
% Inputs:
%   q (4x1): The quaternion representing the rotation.
%
% Output:
%   dq: A 4 by 2 array representing the Dual Quaternion. 
%      The first 4 elements represent the real part (rotation quaternion), 
%      and the last 4 elements represent the dual part (translation quaternion).
%      The order of scalar and vector components within each quaternion 
%      follows the specified 'representation'.
% 
function dq = quat2Dq(q)
    % Dual Part of the Dual Quaternion
    qd = 0*q;
    
    % Assemble the Dual Quaternion
    dq = [q,qd];
end