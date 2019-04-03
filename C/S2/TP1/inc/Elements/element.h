#ifndef _ELEMENT_
#define _ELEMENT_

/** @file element.h
*   @brief Header contenant la definition des elements utiles dans la pile.
*/

#ifdef _OTHER_

/** @def TYPE
*   @brief Type de la structure de données.
*/
#define TYPE ""

/** @def SCAN
*   @brief Macro pour scanner l'element à l'aide de son type.
*   @param var Nom de la variable de type TElement.
*/

#define SCAN(var /**< Nom de la variable de type TElement. */) scanf("%", &var)

/** @typedef TElement
*   @brief L'element de travail.
*/
typedef TYPE TElement;

#elif _FLOAT_

/** @def TYPE
*   @brief Type de la structure de données.
*/
#define TYPE "reels"

/** @def SCAN
*   @brief Macro pour scanner l'element à l'aide de son type.
*   @param var Nom de la variable de type TElement.
*/
#define SCAN(var /**< Nom de la variable de type TElement. */) scanf("%f", &var)

/** @typedef TElement
*   @brief L'element de travail.
*/
typedef float TElement;

#elif _INT_

/** @def TYPE
*   @brief Type de la structure de données.
*/
#define TYPE "entiers"

/** @def SCAN
*   @brief Macro pour scanner l'element à l'aide de son type.
*   @param var Nom de la variable de type TElement.
*/
#define SCAN(var  /**< Nom de la variable de type TElement. */) scanf("%d", &var)

/** @typedef TElement
*   @brief L'element de travail.
*/
typedef int TElement;

#endif

/** @typedef PTElement
*   @brief Pointeur vers l'element de travail: TElement.
*/
typedef TElement* PTElement;

/** @fn TElement_Afficher
*   @brief Affiche l'element TElement.
*   @param Un element de type TElement.
*/
void TElement_Afficher(TElement data /**< Un element de type TElement. */);

#endif /* End of include Guard: _ELEMENT_ */
