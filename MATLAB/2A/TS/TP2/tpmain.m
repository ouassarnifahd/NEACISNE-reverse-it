% TP main test de fonction
close all
clear all

% pkg load signal % OCTAVE-ONLY

load data_BE1

%% 2.1.1

subplot(211);
stem(sig_q1(1:100));
subplot(212);
[Rxx, ec] = xcorr(sig_q1(1:100), 'unbiased');
plot(ec, Rxx);
hold on;
[Rxxb, ec] = xcorr(sig_q1(1:100), 'biased');
plot(ec, Rxxb), '.-r';
legend('unbiased', 'biased');

%% 2.1.2

subplot(221);
[Rxx1, ec] = xcorr(sig_emis(1:1000), 'unbiased');
plot(ec, Rxx1);
hold on;
[Rxxb1, ec] = xcorr(sig_emis(1:1000), 'biased');
plot(ec, Rxxb1, 'r');
subplot(222);
[Rxx2, ec] = xcorr(sig_retour(1:1000), 'unbiased');
plot(ec, Rxx2);
hold on;
[Rxxb2, ec] = xcorr(sig_retour(1:1000), 'biased');
plot(ec, Rxxb2, 'r');
subplot(212);
[Rxy, ec] = xcorr(sig_emis(1:1000), sig_retour(1:1000), 'unbiased');
plot(ec, Rxy);
hold on;
[Rxyb, ec] = xcorr(sig_emis(1:1000), sig_retour(1:1000), 'biased');
plot(ec, Rxyb, 'r');

%% 2.1.3

subplot(311);
[Rxx, ec] = xcorr(sig_spectral(1:20), 'unbiased');
plot(ec, Rxx);
hold on;
[Rxxb, ec] = xcorr(sig_spectral(1:20), 'biased');
plot(ec, Rxxb, 'r');
legend('unbiased', 'biased');
subplot(312);
stem(abs(fft(sig_spectral)));
subplot(313);
[Rxx, ec] = xcorr(sig_spectral(1:20), 'unbiased');
plot(ec, abs(fft(Rxx)));
hold on;
[Rxxb, ec] = xcorr(sig_spectral(1:20), 'biased');
plot(ec, abs(fft(Rxxb)), 'r');
legend('unbiased', 'biased');

%% 2.2.1

rands = sign(randn(1, 127));
B = [2 3];
A = [1];
fltrdsig = filter(B, A, rands);

subplot(211);
[Rxx, ec] = xcorr(fltrdsig, 10, 'biased');
stem(ec, Rxx);
subplot(212);
[Rxy, ec] = xcorr(fltrdsig, rands, 10,'biased');
stem(ec, Rxy);

%% 2.2.2

rands = sign(randn(1, 127));
B = [0.3];
A = [1 -0.7];
fltrdsig = filter(B, A, rands);

subplot(211);
[Rxx, ec] = xcorr(fltrdsig, 10, 'biased');
stem(ec, Rxx);
subplot(212);
[Rxy, ec] = xcorr(fltrdsig, rands, 10,'biased');
stem(ec, Rxy);

%% 2.2.3 Mystere...
