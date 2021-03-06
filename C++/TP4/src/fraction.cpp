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
    reduce();
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

Fraction Fraction::operator+(const Fraction& f) const {
    Fraction add(num_ * f.den_ + f.num_ * den_, den_ * f.den_);
    return add;
}

Fraction Fraction::operator-(const Fraction& f) const {
    Fraction sub(num_ * f.den_ - f.num_ * den_, den_ * f.den_);
    return sub;
}

Fraction Fraction::operator*(const Fraction& f) const {
    Fraction mul(num_ * f.num_, den_ * f.den_);
    return mul;
}

Fraction Fraction::operator/(const Fraction& f) const {
    Fraction div(num_ * f.den_, den_ * f.num_);
    return div;
}

std::istream& operator>>(std::istream& from, Fraction& to) {
    long num = 0, den = 1; char slash;
    from >> num >> slash >> den;
    if (slash == '/') {
        to = Fraction(num, den);
    }
    return from;
}

std::ostream& operator<<(std::ostream& to, Fraction& from) {
    if (from.getDen() == 1) {
        return to << from.getNum();
    } else if (from.getNum() == from.getDen()){
        return to << 1;
    } else {
        return to << from.getNum() << " / " << from.getDen();
    }
}
