function [x_k, Rot_k, F] = prop(x, Rot, dt, Fargs)
% Propagation (prediction) function.
%
% Inputs:
%   x    - non-attitude state (9x1): [position; velocity; angular velocity]
%   Rot  - current attitude estimate (3x3)
%   dt   - time step
%   Fargs- additional parameters (here, Fargs.m is used only for bookkeeping)
%
% Outputs:
%   x_k  - propagated non-attitude state (9x1)
%   Rot_k- propagated attitude estimate (3x3)
%   F    - state transition Jacobian (12x12) for the full error state 
%          (error state = [attitude error; x error])
%   G    - (not used)
    
    % Extract angular velocity from x (assumed to be in indices 7:9)
    w = x(7:9);
    % Propagate attitude using the exponential map (more accurate than a first-order Euler)
    Rot_k = expm(skew(w)*dt) * Rot;
    
    % Propagate the non-attitude state:
    %   Position is updated by velocity; velocity and angular velocity are assumed constant.
    x_k = x;
    x_k(1:3) = x(1:3) + dt * x(4:6);
    
    % Build the full (error-state) state transition matrix F.
    F = [ eye(3) + skew(w)*dt, zeros(3,6), eye(3)*dt;
        zeros(3), eye(3), dt*eye(3), zeros(3);
            zeros(3,6), eye(3),    zeros(3);
            zeros(3,6), zeros(3),  eye(3)];
end
