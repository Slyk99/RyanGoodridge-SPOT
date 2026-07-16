clc
% SaveExpLog

[RED,BLACK,RKF,STRKF,STRKF2,QKF,STQKF,STQKF2,DQKF,STDQKF,STDQKF2,CNN,t] = unpackData(dataClass_rt);

%%
% plotData(BLACK,t)
% plotData(RED,t)
q_red = ang2quat(RED.xs(:,3),t);
q_black = ang2quat(BLACK.xs(:,3),t);
q = [0.2464         0         0    0.9692];
C = quat2Rotm(q','scalarFirst');
CNN.glob = rel2glob(q_red, CNN.q, CNN.x, [RED.x(:,1:2), 0*RED.x(:,1)], t);

rel = golb2rel(q_red, q_black, [BLACK.x(:,1:2), 0*BLACK.x(:,1)], [RED.x(:,1:2), 0*RED.x(:,1)], t);

%%
figure
plot(RED.xs(:,1),RED.xs(:,2),'r')
hold on
plot(BLACK.xs(:,1),BLACK.xs(:,2),'k')
plot(CNN.glob(:,5),CNN.glob(:,6),'b*')

% figure
% title('Rel Position')
% subplot(2,1,1)
% hold on
% grid on
% plot(t,CNN.x(:,1),'b*')
% plot(t,rel(:,5),'k')
% 
% subplot(2,1,2)
% hold on
% grid on
% plot(t,CNN.x(:,2),'b*')
% plot(t,rel(:,6),'k')
% 
% figure
% title('Rel Quaternion')
% subplot(2,1,1)
% hold on
% grid on
% plot(t,CNN.q(:,1),'b*')
% plot(t,rel(:,1),'k')
% 
% subplot(2,1,2)
% hold on
% grid on
% plot(t,CNN.q(:,4),'b*')
% plot(t,rel(:,4),'k')
figure
subplot(2,1,1)
hold on
grid on
plot(t,CNN.glob(:,5),'b*')
plot(t,BLACK.xs(:,1),'k')

subplot(2,1,2)
hold on
grid on
plot(t,CNN.glob(:,6),'b*')
plot(t,BLACK.xs(:,2),'k')

plot(t,QKF.x(:,2),'g')
plot(t,STQKF.x(:,2),'o')
plot(t,STQKF2.x(:,2),'m')

function rel = golb2rel(q_red, q_black, xb, xr, t)
 ang_off = 1.5*pi/180;
 H1 = [0 1 0;
      1 0 0;
      0 0 -1];

pos_off = [0*0.08; 0; 0];
R_off = C3(ang_off);
pos_off = R_off*pos_off;
q_off = rotm2Quat(R_off,'scalarFirst');

rel = zeros(length(t),7);
for i = 1:1:length(t)
    temp = xb(i,:)' - xr(i,:)' - pos_off;
    temp = H1*temp;
    q_red_adj = quatMultiply(q_off,q_red(i,:)','scalarFirst');
    q_red_inv = quatInv(q_red_adj,'scalarFirst');
    xrel = quatRotate(q_red_inv,temp,'scalarFirst');

    q_rel = quatMultiply(q_black(i,:)',q_red_inv,'scalarFirst');
    q_rel = smallQuat(q_rel,'scalarFirst');
    
    % ang = 148.22*pi/180;
    rel(i,:) = [q_rel', (H1*xrel)'];

    %% Test 
    % Rq = quat2Rotm(q_red_inv,'scalarFirst');
    % T = Rq*H1*Rq';
    % xrel
    
    % test = quatRotate(q_red(i,:)',T'*xrel,'scalarFirst') + xr(i,:)' + pos_off

    % H1*T*Rq*(xb(i,:)' - xr(i,:)' - pos_off)

end

end

function q = ang2quat(u,t)
q = zeros(length(t),4);

for i = 1:1:length(t)
    yaw = u(i,1);
    R = C3(yaw);

    q(i,:) = rotm2Quat(R,'scalarFirst');
    q(i,:) = smallQuat(q(i,:),'scalarFirst');
end
end

function y = rel2glob(q_red, q_vis, v, x, t)
y = zeros(length(t),7);

% H1 = [0 1 0;
%       1 0 0;
%       0 0 -1];
% 
% ang_off = 0*1.5*pi/180;
% R_off = C3(ang_off);
% q_off = rotm2Quat(R_off,'scalarFirst');

for i = 1:1:length(t)
    if isfinite(q_vis(i,:))
        q_black = quatMultiply(q_vis(i,:)',q_red(i,:)','scalarFirst');
        q_black = smallQuat(q_black,'scalarFirst');
    else
        q_black = NaN(4,1);
    end
    
    % q_red_adj = quatMultiply(q_off,q_red(i,:)','scalarFirst');
    % q_red_inv = quatInv(q_red,'scalarFirst');
    % Rq = quat2Rotm(q_red_inv,'scalarFirst');
    % T = H1*Rq*H1*Rq';

    % v(i,:) = (T'*(v(i,:)' + [0.07 0.05 0]'))';
    % v(i,:) = v(i,:)';
    temp = quatRotate(q_red(i,:)',v(i,:)','scalarFirst');
    temp = temp + x(i,:)';
    
    y(i,:) = [q_black', temp'];

end
end

function [q_red_out, q_vis_out, v_out, x_out] = rel2glob_p(q_red, rel, xr, ang_off, pos_off)
% rel2glob_prep  Undo the H1/offset steps of glob2rel so that rel2glob works unchanged.
%
% INPUTS:
%   q_red    [n×4]   red-frame quaternions
%   rel      [n×7]   relative states from glob2rel: [q_rel, x_rel_stored]
%   xr       [n×3]   red-frame positions used in glob2rel
%   ang_off  scalar  the same angle offset (in rad) as in your glob2rel
%   pos_off  [3×1]   the same raw pos_off vector as in glob2rel
%
% OUTPUTS (all n×?):
%   q_red_out  = q_red;           % pass through
%   q_vis_out  [n×4]  -> vision/global quaternion for rel2glob
%   v_out      [n×3]  -> “v” argument for rel2glob
%   x_out      [n×3]  -> “x” argument for rel2glob

  % -- build H1, R_off, q_off exactly as in glob2rel
  % H1 = [0 1 0;
  %       1 0 0;
  %       0 0 -1];
  % R_off = C3(ang_off);
  % pos_off = R_off*pos_off;  
  % q_off = rotm2Quat(R_off,'scalarFirst');

  N = size(rel,1);
  q_vis_out = zeros(N,4);
  v_out     = zeros(N,3);
  x_out     = zeros(N,3);
  q_red_out = q_red;

  for i = 1:N
    % split your stored rel
    q_rel         = rel(i,1:4)';       % 4×1
    x_rel_stored  = rel(i,5:7)';       % 3×1

    % invert H1 swap/inversion
    x_rel = H1 * x_rel_stored;         % 3×1

    % prepare the v input for rel2glob
    v_out(i,:) = x_rel';

    % recover “vision” quaternion so that
    %   q_black = q_vis*q_red  and  q_rel = q_black*inv(q_red_adj)
    % => q_vis = q_rel * inv(q_red_adj) * inv(q_red) = q_rel * q_off
    % q_vis = quatMultiply(q_rel, q_off, 'scalarFirst');
    q_vis_out(i,:) = q_vis';

    % rebuild the reference position with the same pos_off
    % because glob2rel did xb − xr − pos_off
    % so we want x = xr + pos_off for rel2glob’s x‑input
    x_out(i,:) = (xr(i,:)' + pos_off)';
  end
end
