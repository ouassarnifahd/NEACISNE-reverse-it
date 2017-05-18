#include "LCDUser.h"
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
