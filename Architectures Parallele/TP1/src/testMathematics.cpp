#include "Fact.hpp"
#include "SommeListe.hpp"
#include "Pow.hpp"
#include "FracSum.hpp"
#include "Exp.hpp"
#include "DotProduct.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

/**
 * Programme principal.
 *
 * @return @c EXIT_FAILURE car exécution toujours réussie.
 */
int
main() {

  // Abolition du préfixage explicite pour le package mathematics.
  using namespace mathematics;

  // Fonction factorielle.
  std::cout << "5! = " << Fact< 5 >::value << std::endl;

  // Somme des entiers d'une liste.
  std::cout << "somme( [ 1 ] ) = "
	    << SommeListe< 1 >::value
	    << std::endl;
  std::cout << "somme( [ 1, 2 ] ) = "
	    << SommeListe< 1, 2 >::value
	    << std::endl;
  std::cout << "somme( [ 1, 2, 3 ] ) = "
	    << SommeListe< 1, 2, 3 >::value
	    << std::endl;

  // Fonction puissance à argument entier.
  std::cout << "3^{5} = " << Pow< 3, 5 >::value << std::endl;

  // Calcul du pgcd de deux entiers signés.
  std::cout << "pgcd(-242, 8) = " << Pgcd< -242, 8 >::value << std::endl;

  // Calcul de la somme de deux fractions avec réduction.
  {
    using Sum = FracSum< -242, 8, 121, 7 >;
    std::cout << "-242/8 + 121/7 = "
  	      << Sum::num
  	      << "/"
  	      << Sum::den
  	      << std::endl;
  }

  // Fonction exponentielle.
  {
    using Exp = Exp< -2 >;
    std::cout << "Exp(-2) = "
  	      << Exp::num
  	      << "/"
  	      << Exp::den
  	      << " = "
  	      << Exp::num * 1.0 / Exp::den
  	      << "\t => std::exp(-2) = "
  	      << std::exp(-2.0)
  	      << std::endl;
  }

  // Déroulage d'un produit scalaire.
  {
    const int vect[] = { 1, 2, 3, 4 };
    std::cout << "Norme([ 1, 2, 3, 4 ]) = "
  	      << DotProduct< int, 4 >::result(vect, vect)
  	      << std::endl;
  }

  // Tout s'est bien passé.
  return EXIT_SUCCESS;

}
