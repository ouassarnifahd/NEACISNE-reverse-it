#ifndef _SORT_
#define _SORT_

/** @file sort.h
*   @brief Header contenant la definition des fonctions de tri pour des tableaux génériques.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <float.h>

/** @def MIN_SORT
*   @brief Taille du tableau minimal a trier recursivement.
*/
#define MIN_SORT 2

/** @fn selection_sort
*   @brief Fonction de tri par selection.
*   @param tabElems Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void selection_sort(void *tabElems /**< Pointeur vers le tableau. */,
                    size_t numElems /**< Nombre d'elements du tableau. */,
                    size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
                    int (*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */); /**< Fonction de tri par selection. */

/** @fn insertion_sort
*   @brief Fonction de tri par insertion.
*   @param tabElems Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void insertion_sort(void *tabElems /**< Pointeur vers le tableau. */,
                    size_t numElems /**< Nombre d'elements du tableau. */,
                    size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
                    int (*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */); /**< Fonction de tri par insertion. */

/** @fn bubble_sort
*   @brief Fonction de tri à bulles.
*   @param tabElems Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void bubble_sort(void *tabElems /**< Pointeur vers le tableau. */,
                 size_t numElems /**< Nombre d'elements du tableau. */,
                 size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
                 int (*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */); /**< Fonction de tri à bulles. */

/** @fn merge_sort
*   @brief Fonction de tri fusion.
*   @param tabElems Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void merge_sort(void *tabElems /**< Pointeur vers le tableau. */,
                size_t numElems /**< Nombre d'elements du tableau. */,
                size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
                int (*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */); /**< Fonction de tri fusion. */

/** @fn quick_sort
*   @brief Fonction de tri rapide.
*   @param tabElems Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
void quick_sort(void *tabElems /**< Pointeur vers le tableau. */,
                size_t numElems /**< Nombre d'elements du tableau. */,
                size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
                int (*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */); /**< Fonction de tri rapide. */

/** @fn is_sorted
*   @brief Fonction de validation du tri.
*   @param tabElems Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*/
bool is_sorted(void *tabElems /**< Pointeur vers le tableau. */,
               size_t numElems /**< Nombre d'elements du tableau. */,
               size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
               int (*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */); /**< Fonction de validation du tri. */

/** @fn swap
*   @brief Fonction d'échange.
*   @param pa Pointeur vers le premier element.
*   @param pb Pointeur vers le deuxieme element.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @return Un booleen.
*/
bool swap(void *pa /**< Pointeur vers le premier element. */,
          void *pb /**< Pointeur vers le deuxieme element. */,
          size_t sizeElem /**< Taille unitaire en octets d’un élément. */); /**< Fonction d'échange. */

/** @fn eval_sort
*   @brief Fonction d'évaluation du tri.
*   @param inTab Pointeur vers le tableau.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param compare Fonction Callback de la relation d'ordre.
*   @param fsort Fonction Callback du tri.
*   @return Durée du tri.
*/
double eval_sort(const void *inTab /**< Pointeur vers le tableau. */,
                 size_t numElems /**< Nombre d'elements du tableau. */,
                 size_t sizeElem /**< Taille unitaire en octets d’un élément. */,
                 int(*compare)(const void *, const void *) /**< Fonction Callback de la relation d'ordre. */,
                 void(*fsort)(void *, size_t, size_t, int(*compare)(const void *, const void *)) /**< Fonction Callback du tri. */); /**< Fonction d'évaluation du tri. */

#endif /* end of include guard : _SORT_ */
