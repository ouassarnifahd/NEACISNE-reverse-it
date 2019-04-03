#ifndef MATVEC_SSE_R4_H
#define MATVEC_SSE_R4_H

#include <x86intrin.h>

/**
 * Forme SIMD de l'algorithme de multiplication matrice-vecteur exploitant le 
 * jeu d'instructions SSE.
 *
 * @param[in]  A la matrice (dépliée en tableau).
 * @param[in]  x le vecteur source.
 * @param[out] b le vecteur cible.
 * @param[in]  size la longueur de nos vecteurs.
 *
 * @note la longueur des vecteurs doit obligatoirement être un multiple de 4.
 * @note le mot-clé @c restrict indique qu'il n'existe aucun recouvrement entre
 *   les zones mémoires associées à la matrice et aux deux vecteurs.
 */
void matvec_sse_r4(const float A[restrict],
                   const float x[restrict],
                         float b[restrict],
                   const unsigned size);

#endif
