#include "LCDUser.h"
void LCD_String_User(char *StringData){

                    char index=0;
                    while(StringData[index]!='\0'){
                        LCD_Char_User(StringData[index]);
                        index++;
                    }
		}