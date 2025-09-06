function [x_new, F] = prop(x, dt, Fargs)
    %% Extract components from state vector x
    q = x(1:4);                % Quaternion (qw, qx, qy, qz)
    omega = x(5:7);            % Angular velocity (rad/s)
    position = x(8:10);        % Position (x, y, z)
    velocity = x(11:13);       % Velocity (vx, vy, vz)
    
    %% Time Update
    % Propagate quaternion using the Hamilton product method
    omega_norm = norm(omega); % Magnitude of angular velocity

    if omega_norm > 1e-10  % Avoid division by zero
        theta = omega_norm * dt / 2; % Half-angle
        delta_q = [cos(theta);
                   sin(theta) * (omega / omega_norm)]; % Small rotation quaternion
    else
        delta_q = [1; 0; 0; 0]; % No rotation if omega is zero
    end

    % Quaternion multiplication: q_new = delta_q ⊗ q
    q_new = quatMultiply(delta_q, q,'scalarFirst');

    % Propagate position and velocity
    position_new = position + velocity * dt;

    %% Return new state vector
    x_new = [q_new; omega; position_new; velocity];

    %% Compute state transition matrix (F)
    AM = [-skew(omega)./2 , eye(3), zeros(3);
          zeros(3), zeros(3), 0.2*ones(3);
          zeros(3), zeros(3), zeros(3)];

    Phi_m = expm(AM.*dt);

    F = [Phi_m(1:3,1:6), zeros(3), zeros(3);
         zeros(3), eye(3), zeros(3), zeros(3);
         zeros(3), zeros(3), eye(3), dt*eye(3);
         zeros(3), zeros(3), zeros(3), eye(3)];

end