function [x_pred, Phi] = prop(x, dt, Fargs)
%% Time Propagation (Prediction)
% Extract current pose (dual quaternion) and biases:
q_current = [x(1:4), x(5:8)]; % 4x2 matrix: col1 = q_r, col2 = q_d
b_omega = x(9:11); 
b_v     = x(12:14);

% In the absence of velocity measurements, the effective twist is:
w_eff = -b_omega; % effective angular velocity
v_eff = -b_v;     % effective linear velocity

% Propagate the pose using the Cayley transform:
%   q_pred = q_current ⊗ cay( (dt/4)*[w_eff, v_eff] )
dq_update = cay(dt * w_eff / 4, dt * v_eff / 4, 'scalarFirst');
q_pred = dqMultiply(q_current, dq_update, 'scalarFirst');

% Predicted state: update pose; biases remain unchanged
x_pred = x; 
x_pred(1:8) = [q_pred(:,1); q_pred(:,2)];

%% Propagation Jacobian

F = [ skew(b_omega),        zeros(3),   -0.5*eye(3), zeros(3);
      skew(b_v),         skew(b_omega), zeros(3),   -0.5*eye(3);
      zeros(3,3),         zeros(3),     zeros(3),    zeros(3);
      zeros(3,3),         zeros(3),     zeros(3),    zeros(3) ];
  
Phi = eye(12) + dt * F;   % Euler discretization

end