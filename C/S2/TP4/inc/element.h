#ifndef _ELEMENT_
#define _ELEMENT_

/**
*   @file element.h
*   @brief Header contenant la definition de l'element.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#ifdef ELEM_SHORT

/** @typedef TElement
*   @brief L'element.
*/
typedef short TElement;

/** @def FORMAT
*   @brief Format de la structure de données.
*/
#define FORMAT "%hi"

#ifdef DEBUG
#define FORMATREAD "%hi"
#endif

#elif ELEM_LONG

/** @typedef TElement
*   @brief L'element.
*/
typedef long TElement;

/** @def FORMAT
*   @brief Format de la structure de données.
*/
#define FORMAT "%li"

#ifdef DEBUG
#define FORMATREAD "%li"
#endif

#elif ELEM_REAL

/** @typedef TElement
*   @brief L'element.
*/
typedef float TElement;

/** @def FORMAT
*   @brief Format de la structure de données.
*/
#define FORMAT "%.2f"

#ifdef DEBUG
#define FORMATREAD "%f"
#endif

#else

/** @typedef TElement
*   @brief L'element.
*/
typedef type TElement;

/** @def FORMAT
*   @brief Format de la structure de données.
*/
#define FORMAT "%"

#endif

/** @typedef PTElement
*   @brief Pointeur vers l'element.
*/
typedef TElement* PTElement;

/** @fn TElement_Display
*   @brief Affiche l'element.
*   @param Pointeur vers l'élément à afficher.
*/
void TElement_Display(const void *pElement);

/** @fn TElement_Compare
*   @brief Compare deux éléments.
*   @param p1 Pointeur vers le premier élément à comparer.
*   @param p2 Pointeur vers le deuxieme élément à comparer.
*   @return Un entier {-1, 0, +1} de comparaison.
*/
int TElement_Compare(const void *p1, const void *p2);

/** @fn TElement_Random
*   @brief Retourne un élément générer aléatoirement.
*   @param pVal Pointeur vers l'élément généré aléatoirement.
*   @param pMin Pointeur vers l'élément minimal voulu.
*   @param pMax Pointeur vers l'élément maximal voulu.
*/
void TElement_Random(void *pVal, const void *pMin, const void *pMax);

#endif /* end of include guard : _ELEMENT_ */
