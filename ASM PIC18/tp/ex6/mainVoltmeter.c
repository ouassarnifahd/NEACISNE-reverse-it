/*********************************
 @file :  mainVoltmeter.c
 @brief : Création d'un voltmètre
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - TCY = 83,2ns ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP=OFF

/*** Includes files ***/
#include <p18f4550.h>

/*** Définition des Macros ***/	
#define		TMROLVALUE		0x00		/*** à compléter ! ***/  
#define		TMROHVALUE		0x00		/*** à compléter ! ***/  

/*** Définition des variables globales ***/
unsigned	char flag20ms = 0;
unsigned	char measure;

#pragma code
/******************************************************/
/*** ISR : routine d'interruption de priorité haute	***/
/******************************************************/
#pragma interrupt High_ISR
void High_ISR(void)
{
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

		/*** Acquisition mesure courante et activation flag 20ms ***/  

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
			
	/*** Configuration broches afficheur LCD 2x16 ***/

			/*** à compléter ! ***/ 
}        

/******************************************************************/
/*** FONCTION :  initialisation du timer0 et de l'IT associée	***/ 
/******************************************************************/
void TIMER0_Init(void)
{
	/*** T0CON : débrouillez-vous ! ***/

			/*** à compléter ! ***/ 

	/*** TMR0 : Initialisation des registres de pré-chargement ***/

			/*** à compléter ! ***/ 

	/*** Gestion des IT : débrouillez-vous ! ***/

			/*** à compléter ! ***/ 

	/*** Démarrage Timer0 ***/

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

	/*** configuration GPIO ***/

			/*** à compléter ! ***/ 

	/*** configuration Timer et Interruption associée ***/

			/*** à compléter ! ***/ 

	/*** configuration ADC ***/

			/*** à compléter ! ***/ 
			
	/*** Initialisation afficheur et pré-configuration affichage ***/

			/*** à compléter ! ***/ 
			
	/*** Démasquage global des IT ***/

			/*** à compléter ! ***/ 

  	while(1){
      	if(0) {             // attente 20ms                         
			/*** Masquage global des IT ***/

				/*** à compléter ! ***/ 	
			
			/*** Conversion mesure (entier) vers string à afficher  ***/
			/*** Conseil : utiliser la librairie standard du C  ***/
			
				/*** à compléter ! ***/ 

			/*** affichage valeur convertie ***/

				/*** à compléter ! ***/ 
				
			/*** Démasquage global des IT ***/

				/*** à compléter ! ***/ 	
     	}
  	};
}

