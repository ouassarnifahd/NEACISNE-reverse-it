#include "ForEach.hpp"
#include "Metrics.hpp"
#include <omp.h>
#include <algorithm>
#include <array>
#include <list>
#include <iostream>
#include <cstdlib>

/**
 * Calcule le carré du nombre entier fourni en argument.
 *
 * @param[in] e - le nombre.
 * @return le carré du nombre.
 *
 * @note le temps de calcul de cette fonction est parfaitement homogène.
 */
unsigned long
carre(const int& e) {
  return e * e;
}

/**
 * Calcule le pgcd (algorithme d'Euclide) du numérateur fourni en argument et
 * d'un dénominateur égal à la valeur 21.
 *
 * @param[in] num - le numérateur.
 * @return le pgcd du numérateur et de la valeur 21.
 *
 * @note l'algorithme d'Euclide est fortement hétérogène en termes de nombre
 * d'instructions à exécuter.
 */
unsigned
euclide21(const int& num) {
  const int den = 21;
  int a = std::abs(num);
  int b = den;
  if (a % b == 0) {
    return b;
  }
  int r = 0;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

/**
 * Routine d'évaluation des performances.
 *
 * @param[in] first - le paramètre @c first de l'algorithme.
 * @param[in] last - le paramètre @c last de l'algorithme.
 * @param[in] fn - le paramètre @c fn de l'algorithme.
 * @param[in] threads - le nombre de threads utilisés.
 * @param[in] titre - le titre du benckmark.
 */
template< typename InputIterator, typename Function >
void
tester(const InputIterator& first,
       const InputIterator& last,
       const Function& fn,
       const int& threads,
       const std::string& titre) {

  using namespace paralgos;

  // Nombre d'itérations à effectuer sur le même algorithme pour obtenir des
  // mesures de temps conséquentes.
  const int combien = 64;

  // Durée d'exécution de la version séquentielle (bibliothèque standard).
  double seq;
  {
    const double start = omp_get_wtime( );
    for (int i = 0; i < combien; i ++) {
      std::for_each(first, last, fn);
    }
    const double stop = omp_get_wtime( );
    seq = stop - start;
  }

  // Durée d'exécution de la version parallèle.
  double par;
  {
    const double start = omp_get_wtime( );
    for (int i = 0; i < combien; i ++) {
      ForEach::apply(first, last, fn);
    }
    const double stop = omp_get_wtime( );
    par = stop - start;
  }

  // Affichage des résultats.
  std::cout << "--[ " << titre << ": begin ] --" << std::endl;
  std::cout << "\tDurée seq. :\t\t" << seq << " sec." << std::endl;
  std::cout << "\tDurée par. :\t\t" << par << " sec." << std::endl;
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
    const int n = 1021 * 1023;

  // Conteneurs manipulés. Tous sont déclarés au même niveau afin que leurs
  // destructeurs éventuels ne viennent pas parasiter les mesures de durées
  // d'exécution.
  std::list< long > liste;
  std::array< long, n > tableau;
  for (int i = 0; i < n; i ++) {
      liste.push_back(i);
      tableau[i] = i;
  }

  // Premier test : une liste d'entiers + l'algorithme d'Euclide.
  {
    const std::string titre = "list + Euclide";
    tester(liste.begin(),
    	   liste.end(),
    	   euclide21,
    	   threads,
    	   titre);
  }

  // Second test : un tableau d'entiers + l'algorithme d'Euclide.
  {
    const std::string titre = "array + Euclide";
    tester(tableau.begin(),
    	   tableau.end(),
    	   euclide21,
    	   threads,
    	   titre);
  }

  // Troisième test : une liste d'entiers + le calcul d'un carré.
  {
    const std::string titre = "list + carré";
    tester(liste.begin(),
    	   liste.end(),
    	   carre,
    	   threads,
    	   titre);
  }

  // Quatrième test : un tableau d'entiers + le calcul d'un carré.
  {
    const std::string titre = "array + carré";
    tester(tableau.begin(),
    	   tableau.end(),
    	   carre,
    	   threads,
    	   titre);
  }

  // Tout s'est bien passé.
  return EXIT_SUCCESS;

}
