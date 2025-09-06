function [x, P, y, H, V] = STQMEKF(z, dt, x, P, a, f, Q, R, r, V, rho, dmax, Fhndl, Fargs, Hhndl, Hargs)
%% QMEKF: Quaternion-MEKF that extends to an EKF for non-quaternion states
% Inputs:
% z      - Measurement vector (quaternion + other measurements)
% dt     - Time step
% x      - Current state vector [quaternion (4x1); angular velocity (3x1); other measurements]
% P      - Current state covariance matrix
% a, f   - Constants for Modified Rodrigues Parameters (MRPs)
% Q      - Process noise covariance matrix
% R      - Measurement noise covariance matrix
% V      - True Pzz for ST adaptation 
% rho    - Forgetting factor 0 < rho < 1
% dmax   - Maximum Mahalanobis Distance
% Fhndl  - Function handle for state transition model
% Fargs  - Additional arguments for the state transition model
% Hhndl  - Function handle for measurement model
% Hargs  - Additional arguments for the measurement model
%
% Outputs:
% x      - Updated state vector
% P      - Updated covariance matrix
%
    %% Predict Step
    [x_k, F] = Fhndl(x, dt, Fargs); % State transition function
    P_k = F * P * F' + Q;              % Predict covariance (G*Q*G' is omitted as G = I)
    
    %% Update Step 
    [z_bar, H] = Hhndl(x_k, z, Hargs);
    
    % Inflate noise of state to reduce effects of quantization
    if ~anynan(z)
        delta_q = axang2Quat([0;0;1;(rand(1,1)-0.5)*0],'scalarFirst');
        z(1:4) = quatMultiply(delta_q,z(1:4),'scalarFirst');
    end
    
    % Calculate the residual
    y = qmekfResidual(z,z_bar,a,f);

    %% Mahalanobis distance

    if anynan(z(1:4)) % Reject if NaN
        rejectQuat = true;
    else
        HQuat = H(1:3,:);
        [rejectQuat, ~] = Mahalanobis2(y(1:3), HQuat * P_k * HQuat', dmax(1));
    end
    if anynan(z(5:7)) % Reject if NaN
        rejectPose = true;
    else
        HPose = H(4:6,:);
        [rejectPose, ~] = Mahalanobis2(y(4:6), HPose * P_k * HPose', dmax(2));
    end

    % mask out only the bad part
    if rejectQuat
        y(1:3)    = 0;
        H(1:3, :) = 0;
    end
    if rejectPose
        y(4:6)    = 0;
        H(4:6, :) = 0;
    end

    %% ST Algorithm
    Pzz = H * P_k * H' + R; % Innovation covariance
    % Find better estimate of S
    if rejectQuat && rejectPose
    elseif rejectQuat
        V(4:6,4:6) = optPzz1(V(4:6,4:6),rho,y(4:6)); %%%
        % V(4:6,4:6) = optPzz3(Pzz(4:6,4:6),rho,y(4:6));
    elseif rejectPose
        V(1:3,1:3) = optPzz1(V(1:3,1:3),rho,y(1:3)); %%%
        % V(1:3,1:3) = optPzz3(Pzz(1:3,1:3),rho,y(1:3));
    else
        V = optPzz1(V,rho,y); %%%
        % V = optPzz3(Pzz,rho,y);
    end

    % Find Lambda
    % L = corrP1(V,Pzz,R);
    % L = corrP2(V,R,H,Q,P_k);
    % L = corrP3(V,R,H,Q,Pzz);
    L = corrP4Q(P_k, H, R, V); %%%

    % Corrct Covar
    P_k = L*P_k*L;
    Pzz = H * P_k * H' + R; % Innovation covariance
    V = rho*V;

    %% Kalman Gain and Covariance Update
    K = P_k * H' / Pzz;                                % Kalman gain
    I = eye(size(P));                                  % Identity matrix
    P = (I - K * H) * P_k * (I - K * H)' + K * R * K'; % Joseph form to maintain symmetry
    
    % State Update
    delta_x = K * y; % State correction
    
    % Compute the Kalman error quaternion from MRPs
    delta_q = mrp2quat(delta_x(1:3), a, f, 'scalarFirst');

    % Update the quaternion estimate by applying the correction to the propagated quaternion
    x(1:4) = quatMultiply(delta_q, x_k(1:4),'scalarFirst');
    
    % Update non-quaternion states
    x(5:end) = x_k(5:end) + delta_x(4:end);     
end
