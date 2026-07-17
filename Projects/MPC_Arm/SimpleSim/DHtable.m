function [T, Tiall, Tint] = DHtable(params)
    nJoints = size(params,1);
    
    T = eye(4);
    Tint = zeros(4,4,nJoints);
    Tiall = zeros(4,4,nJoints);
    
    for i = 1:nJoints
        alpha = params(1,i); a = params(2,i); d = params(3,i); theta = params(4,i);
    
        Ti = DHsingle(alpha, a, d, theta);
    
        Tint(:, :, i) = T;
        T = T*Ti;
        Tiall(:, :, i) = T;
    end

end
