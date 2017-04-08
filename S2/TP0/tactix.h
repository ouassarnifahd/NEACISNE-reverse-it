#ifndef _TACTIX_
#define _TACTIX_

/**	@file tactix.h
*	@brief header file for tactix.c
*/

/**	@def N
*	@brief Dimension du plateau de jeu
*/
#define N 4

/**	@def VIDE
*	@brief Valeur representant une case vide
*/
#define VIDE -1

/**	@struct Jeu
*	@brief Structure pour le modele du plateau
*
*	Un tableau a deux dimension de taille N*N
*/
typedef struct jeu{
	int plateau[N][N];
} Jeu;

/**	@struct Coup
*	@brief Structure correspondant a un coup d'un joueur
*/
typedef struct coup{
	int debut;
	int fin;
} Coup;
/**	@struct Position
*	@brief Structure representant la position d'une case sur le plateau
*/
typedef struct position{
	int x;
	int y;
} Position;
/**	@typedef Joueur
*	@brief type synonyme permettant une amelioration de la lecture du code
*/
typedef int Joueur;

/**	@fn creerJeu
*	@brief Creation d'un jeu avec une initialisation du plateau
*/
Jeu creerJeu(void);

void afficherCase(int i, int j);

/**	@fn  afficher
*	@brief Afficher sur la console le jeu en l'etat actuel de la partie
*/
void afficherJeu(Jeu j);

/**	@fn coupPossible
*	@brief Renvoie un booleen indiquant si la partie peut continuer ou non
*/
bool coupPossible(Jeu j);

/**	@fn jouer
*	@brief Jouer un coup pour un joueur donne
*/
Jeu jouer(Jeu j, Joueur p);

/**	@fn tacTix
*	@brief Lance une partie complete
*
*	Renvoie vrai si les joueurs souhaitent continuer
*/
bool tacTix(void);

/** @fn memeLigne
*	@brief Supprime les pions choisis sur une meme ligne.
*
*	Renvoie vrai si OK, faux si coup non permis avec les pions choisis
*/
bool memeLigne(Jeu *pj, Coup cp);

/** @fn memeColonne
*	@brief Supprime les pions choisis sur une meme colonne.
*
*	Renvoie vrai si OK, faux si coup non permis avec les pions choisis
*/
bool memeColonne(Jeu *pj, Coup cp);

/** @fn determinerPositionCase
*	@brief Determine la position d'une case en fonction de son numero associe
*/
Position determinerPositionCase(int val);

/** @fn infosPosition
*	@brief Determiner les deux positions d'un coup.
*
*	Renvoie vrai si succes, faux si une des positions n'est pas valide
*/
bool infosPosition(Coup cp, Position *pdebut, Position *pfin);

/** @fn minimumEtMaximum
*	@brief Determine la valeur minimum et la valeur maximum a partir de deux valeurs.
*/
void minimumEtMaximum(int val1, int val2, int* minimum, int* maximum);

#endif /* end of include guard */
