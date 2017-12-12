% TP main test de fonction
% close all
clear all

pkg load control % OCTAVE-ONLY

%% Choose your system (1,2,3)
sys = 1;

%% Temps
Tsim = 30; % Tsim = 30s
Te = 0.15; % Te = 0.2s
t = 0 : Te : Tsim - Te;

%% Signaux...
N = length(t);
Au = 1;
Ay = 1;
Nu = floor(N / 10);
Ny = 3 * Nu;

% perturbation_entree
C_ = [1];
D_ = [1 -1];

% perturbation_sortie
C = [1];
D = [1 -1];

%% SYS:
if sys == 1
  % Procedes electrique
  Num = [1.5];
  Den = [2.2 1 0];
elseif sys == 2
  % Bille sur le rail
  Num = [1.724];
  Den = [2 0 0];
elseif sys == 3
  % Bras flexible
  Num = [1.87];
  Den = [1 0];
else
  % NULL
  Num = [1];
  Den = [1];
endif

Gp1 = tf(Num, Den);
G1 = c2d(Gp1, Te, 'zoh');
G1.variable = 'z^-1';
A = G1.den{1};
B = G1.num{1};

%% regulateur
khi = 1;
w0 = 2;

% Pc
Pc_ = [1 (2 * khi * w0) (w0 * w0)];
zr = exp(roots(Pc_) .* Te);
Pc_d = [1 -zr(1)];
for k=2:length(zr)
    Pc_d = conv(Pc_d, [1 -zr(k)]);
end

npc_aux = length(A) + length(B) + length(D) - length(Pc_d) - 5;
mu = 10;
zraux = exp(- mu * W0 * Te);
Pc_aux = [1];
for k=1:npc_aux
    Pc_aux = conv(Pc_aux, [1 -zraux]);
end

Pc = conv(Pc_aux, Pc_d);

% Bezou Pc = (A*D) * S + B * Rn;
[S, Rn] = Bezout_G(conv(A, D), B);

Rd =

% LSIM
