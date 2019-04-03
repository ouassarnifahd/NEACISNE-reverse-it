function [sbep,rbep]=bezou(abep,bbep,pbep)

%solution minimale d'une équation de BEZOUT
% pour polynômes en p (ou z) par ordre décroissant en p (ou z)
%
%		         	
% 	abez * sbez +  bbez * rbez = pbez

na=length(abep)-1;
nb=length(bbep)-1;
nc=length(pbep)-1;

%Calcul des degres des polynomes regulateur
nr=na-1;
if nc-na>nb-1  ns=nc-na
else            ns=nb-1
end


%Determination des parametres ri et si
nb_param=nr+1+ns+1;

%On complete B pour avoir deux polynomes de meme degres AS et BR 
B=[zeros(1,nc-nr-nb) bbep];
%Autant d equations que de parametres
P=pbep';
  
%Premiere partie de la matrice : celle qui fait la dependance par rapport a
%S
for i=1:1:ns+1
    M(:,i)=[zeros(i-1,1); abep'; zeros(nc+1-(na+1)-(i-1),1)];
end

for i=ns+2:1:nb_param
    
    M(:,i)= [zeros(i-(ns+2),1); B'; zeros(nc+1-length(B)-(i-ns-2),1)];
    
end


%Calcul de la matrice M
parametre=inv(M)*P;
sbep=parametre(1:ns+1);
rbep=parametre(ns+2:nb_param);
rbep=rbep';
sbep=sbep';





