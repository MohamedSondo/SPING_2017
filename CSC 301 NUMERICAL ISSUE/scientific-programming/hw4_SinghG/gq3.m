function y = gaussquad3(f, aa, b, n)

%GQ2        approximate the definite integral of an arbitrary function
%           using the composite three-point Gaussian quadrature rule
%           (i.e., Gauss-Legendre quadrature)
%
%     calling sequences:
%             y = gq3 ( 'f', a, b, n )
%             gq3 ( 'f', a, b, n )
%
%     inputs:
%             f       string containing name of m-file defining integrand
%             a       lower limit of integration
%             b       upper limit of integration
%             n       number of uniformly sized subintervals into which
%                     integration interval is to be divided
%                     (the resulting approximation will require 2*n
%                     function evaluations)
%
%     output:
%             y       approximate value of the definite integral of f(x)
%                     over the interval a < x < b
%
%     NOTE:
%             if GQ3 is called with no output arguments, the approximate
%             value of the definite integral of f(x) over the interval
%             a < x < b will be displayed


h2 = (b-aa)/(2*n);
sq35 = sqrt(0.6);
x = linspace ( aa, b, n+1 );
c1 = 5.0 / 9.0;
c2 = 8.0 / 9.0;

sum = 0.0;
for i = 1:n
    sum = sum + c1 * feval ( f, x(i) + h2 - sq35 * h2 );
	sum = sum + c2 * feval ( f, x(i) + h2 );
	sum = sum + c1 * feval ( f, x(i) + h2 + sq35 * h2 );
end

if ( nargout == 1 )
   y = (h2) * sum;
else
   disp ( (h2) * sum );
end