%% Student - Gurpreet Singh
% CSc 301 - HW #4
% November 28, 2015

%% Problem 1 

% An experiment to measure the intensity of lght as a function of the
% distance from the source of the light produced the following data:

d = [30 35 40 45 50 55 60 65 70 75];
i = [0.85 0.67 0.52 0.42 0.34 0.28 0.24 0.21 0.18 0.15];

% a. Find the best fit quadratic function;

sols = BestFitNOrder(d, i, 2);
a0 = sols(1);
a1 = sols(2);
a2 = sols(3);
for j=1:length(d)
    f_quad(j) = a2*d(j)^2 + a1*d(j) + a0;
end

% b. Find the best fir exponential function;

sold = BestFitExp(d, i);
b0 = sold(1);
b1 = sold(2);
B = exp(b0);

for j=1:length(d)
    f_exp(j) = B*exp(b1*d(j));
end

% c. Find the interpolating polynomial;

cc = InterpN2(d,i);
fcf = strcat('cc(1)'...
    ,'+cc(2)*(x-30)'...
    ,'+cc(3)*(x-30)*(x-35)'...
    ,'+cc(4)*(x-30)*(x-35)*(x-40)'...
    ,'+cc(5)*(x-30)*(x-35)*(x-40)*(x-45)'...
    ,'+cc(6)*(x-30)*(x-35)*(x-40)*(x-45)*(x-50)'...
    ,'+cc(7)*(x-30)*(x-35)*(x-40)*(x-45)*(x-50)*(x-55)'...
    ,'+cc(8)*(x-30)*(x-35)*(x-40)*(x-45)*(x-50)*(x-55)*(x-60)'...
    ,'+cc(9)*(x-30)*(x-35)*(x-40)*(x-45)*(x-50)*(x-55)*(x-60)*(x-65)'...
    ,'+cc(10)*(x-30)*(x-35)*(x-40)*(x-45)*(x-50)*(x-55)*(x-60)*(x-65)*(x-70)');

fcy = [];
for j=1:10
    fcy(j) = eval(strrep(fcf, 'x', num2str(d(j))));
end

% d. Find the interpolating cubic spline;

[D, Dxs, DcubicY, dc] = CubicSpline(d, i);
% 
% figure
% plot(d, i, '-m^') % expected
% hold on
% plot(d, f_quad, '-bx') % quadratic
% hold on
% plot(d, f_exp, '-gd') % exponetial
% hold on
% plot(d, fcy, '-c*') % cubic spline

%% Problem 2

% P 5.4.2 page 200

% Write a script that demonstrates your trigonometric interpolation: 
% generate an example of a periodic function and display the results of 
% the interpolation with different number of sampling points.

A = linspace(0,360,8)';
D = [ 408 89 -66 10 338 807 1238 1511]';

Avals = linspace(0,360,200)'; 
F = CSInterp(D(1:8));
Fvals = CSEval(F,360,Avals);

plot(Avals,Fvals,A,D,'o');
axis([-10 370 -200 1700]);
set(gca,'xTick',linspace(0,360,8));
xlabel('Ascension (Degrees)');
ylabel('Declination (minutes)');


%% Problem 3

% P7.1.1 page 246

n = 100;
b = sort(rand(3,1));
b = b(3:-1:1);

A = [1;1;1];
x = linspace(-1,1,n);

v1   = zeros(n,1);
v2   = zeros(n,1);
vinf = zeros(n,1);

for k=1:n
   v1(k)   = norm(A*x(k)-b,1);
   v2(k)   = norm(A*x(k)-b,2);
   vinf(k) = norm(A*x(k)-b,'inf');
end
% 
% figure
% subplot(2,2,1)
% plot(x,v1,[b(2),b(2)],[0,6])
% title(sprintf('1-norm: min at %5.3f',b(2)))
% 
% subplot(2,2,2)
% plot(x,v2,[sum(b)/3, sum(b)/3],[0,6])
% title(sprintf('2-norm: min at %5.3f',sum(b)/3))
% 
% subplot(2,2,3)
% plot(x,vinf,[(b(1)+b(3))/2,(b(1)+b(3))/2],[0,6])
% title(sprintf('inf-norm: min at %5.3f',(b(1)+b(3))/2))
% 
