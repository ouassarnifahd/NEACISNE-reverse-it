#ifndef FracSum_hpp
#define FracSum_hpp

#include "Pgcd.hpp"

namespace mathematics {

  /**
   * @class FracSum FracSum.hpp
   *
   * Template implémentant la somme de deux fractions avec réduction. 
   *
   * @note le signe de la fraction est systématiquement affecté au numérateur.
   *   Comme nous manipulons des long long, il n'est pas envisageable de
   *   multiplier le numérateur par le dénominateur pour déterminer ce signe.
   */
  template< long long num1, long long den1, long long num2, long long den2 >
  class FracSum {
  public:

    enum : long long { 

      // A compléter.
      num = 0,
      
	// A compléter.
      den = 0
		    
    };

  }; // FracSum< num1, den1, num2, den2 >

} // mathematics

#endif
