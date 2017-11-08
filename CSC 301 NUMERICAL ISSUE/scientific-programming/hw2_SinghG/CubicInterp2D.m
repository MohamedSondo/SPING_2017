function z = CubicInterp2D(xc, yc, a, b, n, c, d, m, fA)

    hx = (b - a)/(n - 1); i = max([1 ceil((xc - a)/hx)]);
    hy = (d - c)/(m - 1); j = max([1 ceil((yc - c)/hy)]);

    % x edges
    if (i > 1) & (i < n - 1)
        x_edges = (i-1):(i+2);
    elseif i == 1
        x_edges = 1:4;
    else
        x_edges = n-3:n;
    end
    
    % y edges
    if (j > 1) & (j < m-1)
        y_edges = (j-1):(j+2);
    elseif 1==j
        y_edges = 1:4;
    else
        y_edges = m-3:m;
    end
    
    % xvals(1) < xvals(2) < xvals(3) < xvals(4)
    x_vals = c + (x_edges-1)*hx;
    
    % yvals(1) < yvals(2) < yvals(3) < yvals(4)
    y_vals = c + (y_edges-1)*hy;  
    
    % fvals - a 4x4 matrix eval of f at the xvals, yvals.
    fvals = fA(x_edges, y_edges);
    
    x_vals = x_vals';
    y_vals = y_vals';
    
    fy = zeros(4,1);
    for a=1:4
        c = InterpN(x_vals, fvals(:,4));
        fy(a) = HornerN(c, x_vals, xc);
    end

    c = InterpN(y_vals, fy);   % interpolate vertically 
    z = HornerN(c, y_vals, yc);
    
end