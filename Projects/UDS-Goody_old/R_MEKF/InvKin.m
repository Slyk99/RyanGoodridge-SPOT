function [roll, pitch, yaw] = InvKin(R)
R = R;
% InvKin – Extract Euler angles (roll, pitch, yaw) from a rotation matrix.
%
% Here we use a simple convention. (You may wish to adjust this for your system.)
    yaw   = atan2(R(1,2), R(1,1));
    roll  = atan2(R(2,3), R(3,3));
    if abs(sin(roll)) < abs(sin(45*pi/180))
        pitch = atan2(-R(1,3), R(3,3)/cos(roll));
    else
        pitch = atan2(-R(1,3), R(2,3)/sin(roll));
    end
end