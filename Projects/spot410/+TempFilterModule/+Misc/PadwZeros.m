function EKFout = PadwZeros(EKFout, EKFoutSmall, m)
    % Pad With zeros to make simulink happy
    EKFout.y(1:m)   = EKFoutSmall.y;
    EKFout.K(:,1:m) = EKFoutSmall.K;
    EKFout.H(1:m,:) = EKFoutSmall.H;
    
    % Same size regardless of measurement size
    EKFout.xk = EKFoutSmall.xk;
    EKFout.Pk = EKFoutSmall.Pk;
    EKFout.d  = EKFoutSmall.d;
    EKFout.F  = EKFoutSmall.F;
    EKFout.G  = EKFoutSmall.G;

end