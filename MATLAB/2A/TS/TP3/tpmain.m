% TP main test de fonction
close all
clear all

% pkg load signal % OCTAVE-ONLY

%% I.

sig = script(5000);
moyenne = mean(sig);
variance = cov(sig);

subplot(211);
[Rxx, ec] = xcorr(sig(1:20), 'unbiased');
plot(ec, Rxx);
hold on;
[Rxxb, ec] = xcorr(sig(1:20), 'biased');
plot(ec, Rxxb, 'r');
legend('unbiased', 'biased');
subplot(212);
[Rxx, ec] = xcorr(sig(1:20), 'unbiased');
plot(ec, abs(fft(Rxx)));
hold on;
[Rxxb, ec] = xcorr(sig(1:20), 'biased');
plot(ec, abs(fft(Rxxb)), 'r');
legend('unbiased', 'biased');

%% II.
