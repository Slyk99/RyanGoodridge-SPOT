function [p, pb, p1, p2, pee] = ForwardKin(q, params)

phi = 68.2840*d2r;      %rad
b0 = 0.2304;            %m

a1 = 0.1933;            %m
b1 = 0.1117;            %m
a2 = 0.1993;            %m
b2 = 0.1057;            %m
a3 = 0.0621;            %m
b3 = 0.0159;            %m

x0 = q(1);
y0 = q(2);
q0 = q(3);
q1 = q(4);
q2 = q(5);
q3 = q(6);

% State of the chaser spacecraft
p = [x0; y0; q0];

% cart coords of the arm base
theta_0 = phi + q0;
pb_x = x0 + b0*cos(theta_0);
pb_y = y0 + b0*sin(theta_0);

pb = [pb_x; pb_y];

% cart coords of the second joint of the arm
theta_1 = pi/2 + q0 + q1;
d1 = a1 + b1;
p1_x = pb_x + d1*cos(theta_1);
p1_b = pb_y + d1*sin(theta_1);

p1 = [p1_x; p1_y];

% cart coords of the second joint of the arm
theta_2 = theta_1 + q2;
d2 = a2 + b2;
p2_x = p1_x + d2*cos(theta_2);
p2_y = p1_b + d2*sin(theta_2);

p2 = [p2_x; p2_y];

% cart coords of the end effect of the arm
theta_3 = theta_2 + q3;
d3 = a3 + b3;
p3_x = p2_x + d3*cos(theta_3);
p3_y = p2_y + d3*sin(theta_3);

pee = [p3_x; p3_y];


end