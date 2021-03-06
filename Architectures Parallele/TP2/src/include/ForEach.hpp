#ifndef ForEach_hpp
#define ForEach_hpp

#include <omp.h>
#include <algorithm>
#include <vector>

namespace paralgos {

  /**
   * @class ForEach ForEach.hpp
   *
   * Version OpenMP de l'algorithme for_each de la bibliothèque standard.
   */
  class ForEach {
  public:

    /**
     * Forme générale de l'algorithme.
     *
     * @param[in, out] first - itérateur repérant le premier élément à traiter.
     * @param[in, out] last - itérateur repérant l'élément situé juste derrière
     *   le dernier élément à traiter.
     * @param[in, out] fn - fonction unaire appliquée à tous les éléments de
     *   l'intervalle @c [first, last[.
     * @return l'argument @c fn.
     */
    template< typename InputIterator, typename Function >
    static Function apply(InputIterator first,
			  InputIterator last,
			  Function fn) {

      // Obtention du nombre de threads. Si celui-ci vaut 1, nous utilisons
      // directement la version séquentielle de l'algorithme, c'est à dire celle
      // de la bibliothèque standard.
      int threads;
#pragma omp parallel
#pragma omp single
      threads = omp_get_num_threads();
      if (threads == 1) {
      	return std::for_each(first, last, fn);
      }

      // Obtention du type des itérateurs first et last (nous passons par le
      // template iterator_traits de la bibliothèque standard afin de pouvoir
      // gérer tous les types de RandomAccessIterator, y compris les simples
      // pointeurs).
      typedef std::iterator_traits< InputIterator > Traits;

      // Instanciation de l'implémentation (sous-classe) adéquate.
      typedef Impl< typename Traits::iterator_category > Impl;

      // Invocation de la version dédiée de cet algorithme.
      Impl::apply(first, last, fn, threads);

      // La fonction unaire est retournée.
      return std::move(fn);

    } // apply

  public:

    /**
     * Implémentation de cet algorithme dédiée aux InputIterator.
     */
    template< typename Category >
    class Impl {
    public:

      // Déclaration d'amitié envers la classe mère : seule cette dernière peut
      // invoquer la méthode de classe privée @c apply.
      friend class ForEach;

    private:

      /**
       * Implémentation de for_each sous la forme d'une procédure.
       *
       * @param[in, out] first - itérateur repérant le premier élément à
       *   traiter.
       * @param[in, out] last - itérateur repérant l'élément situé juste
       *   derrière le dernier élément à traiter.
       * @param[in, out] fn - fonction unaire appliquée à tous les éléments de
       *   l'intervalle @c [first, last[.
       * @param[in] threads - le nombre de threads disponibles.
       */
      template< typename InputIterator, typename Function >
      static void apply(const InputIterator& first,
			const InputIterator& last,
			const Function& fn,
			const int& threads) {
	strategyA(first, last, fn, threads);
      } // apply

    private:

      /**
       * Implémentation basée sur le découpage du conteneur en tronçons, ces
       * derniers étant représentés par des tableaux de pointeurs sur les
       * éléments du conteneur. Une parallélisation via une boucle for et la
       * clause de scheduling auto est alors possible. Le revers de la médaille
       * est l'obligation d'utiliser un tronçon de taille arbitraire
       * (éventuellement fonction du nombre de threads disponibles) car compter
       * le nombre d'éléments du conteneur reviendrait à le parcourir une
       * première fois. L'autre inconvénient est la nécessité d'effectuer des
       * recopies de pointeurs.
       *
       * @param[in] first - itérateur repérant le premier élément à traiter.
       * @param[in] last - itérateur repérant l'élément situé juste derrière le
       *   dernier élément à traiter.
       * @param[in] fn - fonction unaire appliquée à tous les éléments de
       *   l'intervalle @c [first, last[.
       * @param[in] threads - le nombre de threads disponibles.
       */
      template< typename InputIterator, typename Function >
      static void strategyA(const InputIterator& first,
			    const InputIterator& last,
			    const Function& fn,
			    const int& threads) {

	// Taille d'un tronçon fixée arbitrairement.
	const int taille = 128 * threads;

	// Obtention du type des éléments du conteneur.
	typedef std::iterator_traits< InputIterator > Traits;
	typedef typename Traits::value_type Elt;

	// Tronçon constitué de pointeurs vers les éléments du conteneur.
	std::vector< Elt* > troncon(taille);

    // Nombre d'éléments physiquement présents dans le dernier tronçon.
	int combien;

	// Itérateur permettant d'avancer dans le conteneur à tronçonner.
	InputIterator iter = first;

	// Nous encageons le tout dans une région parallèle et nous évitons
	// le omp parallel for afin de garantir que les threads existent tout
	// le temps d'exécution de la boucle. Dans le cas contraire, le choix
	// sera laissé à l'implémentation qui pourrait alors les créer puis les
	// détruire à chaque itération de la boucle while.
#pragma omp parallel
	{

	  // Flag indiquant que tous les éléments du conteneur n'ont pas encore
	  // été traités (privé).
	  bool encore = true;

	  // Boucle de traitement des éléments du conteneur.
	  while (encore) {

	    // Tronçonnage effectué par un seul et unique thread. Les autres
	    // attendent à la barrière de synchronisation du single.
#pragma omp single
	    {

	      // Tronçonnage jusqu'à remplir complètement le tronçon ou bien
	      // atteindre la fin du conteneur. Toutes les données manipulées
	      // ici sont partagées par l'ensemble des threads disponibles.
	      combien = 0;
	      while (iter != last && combien != taille) {
		troncon[combien] = &(*iter);
		iter ++;
		combien ++;
	      }

	    } // omp single (barrière de synchronisation implicite).

	    // Le tronçonnage est terminé : nous lançons tous les threads
	    // disponibles pour traiter les éléments du nouveau tronçon. La
	    // clause d'ordonnancement est auto, ce qui laisse à
	    // l'implémentation la liberté de choisir le meilleur scheduling.
#pragma omp for schedule(auto)
	    for (int i = 0; i < combien; i ++) {
	      fn(*troncon[i]);
	    } // omp par (barrière de synchronisation implicite).

	    // Y'a t-il d'autres tronçons à traiter par la suite ?
	    encore = iter != last;

	    // Barrière de synchronisation explicite permettant d'éviter qu'un
	    // thread entre dans la partie single et modifie l'itérateur partagé
	    // iter alors qu'un autre thread met encore à jour son flag encore.
#pragma omp barrier

	  } // while

	} // omp parallel (barrière de synchronisation implicite).

      } // strategyA

      /**
       * Implémentation toujours basée sur l'idée d'un découpage du conteneur
       * en tronçons mais cette fois-ci, nous allons utiliser la notion de
       * tâches afin d'éviter les recopies de pointeurs dans un tableau. La
       * La contrepartie est un scheduling au niveau des tâches, scheduling sur
       * lequel nous avons peu de prise.
       *
       * @param[in] first - itérateur repérant le premier élément à traiter.
       * @param[in] last - itérateur repérant l'élément situé juste derrière le
       *   dernier élément à traiter.
       * @param[in] fn - fonction unaire appliquée à tous les éléments de
       *   l'intervalle @c [first, last[.
       * @param[in] threads - le nombre de threads disponibles.
       *
       * @note Cette implémentation s'apparente à la clause de scheduling
       *   schedule(dynamic, size).
       */
      template< typename InputIterator, typename Function >
      static void strategyB(const InputIterator& first,
			    const InputIterator& last,
			    const Function& fn,
			    const int& threads) {

	// Taille d'un tronçon fixée arbitrairement.
	const int taille = 128;

    // Toutes les tâches sont créés à l'intérieur d'une région parallèle.
#pragma omp parallel
	{

	  // Ces tâches sont créées par un seul et unique thread. La barrière
	  // de synchronisation implicite est levée afin que les autres threads
	  // se précipitent immédiatement sur le pool de tâches à exécuter en
	  // cours de constitution.
#pragma omp single nowait
	  {

	    // Nombre d'éléments physiquement présent dans le dernier tronçon
	    // produit (privé).
	    int combien;

	    // Itérateur permettant de marquer le début d'un tronçon (privé).
	    InputIterator from = first;

	    // Flag indiquant si le tronçonnage doit ou non se poursuivre
	    // (privé).
	    bool encore = true;

	    // Boucle de traitement des éléments du conteneur.
	    while (encore) {

	      // Création d'un nouveau tronçon.
	      InputIterator iter = from;
	      combien = 0;
	      while (iter != last && combien != taille) {
		iter ++;
		combien ++;
	      }

	      // Création de la tâche chargée de traiter ce tronçon (les
	      // itérateurs from et iter font implicitement l'objet d'une
	      // clause firstprivate). Nous ajoutons la clause untied afin
	      // que le thread qui créée les tâches puisse lui-même participer
	      // à leur exécution lorsque le nombre de tâches en attente devient
	      // trop important.
#pragma omp task shared(fn) untied
	      std::for_each(from, iter, fn);

	      // Mise à jour des itérateurs pour le prochain tronçonnage.
	      from = iter;
	      encore = from != last;

	    } // while

	  } // omp single (barrière de synchronisation implicite levée).

        } // omp parallel (barrière de synchronisation implicite).
	

      } // strategyB

      /**
       * Implémentation basée sur l'idée d'une répartition cyclique des
       * éléments du conteneur entre les différents threads disponibles.
       *
       * @param[in] first - itérateur repérant le premier élément à traiter.
       * @param[in] last - itérateur repérant l'élément situé juste derrière le
       *   dernier élément à traiter.
       * @param[in] fn - fonction unaire appliquée à tous les éléments de
       *   l'intervalle @c [first, last[.
       * @param[in] threads - le nombre de threads disponibles.
       *
       * @note Cette implémentation s'apparente à la clause de scheduling
       *   schedule(static).
       */
      template< typename InputIterator, typename Function >
      static void strategyC(const InputIterator& first,
			    const InputIterator& last,
			    const Function& fn,
			    const int& threads) {

    #pragma omp parallel
    	{

    	  // Itérateur repérant le premier élément (privé) affecté à ce thread.
    	  InputIterator here = first;

    	  // Flag indiquant que l'avancée de ce thread doit se poursuivre
    	  // (privé).
    	  bool encore;

    	  // Tentative de positionnement sur le premier élément affecté à ce
    	  // thread.
    	  {
    	    const int id = omp_get_thread_num();
    	    int combien = 0;
    	    while (here != last && combien != id) {
    	      here ++;
    	      combien ++;
    	    }
    	    encore = here != last;
    	  }

    	  // Boucle de traitement des éléments affectés à ce thread.
    	  while (encore) {

    	    // Traitement de l'élément courant.
    	    fn(*here);

    	    // Tentative de positionnement sur l'élément suivant : le nombre de
    	    // threads disponible fait office de stride.
    	    int combien = 0;
    	    while (here != last && combien != threads) {
    	      here ++;
    	      combien ++;
    	    }
    	    encore = here != last;

    	  } // while

    	} // omp parallel

      } // strategyC

    }; // Impl< not RandomAccessIterator >

  };

  /**
   * Implémentation de cet algorithme dédiée aux RandomAccessIterator.
   */
  template<>
  class ForEach::Impl< std::random_access_iterator_tag > {
  public:

    // Déclaration d'amitié envers la classe mère : seule cette dernièrer peut
    // invoquer la méthode de classe privée @c apply.
    friend class ForEach;

  private:

    /**
     * Implémentation de for_each sous la forme d'une procédure.
     *
     * @param[in] first - itérateur repérant le premier élément à traiter.
     * @param[in] last - itérateur repérant l'élément situé juste derrière le
     *   dernier élément à traiter.
     * @param[in] fn - fonction unaire appliquée à tous les éléments de
     *   l'intervalle @c [first, last[.
     * @param[in] threads - le nombre de threads disponibles.
     */
    template< typename RandomAccessIterator, typename Function >
    static void apply(const RandomAccessIterator& first,
		      const RandomAccessIterator& last,
		      const Function& fn,
		      const int& threads) {

    #pragma omp parallel for schedule(auto)
        for (RandomAccessIterator it = first; it < last; it ++) {
            fn(*it);
        }

    } // apply

  }; // Impl< RandomAccessIterator >

} // paralgos

#endif
