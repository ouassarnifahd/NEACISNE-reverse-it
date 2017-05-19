#ifndef _ELEMENT_
#define _ELEMENT_

/** @file element.h
*   @brief Header contenant la definition de l'elements.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _FLOAT_

#define TYPE "nombres reels"

typedef float BElement;

#elif _INT_

#define TYPE "nombres entiers"

typedef int BElement;

#else

/** @def TYPE
*   @brief Type de la structure de données.
*/
#define TYPE ""

typedef void BElement;

#endif

/** @struct Element
*   @brief Structure de l'élément en programmation orientée objet.
*/
struct Element {
    BElement    *pElement;                      /**< Attribut: Pointeur vers l'élément. */
    void        (*display)   (const void *);    /**< Methode: Affiche l'élément.        */
    bool        (*read)    (const void *);      /**< Methode: Lecture de l'élément.     */
};

typedef struct Element TElement;

/** @typedef PTElement
*   @brief Pointeur vers l'element.
*/
typedef TElement *PTElement;

/** @fn new_element
*   @brief Création d'un nouveau élément.
*   @param sizeofElem La taille unitaire en octets d'un élément.
*   @return Pointeur vers l'élément créé.
*/
PTElement new_element(int sizeofElem /**< La taille unitaire en octets d'un élément. */); /**< Création d'un nouveau élément. */

/** @fn display_element
*   @brief Affiche l'élément.
*   @param pElement L'élément à afficher.
*/
static inline void display_element(const void *pElement /**< L'élément à afficher. */); /**< Affiche l'élément. */

/** @fn read_element
*   @brief Lecture de l'élément.
*   @param pElement L'élément à lire.
*/
static inline bool read_element(const void *pElement /**< L'élément à lire. */); /**< Lecture de l'élément. */

#endif /* End of include Guard: _ELEMENT_ */
