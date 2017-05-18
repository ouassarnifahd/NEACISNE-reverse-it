#include "LCDUser.h"
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
