%%%%%%%%% FFT RECT BETTER %%%%%%%%%
% CLEAR
clc
clear
close all

% LOAD
load sig1_rect.mat

% GVars
Nb=5;

% CODE
N=length(xk);
Ta=N/Fs;
f=0:1/Ta:Fs-1/Ta;
Nbz=N*Nb;
xk1=[xk zeros(1,Nbz)];
N1=length(xk1);
Ta1=N1/Fs;
f1=0:1/Ta1:Fs-1/Ta1;

% FIGURE
stem(f1,abs(fftshift(fft(xk1))),'-r')
hold on
stem(f,abs(fftshift(fft(xk))))

