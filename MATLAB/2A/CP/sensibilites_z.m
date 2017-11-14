function sensibilites_z(A,B,d,Rn,Rd,Rp,Te)

ARd=conv(A,Rd);
BRn=[ zeros(1,d+1)  conv(B,Rn')];

%Calcul du polynome caracteristique
n_ard=length(ARd);
n_brn=length(BRn);



if (n_ard > n_brn)   BRn=[BRn,zeros(1,n_ard-n_brn)];
end
if (n_ard < n_brn)   ARd=[ARd,zeros(1,n_brn-n_ard)];  
end


n=length(ARd)-length(BRn);

Pct=[ARd] + [BRn];
Pct=Pct;
sensibilite_poursuite=tf(conv(B,Rp),Pct,Te,'Variable','z^-1');


sensibilite=tf(conv(A,Rd),Pct,Te,'Variable','z^-1');
sensibilite_complementaire=tf(conv(B,Rp),Pct,Te,'Variable','z^-1');
sensibilite_regul=tf(Rn',Pct,Te,'Variable','z^-1');
%sensibilite_process=tf(conv(B,Rp),Pc,Te,'Variable','z^-1');

figure(1)
bode(sensibilite_poursuite);

figure(2)
bode(sensibilite);

figure(3)
bode(sensibilite_regul);



%Affichage poles et zeros
figure(4)
pzmap(sensibilite);


%affichage des marges de stabilite
sysbo=tf(Rp,Rd,Te)*tf([zeros(1,d+1) B],A,Te);
figure(5)
nichols(sysbo)
