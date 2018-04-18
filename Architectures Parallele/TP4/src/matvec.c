#include "matvec.h"

/**********
 * matvec *
 **********/

void
matvec(const float A[], const float x[], float b[], const unsigned size) {
  
#ifndef DRY_RUN

  // Boucle sur les composantes du vecteur cible b et donc les lignes de la
  // matrice A.
  for (unsigned i = 0; i != size; i ++) {

    // La composante b[i] étant utilisée comme accumulateur pour l'addition, il
    // faut commencer par l'initialiser à zéro.
    b[i] = 0.0;

    // Boucle sur les composantes du vecteur source x et donc les colonnes de
    // la matrice A. Comme cette dernière est représentée sous la forme d'un
    // tableau unidimensionnel, il nous faut réaliser la conversion 2D -> 1D.
    // Par conséquent, deux jeux d'indices sont utilisés : j qui parcourt les
    // colonnes de la ligne i dans la matrice A et k qui parcourt les
    // composantes du vecteur source x.
    for (unsigned j = i * size, k = 0; k != size; j ++, k ++) { 
      b[i] += A[j] * x[k];  
    }
    
  }
  
#endif
  
}
