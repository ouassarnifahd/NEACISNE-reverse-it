%%%%%%%%%%%% Partie II %%%%%%%%%%%%

%% Derivateur
% CLEAR
clc
clear
close all
% LOAD
load sinus600.mat
scrsz = get(0,'ScreenSize');
figure('Name','Derivateur','NumberTitle','off','Position',[scrsz(3)/2 scrsz(4)/2 scrsz(3)/2 scrsz(4)/2.35]);
Fs=8000;
Ts=1/Fs;
Num=[1 -1];
Den=[Ts 0];

% REC
y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=Fs*(x2t(k)-x2t(k-1));
end;
subplot(241);
stem(y); title('sin600 REC');
% FILTER
subplot(245);
stem(filter(Num,Den,x2t)); title('sin600 FILTER');

% LOAD
load sinus1800.mat

y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=Fs*(x2t(k)-x2t(k-1));
end;
subplot(242);
stem(y); title('sin1800 REC');
subplot(246);
stem(filter(Num,Den,x2t)); title('sin1800 FILTER');

% LOAD
load carre600.mat

y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=Fs*(x2t(k)-x2t(k-1));
end;
subplot(243);
stem(y); title('carre600 REC');
subplot(247);
stem(filter(Num,Den,x2t)); title('carre600 FILTER');

% LOAD
load scie600.mat

y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=Fs*(x2t(k)-x2t(k-1));
end;
subplot(244);
stem(y); title('scie600 REC');
subplot(248);
stem(filter(Num,Den,x2t)); title('scie600 FILTER');

%% integrateur
% CLEAR
clc
clear
% LOAD
load sinus600.mat

scrsz = get(0,'ScreenSize');
figure('Name','Integrateur','NumberTitle','off','Position',[1 scrsz(4)/2 scrsz(3)/2 scrsz(4)/2.35]);
Fs=8000;
Ts=1/Fs;
Num=[Ts 0];
Den=[1 -1];
% REC
y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=y(k-1)+Fs*x2t(k);
end;
subplot(241);
stem(y); title('sin600 REC');
% FILTER
subplot(245);
stem(filter(Num,Den,x2t)); title('sin600 FILTER');

% LOAD
load sinus1800.mat

y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=y(k-1)+Fs*x2t(k);
end;
subplot(242);
stem(y); title('sin1800 REC');
subplot(246);
stem(filter(Num,Den,x2t)); title('sin1800 FILTER');

% LOAD
load carre600.mat

y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=y(k-1)+Fs*x2t(k);
end;
subplot(243);
stem(y); title('carre600 REC');
subplot(247);
stem(filter(Num,Den,x2t)); title('carre600 FILTER');

% LOAD
load scie600.mat

y=zeros(1,length(x2t));
for k = 2:1:length(x2t)
    y(k)=y(k-1)+Fs*x2t(k);
end;
subplot(244);
stem(y); title('scie600 REC');
subplot(248);
stem(filter(Num,Den,x2t)); title('scie600 FILTER');

%% moyenneur
% CLEAR
clc
clear
% LOAD
load sinus600.mat

scrsz = get(0,'ScreenSize');
figure('Name','Moyenne Mobile','NumberTitle','off','Position',[1 1 scrsz(3)/2 scrsz(4)/2.35]);

Num=[1 1 1 1 1];
Den=[1 0 0 0 0];
% REC
y=zeros(1,length(x2t));
for k = 5:1:length(x2t)
    y(k)=x2t(k)+x2t(k-1)+x2t(k-2)+x2t(k-3)+x2t(k-4);
end;
subplot(241);
stem(y); title('sin600 REC');
% FILTER
subplot(245);
stem(filter(Num,Den,x2t)); title('sin600 FILTER');

% LOAD
load sinus1800.mat

y=zeros(1,length(x2t));
for k = 5:1:length(x2t)
     y(k)=x2t(k)+x2t(k-1)+x2t(k-2)+x2t(k-3)+x2t(k-4);
end;
subplot(242);
stem(y); title('sin1800 REC');
subplot(246);
stem(filter(Num,Den,x2t)); title('sin1800 FILTER');

% LOAD
load carre600.mat

y=zeros(1,length(x2t));
for k = 5:1:length(x2t)
     y(k)=x2t(k)+x2t(k-1)+x2t(k-2)+x2t(k-3)+x2t(k-4);
end;
subplot(243);
stem(y); title('carre600 REC');
subplot(247);
stem(filter(Num,Den,x2t)); title('carre600 FILTER');

% LOAD
load scie600.mat

y=zeros(1,length(x2t));
for k = 5:1:length(x2t)
     y(k)=x2t(k)+x2t(k-1)+x2t(k-2)+x2t(k-3)+x2t(k-4);
end;
subplot(244);
stem(y); title('scie600 REC');
subplot(248);
stem(filter(Num,Den,x2t)); title('scie600 FILTER');

%% Filtre Notch
% CLEAR
clc
clear
% LOAD
load sinus600.mat

scrsz = get(0,'ScreenSize');
figure('Name','Filtre Notch','NumberTitle','off','Position',[scrsz(3)/2 1 scrsz(3)/2 scrsz(4)/2.35]);
Fs=8000;
Ts=1/Fs;
r=0.9;
f0=600;
w0=2*pi*f0;
Num=[1 -2*cos(w0*Ts) 1];
Den=[1 -2*r*cos(w0*Ts) r*r];
% REC
y=zeros(1,length(x2t));
for k = 3:1:length(x2t)
    y(k)=2*r*cos(w0*Ts)*y(k-1)-r*r*y(k-2)+x2t(k)-2*cos(w0*Ts)*x2t(k-1)+x2t(k-2);
end;
subplot(241);
stem(y); title('sin600 REC');
% FILTER
subplot(245);
stem(filter(Num,Den,x2t)); title('sin600 FILTER');

% LOAD
load sinus1800.mat

y=zeros(1,length(x2t));
for k = 3:1:length(x2t)
    y(k)=2*r*cos(w0*Ts)*y(k-1)-r*r*y(k-2)+x2t(k)-2*cos(w0*Ts)*x2t(k-1)+x2t(k-2);
end;
subplot(242);
stem(y); title('sin1800 REC');
subplot(246);
stem(filter(Num,Den,x2t)); title('sin1800 FILTER');

% LOAD
load carre600.mat

y=zeros(1,length(x2t));
for k = 3:1:length(x2t)
    y(k)=2*r*cos(w0*Ts)*y(k-1)-r*r*y(k-2)+x2t(k)-2*cos(w0*Ts)*x2t(k-1)+x2t(k-2);
end;
subplot(243);
stem(y); title('carre600 REC');
subplot(247);
stem(filter(Num,Den,x2t)); title('carre600 FILTER');

% LOAD
load scie600.mat

y=zeros(1,length(x2t));
for k = 3:1:length(x2t)
    y(k)=2*r*cos(w0*Ts)*y(k-1)-r*r*y(k-2)+x2t(k)-2*cos(w0*Ts)*x2t(k-1)+x2t(k-2);
end;
subplot(244);
stem(y); title('scie600 REC');
subplot(248);
stem(filter(Num,Den,x2t)); title('scie600 FILTER');
