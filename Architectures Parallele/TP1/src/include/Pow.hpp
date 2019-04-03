#ifndef Pow_hpp
#define Pow_hpp

namespace mathematics {

  /**
   * @class Pow Pow.hpp
   *
   * Template récursif implémentant la fonction puissance sur les nombres
   * entiers.
   */
  template< int e, unsigned exp >
  class Pow {
  public:

    enum : long long { value = e * Pow < e , exp - 1 >::value };

  }; // Pow< e, exp >

  template< int e >
  class Pow < e , 0 >{
  public:

    enum : long long { value = 1 };

  }; // Pow< e, 0 >

} // mathematics

#endif
