#ifndef MATVEC_H
#define MATVEC_H

/**
 * Forme canonique de l'algorithme de multiplication matrice-vecteur.
 *
 * @param[in]  A la matrice (dépliée en tableau).
 * @param[in]  x le vecteur source.
 * @param[out] b le vecteur cible.
 * @param[in]  size la longueur de nos vecteurs.
 */
void matvec(const float A[], const float x[], float b[], const unsigned size);

#endif
