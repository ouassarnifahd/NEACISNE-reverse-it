#include <iostream>
#include "libmaths.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Fraction f1(1,1);
    Fraction f3 = exp(f1);
    cout << f3 << endl;
    return 0;
}
