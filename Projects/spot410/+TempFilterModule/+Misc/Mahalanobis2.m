% Ryan Goodridge
% Copyright (C) 2024
%
% Mahalanobis2: Computes the Mahalanobis distance and performs a rejection test.
%
% Description:
% The function calculates the Mahalanobis distance (d) for a given residual (y) 
% and covariance matrix (Pzz). If the distance exceeds the specified maximum (d_max),
% the observation is "rejected" (reject = true), otherwise it is "accepted" (reject = false).
%
% Inputs:
%   y     - The residual vector
%   Pzz     - The inverse of the covariance matrix (or precision matrix)
%   d_max - The threshold for the Mahalanobis distance
%
% Outputs:
%   reject - Boolean indicating whether the distance exceeds the threshold
%   d      - The Mahalanobis distance (scalar)
%

function [reject, d] = Mahalanobis2(y, Pzz, d_max)
    % Compute the squared Mahalanobis distance d^2 = y' * Pzz * y
    d = y' * Pzz * y;
    d = sqrt(d);
    
    % Compare the computed distance to the threshold d_max
    if d < d_max
        reject = false;
    else
        reject = true;
    end
end