#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

class Fraction {
    private:
        long num_;
        long den_;
        void reduce();
    public:
        // Methode Constructor
        Fraction(const long& num = 0, const long& den = 1);
        // Methode~Reconstructor
        void reset(const long& num = 0, const long& den = 1);
        // getters
        const long& getNum() const;
        const long& getDen() const;
        // Operations
        Fraction operator+(const Fraction& f) const;
        Fraction operator-(const Fraction& f) const;
        Fraction operator*(const Fraction& f) const;
        Fraction operator/(const Fraction& f) const;

        friend std::istream& operator>>(std::istream& from, Fraction& to);
        friend std::ostream& operator<<(std::ostream& to, const Fraction& from);
};

std::istream& operator>>(std::istream& from, Fraction& to);
std::ostream& operator<<(std::ostream& to, Fraction& from);

#endif /* end of include guard: FRACTION_HPP */
