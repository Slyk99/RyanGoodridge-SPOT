function plotForce(data,t)

%% Figure 1: Force
figure('Name',' Force','NumberTitle','off');

% Labels for the plots
poseLabels = {'$F_x$ [N]','$F_y$ [N]','$T_z$ [Nm]'};

for i = 1:3
    subplot(3,1,i); 
    hold on;
      plot(t, data.F(:,i),   'k', 'LineWidth',1.2, 'DisplayName','Demanded');
      plot(t, data.Fsat(:,i),      'r',  'LineWidth',1.2, 'DisplayName','Saturated');
    hold off;
    ylabel(poseLabels{i}, ...
           'Interpreter','latex','FontName','Times','FontSize',12)
    if i==1
      title('Demanded Vs Saturated Force', ...
            'Interpreter','latex','FontName','Times','FontSize',14)
      ylim([-0.15,0.15])
    end
    if i == 2
        legend('Location','best','Interpreter','latex','FontSize',10)
        ylim([-0.15,0.15])
    end
    if i==3
      xlabel('Time step','Interpreter','latex','FontName','Times','FontSize',12)
      ylim([-0.025,0.025])
    end
    grid on;
    set(gca,'FontName','Times','FontSize',12)
end

%% Figure 2: Force Components
figure('Name',' Force Components','NumberTitle','off');

% Labels for the plots
poseLabels = {'$F_x$ [N]','$F_y$ [N]','$T_z$ [Nm]'};

for i = 1:3
    subplot(3,1,i); 
    hold on;
      plot(t, data.F(:,i),   'k', 'LineWidth',1.2, 'DisplayName','$F_{sum}$');
      plot(t, data.Fcomp(:,i),      'r',  'LineWidth',1.2, 'DisplayName','$F_P$');
      plot(t, data.Fcomp(:,3+i),      'b',  'LineWidth',1.2, 'DisplayName','$F_D$');

    hold off;
    ylabel(poseLabels{i}, ...
           'Interpreter','latex','FontName','Times','FontSize',12)
    if i==1
      title('Demanded Vs Saturated Force', ...
            'Interpreter','latex','FontName','Times','FontSize',14)
      ylim([-0.15,0.15])
    end
    if i == 2
        legend('Location','best','Interpreter','latex','FontSize',10)
        ylim([-0.15,0.15])
    end
    if i==3
      xlabel('Time step','Interpreter','latex','FontName','Times','FontSize',12)
      ylim([-0.025,0.025])
    end
    grid on;
    set(gca,'FontName','Times','FontSize',12)
end
end