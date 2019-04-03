/**
 * @mainpage
 *
 * Programme de benchmarking de différents algorithmes optimisés de
 * multiplication matrice-vecteur sur le type float.
 *
 * Les quatres algorithmes comparés sont sélectionnés via les symboles
 * pré-processeur suivants : @c RAW (forme canonique et choix par défaut),
 * @c R4 (déroulage de boucle sur une profondeur de 4 et @c SSE_R4 (jeu
 * d'instructions SSE sur 128 bits). Le symbole spécial @c DRY_RUN désigne
 * l'enveloppe de l'algorithme c'est à dire l'ensemble du programme sans les
 * instructions relatives au produit.
 *
 * Les algorithmes sont exécutés plusieurs fois afin d'obtenir des durées
 * d'exécutions significatives.
 */

#include <stdlib.h>
#include <stdio.h>

// #define aligned_alloc(alignment, size) _aligned_malloc(size, alignment)

#define SIZE  2048 // Longueur de nos vecteurs.
#define ITERS   10 // Nombre de répétitions de l'algorithme.

// Inclusion du header correspondant à l'algorithme sélectionné.
#if defined(R4)
#include "matvec_r4.h"
#elif defined(SSE_R4)
#include "matvec_sse_r4.h"
#else
#include "matvec.h"
#endif

/**
 * Programme principal.
 *
 * @return @c EXIT_SUCCESS.
 */
int
main() {

  // Notre matrice (carrée) et nos deux vecteurs qui seront alloués
  // dynamiquement. Le mot-clé restrict indique que les zones mémoires
  // concernées ne se recouvrent pas.
  float *restrict A, *restrict x, *restrict b;

  // Allocation dynamique avec l'alignement correspondant au jeu d'instructions
  // utilisé.
#if defined(SSE_R4)
  A = (float*) aligned_alloc(16, sizeof(float) * SIZE * SIZE);
  x = (float*) aligned_alloc(16, sizeof(float) * SIZE);
  b = (float*) aligned_alloc(16, sizeof(float) * SIZE);
#else
  A = (float*) malloc(sizeof(float) * SIZE * SIZE);
  x = (float*) malloc(sizeof(float) * SIZE);
  b = (float*) malloc(sizeof(float) * SIZE);
#endif

  // Initialisation des éléments de notre matrice ainsi que de ceux du vecteur x
  // à la valeur 1.0.
  for (unsigned i = 0; i != SIZE * SIZE; A[i ++] = 1.0);
  for (unsigned i = 0; i != SIZE;        x[i ++] = 1.0);
  for (unsigned i = 0; i != SIZE;        b[i ++] = 1.0);

  // Boucle de répétition de l'algorithme.
  for (unsigned i = 0; i != ITERS; i ++) {
#if defined(R4)
    matvec_r4    (A, x, b, SIZE);
#elif defined(SSE_R4)
    matvec_sse_r4(A, x, b, SIZE);
#else
    matvec       (A, x, b, SIZE);
#endif
  }

  // Désallocation.
  free(A);
  free(x);
  free(b);

  // C'est terminé.
  return EXIT_SUCCESS;

}
