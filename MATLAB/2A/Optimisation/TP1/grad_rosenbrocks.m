% Gradient de la fonction banane de Rosenbrocks
%
% -- grad_rosenbrocks(X, p)
%
% X : vecteur (taille 2)
% p : parametre (reel)

function grad = grad_rosenbrocks(X, p)
    gr1 = 2 * (X(1) - 1) + 4 * p * X(1) * (X(1) * X(1) - X(2));
    gr2 = - 2 * p * (X(1) * X(1) - X(2));
    grad = [gr1; gr2];
end
