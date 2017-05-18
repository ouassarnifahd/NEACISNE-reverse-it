#include "LCDUser.h"
void LCD_String_XY_User(unsigned char row, unsigned char col, char *StringData){


		    /*** Positionnement du curseur ***/

		    	LCD_Cursor_XY_User(row,col);

		    /*** Envoie d'une chaîne de caractères à la position courante du curseur ***/

		    	LCD_String_User(StringData);

		}