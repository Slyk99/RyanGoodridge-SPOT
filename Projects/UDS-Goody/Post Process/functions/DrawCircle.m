function pos = DrawCircle(xc,yc,r)
    t = linspace(0, 2*pi);
    
    x = r*cos(t);
    y = r*sin(t);

    pos = [xc + x; yc + y]';
end
