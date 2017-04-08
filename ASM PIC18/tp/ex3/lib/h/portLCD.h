/*********************************
 @file :  portLCDUser.c
 @brief : include file à modifier en cas de portage
 @author : 
 last modification : 
*********************************/
#ifndef   __PORTAGE_LCD_HEADER__
#define   __PORTAGE_LCD_HEADER__

	#include <delays.h>			// fichier d'entête pour la gestion des Temporisation 


	/**** Gestion des broches - LCD 4bits 2x16 ***/
	#define	E_PIN_LCD		LATBbits.LATB5	
	#define RS_PIN_LCD		LATBbits.LATB4
	#define D7_PIN_LCD		LATBbits.LATB3
	#define D6_PIN_LCD		LATBbits.LATB2
	#define D5_PIN_LCD		LATBbits.LATB1
	#define D4_PIN_LCD		LATBbits.LATB0

	/**** Gestion des temporisations logicielles 			***/
	/*** avec: PLLDIV=2, FOSC=HSPLL_HS et CPUDIV=OSC1_PLL2 	***/	
	/*** on a: TCY = 83,2ns 								***/
	#define	Delay_2ms()		Delay1KTCYx(24) 		// 24.1000.TCY 	~ 2ms  (mesuré = 2ms)	
	#define	Delay_5ms()		Delay1KTCYx(61)			// 61.1000.TCY 	~ 5ms  (mesuré = 5ms)
	#define	Delay_15ms()	Delay1KTCYx(181)		// 181.1000.TCY ~ 15ms  (mesuré = 15ms)
	#define	Delay_400us()	Delay100TCYx(48)		// 48.100.TCY 	~ 400us 
	#define	Delay_4us()		Delay10TCYx(5)			// 5.10.TCY 	~ 4us

#endif