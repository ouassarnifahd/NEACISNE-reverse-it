% Analyse vocale
close all
clear all

pkg load signal % OCTAVE-ONLY

[Sound, Fs] = audioread('parole1.wav'); % wavread will be removed from Octave!
Ts = 1/Fs;
lenSound = length(Sound);
t = 0 : Ts : (lenSound - 1) * Ts;

% plot(t, Sound);

% Chunk DEF
Tchunk = 0.032; % 32ms
Tscroled  = 0.012; %12ms
lenScroled = floor(Tscroled * Fs);
lenChunk = floor(Tchunk * Fs);

Nchunks = floor((lenSound - lenChunk)/ lenScroled) + 1;

% Saves et Synthese
seuil_peaks = 0.53;
seuil_et = 0.001;
save_et = zeros(1, Nchunks);
ordreAR = 22;
save_AR = zeros(Nchunks, ordreAR);
save_dec = zeros(1, Nchunks);
save_To = zeros(1, Nchunks);

% Filtre passe bas fc=800Hz
Fc = 800;
ordreFiltre = 10;
[Num, Den] = butter(ordreFiltre, 2 * Fc / Fs);

% ANALYSE
for k = 1 : Nchunks,
    Chunk = Sound(1 + (k - 1) * lenScroled: lenChunk + (k - 1) * lenScroled);
    % stem(Chunk); pause 0.5;
    et = std(Chunk);
    if et > seuil_et,
        save_et(k) = et;
    else
        save_et(k) = 0;
    endif
     % Save ecart type
    if max(save_et) == 0,
        zeroAR = [1 zeros(1, ordreAR - 1)];
        save_AR(k,:) = zeroAR;
        save_dec(k) = 0;
        save_To(k) = 0;
    else
        save_AR(k,:) = aryule(Chunk, ordreAR - 1); % save resultat eq Yule Walker
        Chunk = filter(Num, Den, Chunk); % Filtrage du Bruit
        Chunk = resample(Chunk, 1, 5); % sous echantillonnage
        Chunk = Chunk .* hamming(length(Chunk))'; % Fenetrage Hamming
        Num_AR = aryule(Chunk, 4); % Estimation Filtre AR ordre 4
        Chunk = filter(Num_AR, 1, Chunk); % Filtrage AR
        stem(Chunk); pause 0.5;
        Chunk = Chunk .* hamming(length(Chunk))'; % Fenetrage Hamming
        [Chunkxx, ec] = xcorr(Chunk, 'biased'); % Autocorrelation
        % plot(ec, Chunkxx); pause 0.5;
        Chunkxx = Chunkxx ./ max(Chunkxx); % Normalisation autocorrelation
        [maxi, locs] = findpeaks(Chunkxx, 'MinPeakHeight', seuil_peaks, 'DoubleSided'); % Peaks!!
        if length(maxi) > 1,
            save_dec(k) = 1;
            save_To(k) = locs(3) - locs(2);
        else
            save_dec(k) = 0;
            save_To(k) = 0;
        endif
    endif
end

save -mat sound1_compressed.mat save_et save_AR save_dec save_To;
