#ifndef _PILE_
#define _PILE_

/** @file pile.h
*	@brief Header des fonctions de pile
*/

#include"./Elements/element.h"

/** @typedef TPile
*	@brief Le type structure de la pile.
*/
typedef struct Pile {
	int NumElems;	/**< Nombres d'element dans la pile. */
	int TailleMax;	/**< Taille maximale de la pile. */
	TElement *Table;/**< Les elements de la pile. */
} TPile;

/** @typedef PTPile
*	@brief Définition d'un type pointeur vers la structure TPile.
*/
typedef TPile* PTPile;

/** @fn TPile_Creer
*	@brief Création d'une nouvelle file vide.
*	@param maxSize Entier determinant la taille initiale de la pile.
*	@return Une pile vide de taille maxSize.
*/
PTPile TPile_Creer(int maxSize /**< Entier determinant la taille initiale de la pile. */);

/** @fn TPile_EstVide
*	@brief Teste si la file est vide.
*	@param this Une pile de type PTPile (pointeur).
*	@return Un booleen correspondant à l'etat de la pile (vide ou pas).
*/
bool TPile_EstVide(const PTPile this /**< Une pile de type PTPile (pointeur). */);

/** @fn TPile_Taille
*	@brief Renvoie la taille de la pile (nombre d'éléments empilés).
*	@param this Une pile de type PTPile (pointeur).
*	@return La taille de la pile.
*/
int TPile_Taille(const PTPile this /**< Une pile de type PTPile (pointeur). */);

/** @fn TPile_Top
*	@brief Renvoie la valeur de l'élément au sommet de la pile.
*	@param this Une pile de type PTPile (pointeur).
*	@return L'element du sommet de la pile.
*/
TElement TPile_Top(const PTPile this /**< Une pile de type PTPile (pointeur). */);

/** @fn TPile_Empiler
*	@brief Empile un nouvel élément. Si la pile est pleine, doubler la taille du tableau avant d'empiler.
*	@param this Une pile de type PTPile (pointeur).
*	@param newElt Un nouveau element à empiler.
*	@return Une pile de type PTPile (pointeur) modifiée.
*/
PTPile TPile_Empiler(const PTPile this /**< Une pile de type PTPile (pointeur). */,
 					 TElement newElt   /**< Un nouveau element à empiler. */);

/** @fn TPile_Depiler
*	@brief Enlève l’élément au sommet de la pile.
*	@param this Une pile de type PTPile (pointeur).
*	@param pElement Pointeur vers l'element depilé.
*	@return Une booleen test de validation de l'operation depiler.
*/
bool TPile_Depiler(const PTPile this  /**< Une pile de type PTPile (pointeur). */,
	 			   PTElement pElement /**< Pointeur vers l'element depilé. */);

/** @fn TPile_Effacer
*	@brief Efface complètement la pile.
*	@param this Une pile de type PTPile (pointeur).
*/
void TPile_Effacer(const PTPile this /**< Une pile de type PTPile (pointeur). */);

/** @fn TPile_Afficher
*	@brief Affiche l'état de la pile.
*	@param this Une pile de type PTPile (pointeur).
*/
void TPile_Afficher(const PTPile this /**< Une pile de type PTPile (pointeur). */);

/** @fn TPile_Afficher
*	@brief Détruit la pile.
*	@param this Une pile de type PTPile (pointeur).
*/
void TPile_Detruire(const PTPile this /**< Une pile de type PTPile (pointeur). */);

#endif /* end of include guard */
