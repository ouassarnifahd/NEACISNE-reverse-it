/*********************************
 @file :  LCDUser.h
 @brief : include file pour travailler avec la librairier LCDUser.c
 @author :
 last modification :
*********************************/
#ifndef   __LCD_USER_HEADER__
#define   __LCD_USER_HEADER__

	#include "portLCDUser.h"


    /**** Caractùristiques LCD ***/
      #define   ROW_NB_USER            2           // nombre de lignes
      #define   COLUMN_NB_USER         16          // nombre de colonnes

    /**** Commandes standard pour l'affichage ***/
      #define	LCD_USER_COMMAND_CLEAR	          	0x01		// Clear screen, home cursor, unshift display
      #define	LCD_USER_COMMAND_HOME	          	0x02		// Home cursor, unshift display
      #define	LCD_USER_COMMAND_BACKSPACE	      	0x10		// Move cursor left one (destructive based on LCD_DESTRUCTIVE_BS)
      #define	LCD_USER_COMMAND_FWDSPACE	      	0x14		// Move cursor right one
      #define	LCD_USER_COMMAND_PANLEFT	        0x18		// Move screen left one
      #define	LCD_USER_COMMAND_PANRIGHT	      	0x1C		// Move screen right one
      #define	LCD_USER_COMMAND_CURSOROFF	      	0x0C        // clear cursor
      #define	LCD_USER_COMMAND_SECONDROW	      	0xC0        // go to second row

    /**** Sùlection registre Data ou Instruction (contrùleur LCD) ***/
      #define   REG_IR_USER    0          // ùcriture dans le registre d'instruction
      #define   REG_DR_USER    1          // ùcriture dans le registre de donnùe


    /*** Dùclaration fonctions externes pour ex3.c ***/
      extern void LCD_Char_User(char character);
      extern void LCD_String_User(char StringData[16]);
      extern void LCD_Command_User(char command);
      extern void LCD_Char_XY_User(unsigned char row, unsigned char col, char character);
      extern void LCD_String_XY_User(unsigned char row, unsigned char col, char StringData[16]);
      extern void LCD_Init_User(void);

#endif
