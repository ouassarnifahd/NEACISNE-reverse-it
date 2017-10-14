% linear search function 2 (Interpolation parabolique) /!\ boucle infinie
%
% -- lsearch2(fx, grad_fx, xk, dk, p)
%
% fx      : vectorial function
%           -- fx(X, p)
% grad_fx : gradient function of fx
%           -- grad_fx(X, p)
% xk      : vecteur (taille 2)
% dk      : direction (taille 2)
% p       : parametre (reel)

function alpha = lsearch2(fx, grad_fx, xk, dk, p)
    alpha1 = 0; alpha3 = 1;
    f1 = fx(xk, p); f3 = fx(xk + alpha3 * dk, p);
    % cpt = 0;
    while f3 >= f1
        % if cpt == 10000
        %     break;
        % end
        alpha3 = alpha3 / 2;
        f3 = fx(xk + alpha3 * dk, p);
        % cpt = cpt + 1;
    end
    alpha2 = alpha3 / 2;
    f2 = fx(xk + alpha2 * dk, p);
    h1 = (f2 - f1)/alpha2;
    h2 = (f3 - f2)/alpha3;
    h3 = (h2 - h1)/(alpha3 - alpha2);
    alpha0 = 0.5 * (alpha2 - h1/h3);
    f0 = fx(xk + alpha0 * dk, p);
    if f0 < f3
        alpha = alpha0;
    else
        alpha = alpha3;
    end
end

% [X, Y] = meshgrid(-2:.2:2);
% Z = X .* exp(-X^2 -Y^2);
% surf(X,Y,Z);
