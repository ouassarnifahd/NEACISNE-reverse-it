#include "matvec_sse_r4.h"

/*
 * Union permettant d'accéder aux quatre nombre flottants simple précision
 * compactés dans un registre 128 bits. 
 */
typedef union {
  __m128 m128_vec;    // Le registre.
  float  m128_f32[4]; // Ce même registre vu comme un tableau de taille 4.
} xmm_t;

/*****************
 * matvec_sse_r4 *
 *****************/

void
matvec_sse_r4(const float A[restrict],
              const float x[restrict],
                    float b[restrict],
              const unsigned size) {

  // Nos quatre accumulateurs.
  xmm_t acc;

  // A chaque accès mémoire nous allons ramener quatre nombre flottants en
  // provenance de la matrice A et quatre autres en provenance du vecteur
  // source. Il faudra ensuite procéder à la multiplication des quatres valeur
  // en provenance de A par celles en provenance de B. Par conséquent, nous
  // utilisons trois registres 128 bits différents pour simplifier l'écriture.
  __m128 AA, xx, AAxx;

  // Boucle sur les composantes du vecteur cible b et donc les lignes de la
  // matrice A.
  for (unsigned i = 0; i != size; i ++) {

    // Mise à zéro de nos quatre accumulateurs.
    acc.m128_vec = _mm_setzero_ps();

    // ... à compléter ...

    // La valeur finale de la composante b[i] est la somme de nos quatre
    // accumulateurs. La mise à jour est ici faite sous forme scalaire par
    // accès à chaque élément du tableau ce qui peut être pénalisant si la
    // longeur des vecteurs est faible. Nous aurions également pu utiliser
    // une routine particulière du jeu d'instructions SSE3 (_mm_hadd_ps)
    // permettant de sommer les composantes d'un registre. Cependant, ce jeu
    // n'est pas forcément disponible sur l'ensemble des systèmes.
    b[i] = acc.m128_f32[0]
      + acc.m128_f32[1]
      + acc.m128_f32[2]
      + acc.m128_f32[3];
    
  }
}
