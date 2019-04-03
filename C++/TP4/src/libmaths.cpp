#include "libmaths.hpp"

Fraction exp(const Fraction& x) {
    Fraction exp_(1, 1);
    Fraction powx(1, 1);
    Fraction fact(1, 1);
    for (long i = 0; i < N; i++) {
        fact = fact * (i + 1);
        powx = powx * x;
        exp_ = exp_ + powx / fact;
    }
    return exp_;
}
