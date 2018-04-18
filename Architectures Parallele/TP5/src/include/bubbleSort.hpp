#ifndef bubbleSort_hpp
#define bubbleSort_hpp

#include <utility>
#include <functional>

namespace sorting {

  /**
   * Implémentation séquentielle du tri à bulle dont la complexité au pire est 
   * O(n^2) si n réprésente le nombre d'éléments à trier. 
   *
   * @param[in] first - un itérateur repérant le premier élément de la séquence
   *   à trier.
   * @param[in] last - un itérateur repérant l'élément situé juste derrière le
   *   dernier élément de la séquence à trier.
   * @param[in] comp - un comparateur binaire permettant d'ordonner deux 
   *   éléments.
   */
  template< typename RandomAccessIterator, typename Compare >
  void bubbleSort(const RandomAccessIterator& first,
                  const RandomAccessIterator& last,
                  const Compare& comp) {

    /***************
     * A compléter *
     ***************/

  } // bubbleSort

  /**
   * Implémentation séquentielle du tri à bulle dont la complexité au pire est
   * O(n^2) si n réprésente le nombre d'éléments à trier. La relation d'ordre 
   * total utilisée est "strictement inférieur à".
   *
   * @param[in] first - un itérateur repérant le premier élément de la séquence
   *   à trier.
   * @param[in] last - un itérateur repérant l'élément situé juste derrière le
   *   dernier élément de la séquence à trier.
   */
  template< typename RandomAccessIterator >
  void bubbleSort(const RandomAccessIterator& first, 
                  const RandomAccessIterator& last) {

    // Type synonyme pour le type des éléments conteneur. 
    typedef std::iterator_traits< RandomAccessIterator > Traits;
    typedef typename Traits::value_type value_type;

    // Fabriquer le comparateur less puis invoquer la fonction définie 
    // ci-dessus.
    bubbleSort(first, last, std::less< const value_type& >());

  } // bubbleSort

} // sorting

#endif
