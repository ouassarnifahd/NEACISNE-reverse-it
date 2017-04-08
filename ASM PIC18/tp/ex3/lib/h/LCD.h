/*********************************
 @file :  LCD.h
 @brief : include file pour travailler avec la librairie LCD.lib
 @author : 
 last modification : 
*********************************/
#ifndef   __LCD_HEADER__
#define   __LCD_HEADER__

	#include <portLCD.h>
	

    /**** Caractéristiques LCD ***/
      #define   ROW_NB            2           // nombre de lignes
      #define   COLUMN_NB         16          // nombre de colonnes
		
    /**** Commandes standard pour l'affichage ***/
      #define	LCD_COMMAND_CLEAR	          	0x01		// Clear screen, home cursor, unshift display
      #define	LCD_COMMAND_HOME	          	0x02		// Home cursor, unshift display
      #define	LCD_COMMAND_BACKSPACE	      	0x10		// Move cursor left one (destructive based on LCD_DESTRUCTIVE_BS)
      #define	LCD_COMMAND_FWDSPACE	      	0x14		// Move cursor right one
      #define	LCD_COMMAND_PANLEFT	        	0x18		// Move screen left one
      #define	LCD_COMMAND_PANRIGHT	      	0x1C		// Move screen right one
      #define	LCD_COMMAND_CURSOROFF	      	0x0C        // clear cursor
      #define	LCD_COMMAND_SECONDROW	      	0xC0        // go to second row

    /**** Sélection registre Data ou Instruction (contrôleur LCD) ***/
      #define   REG_IR    0          // écriture dans le registre d'instruction
      #define   REG_DR    1          // écriture dans le registre de donnée



    /*** Déclaration fonctions externes pour LCDMainTest.c ***/
      extern void LCD_Char(char character);
      extern void LCD_String(char StringData[16]);
      extern void LCD_Command(char command);
      extern void LCD_Char_XY(unsigned short row, unsigned short col, char character);
      extern void LCD_String_XY(unsigned short row, unsigned short col, char StringData[16]);
      extern void LCD_Init(void);

#endif