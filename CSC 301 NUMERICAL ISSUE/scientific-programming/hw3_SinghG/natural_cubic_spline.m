% natural cubic spline

function [a, B, C, D] = natural_cubic_spline(x, a)
    N = length(x) - 1;
    H = zeros(N, 1);
    ALPHA = zeros(N-1, 1);
    
    L = zeros(N,1);   MU = zeros(N, 1);
    Z = zeros(N+1,1); B = zeros(N+1, 1);
    C = zeros(N+1,1); D = zeros(N+1, 1);
    
    for i=0:N-1
        H(i+1) = x(i+2)-x(i+1);
    end
    
    for i=1:N-1
        Q = 3/H(i+1)*(a(i+2)-a(i+1));
        R = 3/H(i)*(a(i+1)-a(i));
        ALPHA(i) = Q - R;
    end
    
    L(1) = 1; Z(1) = 0; MU(1) = 0;
    
    for i=1:N-1
        Q = 2*(x(i+2)-x(i));
        R = H(i)*MU(i);
        L(i+1)  = Q - R;
        MU(i+1) = H(i+1)/L(i+1);
        Z(i+1)  = (ALPHA(i)-H(i) * Z(i))/L(i+1);
    end
    
    Z(N+1) = 0; C(N+1) = 0;
    
    for j=N-1:-1:0
        C(j+1) = (Z(j+1)-MU(j+1)*C(j+2));
        B(j+1) = (a(j+2)-a(j+1))/H(j+1)-H(j+1)*(C(j+2)+2*C(j+1))/3;
        D(j+1) = (C(j+2)-C(j+1))/(3*H(j+1));
    end
end