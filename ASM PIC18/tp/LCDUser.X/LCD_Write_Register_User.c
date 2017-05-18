#include "LCDUser.h"
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