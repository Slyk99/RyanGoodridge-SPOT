function [xstack, Pstack] = packStates(xred, Pred, xblack, Pblack, xblue, Pblue)
    xstack = zeros(length(xred), 3);
    xstack(:,1) = xred;
    xstack(:,2) = xblack;
    xstack(:,3) = xblue;
    
    Pstack = zeros(length(xred), length(xred), 3);
    Pstack(:,:,1) = Pred;
    Pstack(:,:,2) = Pblack;
    Pstack(:,:,3) = Pblue;
end