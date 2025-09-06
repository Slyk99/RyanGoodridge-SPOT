% Quaternion Logarithm
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes the quaternion logarithm, which is useful for
%   converting a rotation to an equivalent axis-angle representation.
% 
% Inputs:
%   q (4x1): The quaternion to compute the logarithm of, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Outputs:
%   qlog (4x1): The quaternion logarithm.
%
function qlog = quatLog(q,representation) 
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
            % Extract scalar and vector parts
            scalar = q(1);              % Scalar part (w)
            vector = [q(2); q(3); q(4)];% Vector part (v)
            norm_q = norm(q);           % Magnitude of the quaternion
            norm_vector = norm(vector); % Magnitude of the vector part
            
            % Check for zero quaternion
            if norm_q == 0
                error('Logarithm of a zero quaternion is undefined.');
            end
            
            % Compute the logarithm
            if norm_vector == 0
                % Special case: Pure scalar quaternion
                qlog = [log(norm_q); 0; 0; 0];
            else
                % General case
                angle = acos(scalar / norm_q);
                qlog = [log(norm_q);
                        (vector / norm_vector) * angle];
            end

        case 'scalarLast'
            % Extract scalar and vector parts
            scalar = q(4);               % Scalar part (w)
            vector = [q(1); q(2); q(3)]; % Vector part (v)
            norm_q = norm(q);            % Magnitude of the quaternion
            norm_vector = norm(vector);  % Magnitude of the vector part
            
            % Check for zero quaternion
            if norm_q == 0
                error('Logarithm of a zero quaternion is undefined.');
            end
            
            % Compute the logarithm
            if norm_vector == 0
                % Special case: Pure scalar quaternion
                qlog = [log(norm_q); 0; 0; 0];
            else
                % General case
                angle = acos(scalar / norm_q);
                qlog = [(vector / norm_vector) * angle;
                        log(norm_q)];
            end

        otherwise
            error('Unexpected representation. This should not occur.');
    end
end