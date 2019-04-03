% linear search of Armijo Uzawa
%
% -- armijo(fx, grad_fx, gx, jacob_gx, hx, jacob_hx, mu_l, lambda_l, xk, dk)
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
% lambda_l : parameter (real)
% mu_l     : parameter (real)
% xk       : vector (size n)
% dk       : direction vector (size n)

function alpha = armijo(fx, grad_fx, gx, jacob_gx, hx, jacob_hx, lambda_l ,mu_l, xk, dk)
    alpha = 0.5; epsilon = 0.5;
    lagrange = fx(xk) - lambda_l' * gx(xk) + mu_l' * hx(xk);
    grad = grad_fx(xk) - jacob_gx(xk)' * lambda_l + jacob_hx(xk)' * mu_l;

    while fx(xk + alpha * dk) - lambda_l' * gx(xk + alpha * dk) + mu_l' * hx(xk + alpha * dk) > lagrange + epsilon * alpha * grad' * dk
        alpha = alpha / 2;
    end
end
