clf; fig=colordef(gcf, 'white');

echo off
clc

xx = [-2:0.1:2]';
yy = [-2:0.1:4]';
[x,y]=meshgrid(xx',yy') ;

p=10;
 
meshd=(x-1).^2+p*(x.^2-y).^2;

figure(fig)

set(fig,'defaultaxesxgrid','on','defaultaxesygrid','on', ...
      'defaultaxeszgrid','on','defaultaxesbox','on')

conts = exp(0.01:10);

xlabel('x1'),ylabel('x2'),title('Minimization de la fonction en banane')
[C,H]=contour(xx,yy,meshd,conts,'k:');
clabel(C);
