%**********
% File :    matlabToHeader.m
% Author :  Hugo Descoubes
% brief :   export FIR coefficients and input vector from MATLAB format to
% C header format
% date :    june 2014
%**********
clear all
close all

%*** PARAMETERS
load coeff.mat                  % inport FIR coefficients     
Fs = 10000;                     % sample frequency 
F2 = 1000;                      % frequency harmonic n°2 (input vector)
F1 = 100;                       % frequency harmonic n°1 (input vector)
Ts = 1/Fs;                      % period frequency
%XK_LENGTH  = 2048;              % 2K/8Kb samples : length of input vector
XK_LENGTH = 65536;              % 64K/256Kb samples : length of input vector
%XK_LENGTH = 1048576;            % 1M/4Mb samples : length of input vector
t=0 : Ts : (XK_LENGTH-1)*Ts;    % time vector           
% WARNING : update Matlab current directory from workspace before
cd = pwd;

%*** COEFFICIENTS SINGLE PRECISION
a_sp = single(a);

fd_a_sp=fopen('coeff.h','wt');
fprintf(fd_a_sp,'#define A_LENGTH %d\n\n',length(a_sp));
fprintf(fd_a_sp,'// coefficients array in single precision\n');
fprintf(fd_a_sp,'float a_sp[A_LENGTH]={%.6g',a_sp(1));
fprintf(fd_a_sp,',%.6g',a_sp(2:end));
fprintf(fd_a_sp,'};\n\n');
    
%*** INPUT VECTOR SINGLE PRECISION
xk_sp = single(sin(2*pi*F1*t) + sin(2*pi*F2*t));   % input signal generation

fd_xk_sp=fopen('xk_sp.h','wt');
fprintf(fd_xk_sp,'#define XK_LENGTH %d\n\n',length(xk_sp));
fprintf(fd_xk_sp,'// input samples array in single precision\n');
fprintf(fd_xk_sp,'float xk_sp[XK_LENGTH]={%.6g',xk_sp(1));
fprintf(fd_xk_sp,',%.6g',xk_sp(2:end));
fprintf(fd_xk_sp,'};\n\n');
