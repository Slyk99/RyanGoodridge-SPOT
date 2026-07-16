function [x,F,G] = Euler1(x, dt, u, Fargs)
    F = [eye(3), dt*eye(3);
         zeros(3), eye(3)];

    m = diag([1/Fargs.m; 1/Fargs.m; 1/Fargs.I]);

    G = [(dt^2/2)*m; dt*m];

    x = F*x + G*u;
end