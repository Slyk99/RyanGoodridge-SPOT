function [xredfull, xblackfull, xbluefull, xstack, Pstack] = spotNavigation(dt, Measurments, CTL, xstack, Pstack, navOpts)

    %% Inputs
    params      = navOpts.params;
    persistent kfChaser kfTarget kfObs V_red V_black V_blue zred_prev zblack_prev zblue_prev initialized

    % Only initialize once
    if isempty(initialized)
        kfChaser = navOpts.kfChaser;
        kfTarget = navOpts.kfTarget;
        kfObs    = navOpts.kfObs;
        V_red    = zeros(3);
        V_black  = zeros(3);
        V_blue   = zeros(3);
        zred_prev   = zeros(3,1);
        zblack_prev = zeros(3,1);
        zblue_prev  = zeros(3,1);
        initialized = true;
    end

    %% Define Function shorthand
    dynHandle    = @(x, dt, u) spotKF.Dynamics.Euler1(x, dt, u, params);
    measHangle   = @(x) spotKF.Measurments.PSmeas(x);
    FilterHandle = @(z, x, u, P, rho, V, Q, R, ST, OLR, dmax) spotKF.Filter.STEKF(dt, ...
                     z, x, u, P, rho, V, Q, R, ...
                     dynHandle, measHangle, ST, OLR, dmax);

    %% Unpack
    [xred,   ured,   Pred,   zred,  ...
     xblack, ublack, Pblack, zblack,...
     xblue,  ublue,  Pblue,  zblue] = spotKF.Misc.unpackStates(xstack, Pstack, Measurments, CTL);

    % Handle held measurements
    if abs(zred_prev - zred) < 10^-10
        zred = NaN(size(zred));
    end
    zred_prev = zred;

    if abs(zblack_prev - zblack) < 10^-10
        zblack = NaN(size(zblack));
    end
    zblack_prev = zblack;

    if abs(zblue_prev - zblue) < 10^-10
        zblue = NaN(size(zblue));
    end
    zblue_prev = zblue;

    %% RED Filter
    if navOpts.toggleREDkf
        [xred, Pred] = FilterHandle(zred, xred, ured, Pred, ...
         kfChaser.rho, V_red, kfChaser.Q, kfChaser.R, ...
         kfChaser.ST, kfChaser.OLR, kfChaser.dmax);
    else
        vred = spotKF.Filter.pseDerivative(zred, dt, kfChaser.a);
        xred = [zred; vred];
    end
    
    %% BLACK Filter
    if navOpts.toggleBLACKkf
        [xblack, Pblack] = FilterHandle(zblack, xblack, ublack, Pblack, ...
         kfTarget.rho, V_black, kfTarget.Q, kfTarget.R, ...
         kfTarget.ST, kfTarget.OLR, kfTarget.dmax);
    else
        vblack = spotKF.Filter.pseDerivative(zblack, dt, kfTarget.a);
        xblack = [zblack; vblack];
    end
    
    %% BLUE Filter
    if navOpts.toggleBLUEkf
        [xblue, Pblue] = FilterHandle(zblue, xblue, ublue, Pblue, ...
         kfObs.rho, V_blue, kfObs.Q, kfObs.R, ...
         kfObs.ST, kfObs.OLR, kfObs.dmax);
    else
        vblue = spotKF.Filter.pseDerivative(zblue, dt, kfObs.a);
        xblue = [zblue; vblue];
    end

    %% Add acceleration
    ared   = spotKF.Filter.pseDerivative(xred(4:6), dt, kfChaser.a);
    ablack = spotKF.Filter.pseDerivative(xblack(4:6), dt, kfTarget.a);
    ablue  = spotKF.Filter.pseDerivative(xblue(4:6), dt, kfObs.a);

    xredfull   = [xred; ared];
    xblackfull = [xblack; ablack];
    xbluefull  = [xblue; ablue];

    %% Pack
    [xstack, Pstack] = spotKF.Misc.packStates(xred, Pred, xblack, Pblack, xblue, Pblue);

end