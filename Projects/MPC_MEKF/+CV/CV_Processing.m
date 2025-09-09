function [vis_x, vis_yaw, vis_conf, vis_R, vis_dq, vis_q, visZOH_x, visZOH_yaw, visZOH_conf, visZOH_R, visZOH_q, visZOH_dq] = CV_Processing(rawData,rawDataPrev)
    % Computer vision processing
    x     = rawData(1);
    y     = rawData(2);
    yaw   = rawData(3);
    conf  = rawData(4);
    
    % Pseudo measurements
    z     = 0;
    roll  = 0;
    pitch = 0;
    
    
    visZOH_x    = [x; y; z];
    visZOH_yaw  = yaw;
    visZOH_conf = conf;
    
    % Attitude representation 
    visZOH_R = C3(yaw);
    T        = [visZOH_R, visZOH_x; zeros(1,3), 1];
    T        = htformInverse(T);
    
    visZOH_q  = rotm2Quat(visZOH_R,'scalarFirst');
    visZOH_dq = htform2Dq(T,'scalarFirst');
    
    if sum(abs(rawData - rawDataPrev)) < 10^-10 || isempty(rawDataPrev)
        vis_x    = visZOH_x;
        vis_yaw  = visZOH_yaw;
        vis_conf = visZOH_conf;
        vis_R    = visZOH_R;
        vis_q    = visZOH_q;
        vis_dq   = visZOH_dq;
    else
        vis_x    = nan(size(visZOH_x));
        vis_yaw  = nan(size(visZOH_yaw));
        vis_conf = nan(size(visZOH_conf));
        vis_R    = nan(size(visZOH_R));
        vis_q    = nan(size(visZOH_q));
        vis_dq   = nan(size(visZOH_dq));
    end
end