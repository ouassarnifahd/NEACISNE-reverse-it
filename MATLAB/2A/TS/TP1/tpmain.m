% TP main test de fonction
close all
clear all

pkg load signal % OCTAVE-ONLY

% I)
% a) signal sinusuidal
% figure(1);
% acorr(1, 0.1, 1, 50);
%
% % b) bruit blanc
% % 1) rand -> uniforme & randn -> gaussien
% x = randn(1, 1000);
% y = rand(1, 1000);
% figure(2);
% hist(x);
% figure(3);
% hist(y);
%
% % 2)
% puissance = x * x' / length(x);
%
% % 3)
% moyenne = mean(x);
%
% % 4) Thm Central limite b = m + sqrt(V) * randn(1, N);
% % 5-6)
% % figure(4);
% % b = acorrb(2, 3, 100);
%
% % 7)
% % moyenne = sqrt(mean(Rxxnb));
% % puissance = max(b);
%
% % 8)
% figure(5);
% acorrb(2, 3, 1000);
%
% % c)
% xbruit = acorr(1, 0.1, 1, 500);
%
% % 1) V = 1/2
% P = xbruit * xbruit' / 500;

% 2) Non, SNR = 0dB le signal et le bruit sont confondu
% 3) max = 1
% 4) graphiquement on a le max = puissance du signal et la pseudo-periode est la periode du signal sinusuidal

% II)

% bruitblanc = randn(1, 1000);
% bruitblanc100 = bruitblanc(1:100);
% bruitblanc20 = bruitblanc(1:20);
% moy100 = mean(bruitblanc100);
% moy20 = mean(bruitblanc20);
%
% subplot(311);
% [Rxxb, ec] = xcorr(bruitblanc, 20, 'biased');
% plot(ec, Rxxb);
% hold on;
% [Rxxnb, ec] = xcorr(bruitblanc, 20, 'unbiased');
% plot(ec, Rxxnb);
% title('bruitblanc');
% legend('biaisee', 'non biaisee');
%
% subplot(312);
% [Rxxb, ec] = xcorr(bruitblanc100, 20, 'biased');
% plot(ec, Rxxb);
% hold on;
% [Rxxnb, ec] = xcorr(bruitblanc100, 20, 'unbiased');
% plot(ec, Rxxnb);
% title('bruitblanc100');
% legend('biaisee', 'non biaisee');
%
% subplot(313);
% [Rxxb, ec] = xcorr(bruitblanc20, 20, 'biased');
% plot(ec, Rxxb);
% hold on;
% [Rxxnb, ec] = xcorr(bruitblanc20, 20, 'unbiased');
% plot(ec, Rxxnb);
% title('bruitblanc20');
% legend('biaisee', 'non biaisee');

% III) Google Trends ...
