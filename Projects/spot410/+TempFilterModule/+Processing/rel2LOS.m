function LOS_vec = rel2LOS(rel_vec)
    x = rel_vec(1);
    y = rel_vec(2);

    p = sqrt(x^2 + y^2);

    u = rel_vec(1:2)/p;

    LOS_vec = [u; p; rel_vec(3)];

end