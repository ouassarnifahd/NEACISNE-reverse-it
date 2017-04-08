/*********************************
 @file :  ex3.c
 @brief : programme de test pour d�velopper la librairie LCDUser.c
 @author :
 last modification :
*********************************/

/*** Configuration bits - Special Features ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP = OFF

/*** Includes files ***/
#include <p18f4550.h>
#include <LCD.h>
#include "LCDUser.h"

/*** cha�nes de caract�res pour le Debug ***/
char testString1[] = "    ENSICAEN    ";
char testString2[] = "Si vous ne preparez pas vos TP, vous aurez ...";


/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {

    /*** Configuration des broches RB0 � RB5 en sorties ***/

        TRISB = 0xC0;

    /*** n�6 : Initialisation du LCD ***/

        LCD_Init_User();


        LCD_Char_User('d');
        LCD_String_User(testString1);
        LCD_Command_User(LCD_COMMAND_PANRIGHT);

  /*** n�4  : Envoi d'un caract�re au LCD + positionnement curseur ***/
  /*** n�4' : Ecriture fonction LCD_Cursor_XY_User(unsigned short row, unsigned short col); ***/

      LCD_Char_XY_User(2, 3, 'D');

  /*** n�5 : Envoi d'une cha�ne de caract�re au LCD + positionnement curseur ***/

      LCD_String_XY_User(2, 5,testString2);

  while (1);
}
