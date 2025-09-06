%====================================================================%
%          SPOT Plotting Functions for Papers
% 
% These plotting functions are used to generate professional 
% overhead plots of simulation or experiment data to be included
% in published work.
% 
% Author: Courtney Savytska
% Date: September 2024
%====================================================================%


function [shoulder_output,elbow_output,wrist_output] = DrawARM(param)
    % Generate the shapes of the arm, to be plotted.
    %
    % Inputs:
    %    param: a vector of parameters
    %        param(1) is spacecraft COM x-position [m]
    %        param(2) is spacecraft COM y-position [m]
    %        param(3) is spacecraft orientation in the table frame [rads]
    %        param(4) is the arm shoulder angle [rads]
    %        param(5) is the arm elbow angle [rads]
    %        param(6) is the arm wrist angle [rads]
    % Outputs:
    %    [for each]: a matrix of points that can be plotted to show the
    %                 position and orientation of the arm on the table
    % 
    % Author: Courtney Savytska
    % Date: September 2024
    % ================================================== %

    [rs,re,rw,ree] = CalculateArmPosition(param);

    width = 0.015;  % this dimension is probably not accurate
    
    % Obtain the points that make up the shape of the arm
    rers = re-rs;
    size_shoulder = sqrt(rers*rers');
    shoulder = [size_shoulder/2, -width;
                size_shoulder/2, width;
                -size_shoulder/2, width;
                -size_shoulder/2, -width;
                size_shoulder/2, -width];

    rwre = rw-re;
    size_elbow = sqrt(rwre*rwre');
    elbow = [size_elbow/2, -width;
                size_elbow/2, width;
                -size_elbow/2, width;
                -size_elbow/2, -width;
                size_elbow/2, -width];

    reerw = ree - rw;
    size_wrist = sqrt(reerw*reerw');
    wrist = [size_wrist/2, -width;
                size_wrist/2, width;
                -0.01, 0.045;
                -0.01, width;
                -size_wrist/2, width;
                -size_wrist/2, -width;
                -0.01,-width;
                -0.01, -0.045;
                size_wrist/2, -width];

    % Rotate and translate each link to its proper orientation and position
    shoulder_output = rotateARMShape(rs,rers,shoulder);
    elbow_output = rotateARMShape(re,rwre,elbow);
    wrist_output = rotateARMShape(rw,reerw,wrist);
    
    function output = rotateARMShape(r1,r12,link)
        % Define the angle the center location of the arm link
        theta = atan2(r12(2),r12(1));
        center = r1 + r12 / 2;
        linkcenter = [ones(1,length(link))*center(1); ones(1,length(link))*center(2)].' ;
        
        % Define a rotation matrix based on the orientation
        rotmat = [cos(theta), -sin(theta); 
                  sin(theta), cos(theta)];
    
        % Apply the rotation matrix to each of the points
        scbf_rot = zeros(size(link));
        for i=1:length(link)
            scbf_rot(i,:) = rotmat*link(i,:).';
        end
        
        % Transform the arm link to its position
        output = scbf_rot + linkcenter;
    end

end


function [rs,re,rw,ree] = CalculateArmPosition(param)
    % Calculate the shoulder, elbow, wrist, and end-effector positions
    % based on the chaser body position and arm angles.
    %
    % Code based on Alex Crain's SPOT software.
    %
    % Inputs:
    %    param: a vector of parameters
    %        param(1) is spacecraft COM x-position [m]
    %        param(2) is spacecraft COM y-position [m]
    %        param(3) is spacecraft orientation in the table frame [rads]
    %        param(4) is the arm shoulder angle [rads]
    %        param(5) is the arm elbow angle [rads]
    %        param(6) is the arm wrist angle [rads]
    % Outputs:
    %    [rs,re,rw,ree]: positions of the shoulder, elbow, wrist, end-effector
    % 
    % Author: Courtney Savytska
    % Date: September 2024
    % ================================================== %

    x0 = param(1);
    y0 = param(2);
    q0 = param(3);
    q1 = param(4);
    q2 = param(5);
    q3 = param(6); 

    % Some of these parameters may be out of date.
    a1 = 0.1933;    
    a2 = 0.1993;   
    a3 = 0.0621;    
    b0 = 0.2304;   
    b1 = 0.1117;    
    b2 = 0.07;   
    b3 = 0.0459; 
    Phi = 68.284*pi/180 ; 

    rs     = [ x0 + ( b0)*cos(Phi + q0),y0 + ( b0)*sin(Phi + q0) ];                                    
    re     = [ x0 + ( b0)*cos(Phi + q0) + ( a1+ b1)*cos(pi/2 + q0 + q1),y0 + ( b0)*sin(Phi + q0) + ( a1+ b1)*sin(pi/2 + q0 + q1) ];
    rw     = [ x0 + ( b0)*cos(Phi + q0) + ( a1+ b1)*cos(pi/2 + q0 + q1) + ( a2+ b2)*cos(pi/2 + q0 + q1 + q2),y0 + ( b0)*sin(Phi + q0) + ( a1+ b1)*sin(pi/2 + q0 + q1) + ( a2+ b2)*sin(pi/2 + q0 + q1 + q2) ];
    ree    = [ x0 + ( b0)*cos(Phi + q0) + ( a1+ b1)*cos(pi/2 + q0 + q1) + ( a2+ b2)*cos(pi/2 + q0 + q1 + q2) + ( b2+ b3)*cos(pi/2 + q0 + q1 + q2 + q3),y0 + ( b0)*sin(Phi + q0) + ( a1+ b1)*sin(pi/2 + q0 + q1) + ( a2+ b2)*sin(pi/2 + q0 + q1 + q2) + ( b2+ b3)*sin(pi/2 + q0 + q1 + q2 + q3)];
            
end