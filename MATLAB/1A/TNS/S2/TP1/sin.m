%%%%%%%%%%%% SIN %%%%%%%%%%%%
% CLEAR
clc
clear
close all
% LOAD
load sig1_quidonc.mat
% CODE
N=length(xk);
Ts=1/Fs;
t=0:Ts:(N-1)*Ts;

% FIGURE
stem(t,xk)



