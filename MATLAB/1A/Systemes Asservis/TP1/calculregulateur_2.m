
function [reg,Rn,Rd,Rp,Pcc]= calculregulateur_2(B,A,w_reg)

Pc1=[1 2*w_reg w_reg*w_reg];                  %polynome des modes dominants
Pc2=[1 10*w_reg];                               %polynome des modes auxillaires  
%Modele des perturbations
D=[1 0];

%Calcul du ponynome Aprime
Aprime=conv(A,D);

%Ajout d un pole auxilliaire
Pc3=conv(Pc2,Pc2); 
Pc4=conv(Pc3,Pc2); 
Pc=conv(Pc1,Pc4);
[Rdprime,Rn]=bezou(Aprime,B,Pc);

%Calcul du polynome Rd
Rd=conv(Rdprime,D);
reg=tf(Rn,Rd);


%Calcul de Pc
ARd=conv(A,Rd);
BRn=conv(B,Rn);

n_ard=length(ARd);
n_brn=length(BRn);

if(n_ard>n_brn) Pcc=ARd+[zeros(1,n_ard-n_brn) BRn ];
end

if(n_ard<n_brn) Pcc=[zeros(1,n_brn-n_ard) ARd ]'+BRn;
end

if(n_ard==n_brn) Pcc=ARd+BRn;
end


%Calcul de Rp
Rp=Pcc/B;
end
