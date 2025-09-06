function [z_bar,H] = meas(x,z,Hargs)
    %% Define Chaser Pose
    q_c = quatInv(Hargs.red(1:4),'scalarFirst'); 
    position_c = Hargs.red(5:7);

    %% Extract Target Pose
    q_t = x(1:4);                % Quaternion (qw, qx, qy, qz)
    position_t = x(8:10);        % Position (x, y, z)

    %% Predict Measurment
    z_bar = 0*z; % Preallocate

    % Postion
    delta_p = position_t - position_c;
    z_bar(5:7) = quatRotate(q_c,delta_p,'scalarFirst');

    % Quaterion
    z_bar(1:4) = quatMultiply(q_t, q_c,'scalarFirst');
    z_bar(1:4) = smallQuat(z_bar(1:4),'scalarFirst');
    % z_bar(1:4) = quantizeYawQuat(z_bar(1:4));

    %% Compute H
    q_c = quatConj(q_c,'scalarFirst');
    jz = [(1-2*(q_c(3)*q_c(3) + q_c(4)*q_c(4))), 2*(q_c(2)*q_c(3) + q_c(1)*q_c(4)), 2*(q_c(2)*q_c(4) + q_c(1)*q_c(3));
          2*(q_c(2)*q_c(3) - q_c(1)*q_c(4)), (1-2*(q_c(2)*q_c(2) + q_c(4)*q_c(4))), 2*(q_c(3)*q_c(4) + q_c(1)*q_c(2));
          2*(q_c(2)*q_c(4) + q_c(1)*q_c(3)), 2*(q_c(3)*q_c(4) - q_c(1)*q_c(2)), (1-2*(q_c(2)*q_c(2) + q_c(3)*q_c(3)))];

    H = [eye(3), zeros(3), zeros(3), zeros(3); % Quaterion
         zeros(3), zeros(3), jz, zeros(3)];    % Position
end