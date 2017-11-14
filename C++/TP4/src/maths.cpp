#include <iostream>
#include "fraction.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Fraction f1(128, -44);
    cout << f1.getNum() << " / " << f1.getDen() << endl;
    return 0;
}
