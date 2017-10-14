% Fonction de tracé temporel, frequenciel et d'autocorrelation
% d'un signal sinusuidal
%
% -- acorr(A, f0, fe, N)
% A : amplitude du signal
% f0: frequence du signal
% Fe: frequence d'echantillonnage
% N : Nombre d'echantillons

function xb = acorr(A, f0, Fe, N)

Te = 1 / Fe;
Ta = N * Te;

% Trace temporel
t = 0 : Te : Ta - Te;
x = A * sin(2 * pi * f0 *t);
% subplot(411);
% stem(t, x);
% xlabel('Temps(s)');
% ylabel('Amplitude');
% title('Signal sinusuidal');

% Trace frequenciel
% f = 0 : 1 / Ta : Fe - 1 / Ta;
% subplot(412);
% stem(f, abs(fft(x)));
% xlabel('frequence(Hz)');
% ylabel('|X(f)|');
% title('Spectre de x');

% Fonction d'autocorrelation de x
% forme biaisee
% Rxx(k) = 1/N * sum_i=1:N-k_(x(i) * conj(x(i+k)))
Rxxb = zeros(1, N);
Rxxnb = zeros(1, N);
for k = 0 : N - 1
    tmp = [x(1 : N - k)] * [conj(x(k + 1: end))]';
    Rxxb(k + 1) = tmp / N;
    Rxxnb(k + 1) = tmp / (N - k);
end
Rxxbf = [fliplr(Rxxb(2 : end)) Rxxb];
Rxxnbf = [fliplr(Rxxnb(2 : end)) Rxxnb];

n = 1 - N : N - 1;
% subplot(421);
% plot(n * Te, Rxxbf);
% hold on;
% plot(n * Te, Rxxnbf, '-r');
% legend('biaisee', 'non biaisee');

% resultat xcorr MATLAB
% subplot(422);
% plot(n * Te, Rxxbf);
% [Rxcorr, ec] = xcorr(x , 'biased');
% hold on;
% plot(ec, Rxcorr, '-.r');
% legend('acorr', 'xcorr');

% bruit blanc
xb = x + acorrb(0, 0.5, N);
subplot(211);
stem(t, xb);
subplot(212);
Rxx2b = zeros(1, N);
Rxx2nb = zeros(1, N);
for k = 0 : N - 1
    tmp = [xb(1 : N - k)] * [conj(xb(k + 1: end))]';
    Rxx2b(k + 1) = tmp / N;
    Rxx2nb(k + 1) = tmp / (N - k);
end
Rxx2bf = [fliplr(Rxx2b(2 : end)) Rxx2b];
Rxx2nbf = [fliplr(Rxx2nb(2 : end)) Rxx2nb];

plot(n * Te, Rxx2bf);
hold on;
plot(n * Te, Rxx2nbf, '-r');
legend('biaisee', 'non biaisee');

end
