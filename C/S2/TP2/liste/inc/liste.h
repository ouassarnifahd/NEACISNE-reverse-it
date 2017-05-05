#ifndef _LISTE_
#define _LISTE_

/** @file liste.h
*   @brief Header contenant la definition des fonctions de manupilation des listes.
*/

/** @struct Node
*   @brief Structure d'un nœud.
*/
struct Node {
    void* pElement;     /**< Pointeur vers le contenu du nœud.  */
    struct Node *Next;  /**< Pointeur vers le nœud suivant.     */
};

typedef struct Node TNode;

/** @typedef PTNode
*   @brief Type pointeur vers la structure nœud.
*/
typedef struct Node *PTNode;

/** @struct List
*   @brief Structure d'une liste.
*/
struct List {
    int     NumElems;    /**< Nombre d'éléments de la liste.              */
    int     SizeofElem;  /**< Taille unitaire en octets d’un élément.     */
    PTNode  First;       /**< Pointeur vers le premier nœud de la liste.  */
    PTNode  Last;        /**< Pointeur vers le dernier nœud de la liste.  */
    PTNode  Current;     /**< Pointeur vers le nœud courant.              */
    int     Index;       /**< Position du nœud courant dans la liste.     */
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
bool TList_IsEmpty(const PTList this);

/** @fn TList_Length
*   @brief Retourne la taille de la liste.
*   @param this Pointeur vers le type liste.
*   @return la taille de la liste.
*/
int TList_Length(const PTList this);

/** @fn TList_GetSizeofElem
*   @brief Retourne la taille unitaire d’un élément.
*   @param this Pointeur vers le type liste.
*   @return la taille unitaire en octets d’un élément.
*/
int TList_GetSizeofElem(const PTList this);

/** @fn TList_GoTo
*   @brief Positionne le pointeur courant à la position spécifiée et retourne le nœud courant.
*   @param this Pointeur vers le type liste.
*   @param index La position spécifiée.
*   @return Pointeur vers le nœud courant.
*/
PTNode TList_GoTo(const PTList this, int Pos);

/** @fn TList_GetIndex
*   @brief Retourne la position courante.
*   @param this Pointeur vers le type liste.
*   @return la position courante.
*/
int TList_GetIndex(const PTList this);

/** @fn TList_InsertFirst
*   @brief Insère un élément en début de liste et retourne le nœud créé.
*   @param this Pointeur vers le type liste.
*   @param pNewElt Un nouveau élément.
*   @return Pointeur vers le nœud courant.
*/
PTNode TList_InsertFirst(const PTList this, void *pNewElt);

/** @fn TList_RemoveFirst
*   @brief Retire l'élément en début de liste.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
bool TList_RemoveFirst(const PTList this);

/** @fn TList_Add
*   @brief Ajoute un élément en fin de liste et retourne le nœud créé.
*   @param this Pointeur vers le type liste.
*   @param pNewElt Un nouveau élément.
*   @return Pointeur vers le nœud courant.
*/
PTNode TList_Add(const PTList this, void *pNewElt);

/** @fn TList_RemoveLast
*   @brief Retire l'élément en fin de liste.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
bool TList_RemoveLast(const PTList);

/** @fn TList_Insert
*   @brief Insère un élément à la position courante dans la liste et retourne le nœud créé.
*   @param this Pointeur vers le type liste.
*   @param pNewElt Un nouveau élément.
*   @return Pointeur vers le nœud courant.
*/
PTNode TList_Insert(const PTList this, void *pNewElt);

/** @fn TList_RemoveCurrent
*   @brief Retire l'élément à la position courante de la liste.
*   @param this Pointeur vers le type liste.
*   @return Un booleen.
*/
bool TList_RemoveCurrent(const PTList this);

/** @fn TList_Clear
*   @brief Vide la liste.
*   @param this Pointeur vers le type liste.
*/
void TList_Clear(const PTList this);

/** @fn TList_Delete
*   @brief Supprime la liste en libérant les zones mémoires allouées.
*   @param this Pointeur vers le type liste.
*/
void TList_Delete(const PTList this);

/** @fn TList_Display
*   @brief Affiche tous les éléments de la liste.
*   @param this Pointeur vers le type liste.
*   @param display_element Une fonction affichant un élément unitaire.
*/
void TList_Display(const PTList this ,void (*display)(const void *));

#endif /* end of include guard : _LISTE_ */
