% Fonction d'autocorrelation
% d'un bruit blanc
%
% -- acorrb(m, V, N)
% m : moyenne du signal
% V : variance du signal
% N : Nombre d'echantillons

function x = acorrb(m, V, N)

Te = 1;
Ta = N * Te;

t = 0 : Te : Ta - Te;
x = m + sqrt(V) * randn(1, N);

Rxxb = zeros(1, N);
Rxxnb = zeros(1, N);
for k = 0 : N - 1
    tmp = [x(1 : N - k)] * [conj(x(k + 1: end))]';
    Rxxb(k + 1) = tmp / N;
    Rxxnb(k + 1) = tmp / (N - k);
end
Rxxbf = [fliplr(Rxxb(2 : end)) Rxxb];
Rxxnbf = [fliplr(Rxxnb(2 : end)) Rxxnb];

% n = 1 - N : N - 1;
% plot(n * Te, Rxxbf);
% hold on;
% plot(n * Te, Rxxnbf, '-r');
% legend('biaisee', 'non biaisee');

end
