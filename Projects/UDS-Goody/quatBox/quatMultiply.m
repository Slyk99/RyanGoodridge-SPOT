% Quaternion Multiplication
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   This function performs quaternion multiplication for two quaternions.
%
% Inputs:
%   q (4x1 or 1x4): First quaternion.
%   p (4x1 or 1x4): Second quaternion.
%   representation (string, optional): 'scalarFirst' or 'scalarLast' (default: 'scalarLast').
%
% Outputs:
%   r (4x1 or 1x4): Resulting quaternion.
%
function r = quatMultiply(q, p, representation)
    if nargin < 3
        representation = 'scalarLast'; % Default representation
    end
    
    % Ensure input quaternions are column vectors
    q = q(:);
    p = p(:);
    
    if strcmp(representation, 'scalarFirst')
        % For scalar-first: q = [scalar; vector]
        scalar = q(1);
        vector = [q(2); q(3); q(4)];
        q_tilda = [scalar, -vector'; vector, scalar*eye(3) + skew(vector)];

        r = q_tilda*p;
    else
        % For scalar-second: q = [vector; scalar]
        scalar = q(4);
        vector = [q(1); q(2); q(3)];
        q_tilda = [scalar, -vector'; vector, scalar*eye(3) + skew(vector)];

        r = q_tilda*p;
    end
    
end

