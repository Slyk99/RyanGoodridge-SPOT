function [spacecraft] = DrawSpacecraft(param)
            cx = param(1);
            cy = param(2);
            theta = param(3) - pi/2;

            % Obtain the points that make up the shape of the spacecraft,
            % the param(6) is the id that defines the shape: 
            % 1 = chaser (with docking cone along y-axis)
            % 2 = target (with docking cone along y-axis)
            % 3 = obstacle
            % 4 = target (with docking cone along y-axis & solar panels)
            sc = ShapeSpacecraft(param);
        
            % Transform the spacecraft to be at the origin in order to apply the
            % rotation matrix
            sccenter = [ones(1,length(sc))*cx; ones(1,length(sc))*cy].' ;
            scbf = sc - sccenter;
            scbf(:,1) = -scbf(:,1); % Need to flip shape across y-axis
            
            % Define a rotation matrix based on the target orientation
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