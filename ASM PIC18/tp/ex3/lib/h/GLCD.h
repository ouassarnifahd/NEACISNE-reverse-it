/**
 * @file GLCD.h
 * Ce fichier contient les prototypes des fonctions de la bibliothèque
 * permettant le pilotage du GLCD ainsi que divers macros.
 */

#ifndef   __GLCD_HEADER__
#define   __GLCD_HEADER__

	#include "portGLCD.h"		
	
	/*** IMPORTANT : sélections des APIs utilisés ***/
	/************************************************/
	
	
		/**
		 * @name CONFIGURATION : Selection des APIs et FONT utilisees avant compilation (Minimisation de la taille de la librairie une fois compilee).
		 * @{
		 */
		#define   		GLCD_READ_WRITE_ADRESS_PAGE_SIDE_USED		1		// "1" si on souhaite utiliser "GLCD_read_data" ou "GLCD_write_data"  ou
																			// "GLCD_set_page" ou "GLCD_set_address" ou "GLCD_set_side"
		#define   		GLCD_CLEARSCREEN_USED						1		// "1" si on souhaite utiliser "GLCD_ClearScreen"
		#define   		GLCD_DOT_USED								1		// "1" si on souhaite utiliser "GLCD_Dot"
		#define   		GLCD_PICTURE_USED							1		// "1" si on souhaite utiliser "GLCD_Picture"
		#define   		GLCD_BOX_USED								1		// "1" si on souhaite utiliser "GLCD_Box"
		#define   		GLCD_RECTANGLE_USED							1		// "1" si on souhaite utiliser "GLCD_Rectangle"
		#define   		GLCD_CHAR_USED								1		// "1" si on souhaite utiliser "GLCD_Char"
		#define   		GLCD_TEXT_USED								1		// "1" si on souhaite utiliser "GLCD_Text"
		#define   		GLCD_BUTTON_USED							1		// "1" si on souhaite utiliser "GLCD_Button"
		#define   		GLCD_SPECTRUM_USED							1		// "1" si on souhaite utiliser "GLCD_Spectrum"

		#define   		FONT_3X6									1		// "1" si on souhaite utiliser un FONT 3x6	
		#define   		FONT_5X8									1		// "1" si on souhaite utiliser un FONT 5x8
		#define   		FONT_7X8									1		// "1" si on souhaite utiliser un FONT 7x8
		#define   		FONT_8X12									1		// "1" si on souhaite utiliser un FONT 8x12
		#define   		FONT_8X23									1		// "1" si on souhaite utiliser un FONT 8x23
		/** @} */	
	
		
	/*** Macros communes aux APIs de GLCD.c ***/
	/******************************************/
			
		/**
		 * @name Macros generalistes
		 * @{
		 */
		#define TRUE			1;
		#define FALSE			0;	
		/** @} */
		

		/**
		 * @name Commandes standards pour le controleur et gestion de celui-ci.
		 * @{
		 */
		#define ON				0x3F 	// Commande affichage ON
		#define OFF				0x3E 	// Command affichage OFF
		#define SET_ADDRESS		0x40 	// Commande choix de l'adresse
		#define SET_PAGE		0xB8 	// Commande choix de la page
		#define START_LINE      0xC0 	// Commande choix de la ligne de debut d'affichage
		#define REG_IR    		0     	// Selection Registre d'instructions
		#define REG_DR    		1     	// Selection Registre de donnees
		#define CHIP_RIGHT		0     	// Chip controlant l'affichage droit
		#define CHIP_LEFT		1	  	// Chip controlant l'affichage gauche
		#define CHIP_BOTH		2	  	// Les deux chips
		/** @} */
			
			
		/** 
		* @name Caracteristiques GLCD
		* @{
		*/
		#define   ROW_NB           	64          // Nombre de lignes
		#define   COLUMN_NB        	128         // Nombre de colonnes (total)
		#define   COLUMN_NB_SIDE   	64          // Nombre de colonnes (par cote de l'afficheur)
		#define   PAGE_NB		   	8			// Nombre de pages
		#define	  PIX_PAGE_NB	   	8			// Nombre de pixels par colonne par page
		#define 	BLUE			0x00  		// Couleur d'affichage bleue
		#define 	WHITE			0xFF  		// Couleur d'affichage blanche
		/** @} */
	
	
		/**
		* @name Structure representant un font de caracteres.
		* @{
		*/
		struct Font
		{
			unsigned char x; 				// Largeur d'un caractere.
	 		unsigned char y; 				// Hauteur d'un caractere.
	 		rom unsigned char* font; 		// Tableau codant la fonte.
		};
		/** @} */
	
		
	/*** PARAMETRAGE API "GLCD_Spectrum" ***/
	/***************************************/
	
		/**
		* @name Parametrage de la fonction GLCD_Spectrum
		* @{
		*/
		#define   		SPECTRUM_SIZE		16			// Taille du spectre a afficher. SPECTRUM_SIZE = 16 ou 32 ou 64 
	
		#if     SPECTRUM_SIZE == 16
			#define	 	BAR_WIDTH			8			// Largeur de chaque barre du spectre 
			#define	 	SPECTRUM_SIZE_INIT	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		#elif   SPECTRUM_SIZE == 32
			#define	 	BAR_WIDTH			4
		 	#define	 	SPECTRUM_SIZE_INIT	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		#elif   SPECTRUM_SIZE == 64
			#define	 	BAR_WIDTH			2
		    #define	 	SPECTRUM_SIZE_INIT	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		#else		
			#error Missing definition:  Valeur donnee a _SPECTRUM_SIZE non valide !
		#endif
	
		#define	NOISE_THRESHOLD		0     				// Seuil de rejet d'harmoniques parasites avant affichage de "0" a "64" (en nb de pixels !)
		/** @} */
	
	/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
	/*xxxxx Déclaration FONCTIONS PRIVEES xxxxxx*/
	/*xxxxxxxxxxx   Locales à GLCD.c   xxxxxxxxx*/
	/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
	
		/**
	 	* Envoie de la data vers le registre selectionne (data ou instruction). 
	 	*/
		static void write_enable();
	
	
		/**
	 	* Lecture de la donnee affichee par le GLCD ou de l'etat du GLCD.
	 	* @param 	DR_or_IR Selection du registre de \a data ou \a d'instructions du GLCD.
	 	* @return 	Donnee lue.
	 	*/
		static unsigned char read_enable(unsigned char DR_or_IR);
	
	
		/**
	 	* Selection du controleur droit ou gauche du GLCD.
	 	* @param chip 	Controleur droit ou gauche. Valeurs possibles : \a CHIP_RIGHT, \a CHIP_LEFT ou
	 	* 				\a CHIP_BOTH.
	 	*/
		static void select_chip(unsigned char DR_or_IR);
	
	
		/**
	 	* Positionne le curseur d'un des controleurs du GLCD a une adresse specifiee dans la page courante
	 	* (coordonnee horizontale - en x). 
	 	* @param address	Adresse ou positionner le curseur dans la page courante (entre \a 0 et \a 63).
	 	*/
		static void set_address(unsigned char address);
	
	
		/**
	 	* Positionne le curseur d'un des controleurs (droit ou gauche) sur une page specifiee
	 	* (coordonnee verticale - en y).
	 	* @param page	Page ou positionner le curseur (entre \a 0 et \a 7) 
	 	*/
		static void set_page(unsigned char page);
	
	
	/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
	/*xxxxx Déclaration FONCTIONS PUBLIQUES xxxxxx*/
	/*xxxxxxxxxxx   Externes à GLCD.c   xxxxxxxxxx*/
	/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
	
	
		/**
	 	* Initialisation des controleurs du GLCD. L'initialisation effectue un reset des controleurs, 
	 	* efface les donnees affichees precedemment (L'ecran devient blanc ou bleu suivant la valeur passee en parametre) 
	 	* et positionne le curseur en haut a gauche (adresse 0 de la page superieure gauche).
		* @param color	Couleur au demarrage. Valeurs possibles BLUE ou WHITE.
	 	*/
		extern void GLCD_Init(unsigned char color);
	
	
		/**
	 	* Efface la totalite de l'ecran (64x128)
	 	*/
		extern void GLCD_ClearScreen(void);
	
	
		/**
	 	* Selectionne un cote (droit ou gauche) de l'afficheur GLCD.
	 	* @param chip	Cote droit ou gauche du GLCD. Valeurs possibles : CHIP_RIGHT, CHIP_LEFT
	 	* 				ou CHIP_BOTH.
	 	* @return 		Retourne 0 si le parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_set_side(unsigned char chip);
	
	
		/**
	 	* Positionne le curseur a la page choisie.
	 	* @param page 	Page sur laquelle doit etre positionne le curseur (de 1 a 8)
	 	* @param chip 	Partie droite ou gauche de l'ecran (valeurs possibles : CHIP_LEFT, CHIP_RIGHT ou CHIP_BOTH).
	 	* @return		Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_set_page(unsigned char page, unsigned char chip);
	
	
		/**
	 	* Postionne le curseur de l'un des controleurs (droit ou gauche) a l'adresse
	 	* selectionnee (coordonnee dans une page donne)
	 	* @param address 	Adresse a laquelle doit etre positionne le curseur 
	 	*				  	(entre 1 et 64)
	 	* @param chip		Cote (droit ou gauche) du GLCD concerne par le positionnement 
	 	* 					du curseur. Valeurs possibles : CHIP_RIGHT, CHIP_LEFT, CHIP_BOTH
	 	* @return			Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/	
		extern unsigned char GLCD_set_address(unsigned char address, unsigned char chip);
	
	
		/**
	 	* Affiche une donnee a la position courante du curseur sur un des cotes (droit ou gauche) du GLCD
	 	* @param dataWrite  Donnee sur 8 bits a afficher (colonne de 8 pixels a l'adresse courante dans la page courante)
	 	* @param chip		Controleur droit ou gauche, ou les deux, concerne(s) par l'affichage.
	 	* 					Valeurs possibles : CHIP_RIGHT, CHIP_LEFT ou CHIP_BOTH
	 	* @return 			Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/	
		extern unsigned char GLCD_write_data(unsigned char dataWrite, unsigned char chip);
	
	
		/**
	 	* Lecture de la donnee affichee par l'afficheur a la position courante du curseur.
	 	* @param chip 	Controleur (droit ou gauche) du GLCD concerne par la lecture.
	 	*				Valeurs possibles : CHIP_RIGHT, CHIP_LEFT ou CHIP_BOTH.
	 	* @return	    Donnee lue sur 8 bits (colonne de 8 pixels a l'adresse courante dans la page courante).
	 	*/
		extern unsigned char GLCD_read_data(unsigned char chip);
	
	
		/**
	 	* Affiche un point sur l'afficheur a la position specifiee en parametres
	 	* @param x 		Coordonnee horizontale (en x) du point a afficher (entre 1 et 128)
	 	* @param y 		Coordonnee verticale (en y) du point a afficher (entre 1 et 64)
	 	* @param color 	Couleur du point a afficher. Valeurs possibles : WHITE ou BLUE.
		* @return 		Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_Dot(unsigned char x, unsigned char y, unsigned char color);
	
	
		/**
	 	* Affiche une image sur la totalite de l'afficheur GLCD.
	 	* @param image	pointeur sur l'image a afficher. L'image doit avoir une taille 64x128 pixels et etre
	 	* 				representee par un tableau de unsigned char de taille 1024 ( 16 pages de 64 colonnes de 8 pixels).
	 	*/
		extern void GLCD_Picture(rom unsigned char* image);
	
		/**
	 	* Affichage d'un rectangle plein, blanc ou bleu.
	 	* @param x1		Coordonnee horizontale (en x) de l'angle superieur gauche (entre 1 et 128).
	 	* @param y1		Coordonnee verticale (en y) de l'angle superieur gauche (entre 1 et 64).
	 	* @param x2		Coordonnee horizontale (en x) de l'angle inferieur droit (entre 1 et 128).
	 	* @param y2		Coordonnee verticale (en y) de l'angle inferieur droit (entre 1 et 64).
	 	* @param color	Couleur du rectangle : WHITE ou BLUE
	 	* @return		Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_Box(unsigned char x1, unsigned char y1,unsigned char x2, unsigned char y2, unsigned char color);
		
	
		/**
	 	* Affichage d'un rectangle vide, blanc ou bleu.
	 	* @param x1		Coordonnee horizontale (en x) de l'angle superieur gauche (entre 1 et 128).
	 	* @param y1		Coordonnee verticale (en y) de l'angle superieur gauche (entre 1 et 64).
	 	* @param x2		Coordonnee horizontale (en x) de l'angle inferieur droit (entre 1 et 128).
	 	* @param y2		Coordonnee verticale (en y) de l'angle inferieur droit (entre 1 et 64).
	 	* @param color	Couleur du rectangle : WHITE ou BLUE
	 	* @return		Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_Rectangle(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2, unsigned char color);	
	
	
		/**
	 	* Affiche un caractere a la position specifiee en parametres
	 	* @param displayedChar	Caractere a afficher
	 	* @param color			Couleur d'affichage. Valeurs possibles : BLUE ou WHITE.
	 	* @param x				Coordonnee horizontale (en x) (entre 1 et 128)
	 	* @param y				Coordonnee verticale(en y) (entre 1 et 64)
	 	* @param font			Font utilisee. Il s'agit de la taille des caracteres affiches. 
		*						ATTENTION, Tous les caracteres n'existent pas dans chaque font.
	 	* @return				Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_Char(const unsigned char displayedChar, unsigned char color, unsigned char x, unsigned char y, const struct Font* font);
	
	
		/**
	 	* Affiche une chaine de caracteres a la position specifiee en parametres
	 	* @param texte		pointeur sur la chaine de caracteres a afficher
	 	* @param font		Font utilisee. Il s'agit de la taille des caracteres affiches. 
		*					ATTENTION, Tous les caracteres n'existent pas dans chaque font.
	 	* @param x			Coordonnee horizontale (en x) (entre 1 et 128).
	 	* @param y			Coordonnee verticale(en y) (entre 1 et 64).
		* @param color		Couleur d'affichage. Valeurs possibles : BLUE ou WHITE.
	 	* @return			Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_Text(const unsigned char* texte, const struct Font* font, unsigned char x, unsigned char y, unsigned char color);
	
		/**
	 	* Affiche un bouton contenant du texte a la position specifiee en parametres
	 	* @param texte		pointeur sur la chaine de caracteres a afficher
	 	* @param font		Font utilisee. Il s'agit de la taille des caracteres affiches. 
		*					ATTENTION, Tous les caracteres n'existent pas dans chaque font.
	 	* @param x			Coordonnee horizontale (en x) (entre 1 et 128).
	 	* @param y			Coordonnee verticale(en y) (entre 1 et 64).
		* @param ON_or_OFF	Etat du bouton. Valeurs possibles ON ou OFF. Un boutton ON
	 	* 					affiche un rectangle double. Un boutton OFF affiche un rectangle simple.
		* @param color		Couleur d'affichage. Valeurs possibles : BLUE ou WHITE.
	 	* @return			Retourne 0 si un parametre est invalide et 1 sinon.
	 	*/
		extern unsigned char GLCD_Button(const unsigned char* texte, const struct Font* font, unsigned char x, unsigned char y, unsigned char ON_or_OFF, unsigned char color);	
	
	
		/**
	 	* Affichage du spectre d'un signal.
	 	* @param ptSpectrum		pointeur sur un tableau de unsigned char representant les echantillons frequentiels a afficher (affichage plein ecran).
		*						ATTENTION, la taille du tableau depend de la valeur de la macro SPECTRUM_SIZE a specifiee dans GLCD.h  
	 	*/
		extern void GLCD_Spectrum(unsigned char* ptSpectrum);


#endif