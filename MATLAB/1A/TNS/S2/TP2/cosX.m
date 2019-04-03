function [X,x] = cosX(N,k)
X=[zeros(1,k) N/2 zeros(1,N-(2*k-1)-2) N/2 zeros(1,k-1)];
x=real(ifft(X));
end
