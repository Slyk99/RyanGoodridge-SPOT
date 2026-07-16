function [xs, Ps] = RTS(x, P, xk, Pk, xs, Ps, dt, u, Fhndl, Fargs)
    [~, F, ~] = Fhndl(x, dt, u, Fargs);
    
    S = P*F'*(Pk^-1);
    
    xs = x + S*(xs - xk);
    Ps = P + S*(Ps - Pk)*S';
end