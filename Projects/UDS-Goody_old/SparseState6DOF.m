classdef SparseState6DOF < handle
    %SPARSESTATE6DOF Class to hold and process 3-DOF data as a sparse 6-DOF system
    %   Stores time, position, velocity (optional), Euler angles, rotation matrices,
    %   quaternions, and dual quaternions.

    properties
        time            % t-by-1 time vector
        pos             % t-by-3 position [x y z]
        vel             % t-by-3 velocity [vx vy vz] (empty if no vel)
        euler           % t-by-3 Euler angles [roll pitch yaw]
        R               % 3x3xt array of rotation matrices
        q               % t-by-4 quaternion [qw qx qy qz]
        dq              % t-by-8 dual quaternion [qr,qd]
        stateSparse     % t-by-12 sparse matrix [x y z vx vy vz roll pitch yaw droll dpitch dyaw]
        hasVel logical  % flag indicating if velocity was provided
    end

    methods
        function obj = SparseState6DOF(state3, time, hasVel)
            % Constructor
            % state3: t-by-6 [x y yaw dx dy dyaw]
            % time:  t-by-1
            % hasVel: (optional) true if velocity columns present (default true)

            if nargin < 3 || isempty(hasVel)
                obj.hasVel = true;
            else
                obj.hasVel = hasVel;
            end
            obj.time = time(:);
            t = numel(obj.time);

            % Parse input 3-DOF
            x   = state3(:,1);
            y   = state3(:,2);
            yaw = state3(:,3);
            if obj.hasVel
                dx   = state3(:,4);
                dy   = state3(:,5);
                dyaw = state3(:,6);
            else
                dx   = zeros(t,1);
                dy   = zeros(t,1);
                dyaw = zeros(t,1);
            end

            % Assemble full 6-DOF sparse state
            % Columns: [x y z vx vy vz roll pitch yaw droll dpitch dyaw]
            z      = zeros(t,1);
            roll   = zeros(t,1);
            pitch  = zeros(t,1);
            dpitch = zeros(t,1);
            droll  = zeros(t,1);

            dataMat = [x y z dx dy dz roll pitch yaw droll dpitch dyaw];
            % Note: dz missing, define dz
            dz = zeros(t,1);
            dataMat(:,6) = dz;  % overwrite vz

            obj.stateSparse = sparse(dataMat);

            % Store separate properties
            obj.pos   = [x y z];
            if obj.hasVel
                obj.vel = [dx dy dz];
            else
                obj.vel = [];
            end
            obj.euler = [roll pitch yaw];

            % Initialize R, q, dq as empty, require fill()
            obj.R  = [];
            obj.q  = [];
            obj.dq = [];
        end

        function fill(obj)
            % FILL  Compute rotation matrices, quaternions, and dual quaternions
            t = numel(obj.time);
            obj.R = zeros(3,3,t);
            obj.q = zeros(t,4);
            obj.dq = zeros(t,8);

            for k = 1:t
                % Euler angles (roll=pitch=0, yaw)
                yaw = obj.euler(k,3);

                % Rotation matrix about z-axis
                Cz = [cos(yaw) -sin(yaw) 0; sin(yaw) cos(yaw) 0; 0 0 1];
                obj.R(:,:,k) = Cz;

                % Quaternion [qw qx qy qz]
                qw = cos(yaw/2);
                qz = sin(yaw/2);
                qq = [qw 0 0 qz];
                obj.q(k,:) = qq;

                % Dual quaternion
                % real part qr = qq, dual part qd = 0.5*[0 p] * qq
                p = [0 obj.pos(k,:)];
                qd = 0.5 * quatmultiply(p, qq);
                obj.dq(k,:) = [qr_from_vec(qq) qd];
            end
        end

        function shrink(obj)
            % SHRINK  Remove rows where any entry is NaN
            idx = all(~isnan(obj.stateSparse),2);
            obj.time = obj.time(idx);
            obj.stateSparse = obj.stateSparse(idx,:);
            obj.pos = obj.pos(idx,:);
            if obj.hasVel
                obj.vel = obj.vel(idx,:);
            end
            obj.euler = obj.euler(idx,:);
            if ~isempty(obj.R)
                obj.R = obj.R(:,:,idx);
            end
            if ~isempty(obj.q)
                obj.q = obj.q(idx,:);
            end
            if ~isempty(obj.dq)
                obj.dq = obj.dq(idx,:);
            end
        end

        function trim(obj, frontIdx, backIdx)
            % TRIM  Trim data by indices
            %   trim(f) removes first f-1 entries
            %   trim(f,b) keeps entries f through b
            if nargin < 3
                % only front provided
                idx = frontIdx:numel(obj.time);
            else
                idx = frontIdx:backIdx;
            end
            obj.time = obj.time(idx);
            obj.stateSparse = obj.stateSparse(idx,:);
            obj.pos = obj.pos(idx,:);
            if obj.hasVel
                obj.vel = obj.vel(idx,:);
            end
            obj.euler = obj.euler(idx,:);
            if ~isempty(obj.R)
                obj.R = obj.R(:,:,idx);
            end
            if ~isempty(obj.q)
                obj.q = obj.q(idx,:);
            end
            if ~isempty(obj.dq)
                obj.dq = obj.dq(idx,:);
            end
        end
    end
end

% Helper to extract quaternion from vector if needed
function qr = qr_from_vec(q)
    % input q is [qw qx qy qz]
    qr = q;  % placeholder, user can define differently
end
