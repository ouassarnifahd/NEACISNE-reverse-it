%%%%%%%%%%%% Partie I %%%%%%%%%%%%
% CLEAR
clc
clear
close all
%%% CODE

%% General
Fs=3600;
Ts=1/Fs;

%% derivateur
NumD=[1 -1];
DenD=[Ts 0];
D=tf(NumD,DenD);
subplot(245);
pzmap(D);
[RfD,frD]=freqz(NumD,DenD,1024,Fs);
subplot(241);
plot(frD,abs(RfD)); grid;
title('Filtre Derivateur');

%% integrateur
NumI=[Ts 0];
DenI=[1 -1];
I=tf(NumI,DenI);
subplot(246);
pzmap(I);
[RfI,frI]=freqz(NumI,DenI,1024,Fs);
subplot(242);
plot(frI,abs(RfI)); grid;
title('Filtre Integrateur');

%% moyenneur
NumM=[1 1 1 1 1];
DenM=[1 0 0 0 0];
M=tf(NumM,DenM);
subplot(247);
pzmap(M);
[RfM,frM]=freqz(NumM,DenM,1024,Fs);
subplot(243);
plot(frM,abs(RfM)); grid;
title('Filtre Moyenneur (k=5)');

%% notch
f0=600;
w0=2*pi*f0;
NumN=[1 -2*cos(w0*Ts) 1];
r1=0.9;
r2=0.7;
DenN1=[1 -2*r1*cos(w0*Ts) r1*r1];
DenN2=[1 -2*r2*cos(w0*Ts) r2*r2];
N1=tf(NumN,DenN1);
N2=tf(NumN,DenN2);
subplot(248);
pzmap(N1,N2);
legend('R=0.9','R=0.7',4);
[RfN1,frN1]=freqz(NumN,DenN1,1024,Fs);
[RfN2,frN2]=freqz(NumN,DenN2,1024,Fs);
subplot(244);
plot(frN1,abs(RfN1),frN2,abs(RfN2),'-g'); grid;
legend('R=0.9','R=0.7',4);
title('Filtre Notch Elementaire');
