% Dual Quaternion Rotate
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   Rotates and translates a 3D vector using a dual quaternion.
%
% Inputs:
%   q (4x2): The transformation unit dual quaternion, represented as a 4 by 2 array.
%   v (3x1): The vector to be rotated, represented as a column vector.
%   representation (optional, string): The representation of the quaternion, 
%                                     'scalarFirst' or 'scalarLast'. 
%                                     Defaults to 'scalarLast'.
%
% Outputs:
%   v_rotated (3x1): The rotated vector, represented as a column vector.
%
function v_rotated = dqRotate(dq,v,representation) 

    % Validate input dimensions
    if ~ismatrix(dq) || size(dq, 1) ~= 4 || size(dq, 2) ~= 2
        error('Each dual quaternion must be a 4x2 matrix.');
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

    qr = dq(:,1);
    qd = dq(:,2);

    switch representation
        case 'scalarFirst'
            qrvqr = quatRotate(qr,v,'scalarFirst');
            qdqr = quatMultiply(qd, quatConj(qr,'scalarFirst'),'scalarFirst');
            % qrqd = quatMultiply(qr',-1*quatconj(qd'))';
        
            temp = 2*qdqr + [0; qrvqr]; % + qrqd;
            v_rotated = temp(2:4,1);
            % Note: qrqd == qdqr by definition 

        case 'scalarLast'
            qrvqr = quatRotate(qr,v,'scalarLast');
            qdqr = quatMultiply(qd, quatConj(qr,'scalarLast'),'scalarLast');
            % qrqd = quatMultiply(qr',-1*quatconj(qd'))';
        
            temp = 2*qdqr + [qrvqr; 0]; % + qrqd;
            v_rotated = temp(1:3,1);
            % Note: qrqd == qdqr by definition 

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end
