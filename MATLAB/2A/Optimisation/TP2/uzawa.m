% Algorithme d'Uzawa
%
% -- uzawa(fx, grad_fx, gx, jacob_gx, hx, jacob_hx, X0, lambda0, mu0, ro, Tol, nmax)
%
% fx       : vectorial function
%            -- fx(X)
% grad_fx  : gradient function of fx (size n)
%            -- grad_fx(X)
% gx       : vectorial function (size p)
%            -- gx(X)
% jacob_gx : jacob function of gx (size p*n)
%            -- jacob_gx(X)
% hx       : vectorial function (size m)
%            -- hx(X)
% jacob_hx : jacob function of hx (size m*n)
%            -- jacob_hx(X)
% X0       : start vector (taille n)
% lambda0  : parameter (real)
% mu0      : parameter (real)
% ro       : parameter (real)
% Tol      : tolerance
% nmax     : nombre max d'iteration

function [xmin, fmin, N] = uzawa(fx, grad_fx, gx, jacob_gx, hx, jacob_hx, X0, lambda0, mu0, ro, Tol, nmax)
    err = 1;
    N = 0;
    lambda = lambda0;
    mu = mu0;
    X = X0;
    while err > Tol
        if N > nmax
            xk = X;
            prec = 10 * Tol;
            N2 = 0;
            while prec > Tol
                if N2 < nmax
                    dk = -grad_fx(X) + jacob_gx(X)' * lambda - jacob_hx(X)' * mu;
                    alpha = armijo(fx, grad_fx, gx, jacob_gx, hx, jacob_hx, lambda ,mu, X, dk);
                    X1 = X + alpha * dk;
                    prec = norm(X1 - X)/norm(X);
                    X = X1;
                    N2 = N2 + 1;
                else
                    display('Nombre max iterations depassee');
                    break;
                end
            end
            lambda = lambda + ro * gx(X);
            mu = max(zeros(length(mu),1), mu + ro * hx(X));
            err = norm(X - xk)/norm(X);
            N = N + 1;
        else
            display('Nombre max iterations depassee');
            break;
        end
    end
    xmin = X;
    % fmin = fx(X);
end
