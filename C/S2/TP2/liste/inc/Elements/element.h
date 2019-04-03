#ifndef _ELEMENT_
#define _ELEMENT_

/** @file element.h
*   @brief Header contenant la definition de l'elements.
*/

#ifdef _FLOAT_

#define TYPE "nombres reels"

typedef float TElement;

#elif _INT_

#define TYPE "nombres entiers"

typedef int TElement;

#else

/** @def TYPE
*   @brief Type de la structure de données.
*/
#define TYPE ""

typedef void TElement;

#endif

/** @typedef PTElement
*   @brief Pointeur vers l'element.
*/
typedef TElement *PElement;

/** @fn display_element
*   @brief Affiche l'élément.
*   @param pElement L'élément à afficher.
*/
void display_element(const void *pElement /**< L'élément à afficher. */); /**< Affiche l'élément. */

/** @fn read_element
*   @brief Lecture de l'élément.
*   @param pElement L'élément à lire.
*/
bool read_element(const void *pElement /**< L'élément à lire. */); /**< Lecture de l'élément. */

#endif /* End of include Guard: _ELEMENT_ */
