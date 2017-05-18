#include "LCDUser.h"
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