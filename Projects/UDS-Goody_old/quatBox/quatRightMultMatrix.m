% Quaternion Right–Multiplication Matrix
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail_carleton.ca
%
% Description:
%   Given a quaternion q, this function computes the 4×4 right–multiplication 
%   matrix R(q) such that for any quaternion q1 (4×1 vector) the product:
%
%       q1 * q = R(q) * q1.
%
%   The quaternion can be provided in two representations:
%       'scalarLast'  : q = [v; s] (default)
%       'scalarFirst' : q = [s; v]
%
% Inputs:
%   q (4×1): The quaternion.
%   representation (optional, string): 'scalarLast' (default) or 'scalarFirst'.
%
% Outputs:
%   R (4×4): The right–multiplication matrix for quaternion q.
%
function R = quatRightMultMatrix(q, representation)
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

    % Assign scalar and vector parts based on representation
    switch representation
        case 'scalarLast'
            v = q(1:3);
            s = q(4);
        case 'scalarFirst'
            s = q(1);
            v = q(2:4);
        otherwise
            error('Unexpected representation.');
    end

    % Compute skew-symmetric matrix of vector v
    skew_v = [   0   -v(3)  v(2);
               v(3)    0    -v(1);
              -v(2)  v(1)    0  ];
    
    % Assemble the 4x4 right–multiplication matrix:
    %   R(q) = [ s*I_3 - skew(v),   v;
    %            -v'          ,    s ]
    R = [ s*eye(3) - skew_v,   v;
         -v',                 s ];
end
