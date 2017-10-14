% linear search function 1 (sélection d'Aramijo)
%
% -- lsearch1(fx, grad_fx, xk, dk, p)
%
% fx      : vectorial function
%           -- fx(X, p)
% grad_fx : gradient function of fx
%           -- grad_fx(X, p)
% xk      : vecteur (taille 2)
% dk      : direction (taille 2)
% p       : parametre (reel)

function alpha = lsearch1(fx, grad_fx, xk, dk, p)
    alpha = 0.5; epsilon = 0.5;
    val = fx(xk, p);
    grad = grad_fx(xk, p);
    while fx(xk + alpha * dk, p) > val + epsilon * alpha * grad' * dk
        alpha = alpha / 2;
    end
end
