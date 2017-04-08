/*********************************
 @file :  LCDUser.c
 @brief : Librairie pour piloter un afficheur LCD 2x16
 @author :
 last modification :
*********************************/
#include "LCDUser.h"


/*** Déclaration variables globales et fonctions (locales à LCDUser.c)***/
void LCD_Write_Register_User(char DR_or_IR);
void LCD_Write_Data_User(char character);
void LCD_Cursor_XY_User(unsigned char row, unsigned char col);


/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*xxxxxxxxxxxx FONCTIONS PRIVEES xxxxxxxxxxx*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

		/**********************************************************/
		/*** FONCTION : Envoie d'une DATA 4bits au LCD			***/
		/*** @param	character : donnée 8bits >> envoie des 4LSB	***/
		/**********************************************************/
		void LCD_Write_Data_User(char character){

		    /*** envoie des 4bits LSB de character vers le LCD ***/
		    /****************************************************/

		    D4_PIN_LCD_USER = (0x01 & character);	  // 0000_0001 AND ABCD_EFGH => 0000_000H
			D5_PIN_LCD_USER = (0x02 & character)>>1;  // 0000_0010 AND ABCD_EFGH => 0000_00G0 &> 0000_000G
			D6_PIN_LCD_USER = (0x04 & character)>>2;  // 0000_0100 AND ABCD_EFGH => 0000_0F00 &> 0000_000F
			D7_PIN_LCD_USER = (0x08 & character)>>3;  // 0000_1000 AND ABCD_EFGH => 0000_E000 &> 0000_000E

		}

		/**************************************************/
		/*** FONCTION : Envoie d'une COMMANDE au LCD	***/
		/*** @param	DR_or_IR : registre de destination	***/
		/**************************************************/
		void LCD_Write_Register_User(char DR_or_IR){

		    /*** Sélection du registre à écrire : instruction ou data ***/

		    	if(DR_or_IR){
		    		RS_PIN_LCD_USER = REG_DR_USER; //RS=1
		    	}
				else {
					RS_PIN_LCD_USER = REG_IR_USER; //RS=0
				}

		    /*** écriture dans le registre sélectionné ***/

		    	E_PIN_LCD_USER = 1;
				DelayUser_4us();
				E_PIN_LCD_USER = 0;

				RS_PIN_LCD_USER = REG_IR_USER; //RS=0 evite l'incompatibilité

		    /*** delay de 2ms : spécifications électriques ***/

			DelayUser_2ms();
		}

		/*******************************************************/
		/*** FONCTION : Positionnement curseur				 ***/
		/*** @param	row : n° de la ligne (position curseur)	 ***/
		/*** @param	col : n° de la colonne (position curseur)***/
		/*******************************************************/
		void LCD_Cursor_XY_User(unsigned char row, unsigned char col){
			char i;
			if(row==2){
				LCD_Command_User(LCD_USER_COMMAND_SECONDROW);
				for (i = 0; i < row; i++) {
					LCD_Command_User(LCD_USER_COMMAND_FWDSPACE);
				}
			}
			else {
				for (i = 0; i < row; i++) {
					LCD_Command_User(LCD_USER_COMMAND_FWDSPACE);
				}
			}
		}

/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*xxxxxxxxxxxx FONCTIONS PUBLIQUES xxxxxxxxxxx*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

		/**********************************************/
		/*** FONCTION : Envoie caractère au LCD		***/
		/*** @param	character : caractère à envoyer	***/
		/**********************************************/
		void LCD_Char_User(char character){

		char  characterL, characterH;

		    /*** Sauvegarde des 4bits LSB et 4 bits MSB du caractère ***/

		    	characterH = (0xF0 & character) >> 4;
				characterL =  0x0F & character ;

		    /*** envoie des 4bits MSB du caractere sur le portB (RB4-RB7) ***/

				LCD_Write_Data_User(characterH);
				LCD_Write_Register_User(1);

		    /*** envoie des 4bits LSB du caractere sur le portB (RB4-RB7) ***/

				LCD_Write_Data_User(characterL);
				LCD_Write_Register_User(1);
		}

		/******************************************************************/
		/*** FONCTION : Envoie chaîne de caractères au LCD				***/
		/*** @param	StringData : pointeur sur la chaîne de caractères	***/
		/******************************************************************/
		void LCD_String_User(char *StringData){
				char index;
		    	for(index=0;StringData[index]!='\0';index++){
		    		LCD_Char_User(StringData[index]);
		    	}
		}

		/******************************************************/
		/*** FONCTION : Envoie d'une commande au LCD		***/
		/*** @param	commande : commande sur 8bits à envoyer	***/
		/******************************************************/
		void LCD_Command_User(char commande){
		char  commandeL, commandeH;

		    /*** Sauvegarde des 4bits LSB et 4 bits MSB de la commande***/

				commandeH = (0xF0 & commande) >> 4;
				commandeL =  0x0F & commande ;

		    /*** envoie des 4bits MSB de la commande sur le portB (RB4-RB7) ***/

		    	LCD_Write_Data_User(commandeH);
				LCD_Write_Register_User(0);

		    /*** envoie des 4bits LSB de la commande sur le portB (RB4-RB7) ***/

				LCD_Write_Data_User(commandeL);
				LCD_Write_Register_User(0);
		}

		/******************************************************************/
		/*** FONCTION : Envoie caractère au LCD + positionnement curseur***/
		/*** @param	row : n° de la ligne (position curseur)				***/
		/*** @param	col : n° de la colonne (position curseur)			***/
		/*** @param	character : donnée à envoyer						***/
		/******************************************************************/
		void LCD_Char_XY_User(unsigned char row, unsigned char col, char character){

		    /*** Positionnement du curseur ***/

		    	LCD_Cursor_XY_User(row,col);

		    /*** envoie d'un caractère à la position courante du curseur ***/

		    	LCD_Char_User(character);

		}

		/******************************************************************************/
		/*** FONCTION : Envoie chaîne de caractères au LCD + positionnement curseur	***/
		/*** @param	row : n° de la ligne (position curseur)							***/
		/*** @param	col : n° de la colonne (position curseur)						***/
		/*** @param	StringData : pointeur sur la chaîne de caractères				***/
		/******************************************************************************/
		void LCD_String_XY_User(unsigned char row, unsigned char col, char *StringData){


		    /*** Positionnement du curseur ***/

				LCD_Cursor_XY_User(row,col);

			/*** Envoie d'une chaîne de caractères à la position courante du curseur ***/

		    	LCD_String_User(StringData);

		}

		/***************************************/
		/*** FONCTION : Initialisation LCD	 ***/
		/***************************************/
		void LCD_Init_User(void){
		#define	LCD_USER_COMMAND_FCTSET8	        0b0011			 // Function set  8bits (initialisation)
		#define	LCD_USER_COMMAND_FCTSET4	        0b0010			 // Function set  8bits (initialisation)

		/*** PHASE D'INITIALISATION ***/

		    	/*** à compléter ! ***/

		/*** PHASE DE CONFIGURATION ***/

		    	/*** à compléter ! ***/

		}
