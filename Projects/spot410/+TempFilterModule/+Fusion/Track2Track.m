% TRACK2TRACK  Optimal track-to-track fusion of two Kalman filter tracks
%
%   [x_fuse, P_12] = Track2Track(x1, P1, K1, H1, x2, P2, K2, H2, ...
%                                P_12, Q_12, F, G)
%
%   This function performs optimal track-to-track fusion between two
%   correlated state estimates (e.g., from GNSS and INS Kalman filters)
%   using the cross-covariance matrix between the tracks. The method
%   accounts for cross-correlation to avoid double-counting information.
%
%   Inputs:
%       x1    - State estimate vector from track 1   (n x 1)
%       P1    - State error covariance of track 1    (n x n)
%       K1    - Kalman gain matrix of track 1        (n x m1)
%       H1    - Measurement matrix of track 1        (m1 x n)
%
%       x2    - State estimate vector from track 2   (n x 1)
%       P2    - State error covariance of track 2    (n x n)
%       K2    - Kalman gain matrix of track 2        (n x m2)
%       H2    - Measurement matrix of track 2        (m2 x n)
%
%       P_12  - Cross-covariance between track 1 and track 2 at current step (n x n)
%       Q_12  - Cross-process noise covariance between track 1 and track 2  (n x n)
%
%       F     - State transition matrix              (n x n)
%       G     - Process noise mapping matrix         (n x p)
%
%   Outputs:
%       x_fuse - Fused state estimate vector          (n x 1)
%       P_12   - Updated cross-covariance matrix for next time step (n x n)
%
%   Reference:
%       Y. Bar-Shalom K. C. Chang R. K. Saha. “On optimal track-to-track fusion”.
%       In: IEEE Transactions on Aerospace and Electronic Systems 33.8 (Oct. 1997),
%       pages 1271–1276. DOI: 10.1109 
% 
%       Becker, Alex. Kalman Filter from the Ground Up. A. Becker, 2023. 
%       pages 345-352 DOI: 978-965-93120-0-9
%
%   Notes:
%       - This implementation assumes both tracks estimate the same state vector.
%       - Correct handling of cross-covariance is critical; setting P_12 = 0
%         without justification can significantly overestimate confidence.
%
function [x_fuse, P_12] = Track2Track(x1, P1, K1, H1, x2, P2, K2, H2, P_12, Q_12, F, G)
    I = eye(length(x1));
    P_21 = P_12';
    
    K_12 = (P1 - P_12) * inv(P1 + P2 - P_12 - P_21);
    
    x_fuse = x1 + K_12*(x2 - x1);
    P_12 = (I - K1*H1)*(F*P_12*F')*(I - K2*H2)'...
         + (I - K1*H1)*(G*Q_12*G')*(I - K2*H2)';
end
