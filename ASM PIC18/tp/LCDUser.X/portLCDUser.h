/*********************************
 @file :  	portLCDUser.h
 @brief : 	include file à modifier en cas de portage
 @author :
 last modification :
*********************************/
#ifndef   __PORTAGE_LCD_USER_HEADER__
#define   __PORTAGE_LCD_USER_HEADER__

	#include <p18cxxx.h>
	#include <delays.h>			// fichier d'en-tête pour la gestion des Temporisation (proposé par C18)


	/**** Gestion des broches - LCD 4bits 2x16 ***/

	#define	E_PIN_LCD_USER		LATBbits.LATB5
	#define RS_PIN_LCD_USER		LATBbits.LATB4
	#define D7_PIN_LCD_USER		LATBbits.LATB3
	#define D6_PIN_LCD_USER		LATBbits.LATB2
	#define D5_PIN_LCD_USER		LATBbits.LATB1
	#define D4_PIN_LCD_USER		LATBbits.LATB0

	/**** Gestion des temporisations logicielles 			***/
	/*** avec: PLLDIV=2, FOSC=HSPLL_HS et CPUDIV=OSC1_PLL2 	***/
	/*** on a: TCY = 83,2ns 								***/
	#define	DelayUser_2ms()		Delay1KTCYx(24) 		// 24.1000.TCY 	~ 2ms  (mesuré = 2ms)
	#define	DelayUser_5ms()		Delay1KTCYx(61)			// 61.1000.TCY 	~ 5ms  (mesuré = 5ms)
	#define	DelayUser_15ms()	Delay1KTCYx(181)		// 181.1000.TCY ~ 15ms  (mesuré = 15ms)
	#define	DelayUser_400us()	Delay100TCYx(48)		// 48.100.TCY 	~ 400us
	#define	DelayUser_4us()		Delay10TCYx(5)			// 5.10.TCY 	~ 4us

#endif
