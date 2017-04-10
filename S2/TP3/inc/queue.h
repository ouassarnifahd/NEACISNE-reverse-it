#ifndef _QUEUE_
#define _QUEUE_

/** @file queue.h
*   @brief Header contenant la definition des fonctions de manupilation des files.
*/

#include"./Elements/element.h"

/** @struct Queue
*   @brief Structure d'une file en programmation orientée objet.
*/
struct Queue {
    int         TabSize;                                        /**< Attribut: Taille allouée au tableau.                  */
    int         NumElems;                                       /**< Attribut: Nombre d'éléments dans la file.             */
    int         FrontIndex;                                     /**< Attribut: Indice de la tête de la file.               */
    int         BackIndex;                                      /**< Attribut: Indice de la queue de la file.              */
    PTElement   Table;                                          /**< Attribut: Tableau dynamiquement alloué.               */

    bool        (*IsEmpty)  (const struct Queue *);             /**< Methode: Accesseur - Etat de la file (vide?).         */
    int         (*Length)   (const struct Queue *);             /**< Methode: Accesseur - Taille de la file.               */

    bool        (*Enqueue)  (const struct Queue *, TElement);   /**< Methode: Ajoute un élément en queue de la file.       */
    bool        (*Dequeue)  (const struct Queue *, PTElement);  /**< Methode: Retire l'élément en début de file.           */
    void        (*Clear)    (const struct Queue *);             /**< Methode: Vide la file.                                */
    void        (*Display)  (const struct Queue *);             /**< Methode: Affiche tous les éléments de la file.        */
    void        (*Delete)   (const struct Queue *);             /**< Methode: Destructeur.                                 */
};

typedef struct Queue TQueue;

/** @typedef PTQueue
*   @brief Type pointeur vers la structure Queue.
*/
typedef TQueue *PTQueue;

/** @fn TQueue_New
*   @brief Création d'une nouvelle file vide.
*   @param TabSize Taille à allouer au tableau.
*   @return Un pointeur vers le type file (PTQueue).
*/
PTQueue TQueue_New(int TabSize);

/** @fn TQueue_IsEmpty
*   @brief Retourne true si la file est vide.
*   @param this Pointeur vers le type file (PTQueue).
*   @return Un booleen.
*/
static inline bool TQueue_IsEmpty(const PTQueue this);

/** @fn TQueue_Length
*   @brief Retourne la taille de la file.
*   @param this Pointeur vers le type file (PTQueue).
*   @return la taille de la file.
*/
static inline int TQueue_Length(const PTQueue this);

/** @fn TQueue_Enqueue
*   @brief Ajoute un nouvel élément en queue de la file.
*   @param this Pointeur vers le type file (PTQueue).
*   @param pushElt L'élément à ajouter.
*   @return Un booleen.
*/
static inline bool TQueue_Enqueue(const PTQueue this, TElement pushElt);

/** @fn TQueue_Dequeue
*   @brief Retire l'élément en début de file.
*   @param this Pointeur vers le type file (PTQueue).
*   @param popElt Pointeur vers l'élément retiré.
*   @return Un booleen.
*/
static inline bool TQueue_Dequeue(const PTQueue this, PTElement popElt);

/** @fn TList_Clear
*   @brief Vide la file.
*   @param this Pointeur vers le type file (PTQueue).
*/
static inline void TQueue_Clear(const PTQueue this);

/** @fn TList_Display
*   @brief Affiche tous les éléments de la file.
*   @param this Pointeur vers le type file (PTQueue).
*/
static inline void TQueue_Display(const PTQueue this);

/** @fn TList_Delete
*   @brief Supprime la file en libérant les zones mémoires allouées.
*   @param this Pointeur vers le type file (PTQueue).
*/
static inline void TQueue_Delete(const PTQueue this);

#endif /* end of include guard : _QUEUE_ */
