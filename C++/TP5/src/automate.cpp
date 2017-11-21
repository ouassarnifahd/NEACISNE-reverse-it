/**
 * @mainpage
 *
 * Automate de reconnaissance de la grammaire :
 *
 *   Somme     ::= Variable { Opérateur Variable }
 *   Variable  ::= 'x' | 'y' | 'z'
 *   Opérateur ::= '+' | '-'
 */

#include <iostream>
#include <cstdlib>

/**
 * Programme principal.
 *
 * @return EXIT_SUCCESS.
 */
int main() {

  // Le caractère lu.
  char c;

  // L'état courant.
  int etat = 1;

  // Boucle de lecture de l'entrée standard caractère par caractère.
  while (std::cin >> c) {

    // Alternative sur l'état courant.
    switch (etat) {

      // Etat 1 : nous n'allons dans le 3 que si c = 'x' | 'y' | 'z' sinon
      // direction le puit.
    case 1:
      etat = (c == 'x' || c == 'y' || c == 'z') ? 3 : 2;
      break;

      // Etat 3 : nous n'allons dans le 1 que si c = '+' | '-' sinon direction
      // le puit.
    case 3:
      etat = (c == '+' || c == '-') ? 1 : 2;
      break;

      // Le puit dont nous ne ressortons jamais.
    default:
      break;
    }
  }

  // L'expression est correcte si nous sommes dans l'état 3.
  std::cout << std::endl
            << "Expression correcte : "
            << std::boolalpha
            << (etat == 3)
            << std::endl;

  // C'est terminé.
  return EXIT_SUCCESS;

}
