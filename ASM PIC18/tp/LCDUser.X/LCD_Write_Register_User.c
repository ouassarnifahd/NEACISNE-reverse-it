#include "LCDUser.h"
void LCD_Write_Register_User(char DR_or_IR){

		    /*** S�lection du registre � �crire : instruction ou data ***/

                    if (DR_or_IR==0)
                    {
                        RS_PIN_LCD_USER=0;
                    }
                    else if (DR_or_IR==1)
                    {
                        RS_PIN_LCD_USER=1;
                    }

		    /*** �criture dans le registre s�lectionn� ***/

                    E_PIN_LCD_USER=1;
                    DelayUser_4us();
                    E_PIN_LCD_USER=0;
                    RS_PIN_LCD_USER=0;
		    /*** delay de 2ms : sp�cifications �lectriques ***/
                    DelayUser_2ms();
		}