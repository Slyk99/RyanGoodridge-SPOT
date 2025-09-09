% Quaternion Left–Multiplication Matrix
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail_carleton.ca
%
% Description:
%   Given a quaternion q, this function computes the 4×4 left–multiplication 
%   matrix L(q) such that for any quaternion q2 (4×1 vector) the product:
%
%       q * q2 = L(q) * q2.
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
%   L (4×4): The left–multiplication matrix for quaternion q.
%
function L = quatLeftMultMatrix(q, representation)
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
            v = v(:);
            s = q(4);
        case 'scalarFirst'
            s = q(1);
            v = q(2:4);
            v = v(:);
        otherwise
            error('Unexpected representation.'); %#ok<ERTAG>
    end

    % Compute skew-symmetric matrix of vector v
    skew_v = [   0   -v(3)  v(2);
               v(3)    0    -v(1);
              -v(2)  v(1)    0  ];
    
    % Assemble the 4x4 left–multiplication matrix:
    % For both representations the structure is analogous:
    %   L(q) = [ s*I_3 + skew(v),   v;
    %           -v'           ,    s ]
    L = [ s*eye(3) + skew_v,   v;
         -v',                  s ];
end
