function [z, H] = GNS(x)
z = [x(1:3); x(7:8)];

H = [eye(3), zeros(3,5);
     zeros(2,6), eye(2)];
end