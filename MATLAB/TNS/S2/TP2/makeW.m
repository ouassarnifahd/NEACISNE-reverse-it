function MatW = W(n)
MatW=zeros(n,n);
for i=1:1:n
    for j=1:1:n
        W(i,j)=Wij(i,j,n);
    end
end
