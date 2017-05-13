/*********************************
 @file :  dft.c
 @brief : Librairie pour le TNS : Algorithme DFT(TFD) ...
 @author :
 last modification :
*********************************/
#include "dft.h"

/*** D�claration des variables globales utilis�e par la fonction "TNS_dft" 	***/
/*** ATTENTION : Elles ne peuvent pas �tre utilis�es en variables locales : ***/
/*** Probl�me de taille de la pile logicielle !								***/

const char     Sinus[TFD_SIZE] = {SINUS_TABLE};
const char     Cosinus[TFD_SIZE] = {COSINUS_TABLE};

float    X_float[TFD_SIZE/2];
float  	 Xim_float[TFD_SIZE/2];
float    Xreal_float[TFD_SIZE/2];


/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*xxxxxxxxxxxx FONCTIONS PUBLIQUES xxxxxxxxxxx*/
/*xxxxxxxxxxx    Externes � TNS.c   xxxxxxxxxx*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/


/******************************************************************************************************/
/*** FONCTION : Calcul d'une TFD avec des flottants (DFT)											***/
/*** @param ptInputBuffer	pointeur sur le vecteur d'�chantillons temporels d'entr�e. 				***/
/*** @param ptOutputSpectrum	pointeur sur le vecteur d'�chantillons frenquentiels de sortie.		***/
/******************************************************************************************************/
void TNS_dft_float(signed char* ptInputBuffer,unsigned char* ptOutputSpectrum){
char     n, k, kn, X_uchar;


	/*** Initialisations avant calcul de la TFD ***/

				/*** � compl�ter ! ***/

	/*** Calcul de la moiti� de la TFD [0,Fs/2]. Si n�cessaire, obtention de la deuxi�me moiti� par sym�trie 	***/
	/*** "n" : compteur sur les �chantillons fr�quentiels														***/

				/*** � compl�ter ! ***/

	/*** Obtention spectre complet [Fs/2,Fs] ***/

				/*** � compl�ter ! ***/
}
