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

function [spacecraft] = DrawSpacecraft(param)
    % Generate the points of the spacecraft on the table at its proper 
    % position and orientation.
    %
    % Essentially, takes the output of ShapeSpacecraft() and
    % rotates it to the proper orientation.
    %
    % Inputs:
    %    param: a vector of parameters
    %        param(1) is spacecraft COM x-position [m]
    %        param(2) is spacecraft COM y-position [m]
    %        param(3) is spacecraft orientation in the table frame [rads]
    %        param(4) is the ID that defines the spacecraft shape
    %                 (see ShapeSpacecraft() function for more info)
    % Outputs:
    %    spacecraft: a matrix of points that can be plotted to show the
    %                position and orientation of the platform on the table
    % 
    % Author: Courtney Savytska
    % Date: September 2024
    % ================================================== %

    cx = param(1);
    cy = param(2);
    theta = param(3);

    % Obtain the points that make up the shape of the spacecraft
    sc = ShapeSpacecraft(param);

    % Transform the spacecraft to be at the origin in order to apply the
    % rotation matrix
    sccenter = [ones(1,length(sc))*cx; ones(1,length(sc))*cy].' ;
    scbf = sc - sccenter;
    
    % Define a rotation matrix based on the desired orientation
    rotmat = [cos(theta), -sin(theta); 
              sin(theta), cos(theta)];

    % Apply the rotation matrix to each of the points
    scbf_rot = zeros(size(scbf));
    for i=1:length(sc)
        scbf_rot(i,:) = rotmat*scbf(i,:).';
    end
    
    % Transform the spacecraft back to its correct position at cx,cy
    spacecraft = scbf_rot + sccenter;
end

function [sc] = ShapeSpacecraft(param)
    % Generate the points that make up the shape of the spacecraft. 
    % The horizontal line of the spacecraft shape denotes the +x-body frame
    % direction.
    %
    % Inputs:
    %    param: a vector of parameters
    %        param(1) is spacecraft COM x-position
    %        param(2) is spacecraft COM y-position
    %        param(3) is spacecraft orientation in the table frame --> unused by this function
    %        param(4) is the ID that defines the spacecraft shape 
    %           1 = chaser (with docking cone along y-axis)
    %           2 = target (with docking cone along y-axis)
    %           3 = generic platform, i.e., obstacle
    %           4 = target (with docking cone along y-axis & solar panels)
    %           5 = chaser (with arm joint only)
    %           6 = chaser (with docking cone along x-axis)
    %           7 = generic platform (with solar panels)
    %           8 = capstone chaser
    %           9 = capstone target (without solar panels)
    %           10 = capstone target (with solar panels)
    %
    % Outputs:
    %    sc: a matrix of points that make up the outline of the spacecraft
    % 
    % Author: Courtney Savytska
    % Date: September 2024
    % ================================================== %

    % Get params
    cx = param(1);
    cy = param(2);
    id = param(4);

    % Conversion factor
    cm2m = 1/100;
    
    % Define physical constants
    r  = 0.15;                  % m
    excess = 2.477*cm2m;        % m
    shrink = 1*cm2m;            % m
    bracketwidth = 6.5*cm2m;    % m
    tarcyllength = 8.07*cm2m;   % m
    tarconelength = 5.5*cm2m;   % m
    tarangle = 30*pi/180;       % rads
    chaselength = 5.5*cm2m;     % m
    chaseangle = 20*pi/180;     % rads
    SOLAR_PANEL_LENGTH = 0.45;  % m
    SOLAR_PANEL_WIDTH  = 0.02;  % m
    SOLAR_PANEL_HEIGHT = 0.27;  % m
    
    gamma = r - (excess + shrink + bracketwidth); % m
    
    % Define the points that make-up the outline of the spacecraft
    if id == 1 % chaser (docking grapple, +y axis)
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx+gamma, cy+r;
              cx+gamma+chaselength*sin(chaseangle), cy+r+chaselength;
              cx+gamma+bracketwidth-chaselength*sin(chaseangle), cy+r+chaselength;
              cx+gamma+bracketwidth, cy+r;
              cx-r, cy+r;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy];
    elseif id == 2 % target (docking cone, +y axis)
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx+gamma, cy+r;
              cx+gamma, cy+r+tarcyllength;
              cx+gamma-tarconelength*sin(tarangle), cy+r+tarcyllength+tarconelength;
              cx+gamma+bracketwidth+tarconelength*sin(tarangle), cy+r+tarcyllength+tarconelength;
              cx+gamma+bracketwidth, cy+r+tarcyllength;
              cx+gamma+bracketwidth, cy+r;
              cx-r, cy+r;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy];
    elseif id == 3 % generic platform
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx-r, cy+r;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy];
    elseif id == 4 % target (docking cone, with solar panels)
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx+gamma, cy+r;
              cx+gamma, cy+r+tarcyllength;
              cx+gamma-tarconelength*sin(tarangle), cy+r+tarcyllength+tarconelength;
              cx+gamma+bracketwidth+tarconelength*sin(tarangle), cy+r+tarcyllength+tarconelength;
              cx+gamma+bracketwidth, cy+r+tarcyllength;
              cx+gamma+bracketwidth, cy+r;
              cx-r, cy+r;
              cx-r, cy-SOLAR_PANEL_WIDTH/2;
              cx-r-SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
              cx-r-SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
              cx-r, cy+SOLAR_PANEL_WIDTH/2;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy+SOLAR_PANEL_WIDTH/2;
              cx+r+SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
              cx+r+SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
              cx+r, cy-SOLAR_PANEL_WIDTH/2;
              cx+r, cy];

    elseif id == 5 % chaser (with arm joint)
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx+r-0.08, cy+r;      % these dimensions are probably not accurate
              cx+r-0.08, cy+r+0.08; % these dimensions are probably not accurate
              cx+r-0.02, cy+r+0.08; % these dimensions are probably not accurate
              cx+r-0.02, cy+r;      % these dimensions are probably not accurate
              cx-r, cy+r;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy];
    
    elseif id == 6 % chaser (docking grapple, +x axis)
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx-r, cy+r;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy-gamma;
              cx+r+chaselength, cy-gamma-chaselength*sin(chaseangle);
              cx+r+chaselength, cy-gamma-bracketwidth+chaselength*sin(chaseangle);
              cx+r, cy-gamma-bracketwidth;
              cx+r, cy];
    elseif id == 7 % generic platform (with solar panels)
        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx-r, cy+r;
              cx-r, cy-SOLAR_PANEL_WIDTH/2;
              cx-r-SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
              cx-r-SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
              cx-r, cy+SOLAR_PANEL_WIDTH/2;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy+SOLAR_PANEL_WIDTH/2;
              cx+r+SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
              cx+r+SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
              cx+r, cy-SOLAR_PANEL_WIDTH/2;
              cx+r, cy];
    elseif id == 9 % capstone chaser
        CONE_WIDTH = 0.1;
        CONE_LENGTH = 0.1;
        sc = [cx,     cy;
              cx+r,   cy;
              cx+r,   cy+r;
              cx-r,   cy+r;
              cx-r,   cy-r;
              cx+r,   cy-r;
              cx+r,   cy
              cx+r,   cy+CONE_WIDTH/2;
              cx+r+CONE_LENGTH, cy;
              cx+r,   cy-CONE_WIDTH/2;
              cx+r,   cy];
    elseif id == 10 % capstone target
        PORT_LENGTH = 0.1;
        PORT_WIDTH = 0.1;
        PORT_OVERHANG = 0.07;

        dW = (PORT_LENGTH-PORT_OVERHANG)*(PORT_WIDTH/PORT_LENGTH);

        sc = [cx,   cy;
              cx+r, cy;
              cx+r, cy+r;
              cx-dW/2, cy+r;
              cx-PORT_WIDTH/2, cy+r+PORT_OVERHANG;
              cx+PORT_WIDTH/2, cy+r+PORT_OVERHANG;
              cx+dW/2, cy+r;
              cx-r, cy+r;
              cx-r, cy-SOLAR_PANEL_WIDTH/2;
              cx-r-SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
              cx-r-SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
              cx-r, cy+SOLAR_PANEL_WIDTH/2;
              cx-r, cy-r;
              cx+r, cy-r;
              cx+r, cy+SOLAR_PANEL_WIDTH/2;
              cx+r+SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
              cx+r+SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
              cx+r, cy-SOLAR_PANEL_WIDTH/2;
              cx+r, cy];
    end
    
end