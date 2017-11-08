  function [d, errD, c, errC] = Derivative(fname, a, delta, M2, M3)
% d = Derivative(fname,a,delta,M2);
% fname  a string that names a function f(x) whose derivative
% at x = a is sought. delta is the absolute error associated with
% an f-evaluation and M2 is an estimate of the second derivative
% magnitude near a. d is an approximation to f'(a) and err is an estimate 
% of its absolute error.
%
% Usage:
%     [d,err] =  Derivative(fname,a)   
%     [d,err] =  Derivative(fname,a,delta) 
%     [d,err] =  Derivative(fname,a,delta,M2)

if nargin <= 4
   M3 = 1;
elseif nargin <= 3
   M2 = 1;
   M3 = 1;
end

if nargin == 2
   delta = eps;
end

% errD
errD = 2 * sqrt(delta * M2);
hopt = 2*sqrt(delta/M2);
d = (feval(fname, a + hopt) - feval(fname, a))/hopt;
    
% errC
errC = (M3/6) * ((6 * delta)/M3).^(2/3) + ((2 * delta)/((6 * delta)/M3).^(1/3));
hopt = ((6 * delta)/M3).^(1/3);
c = (feval(fname, a + hopt) - feval(fname, a - hopt))/(2 * hopt);

return