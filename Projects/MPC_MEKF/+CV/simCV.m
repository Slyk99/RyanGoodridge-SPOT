function [xrelblack, xrelblue] = simCV(xRed, xblack, xblue, noise, std, FOV)
    xrelblack = CV.genRelStates(xRed, xblack, noise(1:7),  std, FOV);
    xrelblue  = CV.genRelStates(xRed, xblue,  noise(8:14), std, FOV);
end