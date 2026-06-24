function spotFilterData = genFilterData(dataClass, navOpts, Phase2_End)
    if nargin < 3
        Phase2_End = 0;
    end

    robots = ["RED", "BLACK", "BLUE"];
    PS_states  = struct();
    Est_states = struct();
    
    t_full = dataClass.Time_s.Data.';       % 1 x T_full
    dt     = diff(t_full);
    T_full = length(t_full);

    if Phase2_End > 0
        % Find first sample strictly AFTER Phase2_End
        idxStart = find(t_full > Phase2_End, 1, 'first');

        if isempty(idxStart)
            error("Phase2_End = %.3f occurs after final logged time (%.3f s).", ...
                   Phase2_End, t_full(end));
        end
    else
        idxStart = 1;     % no trimming
    end

    Time.t = t_full(idxStart:end);
    Time.dt = diff(Time.t);    % length = T_trim-1
    Q = navOpts.kfChaser.Q;
    
    % Store trimming index for later reuse in robot loops
    idx = idxStart;

    stateFields_raw = ["Px_m_raw",     "Py_m_raw",     "Rz_rad_raw", ...
                       "Vx_mpers_raw", "Vy_mpers_raw", "RzD_radpers_raw", ...
                       "Ax_mpers2_raw","Ay_mpers2_raw","RzDD_radpers2_raw"];
    
    stateFields_est = ["Px_m",     "Py_m",     "Rz_rad", ...
                       "Vx_mpers", "Vy_mpers", "RzD_radpers", ...
                       "Ax_mpers2","Ay_mpers2","RzDD_radpers2"];
    
    stateFields_imu = ["IMU_Ax_mpers2", "IMU_Ay_mpers2", "IMU_Gz_radpers"];

    inputFields = ["Fx_Sat_N", "Fy_Sat_N", "Tz_Sat_Nm"];
    
    for r = 1:length(robots)
        robot = robots(r);
    
        % Preallocate
        n = length(stateFields_raw);
        m = 6;
        u = length(inputFields);
        T = length(Time.t);
        l = length(stateFields_imu);
        PS_mat  = zeros(n, T);
        inputs  = zeros(u, T);
        IMU_mat = zeros(l, T);

        % Fill each 9×T matrix
        for i = 1:n
            rawVec = dataClass.(robot + "_" + stateFields_raw(i)).Data.';
            PS_mat(i,:) = rawVec(idx:end);
        end

        % Fill IMU
        for i = 1:l
            rawVec = dataClass.(robot + "_" + stateFields_imu(i)).Data.';
            IMU_mat(i,:) = rawVec(idx:end);
        end
    
        % log saturated inputs
        for i = 1:u
            uVec = dataClass.(robot + "_" + inputFields(i)).Data.';
            inputs(i,:) = uVec(idx:end); 
        end
        
        % Store in struct
        PS_states.(robot)   = PS_mat;
        IMU.(robot)         = IMU_mat;
        CTL.(robot)         = inputs;
    end

    %% Run Simulation for filter test
    xRED_in     = [Time.t', PS_states.RED'];
    xBLACK_in   = [Time.t', PS_states.BLACK'];
    xBLUE_in    = [Time.t', PS_states.BLUE'];

    mRED_in     = [Time.t', IMU.RED'];
    mBLACK_in   = [Time.t', IMU.BLACK'];
    mBLUE_in    = [Time.t', IMU.BLUE'];

    uRED_in     = [Time.t', CTL.RED'];
    uBLACK_in   = [Time.t', CTL.BLACK'];
    uBLUE_in    = [Time.t', CTL.BLUE'];
    
    assignin('base','xRED_in',    xRED_in);
    assignin('base','xBLACK_in',  xBLACK_in);
    assignin('base','xBLUE_in',   xBLUE_in);

    assignin('base','mRED_in',   mRED_in);
    assignin('base','mBLACK_in', mBLACK_in);
    assignin('base','mBLUE_in',  mBLUE_in);

    assignin('base','uRED_in',   uRED_in);
    assignin('base','uBLACK_in', uBLACK_in);
    assignin('base','uBLUE_in',  uBLUE_in);


    simData = sim("+spotKF/+PostProcessing/genData.slx");


    %% Use Sim Data to complete spotFilterData
      for r = 1:length(robots)      
        % Determine number of time steps from P11_PS
        rawCov = dataClass.(robot + "_P11_PS").Data;  
        T_trim = length(rawCov(idx:end));
        C = zeros(m, m, T_trim);
        
        for j = 1:m
            for k = 1:m
                field = robot + "_P" + j + k + "_PS";
                covVec = dataClass.(field).Data(:);
                C(j,k,:) = covVec(idx:end);
            end
        end

    
        Cov.(robot) = C;  % 6×6×T
    
        %% Generate smoothed states
        % Generate Predicted measurements
        xk = Est_mat;
        Pk = C; 
    
        for k = 1:1:idx-T_full
           [xk(1:6,k),F,G] = spotKF.Dynamics.Euler1(Est_mat(1:6,k), dt(idx+k-1), inputs(:,k), navOpts.params);
            Pk(:,:,k) = F*C(:,:,k-1)*F' + G*Q*G';
        end
    
        [x_est_s, p_est_s] = spotKF.PostProcessing.RTS_Loop(Est_mat(1:6,:), C, xk(1:6,:), Pk, dt(idx:end), inputs, @spotKF.Dynamics.Euler1, navOpts.params);
    
        % Store
        pred_states.(robot) = xk;
        Cov_pred.(robot)    = Pk;
        smth_states.(robot) = x_est_s;
        Cov_smth.(robot)    = p_est_s;
    end

    %% Smoothed acceleration
    %% -------------------
    % Compute model-consistent, smoothed accelerations (Tikhonov fusion)
    % Requires: x_est_s (6 x T) from RTS smoother, inputs (3 x T), Time.t (1 x T), dt (1 x T-1)
    % Produces: acc_smooth (3 x T) where rows are [Ax; Ay; RzDD]
    %% -------------------
    
    % Parameters
    m = navOpts.params.m;
    I = navOpts.params.I;
    lambda = 1e-2;   % weight for input prior (a ~= u/m). Increase to trust input more.
    mu     = 1e-2;   % smoothing (second-difference) weight. Increase to make a smoother.
    % Note: these are starting values; tune by inspecting residuals/plots.
    
    T = length(Time.t);
    if T < 2
        acc_smooth = zeros(3,T);
    else
        % smoothed velocities from RTS: assume x_est_s has [px;py;rz;vx;vy;rzD]
        vx_s = x_est_s(4,:).';  % T x 1
        vy_s = x_est_s(5,:).';
        wz_s = x_est_s(6,:).';   % angular rate (for rotational accel below)
        dtv  = Time.dt(:);      % (T-1) x 1
    
        % interior length (we solve for a_1..a_{T-1})
        N = T-1;
    
        % discrete difference of velocities: dv = v_{k+1} - v_k  (N x 1)
        dvx = vx_s(2:end) - vx_s(1:end-1);
        dvy = vy_s(2:end) - vy_s(1:end-1);
        dwz = wz_s(2:end) - wz_s(1:end-1);
    
        % Input-derived acceleration a_interior = u(:,1:N)/m
        % map inputs: inputs rows correspond to Fx_Sat_N, Fy_Sat_N, Tz_Sat_Nm
        a_in_x = inputs(1,1:N).' ./ m;   % N x 1
        a_in_y = inputs(2,1:N).' ./ m;
        a_in_w = inputs(3,1:N).' ./ I;   % for rotational accel approximate (torque/moment) — user may want different scaling
    
        % Build diagonal D = diag(dtv)  (N x N)
        D = spdiags(dtv, 0, N, N);   % sparse diag
    
        % Build second-difference smoothing operator L ( (N-2) x N )
        if N >= 3
            e = ones(N,1);
            L = spdiags([e -2*e e], -1:1, N-2, N);
        else
            L = sparse(0,N);  % no smoothing constraint if too short
        end
    
        % Left-hand side: (D'*D + lambda*I + mu*L'*L)
        A = D'*D + lambda * speye(N) + mu * (L' * L);
    
        % RHS: D' * dv + lambda * a_in
        bx = D' * dvx + lambda * a_in_x;
        by = D' * dvy + lambda * a_in_y;
        bw = D' * dwz + lambda * a_in_w;
    
        % Solve (symmetric positive definite) -> use backslash
        a_x_interior = A \ bx;
        a_y_interior = A \ by;
        a_w_interior = A \ bw;
    
        % Compose full-length acceleration vectors of length T:
        % set last element equal to last solved interior (simple padding)
        acc_x = zeros(T,1);
        acc_y = zeros(T,1);
        acc_w = zeros(T,1);
    
        acc_x(1:N) = a_x_interior;
        acc_y(1:N) = a_y_interior;
        acc_w(1:N) = a_w_interior;
    
        % pad last sample (keep same as last solved interior)
        acc_x(T) = a_x_interior(end);
        acc_y(T) = a_y_interior(end);
        acc_w(T) = a_w_interior(end);
    
        acc_smooth = [acc_x.'; acc_y.'; acc_w.'];  % 3 x T
    end
    
    % Append these accelerations to the smoothed state (to create 9xT)
    smoothed_full = [ x_est_s ; acc_smooth];
    smth_states.(robot) = smoothed_full;


    %% Function Output
    spotFilterData.smoothed_States  = smth_states;
    spotFilterData.smoothed_Cov     = Cov_smth;
    spotFilterData.predicted_States = pred_states;
    spotFilterData.predicted_Cov    = Cov_pred;
    spotFilterData.estimated_States = Est_states;
    spotFilterData.estimated_Cov    = Cov;
    spotFilterData.measurements     = PS_states;
    spotFilterData.CTL              = CTL;
    spotFilterData.IMU              = IMU;
    spotFilterData.Time             = Time;
end