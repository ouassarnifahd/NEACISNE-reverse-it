#ifndef Exp_hpp
#define Exp_hpp

#include "Fact.hpp"
#include "Pow.hpp"
#include "FracSum.hpp"

namespace mathematics {

  template< int x, unsigned n >
  class ExpImpl {
  public:

    // A compléter.
    enum : long long {

      num = FracSum< Pow< x, n >::value, Fact< n >::value,
              ExpImpl< x, n - 1 >::num, ExpImpl< x, n - 1 >::den >::num,

      den = FracSum< Pow< x, n >::value, Fact< n >::value,
              ExpImpl< x, n - 1 >::num, ExpImpl< x, n - 1 >::den >::den

    };

  };

  template< int x >
  class ExpImpl < x, 0 >{
  public:

    // A compléter.
    enum : long long {

      num = 1,

      den = 1

    };

  };

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
      num = ExpImpl< x, n >::num,

      // A compléter.
      den = ExpImpl< x, n >::den

    };

  }; // Exp

} // mathematics

#endif
