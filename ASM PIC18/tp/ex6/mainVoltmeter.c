/*********************************
 @file :  mainVoltmeter.c
 @brief : Cr�ation d'un voltm�tre
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - TCY = 83,2ns ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP=OFF

/*** Includes files ***/
#include <p18f4550.h>

/*** D�finition des Macros ***/	
#define		TMROLVALUE		0x00		/*** � compl�ter ! ***/  
#define		TMROHVALUE		0x00		/*** � compl�ter ! ***/  

/*** D�finition des variables globales ***/
unsigned	char flag20ms = 0;
unsigned	char measure;

#pragma code
/******************************************************/
/*** ISR : routine d'interruption de priorit� haute	***/
/******************************************************/
#pragma interrupt High_ISR
void High_ISR(void)
{
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

		/*** Acquisition mesure courante et activation flag 20ms ***/  

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
			
	/*** Configuration broches afficheur LCD 2x16 ***/

			/*** � compl�ter ! ***/ 
}        

/******************************************************************/
/*** FONCTION :  initialisation du timer0 et de l'IT associ�e	***/ 
/******************************************************************/
void TIMER0_Init(void)
{
	/*** T0CON : d�brouillez-vous ! ***/

			/*** � compl�ter ! ***/ 

	/*** TMR0 : Initialisation des registres de pr�-chargement ***/

			/*** � compl�ter ! ***/ 

	/*** Gestion des IT : d�brouillez-vous ! ***/

			/*** � compl�ter ! ***/ 

	/*** D�marrage Timer0 ***/

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

	/*** configuration GPIO ***/

			/*** � compl�ter ! ***/ 

	/*** configuration Timer et Interruption associ�e ***/

			/*** � compl�ter ! ***/ 

	/*** configuration ADC ***/

			/*** � compl�ter ! ***/ 
			
	/*** Initialisation afficheur et pr�-configuration affichage ***/

			/*** � compl�ter ! ***/ 
			
	/*** D�masquage global des IT ***/

			/*** � compl�ter ! ***/ 

  	while(1){
      	if(0) {             // attente 20ms                         
			/*** Masquage global des IT ***/

				/*** � compl�ter ! ***/ 	
			
			/*** Conversion mesure (entier) vers string � afficher  ***/
			/*** Conseil : utiliser la librairie standard du C  ***/
			
				/*** � compl�ter ! ***/ 

			/*** affichage valeur convertie ***/

				/*** � compl�ter ! ***/ 
				
			/*** D�masquage global des IT ***/

				/*** � compl�ter ! ***/ 	
     	}
  	};
}

