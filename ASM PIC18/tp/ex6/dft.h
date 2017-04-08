/*********************************
 @file :  dft.h
 @brief : include file pour travailler avec la librairie dft.c
 @author : 
 last modification : 
*********************************/
#ifndef   __DFT_HEADER__
#define   __DFT_HEADER__

	/*** Fichiers d'en-tête ***/
	#include <math.h>			// pour l'API "sqrt" utilisée dans TNS.c

	/*** Déclaration des Tailles des différents vecteurs ***/
	#define	 TFD_SIZE		32    	
	#define  BUFFER_SIZE    32
		
	/*** Initialisation des tables ***/
	#define  SINUS_TABLE       	0,25,49,71,90,106,118,125,127,125,118,106,90,71,49,25,0,-25,-49,-71,-90,-106,-118,-125,-127,-125,-118,-106,-90,-71,-49,-25
	#define  COSINUS_TABLE     	127,125,118,106,90,71,49,25,0,-25,-49,-71,-90,-106,-118,-125,-127,-125,-118,-106,-90,-71,-49,-25,0,25,49,71,90,106,118,125

	/*** Paramétrage de la fonction "TNS_dft" ***/
	#define  X_FLOAT_FACTOR   1024.0    

/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*xxx   Déclarations FONCTIONS PUBLIQUES   xxx*/
/*xxxxxxxxxxx    Externes à TNS.c   xxxxxxxxxx*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

	/******************************************************************************************************/
	/*** FONCTION : Calcul d'une TFD avec des flottants (DFT)																***/      
	/*** @param ptInputBuffer	pointeur sur le vecteur d'échantillons temporels d'entrée. 				***/
	/*** @param ptOutputSpectrum	pointeur sur le vecteur d'échantillons frenquentiels de sortie.		***/
	/******************************************************************************************************/
	void TNS_dft_float(signed char* ptInputBuffer,unsigned char* ptTFDSpectrum);
	
	
#endif