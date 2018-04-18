%**********
% File :    main_sp.m
% Author :  Hugo Descoubes
% brief :   - test program for FIR filtering algorithm application
%           - input vector generation         
%           - temporal, frequency and system analysis
% date :    june 2014
%**********
clear all
close all

%*** PARAMETERS
load coeff.mat                          % inport FIR coefficients  
a_sp = single(a);
Fs = 10000;                             % sample frequency 
F2 = 1000;                              % frequency harmonic n°2 (input vector)
F1 = 100;                               % frequency harmonic n°1 (input vector)
Ts = 1/Fs;                              % period frequency
XK_LENGTH = 2048;                       % 2K/8Kb samples : length of input temporal vector
%XK_LENGTH = 1048576;                    % 1M/4Mb samples : length of input temporal vector
AK_LENGTH = length(a_sp);               % length of coefficients array
YK_LENGTH = XK_LENGTH - AK_LENGTH + 1;  % length of output temporal array
t=0 : Ts : (XK_LENGTH-1)*Ts;            % time vector
        
%*** INPUT ARRAY GENERATION
xk = single(sin(2*pi*F1*t) + sin(2*pi*F2*t)); 
xk_sp = single(xk);

%*** FIR FILTERING
yk_sp = fir_sp(xk_sp,a_sp,AK_LENGTH,YK_LENGTH);     % our algorithm
yk_sp = [single(zeros(1,AK_LENGTH - 1)) yk_sp];          
yk_matlab = filter(a,1,xk);                         % Matlab algorithm

%*** SIGNAL TEMPORAL ANALYSIS
figure
subplot(2,1,1);
plot(t,xk,'b');
title('digital signal filtering time scope - single precision');
grid on;
hold on;
plot(t,yk_matlab,'g');
hold on;
plot(t,yk_sp,'r');

%*** SIGNAL FREQUENCY ANALYSIS
window =  hanning(XK_LENGTH);       % window
xk_win = xk.*window';
yk_sp_win = yk_sp.*single(window)';

ZERO_PADDING = 12*XK_LENGTH;        % zero padding 
xk_win_padd = [xk_win  zeros(1,ZERO_PADDING)];
yk_sp_win_padd = [yk_sp_win  single(zeros(1,ZERO_PADDING))];
XK_PADD_LENGTH = length(xk_win_padd);

Fr = Fs/XK_PADD_LENGTH;              % frequency spectrum resolution
f=0 : Fr : (XK_PADD_LENGTH-1)*Fr;    % frequency vector
Xn = abs(fft(xk_win_padd));
Yn = single(abs(fft(yk_sp_win_padd)));

subplot(2,1,2);
plot(f,Xn,'b');
title('digital signal filtering spectrum - single precision');
grid on;
hold on
plot(f,Yn,'r');

%*** SYSTEM ANALYSIS
num=a;
den=1;
firFilter=tf(num,den,Ts,'Variable','z^-1');

figure
subplot(2,2,1);                     % z map display
pzmap(firFilter);
title('z map - single precision');
grid on;
subplot(2,2,2);
stem(a);                            % coefficients display
title('filter coefficients (impulse response) - single precision');
grid on;
subplot(2,2,3);
bodemag(firFilter);                    % bode magnitude display
title('magnitude bode - single precision');
grid on;
subplot(2,2,4);
bode(firFilter);                    % bode magnitude and phase display
title('magnitude and phase bode - single precision');
grid on;
