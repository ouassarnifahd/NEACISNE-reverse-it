function MatW = W(n)
MatW=zeros(n,n);
for i=1:n
    for j=1:n
        MatW(i,j)=Wij(i,j,n);
    end
end
