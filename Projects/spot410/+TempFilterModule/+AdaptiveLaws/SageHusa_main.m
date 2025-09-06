function [R_PS, R_LRF, R_Stereo, R_LiDAR, R_IMU, ...
          r_PS, r_LRF, r_Stereo, r_Lidar, r_IMU, ...
          Q_INS, Q_GNS, SageHusa] = SageHusa_main( ...
          navOpts, sensormode, alphaSH, ...
          EKF_INS, EKF_GNS, ...
          Q_INS, Q_GNS, ...
          R_PS, R_LRF, R_Stereo, R_LiDAR, R_IMU, ...
          r_PS, r_LRF, r_Stereo, r_Lidar, r_IMU, ...
          zPS, zLRF, zStereo, zLiDAR, zIMU, ...
          x12, PSHandle, RngHandle, LOSNRngHndle, IMUHandle)

    %% Sage Husa Q Update (The Robinson Monro is used here as a simplified SH update)
    if navOpts.SageHusa_Q
        if navOpts.INStoggle
            Q_INS = TempFilterModule.AdaptiveLaws.RobinsonMonro_Q(Q_INS, EKF_INS.G, alphaSH.QINS, EKF_INS.K, EKF_INS.y);
        end
        if navOpts.GNStoggle
            Q_GNS = TempFilterModule.AdaptiveLaws.RobinsonMonro_Q(Q_GNS, EKF_GNS.G, alphaSH.QGNS, EKF_GNS.K, EKF_GNS.y);
        end
    end
    
    %% Sage Husa R Update (The Robinson Monro is used here as a simplified SH update)
    if navOpts.SageHusa_R
        if sensormode.hasPS
            R_PS     = TempFilterModule.AdaptiveLaws.RobinsonMonro_R(R_PS,     alphaSH.RPS,    EKF_GNS.y, length(zPS));
        end
        if sensormode.hasLRF
            R_LRF    = TempFilterModule.AdaptiveLaws.RobinsonMonro_R(R_LRF,    alphaSH.LRF,    EKF_INS.y, length(zLRF));
        end
        if sensormode.hasStereo
            R_Stereo = TempFilterModule.AdaptiveLaws.RobinsonMonro_R(R_Stereo, alphaSH.Stereo, EKF_INS.y, length(zStereo));
        end
        if sensormode.hasLidar
            R_LiDAR  = TempFilterModule.AdaptiveLaws.RobinsonMonro_R(R_LiDAR,  alphaSH.LiDAR,  EKF_INS.y, length(zLiDAR));
        end
        if sensormode.hasIMU
            R_IMU    = TempFilterModule.AdaptiveLaws.RobinsonMonro_R(R_IMU,    alphaSH.IMU,    EKF_INS.y, length(zIMU));
        end
    end
    
    %% Sensor Bias Update
    if navOpts.SageHusa_r
        if sensormode.hasPS
            r_PS     = TempFilterModule.AdaptiveLaws.SageHusa_r(r_PS,      zPS,    x12, alphaSH.rPS,     PSHandle);
        end
        if sensormode.hasLRF
            r_LRF    = TempFilterModule.AdaptiveLaws.SageHusa_r(r_LRF,    zLRF,    x12, alphaSH.rLRF,    RngHandle);
        end
        if sensormode.hasStereo
            r_Stereo = TempFilterModule.AdaptiveLaws.SageHusa_r(r_Stereo, zStereo, x12, alphaSH.rStereo, LOSNRngHndle);
        end
        if sensormode.hasLidar
            r_Lidar  = TempFilterModule.AdaptiveLaws.SageHusa_r(r_Lidar,  zLiDAR,  x12, alphaSH.rLidar,  LOSNRngHndle);
        end
        if sensormode.hasIMU
            r_IMU    = TempFilterModule.AdaptiveLaws.SageHusa_r(r_IMU,    zIMU,    x12, alphaSH.rIMU,    IMUHandle);
        end
    end
    
    %% Log values
    SageHusa.r_LRF    = r_LRF;
    SageHusa.r_IMU    = r_IMU;
    SageHusa.r_Lidar  = r_Lidar;
    SageHusa.r_Stereo = r_Stereo;
    SageHusa.r_PS     = r_PS;
    
    SageHusa.QINS     = Q_INS;
    SageHusa.QGNS     = Q_GNS;
    
    SageHusa.R_PS     = R_PS;
    SageHusa.R_LRF    = R_LRF;
    SageHusa.R_Stereo = R_Stereo;
    SageHusa.R_LiDAR  = R_LiDAR;
    SageHusa.R_IMU    = R_IMU;
end