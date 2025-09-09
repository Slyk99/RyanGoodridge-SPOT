% Sortest Rotation Quaternion
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   This function finds the shorter rotation of a quaternion.
%
% Inputs:
%   q (4x1 or 1x4): Quaternion.
%   representation (string, optional): 'scalarFirst' or 'scalarLast' (default: 'scalarLast').
%
% Outputs:
%   p (4x1 or 1x4): Resulting quaternion.
%
function p = smallQuat(q, representation)
    if nargin < 2
        representation = 'scalarLast'; % Default representation
    end
    
    % Ensure input quaternion is column vector
    q = q(:);
    
    % Calculate the axsis angle representation
    q = normalizeQuat(q,representation);
    a = quat2Axang(q,representation);
    if anynan(a)
        p = [1;0;0;0];
        return
    end
    a(4) = wrapToPi(a(4));
    
    % Assemble the quaternion again
    p = axang2Quat(a,representation);
    
end