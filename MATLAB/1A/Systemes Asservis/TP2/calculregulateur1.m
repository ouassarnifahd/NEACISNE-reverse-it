
function [reg,Rn,Rd,Pc]= calculregulateur1(B,A,w_reg,alpha)

% Polynomes de Pc
Pc1 = [1 2*w_reg w_reg*w_reg];              
Pc2 = [1 alpha*w_reg];                          

Pc=conv(Pc1,Pc2);
[Rd,Rn]=bezou(A,B,Pc);
reg=tf(Rn,Rd);

end

