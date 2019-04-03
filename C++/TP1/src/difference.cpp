#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // print help
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " nom_fichier1" << " nom_fichier2" << endl;
        return EXIT_SUCCESS;
    }
    // #arg invalid!
    if (argc != 3) {
        cerr << "Nombre d'arguments incorrect." << endl;
        return EXIT_FAILURE;
    }

    ifstream gauche(argv[1]);
    if (!gauche) {
        cerr << "Impossible d'ouvrir le fichier ["
             << argv[1]
             << "]."
             << endl;
        return EXIT_FAILURE;
    }

    ifstream droite(argv[2]);
    if (!droite) {
        cerr << "Impossible d'ouvrir le fichier ["
             << argv[2]
             << "]."
             << endl;
        return EXIT_FAILURE;
    }

    string bufGauche, bufDroite;

    bool flagGauche = !!getline(gauche, bufGauche); // xD
    bool flagDroite = !!getline(droite, bufDroite); // xD

    unsigned long line = 1;

    while (flagGauche || flagDroite) {
        cout << line << endl; line++;
        bool currentflagGauche = flagGauche, currentflagDroite = flagDroite; // xD
        if (flagGauche) {
            cout << "< " << bufGauche << endl;
            flagGauche = !!getline(gauche, bufGauche);
        }
        if (currentflagGauche && currentflagDroite) { // xD
            cout << "———" << endl;
        }
        if (flagDroite) {
            cout << "> " << bufDroite << endl;
            flagDroite = !!getline(droite, bufDroite);
        }
    }

    return EXIT_SUCCESS;
}
