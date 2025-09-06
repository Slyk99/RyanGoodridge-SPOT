% Quaternion Magnitude (Norm)
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail_carleton.ca
% 
% Description:
%   This function computes the magnitude (norm) of a quaternion.
%   The quaternion norm represents the length of the quaternion
%   when visualized as a vector in 4D space.
% 
% Inputs:
%   q (4x1): The quaternion for which to compute the norm, represented as a column vector.
% 
% Outputs:
%   q_mag (scalar): The magnitude (norm) of the quaternion.
%
function q_mag = quatNorm(q)

    % Validate input dimensions
    if ~isvector(q) || length(q) ~= 4
        error('Input quaternion q must be a 4x1 vector.');
    end

    q_mag_sq = sum(q.^2);
    q_mag = sqrt(q_mag_sq);
end
