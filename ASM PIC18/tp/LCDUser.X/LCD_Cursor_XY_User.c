#include "LCDUser.h"
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