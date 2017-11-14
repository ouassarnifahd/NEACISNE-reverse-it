#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // print help
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " <numerateur>" << " <denumerateur>" << endl;
        return EXIT_SUCCESS;
    }
    // #arg invalid!
    if (argc != 3) {
        cerr << "Nombre d'arguments incorrect." << endl;
        return EXIT_FAILURE;
    }

    int num, den;
    { // Get Input DATA
        istringstream issnum(argv[1]);
        istringstream issden(argv[2]);
        issnum >> num; issden >> den;
        if (!issnum || !issnum.eof()) {
            cerr << argv[1] << " incorrect." << endl;
            return EXIT_FAILURE;
        }
        if (!issden || !issden.eof() || den == 0) {
            cerr << argv[2] << " incorrect." << endl;
            return EXIT_FAILURE;
        }
    }

    // detection du signe de la fraction
    bool signe = (num < 0) ^ (den < 0);
    #define _ABS(x) x < 0 ? -x : x
    num = _ABS(num);
    den = _ABS(den);

    { // div euclidienne Entiere
        int a = num, b = den, q = 0, r = 1;
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

    cout << (signe?"-":" ") << num << " / " << den << endl;
    return EXIT_SUCCESS;
}
