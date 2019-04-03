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
      num_ = num1 * den2 + num2 * den1,
      den_ = den1 * den2,

      signe = (num_ < 0) ^ (den_ < 0),
      pgcd = Pgcd < num_, den_ >::value,

      num = (signe? -1 * ((num_ < 0) ? -num_ : num_) : ((num_ < 0) ? -num_ : num_)) / pgcd,
      den = ((den_ < 0) ? -den_ : den_) / pgcd

    };

  }; // FracSum< num1, den1, num2, den2 >

} // mathematics

#endif
