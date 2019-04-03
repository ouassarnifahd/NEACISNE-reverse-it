#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

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

    ifstream entree(argv[1], ios::binary);
    unsigned char octet;
    char* adresse = reinterpret_cast< char * >(&octet);
    unsigned long table[256]; fill(table, table + 256, 0);
    while (entree.read(adresse, 1)) {
        table[octet]++;
    }
    for (unsigned long i = 0; i < 256; i++) {
        cout << i << " found " << table[i] << " times" << endl;
    }
    return EXIT_SUCCESS;
}
