function [z, H] = GNS(x)
H = [eye(4) zeros(4,5);
     zeros(1,7), 1, 1];

z = H*x;
end