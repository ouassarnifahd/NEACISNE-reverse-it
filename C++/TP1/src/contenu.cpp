/**
 * @mainpage 
 *
 * Equivalent de la commande cat Unix (le fichier concerné doit être ASCII ou
 * ASCII-ANSI).
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

/**
 * Programme principal.
 *
 * @param[in] argc le nombre d'arguments de la ligne de commandes.
 * @param[in] argv les arguments de la ligne de commande.
 * @return @c EXIT_SUCCESS si exécution réussie, @c EXIT_FAILURE sinon.
 */
int
main(int argc, char* argv[]) {

  // La ligne de commandes ne contient que le nom du programme : l'utilisateur
  // demande de l'aide.
  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " nom_fichier" << std::endl;
    return EXIT_SUCCESS;
  }

  // Le nombre d'arguments de la ligne de commandes est différent de deux :
  // l'utilisateur fait n'importe quoi.
  if (argc != 2) {
    std::cerr << "Nombre d'arguments incorrect." << std::endl;
    return EXIT_FAILURE;
  }

  // Tentative d'ouverture du fichier indiqué en lecture seule.
  std::ifstream entree(argv[1]);
  if (! entree) {
    std::cerr << "Impossible d'ouvrir le fichier ["
  	      << argv[1]
  	      << "]."
  	      << std::endl;
    return EXIT_FAILURE;
  }

  // Le fichier étant ouvert nous le lisons ligne par ligne.
  std::string ligne;
  while (std::getline(entree, ligne)) {
    std::cout << ligne << std::endl;
  }

  // C'est terminé.
  return EXIT_SUCCESS;

}
