#ifndef ParallelHybridRecursiveMerge_hpp
#define ParallelHybridRecursiveMerge_hpp

#include <tbb/parallel_invoke.h>
#include <functional>
#include <algorithm>

namespace merging {

  /**
   * @class ParallelHybridRecursiveMerge ParallelHybridRecursiveMerge.hpp
   *
   * Version TBB (Intel Threading Building Blocks) de l'algorithme merge de la 
   * biblothèque standard. 
   * 
   * @note L'implémentation proposée est celle du recursive merging décrite dans
   *   Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford 
   *   Stein, "Introduction to Algorithms", 3rd ed., 2009, pp 798-802. La 
   *   récursion est interrompue lorsque la somme des tailles des deux 
   *   sous-conteneurs à fusionner passe sous une certaine tolérance. La fusion 
   *   est alors effectuée via l'algorithme merge de la bibliothèque standard.
   */
  class ParallelHybridRecursiveMerge {
  public:

    /**
     * Implémentation parallèle.
     *
     * @param[in] first1 - un itérateur repérant le premier élément du premier
     *   sous-conteneur concerné par la fusion ;
     * @param[in] last1 - un itérateur repérant l'élément situé juste derrière 
     *   le dernier élément du premier sous-conteneur concerné par la fusion ;
     * @param[in] first2 - un itérateur repérant le premier élément du second
     *   sous-conteneur concerné par la fusion ;
     * @param[in] last2 - un itérateur repérant l'élément situé juste derrière 
     *   le dernier élément du second sous-conteneur concerné par la fusion ;
     * @param[in] result - un itérateur repérant la position ou récopier le 
     *   premier élément résultant de la fusion ;
     * @param[in] comp - un comparateur binaire représentant la relation d'ordre
     *   total régissant les sous-conteneurs ;
     * @param[in] cutoff - la somme des tailles des deux sous-conteneurs au 
     *   dessous de laquelle la fusion est effectuée via l'algorithme merge de 
     *   la bibliothèque standard.
     * @return un itérateur repérant la fin de la zone de fusion dans le
     *   conteneur cible.
     */
    template< typename InputRandomAccessIterator1,
	      typename InputRandomAccessIterator2,
	      typename OutputRandomAccessIterator,
	      typename Compare >
    static OutputRandomAccessIterator 
    apply(const InputRandomAccessIterator1& first1,
	  const InputRandomAccessIterator1& last1,
	  const InputRandomAccessIterator2& first2,
	  const InputRandomAccessIterator2& last2,
	  const OutputRandomAccessIterator& result,
	  const Compare& comp,
	  const size_t& cutoff) {

      /***************
       * A compléter *
       ***************/

    } // apply

    /**
     * Implémentation parallèle pour la relation d'ordre total strictement 
     * inférieur à.
     *
     * @param[in] first1 - un itérateur repérant le premier élément du premier
     *   sous-conteneur concerné par la fusion ;
     * @param[in] last1 - un itérateur repérant l'élément situé juste derrière 
     *   le dernier élément du premier sous-conteneur concerné par la fusion ;
     * @param[in] first2 - un itérateur repérant le premier élément du second
     *   sous-conteneur concerné par la fusion ;
     * @param[in] last2 - un itérateur repérant l'élément situé juste derrière 
     *   le dernier élément du second sous-conteneur concerné par la fusion ;
     * @param[in] result - un itérateur repérant la position ou récopier le 
     *   premier élément résultant de la fusion ;
     * @param[in] comp - un comparateur binaire représentant la relation d'ordre
     *   total régissant les sous-conteneurs ;
     * @param[in] cutoff - la somme des tailles des deux sous-conteneurs au 
     *   dessous de laquelle la fusion est effectuée via l'algorithme merge de 
     *   la bibliothèque standard.
     * @return un itérateur repérant la fin de la zone de fusion dans le
     *   conteneur cible.
     */
    template< typename InputRandomAccessIterator1,
	      typename InputRandomAccessIterator2,
	      typename OutputRandomAccessIterator >
    static OutputRandomAccessIterator
    apply(const InputRandomAccessIterator1& first1,
	  const InputRandomAccessIterator1& last1,
	  const InputRandomAccessIterator2& first2,
	  const InputRandomAccessIterator2& last2,
	  const OutputRandomAccessIterator& result,
	  const size_t& cutoff) {

      // Type synonyme pour le type des éléments du premier conteneur. Le type 
      // des éléments du second devra pouvoir se convertir implicitement en le 
      // type des éléments du premier.
      typedef std::iterator_traits< InputRandomAccessIterator1 > Traits;
      typedef typename Traits::value_type value_type;

      // Fabriquer le comparateur less puis invoquer la méthode définie 
      // ci-dessus.
      return apply(first1, 
		   last1,
		   first2,
		   last2,
		   result,
		   std::less< const value_type& >(),
		   cutoff);
      
    } // apply

  }; // ParallelHybridRecursiveMerge

} // merging

#endif
