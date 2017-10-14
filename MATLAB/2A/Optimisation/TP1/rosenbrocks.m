% Fonction banane de Rosenbrocks
%
% -- rosenbrocks(X, p)
%
% X : vecteur (taille 2)
% p : parametre (reel)

function fx = rosenbrocks(X, p)
    fx = (X(1) - 1) * (X(1) - 1) + p * (X(1) * X(1) - X(2)) * (X(1) * X(1) - X(2));
end
