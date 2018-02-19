#ifndef Exp_hpp
#define Exp_hpp

#include "Fact.hpp"
#include "Pow.hpp"
#include "FracSum.hpp"

namespace mathematics {

  /**
   * @class Exp Exp.hpp
   *
   * Template récursif permettant de calculer la valeur de la fonction 
   * exponentielle pour un argument de type entier via son développement
   * limité au voisinage de 0.
   */
  template< int x, unsigned n = 10 >
  class Exp {
  public:

    enum : long long { 
      
      // A compléter.
      num = 0,

      // A compléter.
      den = 1

    };

  }; // Exp

} // mathematics

#endif
