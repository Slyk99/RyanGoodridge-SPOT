function [xStack, PStack, NAVout] = EstimateStates(xStack, PStack, u, dt, sensors, navOpts)
    %% Inputs
    params = navOpts.params;
    persistent Q_INS Q_GNS Q_12 R_PS R_LRF R_Stereo R_LiDAR R_IMU ...
    r_LRF r_IMU r_Lidar r_Stereo r_PS alphaSH rho V_full V_GNS initialized

    if isempty(initialized)
        Q_INS       = navOpts.Q_INS;    Q_GNS       = navOpts.Q_GNS; 
        Q_12        = navOpts.Q_12;     R_PS        = navOpts.R_PS;    
        R_LRF       = navOpts.R_LRF;    R_Stereo    = navOpts.R_Stereo;
        R_LiDAR     = navOpts.R_LiDAR;  R_IMU       = navOpts.R_IMU;
        r_PS        = navOpts.r_PS;     r_LRF       = navOpts.r_LRF;
        r_IMU       = navOpts.r_IMU;    r_Lidar     = navOpts.r_Lidar;
        r_Stereo    = navOpts.r_Stereo; r_LRF       = navOpts.r_LRF;
        r_IMU       = navOpts.r_IMU;    r_Lidar     = navOpts.r_Lidar;
        r_Stereo    = navOpts.r_Stereo; alphaSH     = navOpts.alphaSH;
        V_full      = zeros(6);         V_GNS       = zeros(4); % V_full = size(m_LOS + m_IMU by m_LOS + m_IMU) % V_GNS = size(zPS)
        rho         = navOpts.rho;      initialized = true;         
    end

    %% Propagation Selection
    dynHandle = @(x, dt, u, args) TempFilterModule.OrbitEstimation.Propagation.Euler1_propagate(x, dt, u, args);

    %% Measurement Selection
    [sensormode, zPS, zStereo, zLiDAR, zLRF, zIMU] =  TempFilterModule.OrbitEstimation.Measurements.queryMeasurements(sensors);
    PSHandle         = @(z,args) TempFilterModule.OrbitEstimation.Measurements.PS(z,args);          % Phase Space (relative)
    RngHandle        = @(z,args) TempFilterModule.OrbitEstimation.Measurements.Rng(z,args);         % Laser Range Finder
    IMUHandle        = @(z,args) TempFilterModule.OrbitEstimation.Measurements.IMU(z,args);         % Inertial Measurement Unit
    IMUNRngHandle    = @(z,args) TempFilterModule.OrbitEstimation.Measurements.IMUNRng(z,args);     % Laser Range Finder + Inertial Measurement Unit
    LOSNRngHndle     = @(z,args) TempFilterModule.OrbitEstimation.Measurements.LOSNRng(z,args);     % Line of Sight + Range (Lidar Or CNN or any combination including range)
    LOSIMUNRngHandle = @(z,args) TempFilterModule.OrbitEstimation.Measurements.LOSIMUNRng(z,args);  % Line of Sight + Range + Inertial Measurement Unit

    %% Filter Selection
    % FilterHandle = @(z, x, u, P, Q, R, H_Handle) TempFilterModule.OrbitEstimation.Filter.EKF(dt, ...
    %              z, x, u, P, Q, R, dynHandle, params, ...
    %              H_Handle, params, navOpts.OLR, navOpts.dmax);

    FilterHandle = @(z, x, u, P, Q, R, rho, V, H_Handle) TempFilterModule.OrbitEstimation.Filter.STEKF(dt, ...
                     z, x, u, P, Q, R, rho, V, dynHandle, params, H_Handle,...
                     params, navOpts.ST, navOpts.OLR, navOpts.d_max);

    %% Unpack data
    [x_INS, P_INS, x_GNS, P_GNS, ~, P12] = TempFilterModule.Misc.unpackStates(xStack, PStack);

    %% Preallocate Space
    % EKF_INS output - Max size, smaller Sizes will fill with zeros
    m_LOS      = length(zLiDAR); m_LRF = length(zLRF); m_IMU = length(zIMU);
    m_max      = m_LOS + m_IMU;
    EKF_INS.y  = zeros(m_max,1); 
    EKF_INS.K  = zeros(length(x_INS),m_max);
    EKF_INS.H  = zeros(m_max,length(x_INS));
    EKF_INS.xk = x_INS;
    EKF_INS.Pk = P_INS;
    EKF_INS.d  = 0;
    EKF_INS.F  = zeros(8);
    EKF_INS.G  = zeros(8,4);

    m_PS       = length(zPS);
    EKF_GNS.y  = zeros(m_PS,1); 
    EKF_GNS.K  = zeros(length(x_INS),m_PS);
    EKF_GNS.H  = zeros(m_PS,length(x_INS));
    EKF_GNS.xk = x_GNS;
    EKF_GNS.Pk = P_GNS;
    EKF_GNS.d  = 0;
    EKF_GNS.F  = zeros(8);
    EKF_GNS.G  = zeros(8,4);

    % Define Temp Var for sensor fusion
    z_LOS = zStereo;
    R_LOS = R_Stereo;
    z_LR  = [z_LOS(4), zLRF];
    R_LR  = cat(3, R_LOS(4,4), R_LRF);
    z_LC  = [zStereo, zLiDAR];
    R_LC  = cat(3, R_Stereo, R_LiDAR);

    %% Inertial Navigation Filter
    if navOpts.INStoggle

        % Fusion for both cameras
        if sensormode.hasLidar && sensormode.hasStereo
            [z_LOS, R_LOS] = TempFilterModule.Fusion.fuseMeasurements(z_LC, R_LC);

        elseif sensormode.hasLidar
            z_LOS = zLiDAR;
            R_LOS = R_LiDAR;
        end

        % Camera and LRF Fusion
        if sensormode.hasLONRng && sensormode.hasLRF

            [z_temp, R_temp] = TempFilterModule.Fusion.fuseMeasurements(z_LR, R_LR);
            z_LOS(3) = z_temp;
            R_LOS(3) = R_temp;
        end

        % Run EKF
        if sensormode.hasLONRng && sensormode.hasIMU
            z = [z_LOS; zIMU];
            R = blkdiag(R_LOS, R_IMU);

            [x_INS, P_INS, V_full, EKF_INS] = FilterHandle(z, x_INS, u, P_INS, Q_INS, R, rho.INS, V_full, LOSIMUNRngHandle);

        elseif sensormode.hasLONRng
            V_LOS = V_full(1:4,1:4);

            [x_INS, P_INS, V_LOS, EKF_LOS] = FilterHandle(z_LOS, x_INS, u, P_INS, Q_INS, R_LOS, rho.INS, V_LOS, LOSNRngHndle);

            % Update the True Pzz for the measurements that were available
            V_full = rho.INS*V_full;
            V_full(1:4,1:4) = V_LOS;

            % Pad With zeros to make simulink happy
            EKF_INS = TempFilterModule.Misc.PadwZeros(EKF_INS, EKF_LOS, m_LOS);

        elseif sensormode.hasLRF && sensormode.hasIMU
            z = [zLRF; zIMU];
            R = blkdiag(R_LRF, R_IMU);
            V_LFR_IMU = V_full(4:6,4:6);

            [x_INS, P_INS, V_LFR_IMU, EKF_IMU_LRF] = FilterHandle(z, x_INS, u, P_INS, Q_INS, R, rho.INS, V_LFR_IMU, IMUNRngHandle);

            % Update the True Pzz for the measurements that were available
            V_full = rho.INS*V_full;
            V_full(4:6,4:6) = V_LFR_IMU;

            % Pad With zeros to make simulink happy
            EKF_INS = TempFilterModule.Misc.PadwZeros(EKF_INS, EKF_IMU_LRF, m_IMU+m_LRF);

        elseif sensormode.hasLRF
            V_LFR = V_full(4,4);

            [x_INS, P_INS, V_LFR, EKF_LRF] = FilterHandle(zLRF, x_INS, u, P_INS, Q_INS, R_LRF, rho.INS, V_LFR, RngHandle);

            % Update the True Pzz for the measurements that were available
            V_full = rho.INS*V_full;
            V_full(4,4) = V_LFR;

            % Pad With zeros to make simulink happy
            EKF_INS = TempFilterModule.Misc.PadwZeros(EKF_INS, EKF_LRF, m_LRF);

        elseif sensormode.hasIMU
            V_IMU = V_full(5:6,5:6);

            [x_INS, P_INS, V_IMU, EKF_IMU] = FilterHandle(zIMU, x_INS, u, P_INS, Q_INS, R_IMU, rho.INS, V_IMU, IMUHandle);
    
            % Update the True Pzz for the measurements that were available
            V_full = rho.INS*V_full;
            V_full(5:6,5:6) = V_IMU;

            % Pad With zeros to make simulink happy
            EKF_INS = TempFilterModule.Misc.PadwZeros(EKF_INS, EKF_IMU, m_IMU);

        else % Just Propagate
            V_full = rho.INS*V_full;
            [x_INS, F, G] = dynHandle(x_INS, dt, u, params);
            P_INS = F*P_INS*F' + G*Q_INS*G';

            EKF_INS.F = F;
            EKF_INS.G = G;

        end % end switch sensor mode

    end % end INS Toggle

    %% Global Navigation Filter (Phasespace)
    if navOpts.GNStoggle
        % Run GNS Filter
        if ~anynan(zPS)
            [x_GNS, P_GNS, V_GNS, EKF_GNS] = FilterHandle(zPS, x_INS, u, P_INS, Q_GNS, R_PS, rho.GNS, V_GNS, PSHandle);

        else
            V_GNS = rho.GNS*V_GNS;
            [x_GNS, F, G] = dynHandle(x_GNS, dt, u, params);
            P_GNS = F*P_GNS*F' + G*Q_GNS*G';

            EKF_GNS.F = F;
            EKF_GNS.G = G;
        end % end switch sensor mode

    end % end GNS Toggle

    %% INS GNS Fusion
    if navOpts.GNStoggle && navOpts.INStoggle
        [x12, P12] = TempFilterModule.Fusion.Track2Track(x_INS, P_INS, ...
        EKF_INS.K, EKF_INS.H, x_GNS, P_GNS, EKF_GNS.K, EKF_GNS.H, P12, Q_12, EKF_GNS.F, EKF_GNS.G);

    elseif navOpts.INStoggle % Keep x12 as best estimate no matter what is selected
        x12 = x_INS;
        P12 = P_INS;

    else
        x12 = x_GNS;
        P12 = P_GNS;
    end % end Track 2 Track

    %% Run Sage Husa main
    [R_PS, R_LRF, R_Stereo, R_LiDAR, R_IMU, ...
     r_PS, r_LRF, r_Stereo, r_Lidar, r_IMU, ...
     Q_INS, Q_GNS, SageHusa] = TempFilterModule.AdaptiveLaws.SageHusa_main( ...
     navOpts, sensormode, alphaSH, ...
     EKF_INS, EKF_GNS, ...
     Q_INS, Q_GNS, ...
     R_PS, R_LRF, R_Stereo, R_LiDAR, R_IMU, ...
     r_PS, r_LRF, r_Stereo, r_Lidar, r_IMU, ...
     zPS, zLRF, zStereo, zLiDAR, zIMU, ...
     x12, PSHandle, RngHandle, LOSNRngHndle, IMUHandle);

    %% Filter Output
    NAVout.EKF_GNS    = EKF_GNS;
    NAVout.EKF_INS    = EKF_INS;
    NAVout.sensormade = sensormode;
    NAVout.SageHusa   = SageHusa;

    [xStack, PStack] = TempFilterModule.Misc.packStates(x_INS, P_INS, x_GNS, P_GNS, x12, P12);

end

