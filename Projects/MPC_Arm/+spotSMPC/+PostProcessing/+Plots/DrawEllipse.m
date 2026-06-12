function pos = DrawEllipse(xc, yc, a, b, theta)
    t = linspace(0, 2*pi);

    x = a * cos(t);
    y = b * sin(t);

    x_rot = x * cos(theta) - y * sin(theta);
    y_rot = x * sin(theta) + y * cos(theta);
    
    pos = [xc + x_rot; yc + y_rot]';
end