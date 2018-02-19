% Clear
close all
clear all

% OCTAVE

%% BINARY 16-QUAM MSG
% 1.
Symbol = 4;
M = Symbol * Symbol;
N = 60 * M;

MSG = randsrc(1, N, 0:M-1);
F_MSG = 1;

MSG_QUAM = qammod(MSG, M);
F_MSG_QUAM = M * F_MSG;

MSG_QUAM_RCOS = rcosflt(MSG_QUAM, F_MSG, F_MSG_QUAM, 'fir', 0.5, 3);

%% I. Diagrammes de loeil et de constellation
% 2.
MSG_QUAM_RCOS_RE = real(MSG_QUAM_RCOS);
MSG_QUAM_RCOS_IM = imag(MSG_QUAM_RCOS);

% 3.
plot(MSG_QUAM_RCOS_RE);

% 4&5.
OFFSET = 0;
T_MSG = 1/F_MSG;
eyediagram(MSG_QUAM_RCOS_RE, 2 * F_MSG_QUAM, T_MSG, OFFSET);

% 6.
scatterplot(MSG_QUAM);
scatterplot(MSG_QUAM_RCOS);

% 7.
hold on;
scatterplot(MSG_QUAM_RCOS, 1, 0, 'c-');

%% II. Analyse d'un systeme de communication
% 2. MSG_GAUSSIAN_NOISE
SNR = 10;
MSG_TX = awgn(MSG_QUAM_RCOS, SNR, 'measured');

% 3. FILTER RCOS
MSG_RX = rcosflt(MSG_TX, F_MSG, F_MSG_QUAM, 'fir', 0.5, 3);

% 4. TRANSMISSION / RECEPTION
plot(real(MSG_TX));
hold on;
plot(real(MSG_RX));

% 5. DIAGRAMME DE L'OEIL
% eyediagram(MSG_RX, 2);

% 6. CONSTELLATION
scatterplot(MSG_RX);

% 7. Demodulation QUAM
MSG_RX_DQUAM = qamdemod(MSG_RX, M);

% 8. SOUS ECHANTILLONNAGE
MSG_RX_DQUAM_DS = downsample(MSG_RX_DQUAM, 3);

% 9. COMPARINGING MSG (source) and MSG_RX_DQUAM_DS (RX filtered)
% BER = biterr();
% SER = symerr()

% 10. ...
