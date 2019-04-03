/**
 * @mainpage
 *
 * Package Lexer demo.
 */

#include "Lexer.hpp"

#include <fstream>

/**
 * Main program.
 *
 * @param[in] argc number of arguments of the command line.
 * @param[in] argv arguments of the command line.
 * @return @c EXIT_SUCCESS if all the files required can be opened else
 * @c EXIT_FAILURE.
 */

using namespace std;

int main(int argc, char* argv[]) {

  using namespace intexpr;
  using namespace lexer;

  // print help
  if (argc == 1) {
    cout << "Usage: " << argv[0] << " <nom_fichier>" << endl;
    return EXIT_SUCCESS;
  }

  // #arg invalid!
  if (argc != 2) {
    cerr << "Nombre d'arguments incorrect." << endl;
    return EXIT_FAILURE;
  }

  // Lecture du ficher impossible!
  ifstream entree(argv[1]);
  if (!entree) {
    cerr << "Impossible d'ouvrir le fichier ["
      << argv[1]
      << "]."
      << endl;
    return EXIT_FAILURE;
  }

  Lexer reader(entree);
  if (reader.isConnected()) {
    Token jeton(reader.nextToken());
    while (!jeton.isEndOfExpression()) {
      jeton.println(cout);
      jeton = reader.nextToken();
    }
  }

  // It's over.
  return EXIT_SUCCESS;

}
