#include "matvec_r4.h"

/*************
 * matvec_r4 *
 *************/

void
matvec_r4(const float A[], const float x[], float b[], const unsigned size) {

  // Quatre accumulateurs différents.
  float acc0, acc1, acc2, acc3;

  // Boucle sur les composantes du vecteur cible b et donc les lignes de la
  // matrice A.
  for (unsigned i = 0; i != size; i ++) {

    // Nos accumulateurs sont ré-initialisés pour le calcul de chaque nouvelle
    // composante du vecteur cible b.
    acc0 = acc1 = acc2 = acc3 = 0.0;

    // ... à compléter ...

    // La valeur finale de la composante b[i] est la somme de nos quatre
    // accumulateurs.
    b[i] = acc0 + acc1 + acc2 + acc3;
    
  }
  
}
