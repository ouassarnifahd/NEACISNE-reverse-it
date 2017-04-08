/*********************************
 @file :  mainDft.c
 @brief : Implémentation d'une TFD et affichage "temps réel" sur afficheur graphique GLCD
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - TCY = 83,2ns ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP=OFF


/*** Includes files ***/
#include <p18f4550.h>
#include <delays.h>
#include <GLCD.h>		/*** Librairie "GLCD.lib" développée par un 2Ainfo en 2009-2010 ***/
#include "dft.h"

/*** Définition des Macros ***/	
#define		DelayUser_1ms()		Delay1KTCYx(12) 		// 12.1000.TCY 	~ 1ms 
#define		TMROLVALUE		0x00		/*** à compléter ! ***/  
#define		TMROHVALUE		0x00		/*** à compléter ! ***/  

/*** Définition des variables globales ***/
unsigned	char DFT_Start = 0;
  signed	char InputBuffer[BUFFER_SIZE];

#pragma code
/******************************************************/
/*** ISR : routine d'interruption de priorité haute	***/
/******************************************************/
#pragma interrupt High_ISR
void High_ISR(void)
{static unsigned char   DataIndex = 0;

    if(INTCONbits.TMR0IF)
    {
		/*** Clear Timer0 overflow flag ***/

			/*** à compléter ! ***/   
       
		/*** pré-chargement de TMR0L + chargement automatique de TMR0H ***/

			/*** à compléter ! ***/ 

		/*** Lancer une conversion ***/

			/*** à compléter ! ***/ 

		/*** Attendre la fin de conversion ***/

			/*** à compléter ! ***/ 

		/*** Acquisition de BUFFER_SIZE éléments ***/  

			/*** à compléter ! ***/ 								  	
    }								
}
/*** Configuration du vecteur d'interruption de priorité haute ***/
#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
   _asm goto High_ISR _endasm
}



#pragma code 
/******************************************************/
/*** FONCTION :  initialisation des ports A et D	***/ 
/******************************************************/
void PORT_Init(void)
{
	/*** Broche RA0 en entrée et RA1-RA7 en sorties ***/

			/*** à compléter ! ***/

	/*** Broches RD0-RD7 en sorties pour la validation d'une conversion A/D ***/

			/*** à compléter ! ***/ 
}        

/******************************************************************/
/*** FONCTION :  initialisation du timer0 et de l'IT associée	***/ 
/******************************************************************/
void TIMER0_Init(void)
{
	/*** T0CON : Timer0=OFF, mode=16bits, synchro=Tcy, prescaler=ON, prescale value=1:2 ***/

			/*** à compléter ! ***/ 

	/*** TMR0 : Initialisation des registres de pré-chargement ***/

			/*** à compléter ! ***/ 

	/*** Gestion des IT : priority mode, vecteur d'IT de priorité haute, démasquage IT TMR0, TMR0IF=0 ***/

			/*** à compléter ! ***/ 

	/*** Validation du Timer0 ***/

			/*** à compléter ! ***/ 	
}        

/**********************************************/
/*** FONCTION :  initialisation de l'ADC	***/ 
/**********************************************/
void ADC_Init(void)
{
	/*** ADCON0 : Channel=0, converter module disable ***/

			/*** à compléter ! ***/ 

	/*** ADCON1 : Vref+ = VDD, Vref- = Vss, AN0 only is Analog Input ***/


			/*** à compléter ! ***/ 

	/*** ADCON2 : Tadmin=700ns < Tad=32*Tosc (ou 64*Tosc), Left Adjust, TacqSelect=12*Tad > TacqCalcul (6,4us)  ***/

			/*** à compléter ! ***/ 

	/*** Validation du module ADC  ***/

			/*** à compléter ! ***/ 
}        


/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {
unsigned char	Spectrum[TFD_SIZE];

	/*** Appel fonction de configuration des ports A et D ***/

			/*** à compléter ! ***/ 

	/*** Appel fonction de configuration du Timer0 et de l'IT associée ***/

			/*** à compléter ! ***/ 

	/*** Appel fonction de configuration de l'ADC ***/

			/*** à compléter ! ***/ 

	/*** Initialisation de l'afficheur graphique GLCD ***/

			/*** à compléter ! ***/ 

	/*** Démasquage global des IT ***/

			/*** à compléter ! ***/ 

  	while(1){
		/*** Test l'acquisition de 32 échantillons temporels d'entrée***/
      	if(0) {                                      
         	/*** Masquage global des IT et RAZ du flag buffer d'entrée plein ***/

				/*** à compléter ! ***/ 

			/*** Algorithme de calcul de la TFD (DFT) ***/

				/*** à compléter ! ***/ 

			/*** Affichage du spectre sur l'afficheur graphique GLCD-64x128 ***/

				/*** à compléter ! ***/ 

         	/*** Démasquage global des IT ***/

				/*** à compléter ! ***/ 
     	}
  	};
}

