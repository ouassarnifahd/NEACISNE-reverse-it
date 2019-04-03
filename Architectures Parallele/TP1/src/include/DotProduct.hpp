#ifndef DotProduct_hpp
#define DotProduct_hpp

namespace mathematics {

  /**
   * @class DotProduct DotProduct.hpp
   *
   * Template récursif permettant de calculer le produit scalaire de deux
   * vecteurs via l'évaluation d'une expression.
   */
  template< typename T, unsigned size >
  class DotProduct {
  public:

    // A compléter.
    static T result(const T left[], const T right[]) {
      return left[size - 1] * right[size - 1] + DotProduct< T, size - 1 >::result(left, right);
    }

  }; // DotProduct< T, size >

  template< typename T >
  class DotProduct < T, 0 > {
  public:

    // A compléter.
    static T result(const T left[], const T right[]) {
      return 0;
    }

  }; // DotProduct< T, size >

} // mathematics

#endif
