%%%%%%%%%%%% PARTIE II %%%%%%%%%%%%
% CLEAR
clc
clear
close all
% CODE 
N1=8000;
k1=500;
t1=0:1/N1:1-1/N1;
[X1,x1]=cosX(N1,k1);
%stem(t1,x1);

N2=4000;
k2=400;
t2=0:1/N1:0.5-1/N1;
[X2,x2]=sinX(N2,k2);
stem(t2,x2);