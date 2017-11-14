#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // print help
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " <nombre_iterations> <fichier_config> <fichier_resultat>" << endl;
        return EXIT_SUCCESS;
    }

    // #arg invalid!
    if (argc != 4) {
        cerr << "Nombre d'arguments incorrect." << endl;
        return EXIT_FAILURE;
    }

    unsigned long niter;
    { // Get Input DATA
        istringstream issniter(argv[1]);
        issniter >> niter;
        if (!issniter || !issniter.eof()) {
            cerr << argv[1] << " incorrect." << endl;
            return EXIT_FAILURE;
        }
    }

    // Lecture du ficher config impossible!
    ifstream config(argv[2]);
    if (!config) {
        cerr << "Impossible d'ouvrir le fichier ["
             << argv[2]
             << "]."
             << endl;
        return EXIT_FAILURE;
    }

    // Ecriture du fichier resultat impossible!
    ofstream resultat(argv[3]);
    if (!resultat) {
        cerr << "Impossible de creer le fichier ["
             << argv[3]
             << "]."
             << endl;
        return EXIT_FAILURE;
    }

    unsigned long M = 0;
    double thetaP = 0, kappa = 0, h = 0;
    double* const theta = new double[M];

    config >> M;
    config >> thetaP;
    config >> kappa;
    config >> theta[0];
    config >> theta[M - 1];
    config >> h;

    double* const alpha = new double[M];

    // Get AlphaM DATA
    for (size_t i = 0; i < M; i++) {
        config >> alpha[i];
    }

    { // init theta
        const double den = M - 1;
        const double& theta0 = theta[0];
        const double& thetaL = theta[M - 1];
        for (size_t i = 2; i < M; i++) {
            theta[i - 1] = ((M - i) * theta0 + (i - 1) * thetaL) / den;
        }
    }

    { // main niter loop
        double cte = kappa / (h * h);
        double* const v1 = new double[M];
        double* const v2 = new double[M];
        for (size_t i = 0; i < M; i++) {
            v1[i] = alpha[i] * thetaP;
            v2[i] = alpha[i] + 2 * cte;
        }

        for (size_t i = 0; i < niter; i++) {
            for (size_t m = 1; m < M - 1; m++) {
                theta[m] = (cte * (theta[m + 1] + theta[m - 1]) + v1[m]) / v2[m];
            }
        }
        delete[] v1;
        delete[] v2;
    }

    { // Save result in resultat
        double x = 0.0;
        for (size_t i = 0; i < M; i++) {
            resultat << x << '\t' << theta[i] << endl;
            x += h;
        }
    }

    delete[] alpha;
    delete[] theta;

    return EXIT_SUCCESS;
}
