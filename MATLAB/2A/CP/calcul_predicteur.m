%TP commande predictive 2014
%TP1 prediction optimale

clear all
close all

pkg load control % OCTAVE-ONLY

%Modele du systeme (sans le bloqueur : le bloqueur est rejoute dans le fichier Simulink)
%(A et B sont donc conformes aux notations du cours)
choice = 0; % MODIFY-ME

B = [0.0644];
A = [1.0000 -0.9556];
d = 0;        %retard en plus du bloqueur
ret = 1 + d;

%periode d echantillonnage
N = 300;
Te = 0.1;
Time = N * Te;
t = 0 : Te : Time - Te;

%Affichage de la config des poles du systeme
sys_ident = tf(B, A, Te, 'Variable','z^-1');

% Bruit Blanc
u = randn(1, N);

if choice == 1

elseif choice == 2

elseif choice == 3

else
    D = 1;
    C = 1;
endif

% precdicteur
[Ej, Fj] = bezou_z(conv(A, D), 1, ret, C);
sys_predi_y = tf(Fj ,C, Te, 'Variable','z^-1');
sys_predi_u = tf(conv(D, conv(B, Ej)), C, Te, 'Variable','z^-1');

% Retard
retard = tf_retard(ret, Te);

%Systemes
sys_retard = retard * sys_ident;

% Simulation
y = lsim(sys_ident, u, t);
u_retard = lsim(retard, u, t);
y_retard = lsim(sys_retard, u, t);

u_predicted = lsim(sys_predi_u, u_retard, t);
y_predicted = lsim(sys_predi_y, y_retard, t);


stem(t, y_retard);
hold on
stem(t, y_predicted);
