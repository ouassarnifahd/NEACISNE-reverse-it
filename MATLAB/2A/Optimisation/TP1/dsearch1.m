% direction search function 1 (Fletcher-Reeves)
%
% -- dsearch1(grad_fx, xk, alphak, dk, p)
%
% grad_fx : gradient (taille 2) -- grad_fx(X, p);
% xk1     : vecteur (taille 2)
% xk      : vecteur (taille 2)
% p       : parametre (reel)

% d(k+1) = - grad_fx(k+1) + beta(k) * d(k)

function beta = dsearch1(grad_fx, xk1, xk, p)
    beta_num = norm(grad_fx(xk1, p)) * norm(grad_fx(xk1, p));
    beta_den = norm(grad_fx(xk, p)) * norm(grad_fx(xk, p));
    beta = beta_num / beta_den;
end
