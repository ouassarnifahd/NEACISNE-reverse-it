#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction {
    private:
        long num_;
        long den_;
        void reduce();
    public:
        Fraction(const long& num = 0, const long& den = 1);
        void reset(const long& num, const long& den);
        const long& getNum() const;
        const long& getDen() const;
        std::ostream print();
        std::ostream println();
};

#endif /* end of include guard: FRACTION_HPP */
