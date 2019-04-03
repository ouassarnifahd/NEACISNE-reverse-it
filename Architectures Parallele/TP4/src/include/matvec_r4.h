#ifndef MATVEC_R4_H
#define MATVEC_R4_H
/**
 * Forme de l'algorithme de multiplication matrice-vecteur avec déroulage de
 * boucle sur une profondeur de 4.
 *
 * @param[in]  A la matrice (dépliée en tableau).
 * @param[in]  x le vecteur source.
 * @param[out] b le vecteur cible.
 * @param[in]  size la longueur de nos vecteurs.
 *
 * @note la longueur des vecteurs doit obligatoirement être un multiple de 4.
 */
void matvec_r4(const float A[],
               const float x[],
               float b[],
               const unsigned size);

#endif
