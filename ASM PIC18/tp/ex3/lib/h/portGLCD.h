/**
 * @file portGLCD.h
 * Fichier contenant des macros specifiques a notre MCU (PIC18F4550).
 */
#ifndef   __PORT_GLCD_HEADER__
#define   __PORT_GLCD_HEADER__

		#include <p18f4550.h>
		#include <delays.h>	
		
		/**
		 * @name Gestion du PORTD du MCU (broches de data des controleurs GLCD).
		 * @{
		 */
		#define DATA_TRIS_GLCD      	TRISD 	// Permet de configurer la direction du port D
		#define DATA_PINS_IN_GLCD		PORTD 	// Lecture du Port D
		#define DATA_PINS_OUT_GLCD      LATD  	// Ecriture sur le Port D
		/** @} */
			
		/** 
		 * @name Gestion du PORTB du MCU (broches de controle des controleurs GLCD).
		 * @{
		 */
		#define RST_PIN_GLCD	LATBbits.LATB5 	// Gestion du Reset des controleurs
		#define	E_PIN_GLCD		LATBbits.LATB4 	// Broche de validation des controleurs (en ecriture ou en lecture)
		#define RW_PIN_GLCD		LATBbits.LATB3 	// Lecture ou ecriture
		#define DI_PIN_GLCD		LATBbits.LATB2 	// Selection du registre cible : instruction ou data
		#define CS2_PIN_GLCD	LATBbits.LATB1 	// Selection du chip controlant la partie gauche du GLCD
		#define CS1_PIN_GLCD	LATBbits.LATB0 	// Selection du chip controlant la partie droite du GLCD
		/** @} */
		

		/*****************************************
		***** IMPORTANT : Configuration bits *****
		******************************************
		PLLDIV=2,  FOSC=HSPLL_HS >> 8MHz vers 96MHz
		CPUDIV=OSC1_PLL2    >> 96MHz vers 48MHz

		On a : 1/48MHz = 20,8ns = Q

		Instruction Cycle = TCY = 4xQ = 4x(1/OSC1) >> OSC1 = 48MHz (cf. ci-dessus)
		******************************************
		******************************************/

		/**
		 * @name Delay soft 1s (TCY est fixe par les bits de configurations)
		 * @{
		 */
		#define	Delay_1s()							\
								Delay10KTCYx(240);	\
								Delay10KTCYx(240);	\
								Delay10KTCYx(240);	\
								Delay10KTCYx(240);	\
								Delay10KTCYx(240)		// Avec : 5.240.10000.TCY ~ 1s (defini dans delays.h fourni avec MCC18)
		/** @} */ 


		/**
		 * @name Delay soft 4us (TCY est fixe par les bits de configurations)
		 * @{
		 */
		#define Delay_4us(); 	Delay10TCYx(5); 		// Avec : 5.10.TCY ~ 4us (defini dans delays.h fourni avec MCC18)
		 /** @} */ 

#endif