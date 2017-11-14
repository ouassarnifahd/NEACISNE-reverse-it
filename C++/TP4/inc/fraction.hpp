#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction {
    private:
        long num_;
        long den_;
        void reduce();
    public:
        Fraction(const long& num = 0, const long& den = 1);
        void reset(const long& num = 0, const long& den = 1);
        const long& getNum() const;
        const long& getDen() const;
        Fraction add(const Fraction& f) const;
        Fraction sub(const Fraction& f) const;
        Fraction mul(const Fraction& f) const;
        Fraction div(const Fraction& f) const;
        void print(std::ostream& os);
        void println(std::ostream& os);
};

#endif /* end of include guard: FRACTION_HPP */
