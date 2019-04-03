% Fonction banane de Rosenbrocks
%
% -- rosenbrocks(X, p)
%
% X : vecteur (taille 2)
% p : parametre (reel)

function fx = rosenbrocks(X, p)
    x1 = X(1); x2 = X(2);
    fx = (x1 - 1) * (x1 - 1) + p * (x1 * x1 - x2) * (x1 * x1 - x2);
end
