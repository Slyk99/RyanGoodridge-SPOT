function [reject, d] = Mahalanobis2(y, S, d_max)
    % Compute the squared Mahalanobis distance d^2 = y' * S * y
    d = y(1:3)' * S(1:3,1:3) * y(1:3);
    
    % Take the square root to get the actual Mahalanobis distance d
    d = sqrt(d);
    
    % Compare the computed distance to the threshold d_max
    if d < d_max
        % If d is less than the threshold, the observation is not rejected
        reject = false;
    else
        % If d is greater than or equal to the threshold, the observation is rejected
        reject = true;
    end
end