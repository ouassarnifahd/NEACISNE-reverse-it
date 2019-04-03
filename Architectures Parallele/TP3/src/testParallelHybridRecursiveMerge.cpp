#include "ParallelHybridRecursiveMerge.hpp"
#include "Metrics.hpp"
#include <tbb/task_scheduler_init.h>
#include <numeric>
#include <vector>
#include <iostream>
#include <chrono>
#include <cstdlib>

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS en cas d'exécution réussie ou @c EXIT_FAILURE en cas
 *   de problèmes.
 */
int
main() {

  // Synonyme du type des éléments à fusionner.
  typedef int Type;

  // Relation d'ordre utilisée : strictement inférieur à.
  const auto comp = std::less< const Type& >();

  // Deux tableaux d'entiers de taille différentes à fusionner.
  std::vector< Type > lhs(128 * 1024), rhs(lhs.size() + 211);
  std::iota(lhs.begin(), lhs.end(), 19);
  std::iota(rhs.begin(), rhs.end(), 5);

  // Conteneur accueillant le résultat de la fusion.
  std::vector< Type > result(lhs.size() + rhs.size());

  // Nombre d'itérations à effectuer à chaque fois pour que les temps de
  // calcul dépassent la seconde.
  const size_t iter = 1024 * 16;

  // Temps auquel sont démarrées et arrêtées chaque séquence de calcul.
  std::chrono::time_point< std::chrono::system_clock > start, stop;

  // Durée d'exécution de l'algorithme merge de la bibliothèque standard.
  start = std::chrono::system_clock::now();
  for (size_t i = 0; i < iter; i ++) {
    std::merge(lhs.begin(), 
    	       lhs.end(),
    	       rhs.begin(), 
    	       rhs.end(),
    	       result.begin(),
    	       comp);
  }
  stop = std::chrono::system_clock::now();
  const int seq = 
    std::chrono::duration_cast< std::chrono::seconds >(stop - start).count();

  // Affichage des performances de la version séquentielle.
  std::cout << "--[ merge: begin ]--" << std::endl;
  std::cout << "\tDurée:\t\t" << seq << " sec." << std::endl;
  std::cout << "\tVerdict:\t\t"
  	    << std::boolalpha 
  	    << std::is_sorted(result.begin(), result.end(), comp)
  	    << std::endl;
  std::cout << "--[ merge: end ]--" << std::endl;
  std::cout << std::endl;

  // Initialisation du scheduler de TBB avec le nombre de cores logiques.
  const int threads = tbb::task_scheduler_init::default_num_threads();
  tbb::task_scheduler_init init(threads);

  // Durées d'exécution de l'algorithme ParallelHybridRecursiveMerge. Nous 
  // allons utiliser plusieurs valeurs du cutoff.
  for (size_t cutoff = 1024; 
       cutoff < result.size();
       cutoff += 1024) {

    // Durée d'exécution de notre version parallèle.
    start = std::chrono::system_clock::now();
    for (size_t i = 0; i < iter; i ++) {
      merging::ParallelHybridRecursiveMerge::apply(lhs.begin(), 
      						   lhs.end(),
      						   rhs.begin(), 
      						   rhs.end(),
      						   result.begin(),
      						   comp,
      						   cutoff);            
    }
    stop = std::chrono::system_clock::now();
    const int par = 
      std::chrono::duration_cast< std::chrono::seconds >(stop - start).count();

    // Affichage des performances de notre version parallèle.
    std::cout << "--[ ParallelHybridRecursiveMerge("
  	      << cutoff
  	      << "): begin ]--" << std::endl;
    std::cout << "\tThread(s):\t" << threads << std::endl;
    std::cout << "\tDurée:\t\t" << par << " sec." << std::endl;
    std::cout << "\tVerdict:\t\t"
  	      << std::boolalpha 
  	      << std::is_sorted(result.begin(), result.end(), comp)
  	      << std::endl;
    std::cout << "\tSpeedup:\t" 
  	      << Metrics::speedup(seq, par)
  	      << std::endl;
    std::cout << "\tEfficiency:\t"
  	      << Metrics::efficiency(seq, par, threads)
  	      << std::endl;
    std::cout << "--[ ParallelHybridRecursiveMerge("
  	      << cutoff
  	      << "): end ]--" << std::endl;
    std::cout << std::endl;

  }

  // Tout s'est bien passé.
  return EXIT_SUCCESS;

}
