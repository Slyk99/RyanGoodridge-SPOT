function [y, H] = PS(x,z)
    % Measurement function with Jacobian
    H = [eye(3), zeros(3,5);
         zeros(1,6), 1, 0];
    z_calc = H*x;

    y = z - z_calc;
    y(3,1) = TempFilterModule.Misc.angErr(z(3,1),z_calc(3,1));
    y(4,1) = TempFilterModule.Misc.angErr(z(4,1),z_calc(4,1));
end