#ifndef Fact_hpp
#define Fact_hpp

namespace mathematics {

  /**
   * @class Fact Fact.hpp
   *
   * Template récursif implémentant la fonction factorielle.
   */
  template < unsigned n >
  class Fact {
  public:

    /**
     * n ! = n x (n - 1) !
     */
    enum : unsigned long long { value = n * Fact< n - 1 >::value };

  }; // Fact< n >

  // Spécialisation totale représentant la condition d'arrêt de la récursion.
  template<>
  class Fact< 0 > {
  public:

    // 0 ! = 1.
    enum : unsigned long long { value = 1 };

  }; // Fact< 0 >

} // mathematics

#endif
