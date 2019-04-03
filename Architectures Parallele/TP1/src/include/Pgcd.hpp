#ifndef Pgcd_hpp
#define Pgcd_hpp

namespace mathematics {

  /**
   * @class PgcdImpl Pgcd.hpp
   *
   * Template récursif implémentant l'algorithme d'Euclide pour le calcul du
   * pgcd de deux nombres.
   *
   * @note l'argument @c a doit être positif ou nul. L'argument @c b doit être
   *   strictement positif.
   */
  template< long long a, long long b, long long r = a % b >
  class PgcdImpl {
  public:

    // A compléter.
    enum : long long { value = PgcdImpl< b, r >::value };

  }; // PgcdImpl< a, b, a % b >

  template< long long a, long long b>
  class PgcdImpl < a, b , 0 >{
  public:

    // A compléter.
    enum : long long { value = b };

  }; // PgcdImpl< a, b, 0 >

  /**
   * @class Pgcd Pgcd.hpp
   *
   * Calcul du pgcd de deux entiers signés effectué via un template récursif.
   */
  template< long long num, long long den >
  class Pgcd {
  public:

    /**
     * Pgcd des entiers signés @c num et @c den.
     */
    enum : long long {
      value = PgcdImpl< (num > 0 ? num : -num), (den > 0 ? den : -den) >::value
    };

  }; // Pgcd

}

#endif
