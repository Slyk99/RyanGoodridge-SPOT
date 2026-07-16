% find_transformation.m
% Estimate the 2D homogeneous transform T_camera between camera and red spacecraft
% such that:
%   p_black_global = p_red_global + R_red * (R_cam * p_rel + t_cam)
%   theta_black = theta_red + theta_cam + theta_rel (with camera z inversion)
% Handles NaNs in rel measurements.

%% Workspace inputs:
% red   : N×3 [x, y, theta]
% rel   : N×3 [x_rel, y_rel, theta_rel]
% black : N×3 [x, y, theta]
% t     : N×1 time vector matching rows
[RED,BLACK,RKF,STRKF,STRKF2,QKF,STQKF,STQKF2,DQKF,STDQKF,STDQKF2,CNN,t] = unpackData(dataClass_rt);

black = BLACK.x(:,1:3);
red = RED.x(:,1:3);
rel = CNN.x;

for i = 1:1:length(rel)
    if ~anynan(CNN.q(i,:))
        qtemp = smallQuat(CNN.q(i,:),'scalarFirst');
        temp = quat2Axang(qtemp,'scalarFirst');
        rel(i,3) = temp(end);
    else
        rel(i,3) = nan(1,1);
    end
end

%% Optimize camera transform with fmincon and bounds
% p0 = [0; 0; -4*pi/180];                 % initial [tx; ty; theta_cam]
% lb = [-0.5; -0.5; 0];         % lower bounds for [tx, ty, theta_cam]
% ub = [0.5;  0.5; 2*pi];       % upper bounds
% initGuess = [0.05; -0.02; pi/8];
% 
% opts = optimoptions('fmincon', 'Display','iter', 'Algorithm','sqp', ...
%                     'TolX',1e-6, 'TolFun',1e-6);
% [p_opt, fval] = fmincon(@(p) costFcn(p, red(78:end,:), rel(78:end,:), black(78:end,:)), p0, ...
%                          [], [], [], [], lb, ub, [], opts);

tx        = 0;
ty        = 0;
theta_cam = 0;

% tx = 0.3825;
% ty = -0.0378;
% theta_cam = -0.075;
% 
% p_opt = [tx,ty,theta_cam];
% costFcn(p_opt, red, rel, black)

% fprintf('Camera transform: tx=%.4f, ty=%.4f, theta_cam=%.4f rad\n',tx,ty,theta_cam);
% fprintf('Final cost: %.6f\n', fval);

%% Prepare estimated states for plotting
valid = ~any(isnan(rel(:,1:2)),2);
[est_pos, est_theta] = estimateStates(p_opt, red, rel, valid);
true_pos  = black(valid,1:2);
true_theta = black(valid,3);
time_valid = t(valid);

%% Plot subplots: x, y, theta vs time
figure;
subplot(3,1,1); hold on; grid on;
plot(time_valid, true_pos(:,1), 'k-', 'LineWidth',1.5);
plot(time_valid, est_pos(:,1), 'b*', 'LineWidth',1.5); 
ylabel('X (m)'); legend('True','Est');
ylim([1.6, 1.9])

subplot(3,1,2); hold on; grid on;
plot(time_valid, true_pos(:,2), 'k-', 'LineWidth',1.5);
plot(time_valid, est_pos(:,2), 'b*', 'LineWidth',1.5);
ylabel('Y (m)');
ylim([1, 1.6])

subplot(3,1,3); hold on; grid on;
plot(time_valid, wrapToPi(true_theta), 'k-', 'LineWidth',1.5);
plot(time_valid, wrapToPi(est_theta), 'b*', 'LineWidth',1.5);
xlabel('Time (s)'); ylabel('\theta (rad)');

%% --- Subfunctions ---
function J = costFcn(p, red, rel, black)
    valid = ~any(isnan(rel(:,1:2)),2);
    theta_valid = valid;

    [est_pos, est_theta] = estimateStates(p, red, rel, valid);

    true_pos = black(valid,1:2);
    true_theta = black(theta_valid,3);

    posErr = sum((est_pos - true_pos).^2, 2);
    angErr = attErr(est_theta,true_theta).^2;
    
    wp = 100;
    wt = 0;
    J = sum(wp*posErr + wt*angErr);
end

function [pts, thetas] = estimateStates(p, red, rel, valid)
    % Camera Transform
    tx          = 0*p(1); 
    ty          =0* p(2); 
    theta_cam   = p(3);

    R_cam = [cos(theta_cam), -sin(theta_cam); sin(theta_cam), cos(theta_cam)];
    t_cam = [tx; ty];

    %% Init Loop
    idx = 0;
    n = sum(valid);
    pts = zeros(n,2);
    thetas = zeros(n,1);
    for k = find(valid)'
        idx = idx + 1;

        % unpack red
        xr = red(k,1); yr = red(k,2); th_red = red(k,3);
        
        % unpack rel
        x_rel = rel(k,1); y_rel = rel(k,2); th_rel = rel(k,3);

        % Check For nan
        if isnan(th_rel)
            th_rel = last_th_rel;
        else
            th_rel = th_rel;  % invert camera z-axis
            last_th_rel = th_rel;
        end

        % position
        R_red = [cos(th_red), -sin(th_red); sin(th_red), cos(th_red)]';
        p_cam = R_cam * [x_rel; y_rel] + t_cam;
        p_est = [xr; yr] + R_red * p_cam;
        pts(idx,:) = p_est';
        % theta
        thetas(idx) = wrapToPi(th_red - theta_cam/2 + th_rel);
    end
end

function e_out = attErr(ref,act)
Ax = [cos(act) sin(act); -sin(act) cos(act)]*[1;0];
Rx = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[1;0];
Ry = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[0;1];

e_in = Rx - Ax;

a = sign(Ry'*e_in);
e_out = -a*norm(e_in);
end