% Quaternion Exponential
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes the quaternion exponential, which is useful for
%   integrating a time-varying angular velocity to obtain a quaternion
%   representing orientation.
% 
% Inputs:
%   q (4x1): The quaternion to exponentiate, represented as a column vector.
%   representation (optional, string): The input format of the quaternion.
%            Valid options are 'scalarFirst' (default) or 'scalarLast'.
% 
% Outputs:
%   qe (4x1): The quaternion exponential.
%
function qe = quatExp(q,representation) 
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

    switch representation
        case 'scalarFirst'
            scalar = q(1);
            vector = [q(2); q(3); q(4)];

            norm_vector = norm(vector);  % Magnitude of the vector part
            % Compute the quaternion exponential
            if norm_vector == 0
                % Special case: zero vector part
                qe = [exp(scalar); 0; 0; 0];
            else
                % General case
                qe = exp(scalar) * [cos(norm_vector);
                                    (vector / norm_vector) * sin(norm_vector)];
            end

        case 'scalarLast'
            scalar = q(4);
            vector = [q(1); q(2); q(3)];

            norm_vector = norm(vector);  % Magnitude of the vector part
            % Compute the quaternion exponential
            if norm_vector == 0
                % Special case: zero vector part
                qe = [exp(scalar); 0; 0; 0];
            else
                % General case
                qe = exp(scalar) * [(vector / norm_vector) * sin(norm_vector);
                                    cos(norm_vector);];
            end

        otherwise
            error('Unexpected representation. This should not occur.');
    end

end
