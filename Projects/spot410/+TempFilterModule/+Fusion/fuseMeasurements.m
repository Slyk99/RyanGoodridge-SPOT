% fuseMeasurements  Optimal fusion of n zero-mean sensor measurements
%
% Inputs:
%   z_all : m x n matrix, measurement vectors from each sensor
%   R_all : m x m x n array, covariance matrices for each sensor
%
% Outputs:
%   z_f   : m x 1 fused measurement vector
%   R_f   : m x m fused covariance matrix
%
function [z_f, R_f] = fuseMeasurements(z_all, R_all)
[m, n] = size(z_all);

% Initialize fused information form
R_f_inv = zeros(m, m);
sum_term = zeros(m, 1);

for i = 1:n
    R_inv = inv(R_all(:,:,i));
    R_f_inv = R_f_inv + R_inv;
    sum_term = sum_term + R_inv * z_all(:,i);
end

% Convert back to covariance form
R_f = inv(R_f_inv);
z_f = R_f * sum_term;

end
