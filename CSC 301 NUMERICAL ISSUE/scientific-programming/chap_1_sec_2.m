% Script File: ExpPlot
% Examines the function
%
%      f(x) = ((1 + x/24)/(1 - x/24 + x^2/384))^8
%
% as an approximation to exp(z) across [0,1].

% Non-Vectorized
n = 200;
x = linspace(0, 1, n);
y = zeros(1, n);
for k=1:n
    y(k) = ((1 + x(k)/24)/(1- x(k)/12 + (x(k)/384)*x(k)))^8;
end

% plot (x, y)

% vectorized

x  = linspace(0,1,200);
num   = 1 + x/24;
denom = 1 - x/12 + (x/384).*x;
quot = num./denom;
y = quot.^8;
% plot(x,y,x,exp(x))


% Script File: TangentPlot
% Plots the function tan(x), -pi/2 <= x <= 9pi/2

close all
ymax = 10;
x = linspace(-pi/2,pi/2,40);
y = tan(x);
% plot(x,y)
% axis([-pi/2 9*pi/2 -ymax ymax])
% title('The Tangent Function')
% xlabel('x')
% ylabel('tan(x)')
% hold on
for k=1:4
   xnew = x+ k*pi;
   plot(xnew,y);
end
% hold off

t = linspace(0, 2*pi, 361);
c = cos(t);
s = sin(t);
% plot(c, s);

x = [c(1) c(121) c(241) c(361)];
y = [s(1) s(121) s(241) s(361)];
% plot(x, y)

x = c(1:120:361)
y = s(1:120:361)
% plot(x, y)

% Script File: Polygons
% Plots selected regular polygons.

% close all
% theta = linspace(0,2*pi,361);
% c = cos(theta);
% s = sin(theta);
% k=0;
% for sides = [3 4 5 6 8 10 12 18 24]
%    stride = 360/sides;
%    k=k+1;
%    subplot(3,3,k)
%    plot(c(1:stride:361),s(1:stride:361))
%    axis([-1.2 1.2 -1.2 1.2])
%    axis equal
% end

% % 
n = 200;
x = linspace(-10, 10, n);
y = zeros(n, 1);
for k=1:n
    y(k) = 2*sin(x(k)) + 3*sin(2*x(k)) + 7*sin(3*x(k)) + 5*sin(4*x(k));
end

% plot(x, y)

% Script File: SumOfSines
% Plots f(x) = 2sin(x) + 3sin(2x) + 7sin(3x) + 5sin(4x)
% across the interval [-10,10].

close all
x = linspace(-10,10,200)';
A = [sin(x) sin(2*x) sin(3*x) sin(4*x)];
y = A*[2;3;7;5];
% plot(x,y)
% title('f(x) = 2sin(x) + 3sin(2x) + 7sin(3x)  + 5sin(4x)')

% Script File: SumOfSines2
% Plots the functions
%         f(x) = 2sin(x) + 3sin(2x) + 7sin(3x) + 5sin(4x)
%         g(x) = 8sin(x) + 2sin(2x) + 6sin(3x) + 9sin(4x)
% across the interval [-10,10].
   
close all
n = 200;
x = linspace(-10,10,n)';
A = [sin(x) sin(2*x) sin(3*x) sin(4*x)];
y = A*[2 8;3 2;7 6;5 9];
% plot(x,y)


% Problem P1_2_1
%
% Subvector illustration

% clc
% z = [10 40 20 80 30 70 60 90]
% disp(' ')
% disp('z(1:2:7) = ')
% disp(' ')
% disp(z(1:2:7))
% disp(' ')
% disp('z(7:-2:1) = ')
% disp(' ')
% disp(z(7:-2:1))
% 
% disp(' ')
% disp('z([3 1 4 8 1]) = ')
% disp(' ')
% disp(z([3 1 4 8 1]))
% 

% Problem P1_2_2
%
% Subvector assignment illustration

% clc
% disp(' ')
% disp('If z =')
% z = [10 40 20 80 30 70 60 90];
% disp(' ')
% disp(z)
% disp('then after z(1:2:7) = zeros(1,4) it looks like')
% disp(' ')
% z(1:2:7) = zeros(1,4);
% disp(z)
% 
% disp(' ')
% disp('If z =')
% z = [10 40 20 80 30 70 60 90];
% disp(' ') 
% disp(z) 
% disp(' ')
% disp('then after z(7:-2:1) = zeros(1,4) it looks like')
% disp(' ')
% z(7:-2:1) = zeros(1,4);
% disp(z)
% disp(' ')
% disp('If z =')
% z = [10 40 20 80 30 70 60 90];
% disp(' ') 
% disp(z) 
% disp(' ')
% disp('then after z([3 4 8 1]) = zeros(1,4) it looks like')
% disp(' ')
% z([3 4 8 1]) = zeros(1,4);
% disp(z)


% Problem P1_2_3
% 
% x = linspace(0, 1, 200);
% y = sqrt(1-x.^2)
% plot(x, y)
% hold on
% plot(-x, y)
% plot(-x, -y)
% plot(x, -y)
% hold off

% Problem P1_2_4
%
% Superpositioning

% close all
% 
% % Method 1:
% figure
% x = linspace(0, 2*pi);
% plot(x, sin(x), x,sin(2*x), x,sin(3*x), x,sin(4*x), x,sin(5*x))
% title('Method 1')
% 
% % Method 2:
% figure 
% plot(x,sin(x));
% hold on
% for k=2:5
%    plot(x,sin(k*x),'-')
% end
% hold off
% title('Method 2')

% Problem P1_2_5
%
% Plotting x, x^2, ... ,x^m where m is a solicited integer.

% a = input('Enter a positive int a');
% x = linspace(0, 1);
% xk = x;
% plot(x, x);
% hold on
% for k=-m:m
%     xk = xk.*x;
%     plot(x, xk);
% end

% Problem P1_2_6
% 
% x = linspace(0, 1);
% m = 10000;
% y = ones(size(x));
% term = x;
% for k=1:m
%     term = x.*term/k;
%     y = y+term;
% end
% plot(x, y)


% Problem P1_2_7
%
% Ellipse plots.

% close all 
% 
% x = linspace(0,2*pi);
% c = cos(x);
% s = sin(x);
% plot(3+6*c,-2+9*s,7+2*c,8+6*s)
% axis square equal

% Problem P1_2_8
%
% Sine superpositioning

close all

x = linspace(0,2*pi);
y = sin(x);
plot(x/2,y)
hold on
for k=1:3
   plot((k*pi)+x/2,y)
end
hold off