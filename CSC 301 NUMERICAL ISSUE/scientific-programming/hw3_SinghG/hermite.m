
% Hermite interpolation function
% input - x, f(x), f'(x)
% output - A, Q

function [A, Q] = hermite(x, fx, f_prime)
    n = length(x);
    z = zeros(2*n,1);
    Q = zeros(2*n,2*n);
    
    for i=1:n
        z(2*i-1) = x(i);
        z(2*i) = x(i);
        Q(2*i-1,1) = fx(i);
        Q(2*i,1) = fx(i);
        Q(2*i,2) = f_prime(i);
        if i ~= 1
            Q(2*i-1,2) = ( Q(2*i-1,1)-Q(2*i-2,1) )/( z(2*i-1)-z(2*i-2) );
        end
    end
    
    for i=3:2*n
        for j=3:i
            Q(i,j) = ( Q(i,j-1)-Q(i-1,j-1) )/( z(i)-z(i-j+1) );
        end
    end
    
    A = diag(Q);
end