% Quaternion Power
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes the quaternion raised to a power.
% 
% Inputs:
%   q (4x1): The quaternion to exponentiate, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
%   pow (scalar): The power to which to raise the quaternion.
% 
% Outputs:
%   qpow (4x1): The quaternion power (q ^ pow).
%
% Notes:
% - Quaternion power is generally defined for real number powers as well.
%
function qpow = quatPower(q,pow, representation)
    % Validate input dimensions
    if ~isvector(q) || numel(q) ~= 4
        error('Input quaternion q must be a 4-element vector.');
    end
    
    % Reshape to 4x1 if it is 1x4
    if size(q, 1) == 1 && size(q, 2) == 4
        q = q'; % Transpose to make it 4x1
    elseif size(q, 1) ~= 4 || size(q, 2) ~= 1
        error('Input quaternion q must be a 4x1 or 1x4 vector.');
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
            q_log = pow*quatLog(q,'scalarFirst');
            qpow = quatExp(q_log,'scalarFirst');
            
        case 'scalarLast'
            q_log = pow*quatLog(q,'scalarLast');
            qpow = quatExp(q_log,'scalarLast');

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end