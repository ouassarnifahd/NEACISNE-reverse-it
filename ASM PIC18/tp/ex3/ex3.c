/*********************************
 @file :  ex3.c
 @brief : programme de test pour développer la librairie LCDUser.c
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - Special Features ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP = OFF

/*** Includes files ***/
#include <p18f4550.h>
#include <LCD.h>
#include "LCDUser.h"

/*** chaînes de caractères pour le Debug ***/
char testString1[] = " C'est beau ca !";
char testString2[] = "Coucou !";


/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {

  /*** Configuration des broches RB0 à RB5 en sorties ***/

    TRISB = 0xC0;

  /*** n°6 : Initialisation du LCD ***/

      LCD_Init();

  /*** n°1 	 : Envoi d'un caractère au LCD ***/
  /*** n°1'  : Ecriture fonction LCD_Write_Register_User(char DR_or_IR); ***/
  /*** n°1'' : Ecriture fonction LCD_write_Data_User(char caracter); ***/

       //LCD_Char_User('d');

  /*** n°2 : Envoi d'une chaîne de caractère au LCD ***/

      //LCD_String_User(testString1);

  /*** n°3 : Envoi d'une commande au LCD ***/

     // LCD_Command(LCD_COMMAND_PANRIGHT);

  /*** n°4  : Envoi d'un caractère au LCD + positionnement curseur ***/
  /*** n°4' : Ecriture fonction LCD_Cursor_XY_User(unsigned short row, unsigned short col); ***/

     //LCD_Char_XY_User(2, 3, 'D');

  /*** n°5 : Envoi d'une chaîne de caractère au LCD + positionnement curseur ***/

      LCD_String_XY_User(2, 5,testString2);

  while (1);
}

