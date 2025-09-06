function [RED,BLACK,RKF,STRKF,STRKF2,QKF,STQKF,STQKF2,DQKF,STDQKF,STDQKF2,CNN,t] = unpackData(data)
IRED = 0.1982;
mRED = 11.2970;
IBLACK = 0.1996;
mBLACK = 11.3620;
%% Extract Black data
t = data.Time_s.Data;
% Phase Space
BLACK.x = [data.BLACK.Px_m.Data, ...
          data.BLACK.Py_m.Data, ...
          data.BLACK.Rz_rad.Data, ...
          data.BLACK.Vx_mpers.Data, ...
          data.BLACK.Vy_mpers.Data, ...
          data.BLACK.RzD_radpers.Data];
% Filter
BLACK.xest = [data.BLACK_Filter.Px_m.Data, ...
             data.BLACK_Filter.Py_m.Data, ...
             data.BLACK_Filter.Rz_rad.Data, ...
             data.BLACK_Filter.Vx_mpers.Data, ...
             data.BLACK_Filter.Vy_mpers.Data, ...
             data.BLACK_Filter.RzD_radpers.Data];
% extract only the first 36 fields into BLACK.P
tmp       = struct2cell(data.BLACK_Filter);
tmp       = tmp(7:42).';
BLACK.P = buildP(tmp);
% black desired path
BLACK.Path = [data.BLACK.Px_Path_m.Data, ...
             data.BLACK.Py_Path_m.Data...
             data.BLACK.Rz_Path_rad.Data];
% Black demanded force
BLACK.F = [data.BLACK.Fx_N.Data,...
          data.BLACK.Fy_N.Data, ...
          data.BLACK.Tz_Nm.Data];
% BLACK CTL input
try
BLACK.CTL = data.CTL.CTL_Input.Data;
catch
% BLACK.CTL = [data.UnnamedSignal_1.Data, ...
%              data.UnnamedSignal_2.Data, ...
%              data.UnnamedSignal_3.Data, ...
%              data.UnnamedSignal_4.Data, ...
%              data.UnnamedSignal_5.Data, ...
%              data.UnnamedSignal_6.Data];
BLACK.CTL = zeros(length(t),6);
end

% Get components of force
A = [zeros(3), eye(3); zeros(3,6)];
B = [zeros(3); diag([1/mBLACK; 1/mBLACK; 1/IBLACK])];
sys = ss(A,B,eye(6), zeros(6,3));
Q = diag([1;1;0.05;10;10;1]);
R = diag([6;6;6]);
N = 0;
Kblack = -1*lqr(sys,Q,R,N);
fcomp = [BLACK.CTL(:,1)*Kblack(1,1), ...
        BLACK.CTL(:,2)*Kblack(2,2), ...
        BLACK.CTL(:,3)*Kblack(3,3), ...
        BLACK.CTL(:,4)*Kblack(1,4), ...
        BLACK.CTL(:,5)*Kblack(2,5), ...
        BLACK.CTL(:,6)*Kblack(3,6)];
BLACK.Fcomp = fcomp;
% Black force saturated
BLACK.Fsat = [data.BLACK.Fx_Sat_N.Data,...
          data.BLACK.Fy_Sat_N.Data, ...
          data.BLACK.Tz_Sat_Nm.Data];
% Smoother
[xs, Ps] = RTS(BLACK.xest', BLACK.P, BLACK.Fsat', mBLACK, IBLACK);
BLACK.xs = xs';
BLACK.Ps = Ps;
%% Extract Black data
RED.x = [data.RED.Px_m.Data, ...
          data.RED.Py_m.Data, ...
          data.RED.Rz_rad.Data, ...
          data.RED.Vx_mpers.Data, ...
          data.RED.Vy_mpers.Data, ...
          data.RED.RzD_radpers.Data];
RED.xest = [data.RED_Filter.Px_m.Data, ...
             data.RED_Filter.Py_m.Data, ...
             data.RED_Filter.Rz_rad.Data, ...
             data.RED_Filter.Vx_mpers.Data, ...
             data.RED_Filter.Vy_mpers.Data, ...
             data.RED_Filter.RzD_radpers.Data];
% extract only the first 36 fields into BLACK.P
tmp       = struct2cell(data.RED_Filter);
tmp       = tmp(7:42).';
RED.P = buildP(tmp);
% black desired path
RED.Path = [data.RED.Px_Path_m.Data, ...
             data.RED.Py_Path_m.Data...
             data.RED.Rz_Path_rad.Data];
% Black demanded force
RED.F = [data.RED.Fx_N.Data,...
          data.RED.Fy_N.Data, ...
          data.RED.Tz_Nm.Data];
% Black force saturated
RED.Fsat = [data.RED.Fx_Sat_N.Data,...
          data.RED.Fy_Sat_N.Data, ...
          data.RED.Tz_Sat_Nm.Data];
% Smoother
[xs, Ps] = RTS(RED.xest', RED.P, RED.Fsat', mRED, IRED);
RED.xs = xs';
RED.Ps = Ps;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Kalman Filters
% RMEKF
RKF.dt = data.RMEKF.CompTime.Data;
RKF.x = data.RMEKF.State.Data;
RKF.err = data.RMEKF.Error.Data;
RKF.NIS = data.RMEKF.NIS.Data;
RKF.P = buildPnc(data.RMEKF.Cov.Data);
% STRMEKF
STRKF.dt = data.STRMEKF.CompTime.Data;
STRKF.x = data.STRMEKF.State.Data;
STRKF.err = data.STRMEKF.Error.Data;
STRKF.NIS = data.STRMEKF.NIS.Data;
STRKF.P = buildPnc(data.STRMEKF.Cov.Data);
% STRMEKF2
STRKF2.dt = data.STRMEKF2.CompTime.Data;
STRKF2.x = data.STRMEKF2.State.Data;
STRKF2.err = data.STRMEKF2.Error.Data;
STRKF2.NIS = data.STRMEKF2.NIS.Data;
STRKF2.P = buildPnc(data.STRMEKF2.Cov.Data);
% QKF
QKF.dt = data.QMEKF.CompTime.Data;
QKF.x = data.QMEKF.State.Data;
QKF.err = data.QMEKF.Error.Data;
QKF.NIS = data.QMEKF.NIS.Data;
QKF.P = buildPnc(data.QMEKF.Cov.Data);
% STQKF
STQKF.dt = data.STQMEKF.CompTime.Data;
STQKF.x = data.STQMEKF.State.Data;
STQKF.err = data.STQMEKF.Error.Data;
STQKF.NIS = data.STQMEKF.NIS.Data;
STQKF.P = buildPnc(data.STQMEKF.Cov.Data);
% STQKF2
STQKF2.dt = data.STQMEKF2.CompTime.Data;
STQKF2.x = data.STQMEKF2.State.Data;
STQKF2.err = data.STQMEKF2.Error.Data;
STQKF2.NIS = data.STQMEKF2.NIS.Data;
STQKF2.P = buildPnc(data.STQMEKF2.Cov.Data);
% DQKF
DQKF.dt = data.DQMEKF.CompTime.Data;
DQKF.x = data.DQMEKF.State.Data;
DQKF.err = data.DQMEKF.Error.Data;
DQKF.NIS = data.DQMEKF.NIS.Data;
DQKF.P = buildPnc(data.DQMEKF.Cov.Data);
% STDQKF
STDQKF.dt = data.STDQMEKF.CompTime.Data;
STDQKF.x = data.STDQMEKF.State.Data;
STDQKF.err = data.STDQMEKF.Error.Data;
STDQKF.NIS = data.STDQMEKF.NIS.Data;
STDQKF.P = buildPnc(data.STDQMEKF.Cov.Data);
% STDQKF2
STDQKF2.dt = data.STDQMEKF2.CompTime.Data;
STDQKF2.x = data.STDQMEKF2.State.Data;
STDQKF2.err = data.STDQMEKF2.Error.Data;
STDQKF2.NIS = data.STDQMEKF2.NIS.Data;
STDQKF2.P = buildPnc(data.STDQMEKF2.Cov.Data);
%% CNN
CNN.Conf = data.CNN.Confidence.Data;
CNN.x = data.CNN.State.Data;
CNN.q = data.CNN.Quat.Data;
CNN = turn2nan(CNN,t);
%% Time
t = data.Time_s.Data;

%% Functions
function CNN = turn2nan(CNN,t)
    for i = 1:1:t
        if CNN.Conf(i,1) == -1
            CNN.Conf(i,1) = nan(1,1);
        end
        if sum(CNN.x(i,:)) == -3
            CNN.x(i,:) = nan(1,3);
        end
        if sum(CNN.q(i,:)) == -4
            CNN.q(i,:) = nan(1,4);
        end
    end
end
function P = buildP(data)
    %% Preallocate Space
    n = sqrt(length(data));
    t = length(data{1}.Data);
    
    P = zeros(n,n,t);
    for i = 1:t
        m = -1;
        for j = 1:n
            for k = 1:n
                P(j,k,i) = data{j+k+m}.Data(i);
            end
            m = m + 5;
        end
    end
end
function P = buildPnc(data)
    %% BUILDP FROM NON‐CELLED LOGGER
    % data: t-by-(n^2) array, where each row i is the flattened P(:,:,i)
    % P:    n-by-n-by-t covariance stack
    [t, nn] = size(data);
    n = sqrt(nn);
    if n~=floor(n)
        error('buildPnc: input must have n^2 columns.');
    end
    P = zeros(n, n, t);
    for i = 1:t
        % reshape row i into an n×n matrix, using MATLAB's column-major order
        P(:,:,i) = reshape(data(i,:), n, n);
    end
end
function [xs, Ps] = RTS(x, P, u, m, I)
%% --- RTS SMOOTHER WITH FORWARD PASS FOR LINEAR KF ----------------------
% Inputs:
%   x  - predicted/measured state trajectory: nx-by-N matrix
%   P  - filtered covariance trajectory: n-by-n-by-N array
%   u  - control input sequence: p-by-N matrix (e.g. [Fx; Fy; tau])
%   m  - mass of chaser (scalar)
%   I  - moment of inertia (scalar)
% Outputs:
%   xs - smoothed state trajectory: nx-by-N matrix
%   Ps - smoothed covariance trajectory: n-by-n-by-N array
% Dimensions and parameters
[nx, N] = size(x);
dt = 0.05;
% State transition and input matrices
F = [eye(3), dt*eye(3);
     zeros(3), eye(3)];          % 6x6
M = diag([1/m; 1/m; 1/I]);
G = [ (dt^2/2)*M;
      dt*M ];                   % 6x3
% Process noise covariance in input space
Q = blkdiag(0.0001*eye(2), 0.00001); % 3x3
% Allocate arrays for predicted trajectories
xk = zeros(nx, N);
Pk = zeros(nx, nx, N);
% Initialize forward pass at time k=1
xk(:,1) = x(:,1);
Pk(:,:,1) = P(:,:,1);
% Forward propagation
for k = 2:N
    % Predict state and covariance
    xk(:,k) = F * x(:,k-1) + G * u(:,k-1);
    Pk(:,:,k) = F * P(:,:,k-1) * F' + G * Q * G';
end
% figure
% hold on
% plot(x(1,:),'r','MarkerSize',3)
% plot(xk(1,:), 'b')
% Initialize backward smoother at final step
xs = zeros(nx, N);
Ps = zeros(nx, nx, N);
xs(:,N) = x(:,N);
Ps(:,:,N) = P(:,:,N);
% Backward pass
for k = (N-1):-1:1
    % Compute smoothing gain
    Ck = P(:,:,k) * F' / Pk(:,:,k+1);
    % State smoothing
    xs(:,k) = x(:,k) + Ck*( xs(:,k+1) - xk(:,k+1) );
    % Covariance smoothing (optional)
    Ps(:,:,k) = P(:,:,k) + Ck*( Ps(:,:,k+1) - Pk(:,:,k+1) )*Ck';
end
end
end