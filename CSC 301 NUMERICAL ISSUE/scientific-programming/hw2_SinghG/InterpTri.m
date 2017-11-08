function fp = InterpTri(x, y, f_vals, p)

% slope of points BC, and AP
BC_slope = (y(2) - y(3))/(x(2) - x(3));
AP_slope = (y(1) - p(2))/(x(1) - p(1));
    
% BC_slope and AP_slope intercept when ...
% BC_slope(x - x(2)) + y(2) = AP_slope(x - x(1)) + y(1)
% BC_slope(x) - BC_slope(x(2)) + y(2) = AP_slope(x) - AP_slope(x(1)) + y(1)

% solving for x gives ...
% BC_slope(x) - AP_slope(x) = BC_slope(x(2)) - AP_slope(x(1)) + y(1) + y(2)

y2 = BC_slope * (x(2));
y1 = AP_slope * (x(1)) + y(1) + y(2);
x2 = BC_slope;
x1 = AP_slope;

Qx = (y2 - y1)/(x2 - x1);

% y = mx + b
Qy = BC_slope * (x - x(2)) + y(2);

% (z - f_vals(2)) = BCZ_slope(y - y(2))
BCZ_slope = (f_vals(2) - f_vals(3))/(y(2) - y(3));

% Q's f(u,v) approximation is
% z = BCZ_slope(y - y(2)) + f_vals(2)
z = BCZ_slope * (Qy - y(2)) + f_vals(2);

% Equation of line APQ in the z-plane using point slope formula
% (z - fvals(1)) = APQ_slope(y - y(1));
APQ_slope = (f_vals(1) - z)/(y(1) - Qy);

% P's f(u,v) approximation is its z value on the APQ line in the z-plane
fp = APQ_slope * (p(2) - y(1)) + f_vals(1)

end

