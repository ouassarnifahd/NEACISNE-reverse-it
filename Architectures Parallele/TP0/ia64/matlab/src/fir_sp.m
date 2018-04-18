%**********
% File :    fir_sp.m
% Author :  Hugo Descoubes
% brief :   FIR filtering algorithm in floating point single precision
% http://www.mathworks.fr/fr/help/fixedpoint/ug/convert-fir-filter-to-fixed-point-with-types-separate-from-code.html
% date :    june 2014
%**********
function yk = fir_sp(xk, coeff, coeffLength, ykLength)
    yk = single(zeros(1,ykLength));    % output array preallocation
    
    % output array loop
    for i=1:ykLength
        yk(i) = single(0);
        
        % FIR filter algorithm - dot product
        for j=1:coeffLength
            yk(i) = single(yk(i)) + single(coeff(j)) * single(xk(i+j-1));
        end
    end
end




