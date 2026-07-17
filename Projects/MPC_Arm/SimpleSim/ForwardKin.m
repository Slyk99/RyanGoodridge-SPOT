function [p, dp, q, dq, pb, p1, p2, pee, v] = ForwardKin(qin, params)

% constants (move to params later)
phi = 68.2840*d2r;      %rad
b0 = 0.2304;            %m

a1 = 0.1933;            %m
b1 = 0.1117;            %m
a2 = 0.1993;            %m
b2 = 0.1057;            %m
a3 = 0.0621;            %m
b3 = 0.0159;            %m

% States
x0  = qin(1);
y0  = qin(2);
q0  = qin(3);
q1  = qin(4);
q2  = qin(5);
q3  = qin(6);
dx0 = qin(7);
dy0 = qin(8);
dq0 = qin(9);
dq1 = qin(10);
dq2 = qin(11);
dq3 = qin(12);

% State of the chaser spacecraft
p = [x0; y0; q0];
dp = [dx0; dy0; dq0];

% Angles of the joints
q = [q1; q2; q3];
dq = [dq1; dq2; dq3];

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

% End effector normal (tool direction)
v = (Pee - p2)/norm(Pee - p2);


end