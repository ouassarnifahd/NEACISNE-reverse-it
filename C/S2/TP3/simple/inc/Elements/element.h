#ifndef _ELEMENT_
#define _ELEMENT_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/** @file element.h
*   @brief Header contenant la definition de l'element.
*/

#ifdef _DOXYGEN_

#define _INT_
#define _FLOAT_
#define _OTHER_

#endif /* _DOXYGEN_ */

#ifdef _OTHER_

/** @typedef TElement
*   @brief L'element.
*/
typedef TYPE TElement;

#elif _FLOAT_

#define TYPE "nombres reels"

/** @typedef TElement
*   @brief L'element.
*/
typedef float TElement;

#elif _INT_

#define TYPE "nombres entiers"

/** @typedef TElement
*   @brief L'element.
*/
typedef int TElement;

#endif

/** @typedef PTElement
*   @brief Pointeur vers l'element.
*/
typedef TElement* PTElement;

/** @fn display_element
*   @brief Affiche l'element.
*   @param pElement L'element a afficher.
*/
void display_element(const void *pElement /**< L'element a afficher. */); /**< Affiche l'element.    */

/** @fn read_element
*   @brief Lecture de l'element.
*   @param pElement L'element a lire.
*/
bool read_element(const void *pElement    /**< L'element a lire.     */); /**< Lecture de l'element. */

#endif /* end of include guard : _ELEMENT_ */
