n=50;
[t,y]=ode45(f,[0 10],0);
plot(t,y)