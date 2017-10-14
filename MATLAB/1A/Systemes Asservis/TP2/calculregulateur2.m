
function [reg,Rn,Rd,Pc]= calculregulateur2(B,A,w_reg,alpha)

% Polynomes de Pc
Pc1 = [1 2*w_reg w_reg*w_reg];              
Pc2 = [1 alpha*w_reg];                          
Pc3 = conv(Pc2,Pc2);
Pc4 = conv(Pc3,Pc3);
Pc=conv(Pc1,Pc4);

D = [1 0];
A2 = conv(A,D);

[Rd2,Rn] = bezou(A2,B,Pc);
Rd = conv(Rd2,D);
reg = tf(Rn,Rd);

end


