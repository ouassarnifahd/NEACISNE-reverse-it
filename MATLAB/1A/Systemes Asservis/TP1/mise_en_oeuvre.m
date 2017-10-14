function [Rn_tf,Rd_tf]= mise_en_oeuvre(Rn_i,Rd_i)



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
end