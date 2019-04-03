% TP main test de fonction
% close all
clear all

pkg load control % OCTAVE-ONLY

%% Choose your perturbations ('Echelon','Sin4rad','Sin7rad')

perturbation_entree = 'Echelon';

perturbation_sortie = '';

%% Choose your regulator (1,2,3)
regulateur = 1;

%% Temps
Tsim = 30; % Tsim = 30s
Te = 0.2; % Te = 0.2s
t = 0 : Te : Tsim - Te;

%% Signaux...
N = length(t);
Au = 1;
Ay = 1;
Nu = floor((Tsim / Te) / 10);
Ny = 3 * Nu;

switch perturbation_entree
  case 'Echelon'
    Vu = [ zeros(1, Nu) Au .* ones(1, N - Nu)];
  case 'Sin4rad'
    Vu = [ zeros(1, Nu) Au .* sin(4 .* t(1:N - Nu))];
  case 'Sin7rad'
    Vu = [ zeros(1, Nu) Au .* sin(7 .* t(1:N - Nu))];
  otherwise
    Vu = zeros(1, N);
endswitch

switch perturbation_sortie
  case 'Echelon'
    Vy = [ zeros(1, Ny) Ay .* ones(1, N - Ny)];
  case 'Sin4rad'
    Vy = [ zeros(1, Ny) Ay .* sin(4 .* t(1:N - Ny))];
  case 'Sin7rad'
    Vy = [ zeros(1, Ny) Ay .* sin(7 .* t(1:N - Ny))];
  otherwise
    Vy = zeros(1, N);
endswitch

%% SYS: G(z)
Num = [1.5];
Den = [2.2 1 0];
Gp = tf(Num, Den);
Gz = c2d(Gp, Te, 'zoh');
Gz.variable = 'z^-1';

%% Regulateurs/Correcteurs
switch regulateur
  case 1
    R = [1];
    SDr = [5];
  case 2
    R = [57.6 -95.12 40.3];
    SDr = [1 -0.43 -0.57];
  case 3
    R = [87 -200 172 -54];
    SDr = [1 -0.635 -0.056 0.758];
  otherwise
    R = [1];
    SDr = [1];
endswitch

Rr = tf(R, SDr, Te, 'variable', 'z^-1');

%% Boucle Ouverte
Gbo = Rr * Gz;

Tvy_y = 1 / (1 + Gbo);
Tvu_y = Gz / (1 + Gbo);
Tvy_u = Rr / (1 + Gbo);
Tvu_u = -Gbo / (1 + Gbo);

%% Nichols
% nichols(Gz,Gbo);

%% SIM
y = lsim(Tvy_y, Vy, t) + lsim(Tvu_y, Vu, t);
u = lsim(Tvy_u, Vy, t) + lsim(Tvu_u, Vu, t);

%% PLOT
figure;
subplot(211);
plot(t,u);
grid;
title('Simulation de u(t)');
xlabel('Time (s)');
ylabel('Amplitude');
subplot(212);
plot(t,y);
grid;
title('Simulation de y(t)');
xlabel('Time (s)');
ylabel('Amplitude');
