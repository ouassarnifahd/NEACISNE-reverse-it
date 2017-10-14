%%%%%%%%%%%% PARTIE I %%%%%%%%%%%%
% CLEAR
clc
clear
close all
% CODE 
W=[1 1 1 1; 1 -i -1 i; 1 -1 1 -1; 1 i -1 -i];
X=[1 3 -1 2];
Winv=inv(W);
% RESULTAT
Xfft=fft(X);
Xf=X*W;
Xt=abs(Xfft*Winv);
Xifft=ifft(Xf);