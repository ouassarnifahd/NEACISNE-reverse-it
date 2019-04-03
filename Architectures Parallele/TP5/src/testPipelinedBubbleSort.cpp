#include "bubbleSort.hpp"
#include "pipelinedBubbleSort.hpp"
#include "Metrics.hpp"
#include <tbb/task_scheduler_init.h>
#include <vector>
#include <numeric>
#include <algorithm>
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

  // Tableau des éléments à trier, ces derniers étant ici des nombres 
  // pseudo-réels double précision.
  std::vector< double > tableau(1021);

  // Relation d'ordre total pour le tri : "strictement inférieur à".
  const auto comp = std::less< const double& >();

  // Comme ce code sera compilé avec les options permettant d'activer les
  // les jeux d'instructions SIMD sse2, sse3, ssse3 et sse4, la durée d'un tri
  // sera inférieure à la seconde pour la version séquentielle. Plutôt que 
  // d'augmenter la taille du tableau à trier, ce qui n'aboutira qu'à faire
  // swapper in fine le système, nous allons trier plusieurs fois le tableau en
  // le replaçant à chaque fois dans la pire des configurations, c'est à dire
  // un tableau trié selon la relation d'ordre total inverse de celle souhaitée.
  // La complexité du tri bulle est alors à son maximum, c'est à dire sa
  // complexité au pire en O(n^2) où n représente le nombre d'éléments à trier.
  const size_t iters = tableau.size() * 10;

  // Instants représentant respectivement le démarrage et l'arrêt du 
  // chronomètre.
  std::chrono::time_point< std::chrono::system_clock > start, stop;

  // Chronométrage de la version séquentielle. A chaque itération de la boucle,
  // nous utilisons l'algorithme iota de la bibliothèque standard pour (re) 
  // placer le tableau à trier dans la pire des configurations pour le bubble 
  // sort.
  start = std::chrono::system_clock::now();
  for (size_t i = 0; i < iters; i ++) {
    std::iota(tableau.rbegin(), tableau.rend(), 0);
    sorting::bubbleSort(tableau.begin(), tableau.end(), comp);
  }
  stop = std::chrono::system_clock::now();
  const int seq = 
    std::chrono::duration_cast< std::chrono::seconds >(stop - start).count();

  // Affichage des résultats de la version séquentielle. Nous utilisons le
  // nouvel algorithme is_sorted, introduit par la norme C++ 2011, pour vérifier
  // que le tableau est trié selon la relation d'ordre total souhaité.
  std::cout << "--[ bubbleSort: begin ]--" << std::endl;
  std::cout << "\tDurée:\t\t" << seq << " sec." << std::endl;
  std::cout << "\tVerdict:\t\t"
	    << std::boolalpha 
	    << std::is_sorted(tableau.begin(), tableau.end(), comp)
	    << std::endl;
  std::cout << "--[ bubbleSort: end ]--" << std::endl;
  std::cout << std::endl;

  // Nombre de tronçons pouvant circuler à un instant donnée dans le pipeline.
  // En règle générale, la configuration optimale consiste à utiliser un thread
  // par coeur, ce nombre de threads représentant également le nombre de jeton
  // pouvant circuler dans le pipeline à un instant donné.
  const size_t chunks = tbb::task_scheduler_init::default_num_threads();
  tbb::task_scheduler_init init(chunks);

  // Chronométrage de la version parallèle dans les mêmes conditions que la
  // version séquentielle.
  start = std::chrono::system_clock::now();
  for (size_t i = 0; i < iters; i ++) {
    std::iota(tableau.rbegin(), tableau.rend(), 0);
    sorting::pipelinedBubbleSort(tableau.begin(), 
    				 tableau.end(), 
    				 comp,
    				 chunks);
  }
  stop = std::chrono::system_clock::now();
  const int par = 
    std::chrono::duration_cast< std::chrono::seconds >(stop - start).count();

  // Affichage des résultats de la version parallèle avec, en plus, le calcul
  // des facteurs d'accélération et d'efficacité. Une accélération sur-linéaire
  // indique une meilleure utilisation des caches L2 (partagé) et L1 (privé).
  std::cout << "--[ pipelinedBubbleSort: begin ]--" << std::endl;
  std::cout << "\tThread(s):\t" << chunks << std::endl;
  std::cout << "\tDurée:\t\t" << par << " sec." << std::endl;
  std::cout << "\tVerdict:\t\t"
	    << std::boolalpha 
	    << std::is_sorted(tableau.begin(), tableau.end(), comp)
	    << std::endl;
  std::cout << "\tSpeedup:\t" 
	    << Metrics::speedup(seq, par)
	    << std::endl;
  std::cout << "\tEfficiency:\t"
	    << Metrics::efficiency(seq, par, chunks)
	    << std::endl;
  std::cout << "--[ pipelinedBubbleSort: end ]--" << std::endl;
  std::cout << std::endl;

  // Tout s'est bien passé.
  return EXIT_SUCCESS;

}
