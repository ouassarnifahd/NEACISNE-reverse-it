#include <iostream>
#include "fraction.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Fraction f1(12,11);
    Fraction f2(31,43);
    Fraction f3 = f1.sub(f2);
    f3.println(cout);
    return 0;
}
