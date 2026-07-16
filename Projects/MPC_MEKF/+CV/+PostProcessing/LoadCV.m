function CVdata = LoadCV(dataClass,Phase2_End)
    
    CVdata = struct;
    noise = zeros(16,1);
    std = 0;
    FOV = 0;

    n = 9;
    t_full = dataClass.Time_s.Data.';       % 1 x T_full
    dt     = diff(t_full);
    T_full = length(t_full);

    if Phase2_End > 0
        % Find first sample strictly AFTER Phase2_End
        idxStart = find(t_full > Phase2_End, 1, 'first');

        if isempty(idxStart)
            error("Phase2_End = %.3f occurs after final logged time (%.3f s).", ...
                   Phase2_End, t_full(end));
        end
    else
        idxStart = 1;     % no trimming
    end


    Time.t = t_full(idxStart:end);
    Time.dt = diff(Time.t);    % length = T_trim-1
    
    % Store trimming index for later reuse in robot loops
    idx = idxStart;

    T = length(Time.t);
    Est_mat = zeros(n, T);

    stateFields_est = ["Px_m",     "Py_m",     "Rz_rad", ...
                       "Vx_mpers", "Vy_mpers", "RzD_radpers", ...
                       "Ax_mpers2","Ay_mpers2","RzDD_radpers2"];
    robots = ["RED", "BLACK", "BLUE"];    
    % Fill each 9×T matrix
    for r = 1:1:3
        robot = robots(r);
        for i = 1:n
            estVec = dataClass.(robot + "_" + stateFields_est(i)).Data.';
            Est_mat(i,:) = estVec(idx:end);
        end
        True.(robot) = Est_mat;
    end

    %% CV Stuff

    % First Create Vector of UDP
    xyz = dataClass.Vis_x.Data(idx:end,:);
    theta = dataClass.Vis_yaw.Data(idx:end,:);
    conf = dataClass.Vis_conf.Data(idx:end,:);
    
    UDP = [xyz(:,1:2), theta, conf]';

    CVdata.Truth    = True;
    CVdata.Time     = Time.t;
    CVdata.x        = zeros(3,T);
    CVdata.yaw      = zeros(1,T);
    CVdata.conf     = zeros(1,T);
    CVdata.R        = zeros(3,3,T);
    CVdata.q        = zeros(4,T);
    CVdata.dq       = zeros(4,2,T);
    CVdata.ZOH.x    = zeros(3,T);
    CVdata.ZOH.yaw  = zeros(1,T);
    CVdata.ZOH.conf = zeros(1,T);
    CVdata.ZOH.R    = zeros(3,3,T);
    CVdata.ZOH.q    = zeros(4,T);
    CVdata.ZOH.dq   = zeros(4,2,T);
    for i = 1:1:length(UDP)
        xRed = True.RED(:,i);
        xblack = True.BLACK(:,i);
        xblue = True.BLUE(:,i);
        [vis_x, vis_yaw, vis_conf, vis_R, vis_dq, vis_q, visZOH_x, visZOH_yaw, visZOH_conf, visZOH_R, visZOH_q, visZOH_dq] = CV.CVmain(UDP(:,i), 1, xRed, xblack, xblue, noise, std, FOV);
        
        CVdata.x(:,i)        = vis_x;
        CVdata.yaw(:,i)      = vis_yaw;
        CVdata.conf(:,i)     = vis_conf;
        CVdata.R(:,:,i)      = vis_R;
        CVdata.q(:,i)        = vis_q;
        CVdata.dq(:,:,i)     = vis_dq;
        CVdata.ZOH.x(:,i)    = visZOH_x;
        CVdata.ZOH.yaw(:,i)  = visZOH_yaw;
        CVdata.ZOH.conf(:,i) = visZOH_conf;
        CVdata.ZOH.R(:,:,i)  = visZOH_R;
        CVdata.ZOH.q(:,i)    = visZOH_q;
        CVdata.ZOH.dq(:,:,i) = visZOH_dq;
    end

end