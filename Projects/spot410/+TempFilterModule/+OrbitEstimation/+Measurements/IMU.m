function [y, H] = IMU(x,z)
    % Measurement function with Jacobian
    H = [zeros(2,6), eye(2)];
    z_calc = H*x;

    y = z - z_calc;
end