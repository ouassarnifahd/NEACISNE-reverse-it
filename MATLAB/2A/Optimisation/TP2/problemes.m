% Problemes TP2
close all
clear all

% pkg load signal % OCTAVE-ONLY

%% Pb1

pb1_fx = @(x) 2 * (x(1) * x(1)) + 3 * (x(1) * x(2)) + 2 * (x(2) * x(2));

pb1_grad_fx = @(x) [4 * x(1) + 3 * x(2); 4 * x(2) + 3 * x(1)];

pb1_gx = @(x) [0];

pb1_jacob_gx = @(x) [0 0];

pb1_hx = @(x) [x(1) + 0.5; x(2) + 0.5];

pb1_jacob_hx = @(x) [1 0; 0 1];

%% Pb2

pb2_fx = @(x) x * x + 10 * sin(x);

pb2_grad_fx = @(x) 2 * x + 10 * cos(x);

pb2_gx = @(x) [0];

pb2_jacob_gx = @(x) [0];

pb2_hx = @(x) [2 - x; x - 10];

pb2_jacob_hx = @(x) [-1 1];

%% Pb3

pb3_fx = @(x) x' * [5 3 1; 3 2 1; 1 1 4] * x;

pb3_grad_fx = @(x) [2 * [5 3 1; 3 2 1; 1 1 4] * x];

pb3_gx = @(x) [3 * x(1) - 2 * x(2) - x(3)];

pb3_jacob_gx = @(x) [3 -2 -1];

pb3_hx = @(x) [x(1) + x(2) - x(3)];

pb3_jacob_hx = @(x) [1 1 -1];

%% Pb4

pb4_fx = @(x) 0.5 * (x - [1; 1; 1; 1])' * (x - [1; 1; 1; 1]);

pb4_grad_fx = @(x) [x - [1; 1; 1; 1]];

pb4_gx = @(x) [[3 1 0 2] * x - 1];

pb4_jacob_gx = @(x) [3 1 0 2];

pb4_hx = @(x) [0];

pb4_jacob_hx = @(x) [0 0 0 0];
