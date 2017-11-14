#include <iostream>
#include "fraction.hpp"

Fraction::Fraction(const long& num, const long& den): num_(num), den_(den) {
    // this->num_ = num; // Danger si c'est une const
    // this->den_ = den; // Danger si c'est une const
    this->reduce();
}

void Fraction::reset(const long& num, const long& den) {
    this->num_ = num;
    this->den_ = den;
}

void Fraction::reduce() {
    long num = getNum(), den = getDen();
    bool signe = (num < 0) ^ (den < 0);
    #define _ABS(x) x < 0 ? -x : x
    num = _ABS(num);
    den = _ABS(den);

    { // div euclidienne Entiere
        long a = num, b = den, q = 0, r = 1;
        while (r > 0) {
            // cout << a << " = " << a / b << " * " << b << " + " << a % b << endl;
            q = a / b;
            r = a % b;
            a = b;
            b = r;
        }
        num /= a;
        den /= a;
    }

    this->num_ = (signe) ? -num : num;
    this->den_ = den;
}

const long& Fraction::getNum() const {
    return this->num_;
}

const long& Fraction::getDen() const {
    return this->den_;
}

std::ostream Fraction::print() {
    std::ostream toString(std::cout);
    toString << getNum() << " / " << getDen();
    return toString;
}

std::ostream Fraction::println() {
    return getNum() << " / " << getDen() << std::endl;
}
