#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // print help
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " nom_fichier" << endl;
        return EXIT_SUCCESS;
    }
    // #arg invalid!
    if (argc != 2) {
        cerr << "Nombre d'arguments incorrect." << endl;
        return EXIT_FAILURE;
    }

    ifstream entree(argv[1]);
    if (!entree) {
        cerr << "Impossible d'ouvrir le fichier ["
             << argv[1]
             << "]."
             << endl;
        return EXIT_FAILURE;
    }

    unsigned long cl = 0, cm = 0, cc = 0;
    string ligne, mot;
    while (getline(entree, ligne)) {
        cl++;
        cc += ligne.length() + 1;
        istringstream mots(ligne);
        while (mots >> mot) {
            cm++;
        }
    }
    cout << '\t' << cl << '\t' << cm << '\t' << cc << ' ' << argv[1] << endl;

    return EXIT_SUCCESS;
}
