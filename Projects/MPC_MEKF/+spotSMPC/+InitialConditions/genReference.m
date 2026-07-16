% genReference  Build stacked MPC reference vectors with “look‐at” angle
%
% Inputs:
%   xTstack       6×N target-state over horizon
%   DockPort      2×N inertial docking-port positions
%   DockingRadius 2×N inertial offset vectors (r_I)
%   m             control dimension
%   n             state dimension (here 6)
%   N             horizon length
%   dt            time step between columns of xTstack
%
% Outputs:
%   x_ref         (n*N)×1 column vector [x_ref(:,1); …; x_ref(:,N)]
%   u_ref         (m*N)×1 column vector (all zeros)
%
function [x_ref, u_ref] = genReference(z0, xTstack, DockPort, DockingRadius, m, n, N, dt, Camera_Offset)

    % Preallocate
    x_ref = zeros(n * N, 1);
    u_ref = zeros(m * N, 1);

    % Extract chaser/camera states from z0 (assumes same layout as before)
    xCStack = reshape(z0(m*N+1:end), n, N);  % n x N

    % body-frame camera position offset (2x1) and camera yaw offset (scalar)
    o_b = Camera_Offset(1:2);        % body-fixed translation of camera
    cam_yaw_offset = Camera_Offset(3);  % camera orientation relative to body

    % allocate phi (unwrapped)
    phi = zeros(1, N);

    for k = 1:N
        % chaser pose at step k
        p_C = xCStack(1:2, k);      % [x; y]
        theta_C = xCStack(3, k);    % chaser yaw

        % rotate body offset into inertial: o_I = R(theta_C) * o_b
        R_theta = [cos(theta_C), -sin(theta_C);
                   sin(theta_C),  cos(theta_C)];
        o_I = R_theta * o_b;

        % camera position and orientation (inertial)
        p_cam = p_C + o_I;

        % vector from camera to target (in inertial frame)
        p_T = xTstack(1:2, k);
        s = p_T - p_cam;    % [sx; sy]

        % angle_to_target in inertial frame
        angle_to_target = atan2(s(2), s(1));   % global angle from camera -> target

        % raw desired chaser heading so camera points at target:
        raw_phi = angle_to_target - cam_yaw_offset;  % principal value in (-pi,pi]

        if k == 1
            % For the first step, choose the branch nearest the current chaser heading
            % so the reference starts continuous with vehicle heading.
            phi(k) = raw_phi + 2*pi * round((theta_C - raw_phi)/(2*pi));
        else
            % For later steps, choose the branch nearest the previous phi to keep continuity.
            phi(k) = raw_phi + 2*pi * round((phi(k-1) - raw_phi)/(2*pi));
        end
    end

    % 2) Numeric derivative for ω_ref (use unwrapped differences)
    omega_ref = zeros(1,N);
    for k = 1:N-1
        dphi = phi(k+1) - phi(k);     % unwrapped difference -> no wrap needed
        omega_ref(k) = dphi / dt;
    end
    omega_ref(N) = omega_ref(N-1);  % copy last slope (or use backward diff)

    % 3) Build the stacked x_ref
    for k = 1:N
        ix = (k-1)*n + (1:n);  % indices into big vector

        % Position of the port
        x_ref(ix(1:2)) = DockPort(:, k);

        % Heading: look‐at angle φ_k (unwrapped)
        x_ref(ix(3)) = phi(k);

        % Linear velocity (same as before)
        v_t     = xTstack(4:5, k);
        omega_t = xTstack(6,   k);
        r_I     = DockingRadius(:, k);
        x_ref(ix(4:5)) = v_t + omega_t * [-r_I(2); r_I(1)];

        % Angular velocity: the newly computed look‐at rate
        x_ref(ix(6)) = omega_ref(k);

        % Control ref: zero
        iu = (k-1)*m + (1:m);
        u_ref(iu) = zeros(m,1);
    end
end
