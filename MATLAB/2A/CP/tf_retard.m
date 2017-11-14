function retard = tf_retard(ret, Te)
    Num_ret = zeros(1, ret + 1); Num_ret(1) = 1;
    Den_ret = zeros(1, ret + 1); Den_ret(ret + 1) = 1;
    retard = tf(Den_ret, Num_ret, Te, 'Variable','z^-1');
end
