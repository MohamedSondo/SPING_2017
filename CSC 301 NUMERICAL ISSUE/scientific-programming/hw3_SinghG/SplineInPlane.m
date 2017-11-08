function [xi, yi] = SplineInPlane(x, y, m)
% Input
% x and y - column vectors.
% m - output m points

% Output
% the xi-yi coordinates of m points on the curve

n = length(x);
d = sqrt((x(2:n)-x(1:n-1)).^2 + (y(2:n)-y(1:n-1)).^2 );
t = [0; cumsum(d)];
ti = linspace(0, t(n), m)';
xi = spline(t, x, ti);
yi = spline(t, y, ti);