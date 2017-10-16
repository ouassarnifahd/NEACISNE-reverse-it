% Gradient de la fonction banane de Rosenbrocks
%
% -- grad_rosenbrocks(X, p)
%
% X : vecteur (taille 2)
% p : parametre (reel)

function grad = grad_rosenbrocks(X, p)
    x1 = X(1); x2 = X(2);
    gr1 = 2 * (x1 - 1) + 4 * p * x1 * (x1 * x1 - x2);
    gr2 = - 2 * p * (x1 * x1 - x2);
    grad = [gr1; gr2];
end
