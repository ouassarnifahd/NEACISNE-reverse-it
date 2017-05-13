/*********************************
 @file :  dft.c
 @brief : Librairie pour le TNS : Algorithme DFT(TFD) ...
 @author :
 last modification :
*********************************/
#include "dft.h"

/*** Déclaration des variables globales utilisée par la fonction "TNS_dft" 	***/
/*** ATTENTION : Elles ne peuvent pas être utilisées en variables locales : ***/
/*** Problème de taille de la pile logicielle !								***/

const char     Sinus[TFD_SIZE] = {SINUS_TABLE};
const char     Cosinus[TFD_SIZE] = {COSINUS_TABLE};

float    X_float[TFD_SIZE/2];
float  	 Xim_float[TFD_SIZE/2];
float    Xreal_float[TFD_SIZE/2];


/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*xxxxxxxxxxxx FONCTIONS PUBLIQUES xxxxxxxxxxx*/
/*xxxxxxxxxxx    Externes à TNS.c   xxxxxxxxxx*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/


/******************************************************************************************************/
/*** FONCTION : Calcul d'une TFD avec des flottants (DFT)											***/
/*** @param ptInputBuffer	pointeur sur le vecteur d'échantillons temporels d'entrée. 				***/
/*** @param ptOutputSpectrum	pointeur sur le vecteur d'échantillons frenquentiels de sortie.		***/
/******************************************************************************************************/
void TNS_dft_float(signed char* ptInputBuffer,unsigned char* ptOutputSpectrum){
char     n, k, kn, X_uchar;


	/*** Initialisations avant calcul de la TFD ***/

				/*** à compléter ! ***/

	/*** Calcul de la moitié de la TFD [0,Fs/2]. Si nécessaire, obtention de la deuxième moitié par symétrie 	***/
	/*** "n" : compteur sur les échantillons fréquentiels														***/

				/*** à compléter ! ***/

	/*** Obtention spectre complet [Fs/2,Fs] ***/

				/*** à compléter ! ***/
}
