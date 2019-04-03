%%%%%%%%%%% FFT SIN %%%%%%%%%%%
% CLEAR
clc
clear
close all
% LOAD
load sig1_quidonc.mat
% CODE
N=length(xk);
Ta=N/Fs;
f=0:1/Ta:Fs-1/Ta;
% FIGURE
stem(f,abs(fftshift(fft(xk))))

