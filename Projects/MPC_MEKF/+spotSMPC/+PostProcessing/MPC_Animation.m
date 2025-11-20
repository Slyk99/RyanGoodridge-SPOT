close all

spotFilterData = spotKF.PostProcessing.FilterData(dataClass, navOpts, Phase2_End);
MPCdata = spotSMPC.PostProcessing.loadMPCData(dataClass, Phase2_End);
allConstraints = spotSMPC.PostProcessing.runMPC_postProcess(dataClass, spotFilterData, MPCdata, mpcConfig, navOpts, M, Phase2_End);

%%
robots  = ["RED", "BLACK", "BLUE"];
color   = ['r', 'k', 'b'];
alpha   = 1;

figure
hold on
grid on

for i = 1:1:length(MPCdata.Results)
    cla
    % Plot all three spacecraft
    for r = 1:length(robots)
        robot = robots(r);
    
        param = [spotFilterData.estimated_States.(robot)(1:3,i); r];
        [spacecraft] = spotSMPC.PostProcessing.Plots.DrawSpacecraft(param);
        patch(spacecraft(:,1), spacecraft(:,2), 'w', 'facealpha', 0.5, 'edgecolor', color(r), 'edgealpha',alpha,'Linewidth',0.5)
    
    end
    
    % Plot desired Trajectory
    x = MPCdata.optimalStates(1,:,i);
    y = MPCdata.optimalStates(2,:,i);
    plot(x, y, 'r', 'LineWidth', 1)
    
    % Plot Constraint 
    ellipse = allConstraints.target_ellipse(:,:,1,i)';
    plot(ellipse(1,:), ellipse(2,:), 'k')
    % ellipse = allConstraints.Starget_ellipse(:,:,1,i)';
    % plot(ellipse(1,:), ellipse(2,:), 'r')
    
    ellipse = allConstraints.obstacle_ellipse(:,:,1,i)';
    plot(ellipse(1,:), ellipse(2,:), 'b')
    
    % Plot desired location
    r = 0.15;
    theta = spotFilterData.estimated_States.BLACK(3,i);
    x = spotFilterData.estimated_States.BLACK(1,i);
    y = spotFilterData.estimated_States.BLACK(2,i);
    R_theta = [cos(theta), -sin(theta);
               sin(theta),  cos(theta)];
    xd = mpcConfig.docking_Offset(1);
    yd = mpcConfig.docking_Offset(2);

    docking_port = [x;y] + R_theta*[xd;yd];
    plot(docking_port(1), docking_port(2), 'k*')
    % px = [mpcConfig.docking_Offset(1); mpcConfig.docking_Offset(1) + r*cos(mpcConfig.Camera_Offset(3))];
    % py = [mpcConfig.docking_Offset(2); mpcConfig.docking_Offset(2) + r*sin(mpcConfig.Camera_Offset(3))];
    % plot(px+x, py+y, 'r')

    grid on
    box on
    axis equal
    xlim([0 3.5])
    ylim([0 2.4])
    pause(0.005)
end