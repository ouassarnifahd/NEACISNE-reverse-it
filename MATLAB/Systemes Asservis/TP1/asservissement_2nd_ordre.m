%TP de Syst�mes Asservis n�1
%Nom du binome : 

close all
clear all
%%
%DEFINITION DE TOUS LES PARAMETRES NUMERIQUES
%Sch�ma simulink
Temps_Fin =10;   % Dur�e de la simulation

%definition du systeme
k=1.5;          % Gain statique
ksi=0.5;        % facteur d'amortissement
w0=2;           % Pulsation propre
B=k*w0*w0;
A=[1 2*ksi*w0 w0*w0];
G1=tf(B,A);

%valeurs des parametres de synth�se pour l asservissement

w_reg=1.5*w0;        % pulsation naturelle dominante en regulation
wp=w_reg/2;
w=logspace(-3,5,500);
%Synth�se des 4 regulateurs

%Regulateur 1
[reg1,Rn_1,Rd_1,Pc_1]=calculregulateur(B,A,w_reg,1);

%Regulateur 2
[reg2,Rn_2,Rd_2,Pc_2]=calculregulateur(B,A,w_reg,2);

%Regulateur 3
[reg3,Rn_3,Rd_3,Pc_3]=calculregulateur(B,A,w_reg,3);

%Regulateur 4
[reg4,Rn_4,Rd_4,Rp_4,Pc_4]=calculregulateur_2(B,A,w_reg);


%%
%********************************
%I Analyse du systeme � commander
%********************************

figure(1);
%A compl�ter
title('R�ponse impulsionnelle du syst�me � commander');
impulse(G1);

figure(2);
title('Position des p�les et des z�ros du syst�me � commander');
%A completer
pzmap(G1);

%%
%Essai sous Simulink
%S�lection des signaux d excitation
entree_bo=1;
pertu_bo=1;

sim('simulation_boucle_ouverte');

%%
%********************************
%II Objectif de regulation
%********************************

%II.1   Premier regulateur
%1  Effets des perturbations de sortie

%Definition de la fonction de transfert entre la perturbation de sortie et la sortie
%A completer
Sensibilite=tf(conv(A,Rd_1),Pc_1);

figure(3);
title('Position des p�les et des z�ros de la Fonction de Transfert : Y/Vy');
%A completer
pzmap(Sensibilite);

figure(4);
title('Bode de Y/Vy');
%A completer
Bode(Sensibilite);

%Definition de la fonction de transfert entre le bruit de mesure et la commande
%A completer
Sensibilite2=tf(conv(A,Rn_1),Pc_1);

figure(5);
title('Bode de U/ny');
%A completer
Bode(Sensibilite2);

%%
%Essai sous Simulink
%S�lection des signaux d excitation
pertu_bf=1;
bruit_bf=0;

%Calcul des objets syst�mes pour le sch�ma simulink
[Rn_tf,Rd_tf]= mise_en_oeuvre(Rn_1,Rd_1);



%***************************************
%BILAN du II.1
%****************************************


%%
%II.2   Prise en compte des perturbations

%Definition de la fonction de transfert entre la perturbation de sortie et la sortie
%A completer
Sensibilite=tf(conv(A,Rd_2),Pc_2);

figure(6);
title('Position des p�les et des z�ros de la Fonction de Transfert : Y/Vy');
%A completer
pzmap(Sensibilite);


figure(7)
title('Bode de Y/Vy');
%A completer
Bode(Sensibilite);

%Definition de la fonction de transfert entre le bruit de mesure et la commande
%A completer
Sensibilite2=tf(conv(A,Rn_2),Pc_2);

figure(8)
title('Bode de U/ny');
%A completer
Bode(Sensibilite2);

%Affichage des poles et zeros du regulateur 2
figure(9)
%A completer
pzmap(Sensibilite2);

%%
%Essai sous Simulink
%S�lection des signaux d excitation
pertu_bf=0;
bruit_bf=1;

%Calcul des objets syst�mes pour le sch�ma simulink (Code a demasquer pour
%faire l essai du regulateur 2)
[Rn_tf,Rd_tf]= mise_en_oeuvre(Rn_2,Rd_2);




%***************************************
%BILAN du II.2

%****************************************

%%
%II.3   Prise en compte de la sensibilite au bruit de mesure

%Definition de la fonction de transfert entre la perturbation de sortie et
%la sortie
%A completer
Sensibilite=tf(conv(A,Rd_3),Pc_3);

figure(10)
%A completer
pzmap(Sensibilite);

%un zero en 0 : rejet de perturbation de type echelon
figure(11)
title('Bode de Y/Vy');
%A completer
Bode(Sensibilite);

%Definition de la fonction de transfert entre le bruit de mesure et la
%commande
%A completer
Sensibilite2=tf(conv(A,Rn_3),Pc_3);


figure(12)
title('Bode de U/ny');
%A completer
Bode(Sensibilite2);

%Affichage des poles et zeros du regulateur 3
figure(13)
%A completer
pzmap(Sensibilite2);


%%
%Essai sous Simulink
%S�lection des signaux d excitation
pertu_bf=0;
bruit_bf=1;

%Calcul des objets syst�mes pour le sch�ma simulink(Code a demasquer pour
%faire l essai du regulateur 3)
[Rn_tf,Rd_tf]= mise_en_oeuvre(Rn_3,Rd_3);


%***************************************
%BILAN du II.3
%****************************************

%%
%II.4
%Etude de l effet de wr 

%***************************************
%BILAN du II.4
%****************************************

%III Probleme de poursuite

%Creation du modele de reference B*/A*
Bstar=wp*wp;
Astar=[1 2*wp wp*wp];
modele_reference=tf(Bstar,Astar);

%Calcul des objets syst�mes pour le sch�ma simulink(Code a demasquer pour
%faire l essai du regulateur 3)
[Rn_tf,Rd_tf,Rp_tf]= mise_en_oeuvre2(Rn_4,Rd_4,Rp_4);

%%
%Essai sous Simulink
%S�lection des signaux d excitation
consigne_bf=1;
pertu_bf=0;


