%%%%%%%%%% FILTRE %%%%%%%%%%%
% CLEAR
clc
clear
close all

% Filtrage
Fs  = 8000;
Fp  = 2500; % freq parasite
Rp  = 0.1;
Rs  = 0.9;
Bc  = 400;  % 1/2 bande coupe
dWs = 50;   % largeur de coupure

Wp1 = (Fp-Bc-dWs)/(Fs/2);
Ws1 = Wp1+dWs/(Fs/2);
Wp2 = (Fp+Bp+dWs)/(Fs/2);
Ws2 = Wp2 - 2*dWs/(Fs/2);

%% Butterworth_passe_bas
[N,Wn] = buttord(Wp1,Ws1,Rp,Rs);
[Num,Den]=butter(N,Wn);

% SIMULINK
sim('LockwoodFFT',[0 41]);
pause ;

%% Butterworth_passe_bande
[N,Wn] = buttord([Wp1 Wp2],[Ws1 Ws2],Rp,Rs);
[Num,Den]=butter(N,Wn,'stop');

% SIMULINK
sim('LockwoodFFT',[0 41]);
pause ;

%% Chebyshev1

[N,Wn]=cheb1ord([Wp1 Wp2],[Ws1 Ws2],Rp,Rs);
[Num,Den]=butter(N,Wn,'stop');

% SIMULINK
sim('LockwoodFFT',[0 41]);
pause ;

%% Chebyshev2

[N,Wn]=buttord([Wp1 Wp2],[Ws1 Ws2],Rp,Rs);
[Num,Den]=cheby1(N,0.02,Wn,'stop');

% SIMULINK
sim('LockwoodFFT',[0 41]);
pause ;

%% RIF (revoir)

[N,Wn]=buttord([Wp1 Wp2],[Ws1 Ws2],Rp,Rs);
Num=fir1(N,Wn,'stop');

% SIMULINK
sim('LockwoodFFT',[0 41]);
pause ;
