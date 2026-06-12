function [J, G] = MPCcost(x, p_ref, Q_blk, R_blk, params, n, N, m, M)
    % p_ref = [x, y, theta, 0, 0, 0, 0, 0, 0, x_ee, y_ee]' all in cart
    U = x(1:N*m,1);
    q = x(N*m + 1:end, 1);

    for i = 1:1:N
        p_ref_current = p_ref(:,i);
        [p, pb, p1, p2, pee] = ForwardKin(q, params);
        e = [p]
    end

    G_U = R_blk*U;
    J_U = U'*G_U;

    G_p = Q_blk*e;
    J_p = e'*G_p;

    J = J_U + J_p;
    G = [G_U; G_P];
end