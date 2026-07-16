function MPCdata = loadMPCData(dataClass, Phase2_End)

    if nargin < 2
        Phase2_End = 0;   % default: no trimming
    end

    %  Load time
    t_full = dataClass.Time_s.Data.';     % 1 × T_full
    T_full = length(t_full);

    %  Determine trim index
    if Phase2_End > 0
        idxStart = find(t_full > Phase2_End, 1, 'first');
        if isempty(idxStart)
            error("Phase2_End = %.3f occurs after final logged time (%.3f s).", ...
                   Phase2_End, t_full(end));
        end
    else
        idxStart = 1;   % no trimming
    end

    %  Load MPC solver results (t × 4) and trim rows
    Results_full = dataClass.MPC_results.Data;   % T_full × 4
    Results_trim = Results_full(idxStart:end, :);

    MPCdata.Results = spotSMPC.PostProcessing.zohMPCResults(Results_trim);


    %  Load MPC_z (t × 9N) and trim rows
    z_full = dataClass.MPC_z.Data;      % T_full × (9N)
    z_trim = z_full(idxStart:end, :);   % T_trim × (9N)

    [T_trim, L] = size(z_trim);

    % Number of prediction steps N
    if mod(L, 9) ~= 0
        error('loadMPCData: Length of each row of MPC_z (%d) is not divisible by 9.', L);
    end

    N = L / 9;

    %  Unvectorize prediction horizon for each time step
    % First 3N columns = control inputs
    % Last  6N columns = states
    u_vec = z_trim(:, 1:3*N);     % T_trim × (3N)
    x_vec = z_trim(:, 3*N+1:end); % T_trim × (6N)

    % Preallocate arrays: (3 × N × T_trim), (6 × N × T_trim)
    u = zeros(3, N, T_trim);
    x = zeros(6, N, T_trim);

    for i = 1:T_trim
        u(:,:,i) = reshape(u_vec(i,:), 3, N);   % (3 × N)
        x(:,:,i) = reshape(x_vec(i,:), 6, N);   % (6 × N)
    end

    MPCdata.optimalInputs = u;     % 3 × N × T_trim
    MPCdata.optimalStates = x;     % 6 × N × T_trim

    % Also return trimmed time for convenience
    MPCdata.Time = t_full(idxStart:end);

end
