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
		    D4_PIN_LCD_USER = (0x01 & character);	//envoie du bit de poids faible de character à la broche n°4 du MCU 
                    D5_PIN_LCD_USER = (0x02 & character)>>1;
                    D6_PIN_LCD_USER = (0x04 & character)>>2;
                    D7_PIN_LCD_USER = (0x08 & character)>>3;
                    
		}

		/**************************************************/
		/*** FONCTION : Envoie d'une COMMANDE au LCD		***/ 
		/*** @param	DR_or_IR : registre de destination	***/
		/**************************************************/
		void LCD_Write_Register_User(char DR_or_IR){
		
		    /*** Sélection du registre à écrire : instruction ou data ***/
		
                    if (DR_or_IR==0)
                    {
                        RS_PIN_LCD_USER=0;
                    }
                    else if (DR_or_IR==1)
                    {
                        RS_PIN_LCD_USER=1;
                    }
		
		    /*** écriture dans le registre sélectionné ***/
		
                    E_PIN_LCD_USER=1;
                    DelayUser_4us();
                    E_PIN_LCD_USER=0;
                    RS_PIN_LCD_USER=0;
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
                         for(i=0;i<col;i++){
                            LCD_Command_User(LCD_USER_COMMAND_FWDSPACE);
                        }
                    }
                    else {
                        for(i=0;i<col;i++){
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
		
		    	characterH = (0xF0 & character) >>4;
                        characterL = 0x0F & character;
		
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
		
                    char index=0;
                    while(StringData[index]!='\0'){
                        LCD_Char_User(StringData[index]);
                        index++;
                    }
		}

		/******************************************************/
		/*** FONCTION : Envoie d'une commande au LCD			***/ 
		/*** @param	commande : commande sur 8bits à envoyer	***/
		/******************************************************/
		void LCD_Command_User(char commande){
		char  commandeL, commandeH;
		
		    /*** Sauvegarde des 4bits LSB et 4 bits MSB de la commande***/
		
		    	commandeL = 0x0F & commande;
                        commandeH = (0xF0 & commande)>>4;
	
		    /*** envoie des 4bits MSB de la commande sur le portB (RB4-RB7) ***/

                        LCD_Write_Data_User(commandeH);
			LCD_Write_Register_User(0);
		
		    /*** envoie des 4bits LSB de la commande sur le portB (RB4-RB7) ***/
		
		    	LCD_Write_Data_User(commandeL);
                        LCD_Write_Register_User(0);
                        
		}

		/******************************************************************/
		/*** FONCTION : Envoie caractère au LCD + positionnement curseur	***/ 
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
		
                    DelayUser_15ms();
                    LCD_Command_User(LCD_USER_COMMAND_FCTSET8);
                    DelayUser_5ms();
                    LCD_Command_User(LCD_USER_COMMAND_FCTSET8);
                    DelayUser_400us();
                    LCD_Command_User(LCD_USER_COMMAND_FCTSET8);
                    LCD_Command_User(LCD_USER_COMMAND_FCTSET4);
                    
		/*** PHASE DE CONFIGURATION ***/
		
                    LCD_Command_User(LCD_USER_COMMAND_CLEAR);
                    LCD_Command_User(0x28);
                    LCD_Command_User(0x0F);
                    LCD_Command_User(0x06);

		
		}
