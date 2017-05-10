#ifndef _ARRAY_
#define _ARRAY_

/** @file array.h
*   @brief Header contenant la definition des fonctions de manupilation des tableaux génériques.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/** @def ARRAY_SIZE
*   @brief Taille du tableau.
*/
#define ARRAY_SIZE 20

/** @fn displayTab
*   @brief Fonction d'affichage d'un tableau générique.
*   @param tabElems Pointeur vers le tableau à afficher.
*   @param numElems Nombre d'elements du tableau.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param display Fonction Callback pour l'affichage d'un élément.
*/
void displayTab(void *tabElems, size_t numElems, size_t sizeElem, void (*display)(const void *));

/** @fn initRandomTab
*   @brief Retourne un tableau générique aléatoire.
*   @param numElems Nombre d'elements du tableau.
*   @param pMin Pointeur vers l'élément minimal voulu.
*   @param pMax Pointeur vers l'élément maximal voulu.
*   @param sizeElem Taille unitaire en octets d’un élément.
*   @param random Fonction Callback pour la génération d'un élément aléatoire.
*   @return Un pointeur générique vers le debut du tableau aléatoire.
*/
void* initRandomTab(size_t numElems, const void *pMin, const void *pMax, size_t sizeElem, void (*random)(void *, const void *, const void *));

#endif /* end of include guard : _ARRAY_ */
