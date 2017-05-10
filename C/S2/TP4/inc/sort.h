#ifndef _SORT_
#define _SORT_

/** @file sort.h
*   @brief Header contenant la definition des fonctions de tri pour des tableaux génériques.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
#define MIN -10


/** @fn selection_sort
*   @brief Fonction de tri par selection.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void selection_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *));

/** @fn insertion_sort
*   @brief Fonction de tri par insertion.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void insertion_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *));

/** @fn bubble_sort
*   @brief Fonction de tri à bulles.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void bubble_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *));

/** @fn merge_sort
*   @brief Fonction de tri fusion.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void merge_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *));

/** @fn quick_sort
*   @brief Fonction de tri rapide.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void quick_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *));

/** @fn is_sorted
*   @brief Fonction de validation du tri.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
bool is_sorted(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *));

/** @fn swap
*   @brief Fonction d'échange.
*   @param pa Pointeur vers le premier element.
*   @param pb Pointeur vers le deuxieme element.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @return Un booleen.
*/
bool swap(void *pa, void *pb, size_t sizeElem);

#endif /* end of include guard : _SORT_ */
