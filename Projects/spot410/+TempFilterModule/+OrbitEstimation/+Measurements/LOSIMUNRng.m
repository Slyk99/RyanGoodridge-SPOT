function [y, H] = LOSIMUNRng(x,z)
    % Measurement function with Jacobian
    
    % Extract position components
    px = x(1);
    py = x(2);
    
    % Compute range
    p = sqrt(px^2 + py^2);
    
    % Unit vector
    if p == 0
        s = [0;0];
    else
        s = x(1:2) / p;
    end
    
    % Measurement vector
    z_calc = [s;
              p;
              x(3);
              x(7);
              x(8)];
    
    % Common terms
    p2 = p^2;
    p3 = p2*p;
    
    % Initialize Jacobian
    H = zeros(6, 8);
    
    if p ~= 0
    % s_x derivatives
    H(1,1) = (p2 - px^2) / p3;
    H(1,2) = -px*py / p3;
    
    % s_y derivatives
    H(2,1) = -px*py / p3;
    H(2,2) = (p2 - py^2) / p3;
    
    % p derivatives
    H(3,1) = px / p;
    H(3,2) = py / p;
    end
    
    % theta derivative
    H(4,3) = 1;

    % w_s row
    H(5:6,7:8) = eye(2);

    y = z - z_calc;
    y(4,1) = TempFilterModule.Misc.angErr(z(4,1),z_calc(4,1));

end