/*********************************
 @file :  mainDft.c
 @brief : Impl�mentation d'une TFD et affichage "temps r�el" sur afficheur graphique GLCD
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - TCY = 83,2ns ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP=OFF


/*** Includes files ***/
#include <p18f4550.h>
#include <delays.h>
#include <GLCD.h>		/*** Librairie "GLCD.lib" d�velopp�e par un 2Ainfo en 2009-2010 ***/
#include "dft.h"

/*** D�finition des Macros ***/	
#define		DelayUser_1ms()		Delay1KTCYx(12) 		// 12.1000.TCY 	~ 1ms 
#define		TMROLVALUE		0x00		/*** � compl�ter ! ***/  
#define		TMROHVALUE		0x00		/*** � compl�ter ! ***/  

/*** D�finition des variables globales ***/
unsigned	char DFT_Start = 0;
  signed	char InputBuffer[BUFFER_SIZE];

#pragma code
/******************************************************/
/*** ISR : routine d'interruption de priorit� haute	***/
/******************************************************/
#pragma interrupt High_ISR
void High_ISR(void)
{static unsigned char   DataIndex = 0;

    if(INTCONbits.TMR0IF)
    {
		/*** Clear Timer0 overflow flag ***/

			/*** � compl�ter ! ***/   
       
		/*** pr�-chargement de TMR0L + chargement automatique de TMR0H ***/

			/*** � compl�ter ! ***/ 

		/*** Lancer une conversion ***/

			/*** � compl�ter ! ***/ 

		/*** Attendre la fin de conversion ***/

			/*** � compl�ter ! ***/ 

		/*** Acquisition de BUFFER_SIZE �l�ments ***/  

			/*** � compl�ter ! ***/ 								  	
    }								
}
/*** Configuration du vecteur d'interruption de priorit� haute ***/
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
	/*** Broche RA0 en entr�e et RA1-RA7 en sorties ***/

			/*** � compl�ter ! ***/

	/*** Broches RD0-RD7 en sorties pour la validation d'une conversion A/D ***/

			/*** � compl�ter ! ***/ 
}        

/******************************************************************/
/*** FONCTION :  initialisation du timer0 et de l'IT associ�e	***/ 
/******************************************************************/
void TIMER0_Init(void)
{
	/*** T0CON : Timer0=OFF, mode=16bits, synchro=Tcy, prescaler=ON, prescale value=1:2 ***/

			/*** � compl�ter ! ***/ 

	/*** TMR0 : Initialisation des registres de pr�-chargement ***/

			/*** � compl�ter ! ***/ 

	/*** Gestion des IT : priority mode, vecteur d'IT de priorit� haute, d�masquage IT TMR0, TMR0IF=0 ***/

			/*** � compl�ter ! ***/ 

	/*** Validation du Timer0 ***/

			/*** � compl�ter ! ***/ 	
}        

/**********************************************/
/*** FONCTION :  initialisation de l'ADC	***/ 
/**********************************************/
void ADC_Init(void)
{
	/*** ADCON0 : Channel=0, converter module disable ***/

			/*** � compl�ter ! ***/ 

	/*** ADCON1 : Vref+ = VDD, Vref- = Vss, AN0 only is Analog Input ***/


			/*** � compl�ter ! ***/ 

	/*** ADCON2 : Tadmin=700ns < Tad=32*Tosc (ou 64*Tosc), Left Adjust, TacqSelect=12*Tad > TacqCalcul (6,4us)  ***/

			/*** � compl�ter ! ***/ 

	/*** Validation du module ADC  ***/

			/*** � compl�ter ! ***/ 
}        


/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {
unsigned char	Spectrum[TFD_SIZE];

	/*** Appel fonction de configuration des ports A et D ***/

			/*** � compl�ter ! ***/ 

	/*** Appel fonction de configuration du Timer0 et de l'IT associ�e ***/

			/*** � compl�ter ! ***/ 

	/*** Appel fonction de configuration de l'ADC ***/

			/*** � compl�ter ! ***/ 

	/*** Initialisation de l'afficheur graphique GLCD ***/

			/*** � compl�ter ! ***/ 

	/*** D�masquage global des IT ***/

			/*** � compl�ter ! ***/ 

  	while(1){
		/*** Test l'acquisition de 32 �chantillons temporels d'entr�e***/
      	if(0) {                                      
         	/*** Masquage global des IT et RAZ du flag buffer d'entr�e plein ***/

				/*** � compl�ter ! ***/ 

			/*** Algorithme de calcul de la TFD (DFT) ***/

				/*** � compl�ter ! ***/ 

			/*** Affichage du spectre sur l'afficheur graphique GLCD-64x128 ***/

				/*** � compl�ter ! ***/ 

         	/*** D�masquage global des IT ***/

				/*** � compl�ter ! ***/ 
     	}
  	};
}

