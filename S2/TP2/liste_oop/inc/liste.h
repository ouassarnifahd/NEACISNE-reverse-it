#ifndef _LISTE_
#define _LISTE_

/** @file liste.h
*   @brief Header contenant la definition des fonctions de manupilation des listes.
*/

#include "./Elements/element.h"

/** @struct Node
*   @brief Structure d'un nœud en programmation orientée objet.
*/
struct Node {
    PTElement Element;  /**< Pointeur vers le contenu du nœud.  */
    struct Node *Next;  /**< Pointeur vers le nœud suivant.     */
};

typedef struct Node TNode;

/** @typedef PTNode
*   @brief Type pointeur vers la structure nœud.
*/
typedef struct Node *PTNode;

/** @struct List
*   @brief Structure d'une liste en programmation orientée objet.
*/
struct List {
    int     NumElems;                                                    /**< Attribut: Nombre d'éléments de la liste.              */
    int     SizeofElem;                                                  /**< Attribut: Taille unitaire en octets d’un élément.     */
    PTNode  First;                                                       /**< Attribut: Pointeur vers le premier nœud de la liste.  */
    PTNode  Last;                                                        /**< Attribut: Pointeur vers le dernier nœud de la liste.  */
    PTNode  Current;                                                     /**< Attribut: Pointeur vers le nœud courant.              */
    int     Index;                                                       /**< Attribut: Position du nœud courant dans la liste.     */

    bool    (*IsEmpty)       (const struct List *);                      /**< Methode: Accesseur - Etat de la liste (vide?).        */
    int     (*Length)        (const struct List *);                      /**< Methode: Accesseur - Taille de la liste.              */
    int     (*GetIndex)      (const struct List *);                      /**< Methode: Accesseur - Position du nœud courant.        */

    PTNode  (*GoTo)          (const struct List *, int);                 /**< Methode: Mutateur - Pointeur courant.                 */

    PTNode  (*InsertFirst)   (const struct List *, void *);              /**< Methode: Insère un élément en début de liste.         */
    bool    (*RemoveFirst)   (const struct List *);                      /**< Methode: Retire l'élément en début de liste.          */
    PTNode  (*Add)           (const struct List *, void *);              /**< Methode: Ajoute un élément en fin de liste.           */
    bool    (*RemoveLast)    (const struct List *);                      /**< Methode: Retire l'élément en fin de liste.            */
    PTNode  (*Insert)        (const struct List *, void *);              /**< Methode: Insère un élément à la position courante.    */
    bool    (*RemoveCurrent) (const struct List *);                      /**< Methode: Retire l'élément à la position courante.     */
    void    (*Clear)         (const struct List *);                      /**< Methode: Vide la liste.                               */
    void    (*Display)       (const struct List *,
                              void (*display_element)(const void *));    /**< Methode: Affiche tous les éléments de la liste.       */
    void    (*Delete)        (const struct List *);                      /**< Methode: Destructeur                                  */
};

typedef struct List TList;

/** @typedef PTList
*   @brief Type pointeur vers la structure liste.
*/
typedef TList *PTList;

/** @fn TList_New
*   @brief Création d'une nouvelle liste vide.
*   @param sizeofElem Taille unitaire en octets d'un élément.
*   @return Un pointeur vers le type liste.
*/
PTList TList_New(int sizeofElem); /* Methode: Constructeur */

/** @fn TList_IsEmpty
*   @brief Retourne true si la liste est vide.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
static inline bool TList_IsEmpty(const PTList this);

/** @fn TList_Length
*   @brief Retourne la taille de la liste.
*   @param this Pointeur vers le type liste.
*   @return la taille de la liste.
*/
static inline int TList_Length(const PTList this);

/** @fn TList_GetSizeofElem
*   @brief Retourne la taille unitaire d’un élément.
*   @param this Pointeur vers le type liste.
*   @return la taille unitaire en octets d’un élément.
*/
static inline int TList_GetSizeofElem(const PTList this);

/** @fn TList_GoTo
*   @brief Positionne le pointeur courant à la position spécifiée et retourne le nœud courant.
*   @param this Pointeur vers le type liste.
*   @param index La position spécifiée.
*   @return Pointeur vers le nœud courant.
*/
static inline PTNode TList_GoTo(const PTList this, int Pos);

/** @fn TList_GetIndex
*   @brief Retourne la position courante.
*   @param this Pointeur vers le type liste.
*   @return la position courante.
*/
static inline int TList_GetIndex(const PTList this);

/** @fn TList_InsertFirst
*   @brief Insère un élément en début de liste et retourne le nœud créé.
*   @param this Pointeur vers le type liste.
*   @param pNewElt Un nouveau élément.
*   @return Pointeur vers le nœud courant.
*/
static inline PTNode TList_InsertFirst(const PTList this, void *pNewElt);

/** @fn TList_RemoveFirst
*   @brief Retire l'élément en début de liste.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
static inline bool TList_RemoveFirst(const PTList this);

/** @fn TList_Add
*   @brief Ajoute un élément en fin de liste et retourne le nœud créé.
*   @param this Pointeur vers le type liste.
*   @param pNewElt Un nouveau élément.
*   @return Pointeur vers le nœud courant.
*/
static inline PTNode TList_Add(const PTList this, void *pNewElt);

/** @fn TList_RemoveLast
*   @brief Retire l'élément en fin de liste.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
static inline bool TList_RemoveLast(const PTList);

/** @fn TList_Insert
*   @brief Insère un élément à la position courante dans la liste et retourne le nœud créé.
*   @param this Pointeur vers le type liste.
*   @param pNewElt Un nouveau élément.
*   @return Pointeur vers le nœud courant.
*/
static inline PTNode TList_Insert(const PTList this, void *pNewElt);

/** @fn TList_RemoveCurrent
*   @brief Retire l'élément à la position courante de la liste.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
static inline bool TList_RemoveCurrent(const PTList this);

/** @fn TList_Clear
*   @brief Vide la liste.
*   @param this Pointeur vers le type liste.
*/
static inline void TList_Clear(const PTList this);

/** @fn TList_Delete
*   @brief Supprime la liste en libérant les zones mémoires allouées.
*   @param this Pointeur vers le type liste.
*/
static inline void TList_Delete(const PTList this);

/** @fn TList_Display
*   @brief Affiche tous les éléments de la liste.
*   @param this Pointeur vers le type liste.
*   @param display_element Une fonction affichant un élément unitaire.
*/
static inline void TList_Display(const PTList this ,void (*display)(const void *));

#endif /* end of include guard : _LISTE_ */
