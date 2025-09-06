function [y, H] = Rng(x,z)
    % Measurement function with Jacobian
    
    % Extract position components
    px = x(1);
    py = x(2);
    
    % Compute range
    p = sqrt(px^2 + py^2);
    
    % Measurement vector
    z_calc = p; 
    
    % Initialize Jacobian
    H = zeros(1, 8);

    % p row
    H(1,1) = px / p;
    H(1,2) = py / p;

    y = z - z_calc;
end