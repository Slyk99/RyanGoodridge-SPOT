function plotData(data,t)
%% Figure 1: pose states (measure, filtered, smoothed)
figure('Name','Pose States','NumberTitle','off');

% Labels for the plots
poseLabels = {'$x$ [m]','$y$ [m]','$\theta$ [rad]'};
velLabels  = {'$v_x$ [m/s]','$v_y$ [m/s]','$\omega_z$ [rad/s]'};

for i = 1:3
    subplot(3,1,i); 
    hold on;
      plot(t, wrapTo2Pi(data.x(:,i)),   'b*', 'DisplayName','measured y','MarkerSize',3);
      plot(t, wrapTo2Pi(data.xest(:,i)),      'r',  'LineWidth',1.2, 'DisplayName','filtered');
      plot(t, wrapTo2Pi(data.xs(:,i)),     'g','LineWidth',1.2, 'DisplayName','smoothed');
    hold off;
    ylabel(poseLabels{i}, ...
           'Interpreter','latex','FontName','Times','FontSize',12)
    if i==1
      title('Pose: Measurement vs Filter vs RTS Smoother', ...
            'Interpreter','latex','FontName','Times','FontSize',14)
    end
    if i == 2
        legend('Location','best','Interpreter','latex','FontSize',10)
    end
    if i==3
      xlabel('Time step','Interpreter','latex','FontName','Times','FontSize',12)
    end
    grid on;
    set(gca,'FontName','Times','FontSize',12)
end

%% Figure 2: velocity states (filtered, smoothed)
figure('Name','Velocity States','NumberTitle','off');
for k = 1:3
    subplot(3,1,k);
    hold on;
      plot(t, data.x(:,3+k),   'b*', 'DisplayName','measured y','MarkerSize',3);
      plot(t, data.xest(:,3+k),   'r',  'LineWidth',1.2, 'DisplayName','filtered');
      plot(t, data.xs(:,3+k),  'g','LineWidth',1.2, 'DisplayName','smoothed');
    hold off;
    ylabel(velLabels{k}, ...
           'Interpreter','latex','FontName','Times','FontSize',12)
    if k==1
      title('Velocities: Filter vs RTS Smoother', ...
            'Interpreter','latex','FontName','Times','FontSize',14)
    end
    if i == 2
        legend('Location','best','Interpreter','latex','FontSize',10)
    end
    if k==3
      xlabel('Time step','Interpreter','latex','FontName','Times','FontSize',12)
    end
    grid on;
    set(gca,'FontName','Times','FontSize',12)
end

%% Figure 3: pose states (measure, filtered, smoothed)
figure('Name','Error States','NumberTitle','off');

% Labels for the plots
poseLabels = {'$x$ [m]','$y$ [m]','$\theta$ [rad]'};

e = data.Path - data.x(:,1:3);
e(:,3) = anger(data.Path(:,3),data.x(:,3));

eest = data.Path - data.xest(:,1:3);
eest(:,3) = anger(data.Path(:,3),data.xest(:,3));

es = data.Path - data.xs(:,1:3);
es(:,3) = anger(data.Path(:,3),data.xs(:,3));

for i = 1:3
    subplot(3,1,i); 
    hold on;
      plot(t, e(:,i),   'b', 'DisplayName','measured e','MarkerSize',3);
      plot(t, eest(:,i),   'r', 'DisplayName','filtered e','MarkerSize',3);
      plot(t, es(:,i),   'g', 'DisplayName','smoothed e','MarkerSize',3);
    hold off;
    ylabel(poseLabels{i}, ...
           'Interpreter','latex','FontName','Times','FontSize',12)
    if i==1
      title('Error: Measurement vs Filter vs RTS Smoother', ...
            'Interpreter','latex','FontName','Times','FontSize',14)
    end
    if i == 2
        legend('Location','best','Interpreter','latex','FontSize',10)
    end
    if i==3
      xlabel('Time step','Interpreter','latex','FontName','Times','FontSize',12)
    end
    grid on;
    set(gca,'FontName','Times','FontSize',12)
end

%% Plot 4, Drawn on Table
figure;

% Top: 2/3 of height
ax1 = subplot(3,1,[1 2]);
hold(ax1,'on');

% draw the shaded rectangle footprint
y_min = 0;   y_max = 2.4;
x_min = 0;   x_max = 3.5;
Y = [y_min, y_max, y_max, y_min];
X = [x_min, x_min, x_max, x_max];
patch(ax1, X, Y, 0.9*[1 1 1], 'EdgeColor','k','LineWidth',2);

% plot trajectories
plot(ax1, data.Path(:,1),   data.Path(:,2),   'k','LineWidth',1.5);
plot(ax1, data.x(:,1),      data.x(:,2),      'b*','MarkerSize',3);
plot(ax1, data.xest(:,1),   data.xest(:,2),   'r','LineWidth',1.5);
plot(ax1, data.xs(:,1),     data.xs(:,2),     'g','LineWidth',1.5);

% labels & styling
xlabel(ax1,'X-Coordinate (m)');
ylabel(ax1,'Y-Coordinate (m)');
% axis(ax1,'equal');
xlim(ax1,[x_min-0.2, x_max+0.2]);
ylim(ax1,[y_min-0.2, y_max+0.2]);
grid(ax1,'on');
title(ax1,'Trajectories in Plane');
hold(ax1,'off');

% Bottom: 1/3 of height – angle vs time
ax2 = subplot(3,1,3);
hold(ax2,'on');

plot(ax2, t, wrapTo2Pi(data.x(:,3)),    'b*','MarkerSize',3);
plot(ax2, t, wrapTo2Pi(data.xest(:,3)), 'r','LineWidth',1.5);
plot(ax2, t, wrapTo2Pi(data.xs(:,3)),   'g','LineWidth',1.5);

xlabel(ax2,'Time (s)');
ylabel(ax2,'\theta (rad)');
legend(ax2,{'measured','estimated','smoothed'},...
       'Location','best');
grid(ax2,'on');
title(ax2,'Third State (\theta) vs Time');

hold(ax2,'off');
end

function e_out = anger(refmat,actmat)

for i = 1:1:length(refmat)
    ref = refmat(i);
    act = actmat(i);
    % ref
    rx = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[1;0];
    ry = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[0;1];
    
    % Act
    ax = [cos(act) sin(act); -sin(act) cos(act)]*[1;0];
    
    % diff
    dx = rx - ax;
    
    % Angle Error
    a = sign(ry'*dx);
    e_out(i) = -a*norm(dx);
end

end