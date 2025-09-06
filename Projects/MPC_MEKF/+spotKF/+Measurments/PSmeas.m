function [zbar, H] = PSmeas(x)
    H = [eye(3), zeros(3)];
    zbar = H*x;
end