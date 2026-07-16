function [xred,   ured,   Pred,   zred,  ...
     xblack, ublack, Pblack, zblack,...
     xblue,  ublue,  Pblue,  zblue] = unpackStates(xstack, Pstack, Measurments, CTL)


    xred   = xstack(:,1);
    xblack = xstack(:,2);
    xblue  = xstack(:,3);
    
    Pred   = Pstack(:,:,1);
    Pblack = Pstack(:,:,2);
    Pblue  = Pstack(:,:,3);

    zred   = Measurments(1:3,1);   % 4:6 is IMU
    zblack = Measurments(1:3,2);   % 4:6 is IMU
    zblue  = Measurments(1:3,3);   % 4:6 is IMU

    ured   = CTL(:,1);
    ublack = CTL(:,2);
    ublue  = CTL(:,3);
end