#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
  // print help
  if (argc == 1) {
    cout << "Usage: "
         << argv[0]
         << " <expression>"
         << endl;
    return EXIT_SUCCESS;
  }

  // #arg invalid!
  if (argc != 2) {
    cerr << "Nombre d'arguments incorrect." << endl;
    return EXIT_FAILURE;
  }

  // It's over.
  return EXIT_SUCCESS;
}
