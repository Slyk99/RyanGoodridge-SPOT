function [sensormode, zPS, zStereo, zLiDAR, zLRF, zIMU] = queryMeasurements(sensors)
    %% Extract Measurements
    % PS
    x_m         = sensors(1);
    y_m         = sensors(2);
    theta_m     = sensors(3);
    theta_s     = sensors(7);

    % Stereo
    LOS_Stereo  = sensors(8:10);
    rho_Stereo  = sensors(11);

    % LiDAR
    LOS_LiDAR   = sensors(12:14);
    rho_LiDAR   = sensors(15);

    % LRF
    rho_LFR     = sensors(16);
    
    % w_S
    theta_s     = sensors(17);
    w_s_IMU     = sensors(18);
    
    % PS Measurement Vector (3x1 Matrix)
    zPS = [x_m; y_m; theta_m; theta_s];
    % zPS = nan(size(zPS));

    % Line of Sight and Range Measurement Vector (3x1 Matrix)
    zStereo = [LOS_Stereo; rho_Stereo;];
    % zStereo = nan(size(zStereo));

    % Line of Sight and Range Measurement Vector (3x1 Matrix)
    zLiDAR = [LOS_LiDAR; rho_LiDAR;];
    % zLiDAR = nan(size(zLiDAR));

    % Range Only Measurement Vector (1x1 Matrix)
    zLRF = rho_LFR;
    % zLRF = nan(size(zLRF));
    
    % PS RED angle + IMU angular velocity Measurement
    zIMU = [theta_s; w_s_IMU];
    % zIMU = nan(size(zIMU));
    
    %% Sensor mode
    sensormode.hasPS     = ~anynan(zPS);
    sensormode.hasLRF    = ~anynan(zLRF);
    sensormode.hasLidar  = ~anynan(zLiDAR);
    sensormode.hasStereo = ~anynan(zStereo);
    sensormode.hasIMU    = ~anynan(zIMU);
    sensormode.hasLONRng = ~anynan(zLiDAR) || ~anynan(zStereo);

    % disp(sensormode)
end