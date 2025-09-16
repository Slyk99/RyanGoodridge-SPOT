function [z, H] = GNS(x)
H = [eye(3), zeros(3,6);
     zeros(1,6), 1, zeros(1,2);
     zeros(1,7), 2, 1];

z = H*x;
end