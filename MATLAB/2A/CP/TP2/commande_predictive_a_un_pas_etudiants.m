%TP Commande predictive a un pas sur le robot manipulateur

close all

pkg load control % OCTAVE-ONLY

sys_sans_retard = tf(1, [1.5 1]);
retard = 2 * 1.28 + 0.005;
Te = 0.285;
sys_discret = c2d(sys_sans_retard, Te, 'zoh')

%Modele echantillonne non retarde
B = [0.276865 -0.103825];
A = [1 -0.826959];

%A completer
d = floor(retard/Te); %retard en plus du bloqueur

%Determination des parametres d un precdicteur a d+1 pas
%prenant en compte les perturbations de type echelon



%Chargement de donnees de simulation pour le bruit de capteur
load bruit.dat;
n = length(bruit);
temps = 0 : Te : (n - 1) * Te;

%Analyse spectrale du bruit de capteur
figure(1);


%Synthese du filtre pour attenuer le bruit de capteur(ponderation frequentielle H/W')


%Calcul du filtre complet H/W (W = W'D)





%Calcul du polynome caracteristique P sur le systeme non retarde avec le
%filtre H/W pr�c�demment calcul�


%Affichage de la position des p�les en boucle ferm�e : qu en pensez vous ?





%Le p�les du syst�me en boucle en ferm�e ne sont pas n�cessairement situ�s � un
%endroit judicieux. Nous allons modifier le filtre H/W en le multipliant
%par un gain mu. Ce gain va �tre calcul� pour d�placer les p�les de la
%boucle ferm�e � un endroit plus ad�quat.



%Determination du gain mu par la methode du Lieu des racines en d�placant
%les p�les de la boucle ouverte
%utiliser la fonction matlab rlocus()




%Recalcul du filtre mu*H/W  (on introduit mu dans H)



%Affichage des diagrammes de Bode des fonctions de transfert demand�es




%Analyse des performances du syst�me de commande sous Simulink
