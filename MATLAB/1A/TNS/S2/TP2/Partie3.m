%%%%%%%%%%%% PARTIE III %%%%%%%%%%%%
% CLEAR
clc
clear
close all
% CODE

for power=2:6
    tic;
    X=[rand + zeros(1,2^power)]*W(2^power);
    toc;
end