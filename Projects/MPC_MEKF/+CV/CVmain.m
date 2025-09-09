function [vis_x, vis_yaw, vis_conf, vis_R, vis_dq, vis_q, visZOH_x, visZOH_yaw, visZOH_conf, visZOH_R, visZOH_q, visZOH_dq] = CVmain(UDP, flag, xRed, xblack, xblue, noise, std, FOV)

    persistent xrelblack_prev
    
    if flag 
        [xrelblack, ~] = CV.simCV(xRed, xblack, xblue, noise, std, FOV);
    else
        xrelblack = UDP;
    end

    if isempty(xrelblack_prev)
        xrelblack_prev = 0*xrelblack;
    end
    
    [vis_x, vis_yaw, vis_conf, vis_R, vis_dq, vis_q, visZOH_x, visZOH_yaw, visZOH_conf, visZOH_R, visZOH_q, visZOH_dq] = CV.CV_Processing(xrelblack,xrelblack_prev);
    xrelblack_prev = xrelblack;
end