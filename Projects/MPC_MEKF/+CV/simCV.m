function [xrelblack, xrelblue] = simCV(xRed, xblack, xblue, noise, std, FOV)
    xrelblack = CV.genRelStates(xRed, xblack, noise(1:8),  std, FOV);
    xrelblue  = CV.genRelStates(xRed, xblue,  noise(9:16), std, FOV);

    %% Add confidance
    xrelblack = [xrelblack; 1];
    xrelblue  = [xrelblue; 1];
end