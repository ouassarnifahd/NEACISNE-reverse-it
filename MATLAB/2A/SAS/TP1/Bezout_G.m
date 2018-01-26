function [sbez,rbez]=Bezout_G(abez,bbez,pbez)

%solution generale d'une equation de BEZOUT
% = la division polynomiale
% augmentation du degre de S
% les retards sont integres dans B
%
% 	abez * sbez + bbez * rbez = pbez
%
%function [sbez,rbez]=bezout_G(abez,bbez,pbez)

na = size(abez, 2) - 1;
nb = size(bbez, 2) - 1;
np = size(pbez, 2) - 1;
nr = na - 1;
ns = max(nb - 1, np - na);

% Matrice de Toeplitz colonne par colonne
% Coefficients de S
Mbez = [abez'; zeros(ns, 1)];
for i= 1 : ns
	Madd = [zeros(i, 1); abez'; zeros(ns - i, 1)];
	Mbez = [Mbez Madd];
end

%coefficients de R
for i= 0 : nr
	Madd = [zeros(i, 1); bbez'; zeros(na + ns - nb - i, 1)];
	Mbez = [Mbez Madd];
end

phi = [pbez zeros(1, na + ns - np)];
result = inv(Mbez) * phi';
sbez = (result(1 : ns + 1))';
rbez = (result(ns + 2 : ns + 1 + na))';
