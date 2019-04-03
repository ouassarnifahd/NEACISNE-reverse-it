#ifndef pipelinedBubbleSort_hpp
#define pipelinedBubbleSort_hpp

#include "bubbleSort.hpp"
#include <tbb/pipeline.h>
#include <vector>
#include <algorithm>

namespace sorting {

  /**
   * Implémentation pipeline de l'algorithme du bubble sort.
   *
   * @param[in] first - un itérateur repérant le premier élément de la séquence
   *   à trier.
   * @param[in] last - un itérateur repérant l'élément situé juste derrière le
   *   dernier élément de la séquence à trier.
   * @param[in] comp - un comparateur binaire permettant d'ordonner deux 
   *   éléments.
   * @param[in] chunks - nombre de tronçons maximum en circulation dans le
   *   pipeline à un instant donné.
   */
  template< typename RandomAccessIterator, typename Compare >
  void pipelinedBubbleSort(const RandomAccessIterator& first,
                           const RandomAccessIterator& last,
                           const Compare& comp,
                           const size_t& chunks) {
    
    /***************
     * A compléter *
     ***************/

  } // pipelinedBubbleSort

  /**
   * Implémentation pipeline de l'algorithme du bubble sort. La relation d'ordre
   * total utilisée est "strictement inférieur à".
   *
   * @param[in] first - un itérateur repérant le premier élément de la séquence
   *   à trier.
   * @param[in] last - un itérateur repérant l'élément situé juste derrière le
   *   dernier élément de la séquence à trier.
   * @param[in] chunks - nombre de tronçons maximum en circulation dans le
   *   pipeline à un instant donné.
   */
  template< typename RandomAccessIterator >
  void pipelinedBubbleSort(const RandomAccessIterator& first,
                           const RandomAccessIterator& last,
                           const size_t& chunks) {

    // Type synonyme pour le type des éléments conteneur. 
    typedef std::iterator_traits< RandomAccessIterator > Traits;
    typedef typename Traits::value_type value_type;

    // Fabriquer le comparateur less et invoquer la fonction définie ci-dessus.
    pipelinedBubbleSort(first, 
			last, 
			std::less< const value_type& >(),
			chunks);

  } // pipelinedBubbleSort

} // sorting

#endif
