function [y, H] = IMUNRng(x,z)
    % Measurement function with Jacobian
    
    % Extract position components
    px = x(1);
    py = x(2);
    
    % Compute range
    p = sqrt(px^2 + py^2);
    
    % Measurement vector
    z_calc = [p; x(7); x(8)]; 
    
    % Initialize Jacobian
    H = zeros(3, 8);

    % p row
    H(1,1) = px / p;
    H(1,2) = py / p;

    % w_s row
    H(2:3,7:8) = eye(2);

    y = z - z_calc;
end