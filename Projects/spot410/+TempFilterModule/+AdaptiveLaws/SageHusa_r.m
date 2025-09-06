function r = SageHusa_r(r, z, x_est, alpha, Hhndl)
    [r_new, ~] = Hhndl(x_est,z);
    r = (1 - alpha)*r + alpha*r_new;
end