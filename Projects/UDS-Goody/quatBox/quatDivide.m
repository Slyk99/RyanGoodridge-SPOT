% Quaternion Division
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes the division of two quaternions using the
%   method of multiplicative inverses. Quaternion division is not
%   commutative (i.e. the order matters). This function performs division
%   in the order r = q / p.
% 
% Inputs:
%   q (4x1): The dividend quaternion represented as a column vector.
%   p (4x1): The divisor quaternion represented as a column vector.
%   representation (optional, string): The input format of the quaternions.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Outputs:
%   r (4x1): The result of the quaternion division.
%
function r = quatDivide(q,p,representation) 
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

    % Compute quaternion conjugate based on representation
    switch representation
        case 'scalarFirst'
            q0 = q(1); q1 = q(2); q2 = q(3); q3 = q(4); % Quaterion 1
            p0 = p(1); p1 = p(2); p2 = p(3); p3 = p(4); % Quaterion 2
            den = (sum(p.^2));

            r = [0;0;0;0];
            r(1) = (q0*p0 + q1*p1 + q2*p2 + q3*p3)/den;
            r(2) = (p0*q1 - p1*q0 - p2*q3 + p3*q2)/den;
            r(3) = (p0*q2 + p1*q3 - p2*q0 - p3*q1)/den;
            r(4) = (p0*q3 - p1*q2 + p2*q1 - p3*q0)/den;

        case 'scalarLast'
            q0 = q(4); q1 = q(2); q2 = q(3); q3 = q(1); % Quaterion 1
            p0 = p(4); p1 = p(2); p2 = p(3); p3 = p(1); % Quaterion 2
            den = (sum(p.^2));

            r = [0;0;0;0];
            r(1) = (q0*p0 + q1*p1 + q2*p2 + q3*p3)/den;
            r(2) = (p0*q1 - p1*q0 - p2*q3 + p3*q2)/den;
            r(3) = (p0*q2 + p1*q3 - p2*q0 - p3*q1)/den;
            r(4) = (p0*q3 - p1*q2 + p2*q1 - p3*q0)/den;


        otherwise
            error('Unexpected representation. This should not occur.');
    end
end