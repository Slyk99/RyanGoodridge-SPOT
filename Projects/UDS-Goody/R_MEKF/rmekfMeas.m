function [z_calc, Rot_bar, H_meas] = rmekfMeas(x, z, Rot, Hargs)
% Measurement function.
%
% Inputs:
%   x     - non-attitude state (9x1); here x(1:3) is the target position.
%   z     - measurement vector (expected to be 3x1, see below)
%   Rot   - current (propagated) attitude estimate (3x3)
%   Hargs - structure with chaser parameters (chaser x, y, z, and yaw)
%
% Outputs:
%   z_calc - calculated measurement (3x1)
%   Rot_bar- predicted target attitude transformed into the chaser frame (3x3)
%   H_meas - measurement Jacobian with respect to x (3x9)

    % Use chaser position and yaw (assumed provided in Hargs)
    x_c = Hargs.x;
    y_c = Hargs.y;
    z_c = Hargs.z;
    yaw_c = Hargs.yaw;
    
    % Build the chaser’s rotation matrix
    R_chaser = quat2Rotm(yaw_c,'scalarFirst');
    
    % The target (object) position is the first three elements of x.
    pos_t = x(1:3);
    pos_c = [x_c; y_c; z_c];
    
    % Relative position vector from chaser to target (in the global frame)
    v_tc = pos_t - pos_c;
    
    % The expected translation measurement (expressed in the chaser frame)
    z_calc = R_chaser * v_tc;   % 3x1
    
    Rot_bar = R_chaser * Rot';
    
    % The measurement Jacobian
    H_meas = [eye(3), zeros(3,9);
              zeros(3), R_chaser, zeros(3, 6) ];
end