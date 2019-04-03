function [Rn_tf,Rd_tf,Rp_tf]= mise_en_oeuvre2(Rn_i,Rd_i,Rp_i)



%Creation du filtre
polynome_elementaire=[1 50];


F=1;

if(length(Rd_i)>1)
for i=1:1:length(Rd_i)-1
    F=conv(F,polynome_elementaire);
end
end
Rn_tf=tf(Rn_i,F);
Rd_tf=tf(Rd_i,F);

%Filtre F de degre = degre de Rd
%On rajoute des modes hautes frequences a Rp_tf pour rendre realisable
%Rp=Pc/B

n_rp=length(Rp_i);
n_rd=length(Rd_i);

polynome_elementaire2=[1 5000];
Fp=F;
for i=1:1:n_rp-n_rd
Fp=conv(Fp,polynome_elementaire2);
end
Rp_tf=tf(5000^(n_rp-n_rd)*Rp_i,Fp);
end
