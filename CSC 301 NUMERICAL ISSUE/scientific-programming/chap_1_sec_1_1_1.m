% Gurpreet Singh
% Cs 301 Lecture 1

% rows
x = [1 2 3 4 5];

% cols
x = [1; 2; 3; 4; 5];

% simple code to create an array from 0 - 21 (like linespace)
% 21 points evenly seperated 
n = 21;
h = 1/(n - 1);
for k=1:n
    x(k) = (k - 1)*h;
end

% j = length(x)
% x

% simple code to create an array from 0 - 21
n = 21;
h = 1/(n - 1);
x = zeros(1, n);
for k=1:n
    x(k) = (k - 1)*h;
end

% j = length(x)
% x

u = [1 2 3];
% i = length(u)
u = [1; 2; 3];
% i = length(u)
u = [1 2];
% i = length(u)

% array from 20 30
x = 20:30;
% array from 20 30, evenly space by 2
x = 20:2:30;

% 10 to 1
x = 10:-1:1;

% empty array
x = 3:2;

% linespace
% X(k) = a + (k - 1)*(b - a)/(n - 1)
% 0 to 1, 21 evenly space points
x = linspace(0, 1, 21);

% logorithms spacing
x = logspace(0, 1, 21);
x = logspace(-2, 2, 6);

% equivalent to
m = linspace(-2, 2, 6);
for k=1:6
    x(k) = 10^m(k);
end

% sin values that corresponds to the value in x
n = 21;
x = linspace(0, 1, n);
y = zeros(1, n);
for k=1:n
    y(k) = sin(x(k));
end

% sin(2*pi*x)
y = 0;
n = 21;
x = linspace(0, 1, 21);
m = 5;
n = 4*m+1;
x = linspace(0, 1, n);
a = x(1:m+1);                   % index [1:m+1]
y(1:m+1) = sin(2*pi*a);         % mult the vector by 2pi
y(2*m+1:-1:m+2) = y(1:m);       % from 11 down to 7 
y(2*m+2:n) = -y(2:2*m+1);       % from 12 up to 21

% sine table
clc
n = 21;
x = linspace(0, 1, n);
y = sin(2*pi*x);
% disp(' ')
% disp('  k     x(k)     sin(x(k))')
% disp('-------------------------------')
for k=1:21 
    degrees = (k-1)*360/(n-1);
%     disp(sprintf('  %2.0f     %3.0f     %6.3f     ',k,degrees, y(k)));
end
% disp(' ');
% disp('x(k) is given in degrees.');
% disp(sprintf('One Degree = %5.3e Radians', pi/180));

% A simple plot

n = 21;                              % changing n makes the graph smoother
x = linspace(0, 1, n);
y = sin(2*pi*x);
% plot(x, y);
% title('The function y=sin(2*pi*x)');
% xlabel('x (in radians)');
% ylabel('y');

% SinePlot
for n = [4 8 12 16 20 50 100 200 400]
    x = linspace(0, 1, n);
    y = sin(2*pi*x);
%     plot(x, y);
%     pause(1);
end

% Problem P1_1_1
%
% Plots various built-in functions

% close all
% 
% x = linspace(-1,1);
% % plot(x,abs(x))
% title('The Absolute Value Function')
% pause(2)
% 
% figure
% x = linspace(0,10);
% % plot(x,sqrt(x))
% title('The Square Root Function')
% pause(2)   
% 
% figure
% x = linspace(-2,2);
% % plot(x,exp(x))
% title('The Exponential')
% pause(2)
% 
% figure
% x = linspace(1,100);
% % plot(x,log(x))
% title('The Natural Log')
% pause(2)
% 
% figure
% x = linspace(0,4*pi); 
% % plot(x,sin(x))
% title('The Sine Function')
% pause(2)
% 
% figure
% x = linspace(0,4*pi);
% % plot(x,cos(x))
% title('The Cosine Function')
% pause(2)
% 
% figure
% x = linspace(-1,1);
% % plot(x,asin(x))
% title('The Inverse Sine Function')
% pause(2)
% 
% figure
% x = linspace(-1,1);
% % plot(x,acos(x))
% title('The Inverse Cosine Function')
% pause(2)
% 
% figure
% x = linspace(-5,5);
% % plot(x,atan(x))
% title('The Inverse Tangent Function')
% pause(2)

close all

% Problem P1_2_1
%
% Subvector illustration

for i=1:201
    x = 8*(i-1)/200;
    if (0 <= x <= 2)
        yi = sqrt(1 -(x-1).^2)
    else if (2 < x <= 4)
        yi = sqrt(1 -(x-3).^2)
    else if (4 < x <= 6)
        yi = sqrt(1 -(x-5).^2)
    else if (6 < x <= 8)
        yi = sqrt(1 -(x-7).^2)
    end
    end
    end
    end
end





