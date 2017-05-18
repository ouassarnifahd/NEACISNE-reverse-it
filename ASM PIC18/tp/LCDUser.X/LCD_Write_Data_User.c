#include "LCDUser.h"
void LCD_Write_Data_User(char character){

		    /*** envoie des 4bits LSB de character vers le LCD ***/
		    /****************************************************/
		    D4_PIN_LCD_USER = (0x01 & character);	//envoie du bit de poids faible de character à la broche n°4 du MCU
                    D5_PIN_LCD_USER = (0x02 & character)>>1;
                    D6_PIN_LCD_USER = (0x04 & character)>>2;
                    D7_PIN_LCD_USER = (0x08 & character)>>3;

}