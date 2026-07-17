function [sc] = ShapeSpacecraft(param)
            % Obtain the points that make up the shape of the spacecraft,
            % the param(6) is the id that defines the shape: 
            % 1 = chaser (with docking cone along y-axis)
            % 2 = target (with docking cone along y-axis)
            % 3 = obstacle
            % 4 = target (with docking cone along y-axis & solar panels)

            % Get params
            cx = param(1);
            cy = param(2);
            r = param(4) / 2;
            id = param(5);

            % Conversion factor
            cm2m = 1/100;
            
            % Define physical constants
            excess          = 2.477*cm2m; % m
            shrink          = 1*cm2m; % m
            bracketwidth    = 6.5*cm2m; % m
            tarcyllength    = 8.07*cm2m; % m
            tarconelength   = 5.5*cm2m; % m
            tarangle        = 30*pi/180; % rads
            chaselength     = 5.5*cm2m; % m
            %chaseangle      = 20*pi/180; % rads
            chaseangle      = 20*pi/180; % rads
            % SOLAR_PANEL_LENGTH = evalin("base","SOLAR_PANEL_LENGTH"); % m
            % SOLAR_PANEL_WIDTH  = evalin("base","SOLAR_PANEL_WIDTH");  % m
            % SOLAR_PANEL_HEIGHT = evalin("base","SOLAR_PANEL_HEIGHT"); % m
            SOLAR_PANEL_LENGTH = 0.45; % m
            SOLAR_PANEL_WIDTH  = 0.02;  % m
            SOLAR_PANEL_HEIGHT = 0.27; %#ok<NASGU> % m
            
            gamma = r - (excess + shrink + bracketwidth); % cm

            % Based on the currently selected option, set the rotation of
            % the docking cone
            ConeFaceDropDown = "RED: Positive X";
            if ConeFaceDropDown == "RED: Positive X"
                % Cone is on +X
                coneRot = 90;
            elseif ConeFaceDropDown == "RED: Negative X"  
                 % Cone is on -X
                coneRot = -90;               
            elseif ConeFaceDropDown == "RED: Positive Y"  
                 % Cone is on +Y
                coneRot = 0;  
            elseif ConeFaceDropDown == "RED: Negative Y" 
                 % Cone is on -Y
                coneRot = 180;  
            end
            conePos1Rot = [gamma, r]*[cosd(coneRot) -sind(coneRot); sind(coneRot) cosd(coneRot)] + [cx, cy];
            conePos2Rot = [gamma+chaselength*sin(chaseangle), r+chaselength]*[cosd(coneRot) -sind(coneRot); sind(coneRot) cosd(coneRot)] + [cx, cy];
            conePos3Rot = [gamma+bracketwidth-chaselength*sin(chaseangle), r+chaselength]*[cosd(coneRot) -sind(coneRot); sind(coneRot) cosd(coneRot)] + [cx, cy];
            conePos4Rot = [gamma+bracketwidth, r]*[cosd(coneRot) -sind(coneRot); sind(coneRot) cosd(coneRot)] + [cx, cy];

            % Based on the currently selected option, set the rotation of
            % the target dock
            DockFaceDropDown = "BLACK: Positive X";
            if DockFaceDropDown == "BLACK: Positive X"
                % Cone is on +X
                dockRot = 90;
            elseif DockFaceDropDown == "BLACK: Negative X"  
                 % Cone is on -X
                dockRot = -90;               
            elseif DockFaceDropDown == "BLACK: Positive Y"  
                 % Cone is on +Y
                dockRot = 0;  
            elseif DockFaceDropDown == "BLACK: Negative Y"  
                 % Cone is on -Y
                dockRot = 180;  
            end  
            dockPos1Rot = [gamma, r]*[cosd(dockRot) -sind(dockRot); sind(dockRot) cosd(dockRot)] + [cx, cy];
            dockPos2Rot = [gamma, r+tarcyllength]*[cosd(dockRot) -sind(dockRot); sind(dockRot) cosd(dockRot)] + [cx, cy];
            dockPos3Rot = [gamma-tarconelength*sin(tarangle), r+tarcyllength+tarconelength]*[cosd(dockRot) -sind(dockRot); sind(dockRot) cosd(dockRot)] + [cx, cy];
            dockPos4Rot = [gamma+bracketwidth+tarconelength*sin(tarangle), r+tarcyllength+tarconelength]*[cosd(dockRot) -sind(dockRot); sind(dockRot) cosd(dockRot)] + [cx, cy];
            dockPos5Rot = [gamma+bracketwidth, r+tarcyllength]*[cosd(dockRot) -sind(dockRot); sind(dockRot) cosd(dockRot)] + [cx, cy];
            dockPos6Rot = [gamma+bracketwidth, r]*[cosd(dockRot) -sind(dockRot); sind(dockRot) cosd(dockRot)] + [cx, cy];

            % Define the points that make-up the outline of the target spacecraft
            if id == 1 % chaser (docking grapple)
                sc = [cx,   cy;
                      cx+r, cy;
                      cx+r, cy+r;
                      cx-r, cy+r;
                      cx-r, cy-r;
                      cx+r, cy-r;
                      cx+r, cy+r;
                      conePos1Rot(1), conePos1Rot(2);
                      conePos2Rot(1), conePos2Rot(2);
                      conePos3Rot(1), conePos3Rot(2);
                      conePos4Rot(1), conePos4Rot(2);
                      cx+r, cy+r;
                      cx+r, cy];
            elseif id == 2 % target (docking cone)
                sc = [cx,   cy;
                      cx+r, cy;
                      cx+r, cy+r;
                      cx-r, cy+r;
                      cx-r, cy-r;
                      cx+r, cy-r;
                      cx+r, cy+r;
                      dockPos1Rot(1), dockPos1Rot(2);
                      dockPos2Rot(1), dockPos2Rot(2);
                      dockPos3Rot(1), dockPos3Rot(2);
                      dockPos4Rot(1), dockPos4Rot(2);
                      dockPos5Rot(1), dockPos5Rot(2);
                      dockPos6Rot(1), dockPos6Rot(2);
                      cx+r, cy+r;
                      cx+r, cy];
            elseif id == 3 % obstacle
                sc = [cx,   cy;
                      cx+r, cy;
                      cx+r, cy+r;
                      cx-r, cy+r;
                      cx-r, cy-r;
                      cx+r, cy-r;
                      cx+r, cy];
            elseif id == 4 % target (with cone and solar panels)
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
                      cx+r, cy-SOLAR_PANEL_WIDTH/2;
                      cx+r+SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
                      cx+r+SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
                      cx+r, cy+SOLAR_PANEL_WIDTH/2;
                      cx+r, cy+r;
                      dockPos1Rot(1), dockPos1Rot(2);
                      dockPos2Rot(1), dockPos2Rot(2);
                      dockPos3Rot(1), dockPos3Rot(2);
                      dockPos4Rot(1), dockPos4Rot(2);
                      dockPos5Rot(1), dockPos5Rot(2);
                      dockPos6Rot(1), dockPos6Rot(2);
                      cx+r, cy+r;
                      cx+r, cy];
            elseif id == 5 % target (with solar panels only)

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
                      cx+r, cy-SOLAR_PANEL_WIDTH/2;
                      cx+r+SOLAR_PANEL_LENGTH, cy-SOLAR_PANEL_WIDTH/2;
                      cx+r+SOLAR_PANEL_LENGTH, cy+SOLAR_PANEL_WIDTH/2;
                      cx+r, cy+SOLAR_PANEL_WIDTH/2;
                      cx+r, cy+r;
                      cx+r, cy+r;
                      cx+r, cy];
            elseif id == 6
                 q = params([1,2,3,6,7,8]);
                arm.phi = 68.2840*d2r;      %rad
                arm.b4  = 0.2304;            %m
                arm.a5  = 0.1933;            %m
                arm.b5  = 0.1117;            %m
                arm.a6  = 0.1993;            %m
                arm.b6  = 0.1057;            %m
                arm.a7  = 0.0621;            %m
                arm.b7  = 0.0159;            %m

                
                sc = [cx,   cy;
                      cx+r, cy;
                      cx+r, cy+r;
                      cx-r, cy+r;
                      cx-r, cy-r;
                      cx+r, cy-r;
                      cx+r, cy+r;
                      conePos1Rot(1), conePos1Rot(2);
                      conePos2Rot(1), conePos2Rot(2);
                      conePos3Rot(1), conePos3Rot(2);
                      conePos4Rot(1), conePos4Rot(2);
                      cx+r, cy+r;
                      cx+r, cy];
            end
        end