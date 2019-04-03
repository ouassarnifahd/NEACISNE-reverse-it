#include "CountIf.hpp"
#include "Metrics.hpp"
#include <omp.h>
#include <algorithm>
#include <array>
#include <list>
#include <iostream>
#include <cstdlib>

/**
 * Indique si l'entier naturel fourni en argument est pair.
 * 
 * @param[in] e - un entier naturel.
 * @return @c true si @c e est un entier naturel pair sinon @c false.
 *
 * @note le temps de calcul de cette fonction est parfaitement homogène.
 */
bool
estPair(const uint& e) {
  return e % 2 == 0;
}

/**
 * Indique si le pgcd de l'entier naturel fourni en argument et de la valeur 21
 * vaut 3.
 *
 * @param[in] num - un entier naturel.
 * @return @c true si le pgcd de l'entier naturel fourni en argument et de la 
 *   valeur 21 vaut 3 sinon @c false.
 *
 * @note l'algorithme d'Euclide, utilisé pour la réduction, est fortement 
 *   hétérogène en termes de nombre d'instructions à exécuter.
 */
bool
pgcd21Vaut3(const uint& num) {
  const uint den = 21;
  const uint esperee = 3;
  uint a = num;
  uint b = den;
  if (a % b == 0) {
    return b == esperee;
  }
  int r = 0;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a == esperee;
}

/**
 * Routine d'évaluation des performances.
 *
 * @param[in] first - le paramètre @c first de l'algorithme.
 * @param[in] last - le paramètre @c last de l'algorithme.
 * @param[in] pred - le paramètre @c pred de l'algorithme.
 * @param[in] threads - le nombre de threads utilisés.
 * @param[in] titre - le titre du benckmark.
 */
template< typename InputIterator, typename UnaryPredicate >
void
tester(const InputIterator& first, 
       const InputIterator& last, 
       const UnaryPredicate& pred,
       const int& threads,
       const std::string& titre) {

  using namespace paralgos;

  // Type synonyme pour le résultat de l'algorithme count_if.
  typedef typename std::iterator_traits< InputIterator >::difference_type
    Result;

  // Nombre d'itérations à effectuer sur le même algorithme pour obtenir des
  // mesures de temps conséquentes.
  const int combien = 64;

  // Durée d'exécution de la version séquentielle (bibliothèque standard) et
  // son résultat.
  double seq;
  Result seqCountIf;
  {
    const double start = omp_get_wtime();
    for (int i = 0; i < combien; i ++) {
      seqCountIf = std::count_if(first, last, pred); 
    }
    const double stop = omp_get_wtime();
    seq = stop - start;
  }

  // Durée d'exécution de la version parallèle et son résultat.
  double par;
  Result parCountIf;
  {
    const double start = omp_get_wtime();
    for (int i = 0; i < combien; i ++) {
      parCountIf = CountIf::apply(first, last, pred);
    }
    const double stop = omp_get_wtime();
    par = stop - start;
  }

  // Affichage des résultats.
  std::cout << "--[ " << titre << ": begin ] --" << std::endl;
  std::cout << "\tDurée seq. :\t\t" << seq << " sec." << std::endl;
  std::cout << "\tDurée par. :\t\t" << par << " sec." << std::endl;
  std::cout << "\tVerdict:\t"
	    << std::boolalpha
	    << (seqCountIf == parCountIf)
	    << std::endl;
  std::cout << "\tThread(s):\t" << threads << std::endl;
  std::cout << "\tSpeedup:\t" << Metrics::speedup(seq, par) << std::endl;
  std::cout << "\tEfficiency:\t"
	    << Metrics::efficiency(seq, par, threads)
	    << std::endl;
  std::cout << "--[ " << titre << ": end ] --" << std::endl;
  std::cout << std::endl;

}

/**
 * Programme de test de l'algorithme multithreadé ForEach.
 * 
 * @return @c EXIT_SUCCESS puisqu'exécution toujours réussie.
 */
int
main() {

  //  Nombre de threads utilisés.
  int threads;
#pragma omp parallel
#pragma omp single
    threads = omp_get_num_threads();

  // Nombres d'éléments à traiter.
  const uint n = 1021 * 1023;

  // Conteneurs manipulés. Tous sont déclarés au même niveau afin que leurs
  // destructeurs éventuels ne viennent pas parasiter les mesures de durées
  // d'exécution.
  std::list< uint > liste;
  std::array< uint, n > tableau;
  for (uint i = 0; i < n; i ++) {
      liste.push_back(i);
      tableau[i] = i;
  }

  // Premier test : une liste d'entiers + le prédicat pgcd21Vaut3.
  {
    const std::string titre = "list + pgcd21Vaut3";   
    tester(liste.begin(), 
    	   liste.end(), 
    	   pgcd21Vaut3,
    	   threads,
    	   titre);
  }

  // Second test : un tableau d'entiers + le prédicat pgcd21Vaut3.
  {
    const std::string titre = "array + pgcd21Vaut3";   
    tester(tableau.begin(),
    	   tableau.end(), 
    	   pgcd21Vaut3,
    	   threads,
    	   titre);
  }

  // Troisième test : une liste d'entiers + le prédicat estPair.
  {
    const std::string titre = "list + estPair";   
    tester(liste.begin(), 
    	   liste.end(), 
    	   estPair,
    	   threads,
    	   titre);
  }

  // Quatrième test : un tableau d'entiers + le prédicat estPair.
  {
    const std::string titre = "array + estPair";   
    tester(tableau.begin(),
    	   tableau.end(), 
    	   estPair,
    	   threads,
    	   titre);
  }

  // Tout s'est bien passé.
  return EXIT_SUCCESS;

}
