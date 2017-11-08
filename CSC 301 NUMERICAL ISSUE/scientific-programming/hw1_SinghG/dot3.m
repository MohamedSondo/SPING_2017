function result = dot3(x, y)
% x and y are column vectors of the same length.
% result = 3-digit representation of x'*y

result = Represent(0);
for i=1:length(x)
    xi = Represent(x(i));
    yi = Represent(y(i));
    p = Float(xi, yi, '*');
    result = Float(result, p, '+');
end