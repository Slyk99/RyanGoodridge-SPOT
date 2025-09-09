function [zINS,R_INS] = fusion(zINS_full, RINSfull)
    % Measurement unpacking
    zStereo = zINS_full(1:4); 
    zLiDAR  = zINS_full(5:8); 
    zLRF    = zINS_full(9); 
    zIMU    = zINS_full(10:11); 

    % --- LOS fusion ---
    if ~anynan(zStereo) && ~anynan(zLiDAR)
        RLOSfull = zeros(4,4,2);
        RLOSfull(:,:,1) = diag(RINSfull(1:4));
        RLOSfull(:,:,2) = diag(RINSfull(5:8));
        zLOS_full = [zStereo, zLiDAR];

        [zLOSNR,RLOSNR] = TempFilterModule.Fusion.fuseMeasurements(zLOS_full, RLOSfull);
    elseif ~anynan(zStereo)
        zLOSNR = zStereo;
        RLOSNR = diag(RINSfull(1:4));
    elseif ~anynan(zLiDAR)
        zLOSNR = zLiDAR;
        RLOSNR = diag(RINSfull(5:8));
    else
        zLOSNR = nan(4,1);
        RLOSNR = nan(4);
    end

    % --- Range fusion ---
    if ~anynan(zLOSNR) && ~anynan(zLRF)
        RNGfull = zeros(1,1,2);
        RNGfull(:,:,1) = RLOSNR(3,3);
        RNGfull(:,:,2) = RINSfull(9);
        zRNG_full = [zLOSNR(3), zLRF];

        [zRNG,RRNG] = TempFilterModule.Fusion.fuseMeasurements(zRNG_full, RNGfull);

        zLOSNR(3) = zRNG;
        RLOSNR(3,3) = RRNG;
    elseif ~anynan(zLRF)
        zLOSNR(3) = zLRF;
        RLOSNR(3,3) = RINSfull(9);
    else
        % leave NaN as-is if zLOSNR already NaN
    end

    % --- Final assembly ---
    zINS  = [zLOSNR; zIMU];
    R_INS = blkdiag(RLOSNR, diag(RINSfull(10:11))); 
end
