#include "LCDUser.h"
void LCD_Char_XY_User(unsigned char row, unsigned char col, char character){

		    /*** Positionnement du curseur ***/

		    	LCD_Cursor_XY_User(row,col);

		    /*** envoie d'un caractère à la position courante du curseur ***/

		    	LCD_Char_User(character);

		}
