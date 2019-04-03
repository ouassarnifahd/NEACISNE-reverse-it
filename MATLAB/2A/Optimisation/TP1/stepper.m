% Algorithme du gradient a pas optimal
%
% -- stepper(fx, grad_fx, X0, Tol, lsearch, p, nmax)
%
% fx      : vectorial function
%           -- fx(X, p)
% grad_fx : gradient function of fx
%           -- grad_fx(X, p)
% X0      : start vector (taille 2)
% Tol     : tolerance
% lsearch : linear search function
%           -- lsearch1(fx, grad_fx, xk, dk, p) (sélection d'Aramijo)
%           -- lsearch2(fx, grad_fx, xk, dk, p) (Interpolation parabolique)
% p       : parametre (reel)
% nmax    : nombre max d'iteration

function [xmin, fmin, N] = stepper(fx, grad_fx, X0, Tol, lsearch, p, nmax)
    % /!\ A analyser MATLAB
    % clf;
    % % fig = colordef(gcf, 'white');
    % echo off
    % clc
    % xx = [-2:0.1:2]';
    % yy = [-2:0.1:4]';
    % [x,y] = meshgrid(xx',yy') ;
    % meshd = (x-1).^2+p*(x.^2-y).^2;
    % figure(1);
    % set(1,'defaultaxesxgrid','on','defaultaxesygrid','on', ...
    %       'defaultaxeszgrid','on','defaultaxesbox','on');
    % conts = exp(0.01:10);
    % xlabel('x1'),ylabel('x2'),title('Minimization de la fonction en banane');
    % [C,H] = contour(xx,yy,meshd,conts,'k:');
    % clabel(C);

    xk = X0;
    prec = 10 * Tol;
    N = 0;
    % buf = [X0'];
    % text(X0(1), X0(2), 'Debut');
    while prec > Tol
        if N < nmax
            dk = -grad_fx(xk, p);
            alphak = lsearch(fx, grad_fx, xk, dk, p);
            xk1 = xk + alphak * dk;
            prec = norm(xk1 - xk)/norm(xk);
            xk = xk1;
            % fk = fx(xk, p);
            N = N + 1;
            % buf = [buf ; xk'];
        else
            display('Nombre max iterations depassee');
            break;
        end
    end
    % plot(buf(:,1), buf(:,2));
    xmin = xk;
    fmin = fx(xk, p);
end
