function S = skew(v)
% Returns the 3x3 skew-symmetric matrix for a 3x1 vector v.
    S = [    0   -v(3)   v(2);
          v(3)      0   -v(1);
         -v(2)   v(1)      0];
end