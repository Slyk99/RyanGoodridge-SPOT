function [J, G] = MPCcost(z, refTraj, params, n, N, m, M)
    % q  = jointAngles;
    % p  = endEffector;
    % v  = endEffectorNormal;
    % x  = basePose;
    % u  = Control;
    % du = Controldiff;

    %% Separate Data
    U  = z(1:N*m,1);
    zq = z(N*m + 1:end, 1);
    zq = reshape(zq,12,N);

    % Preallocate
    x   = zeros(6*N,1);
    q   = zeros(6*N,1);
    pee = zeros(2*N,1);
    v   = zeros(2*N,1);

    %% Main Loop
    for i = 1:1:N
        [xi, qi, ~, ~, ~, peei, vi] = ForwardKin(zq(:,i), params);


    end

    %% Cost Function
    % Include rates in these variables
    q  = jointAngles;
    p  = endEffector;
    v  = endEffectorNormal;
    x  = basePose;
    u  = Control;
    du = Controldiff;
    normal = DockingPortNormal;

    % J          = J_task                      +J_align              + J_pose                     + J_effort + J_smooth                    + J_jerk 
    % J          = (p - p_ref)'*Q*(p - p_ref)  + w*(1 - v'*normal)^2 + (x - x_ref)'*B*(x -x_ref)  + u'*R*u   + (q - q_ref)'*S*(q - q_ref)  + (Delta u)'*W*(Delta u)
    % J_terminal = (p - p_ref)'*PQ*(p - p_ref) + Pw*(1 - v'*normal)^2 +(x - x_ref)'*PB*(x -x_ref) + u'*PR*u  + (q - q_ref)'*PS*(q - q_ref) + (Delta u)'*PW*(Delta u)
    % Derivative references can be 0 or derived from some optimal trajectory
    % xyz desired position weight and angle desired position weight should be zeros unless I really need the gradient for convexity 
end