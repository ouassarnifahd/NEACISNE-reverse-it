/*********************************
 @file :  ex4.c
 @brief : gestion d'un clavier matriciel (DIGICODE)
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - Special Features ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP = OFF

/*** Includes files ***/
#include <p18f4550.h>
#include <delays.h>	
#include "LCDUser.h"

/*** Définition des Macros ***/
#define	Delay_200ms()		Delay10KTCYx(240)	/*** 240.10000.TCY 	~ 200ms ***/

#define	Delay_1s()								\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240)	
#define		CODE_VALUE		1492
#define		TMROHVALUE		/*** à compléter ! ***/
#define		TMROLVALUE		/*** à compléter ! ***/

/*** Déclaration des variables globales ***/
char welcomeMess[] = "Saisir code :";
char clearMess[] = "    ";
char openMess[] = "Open";
 int CODE = CODE_VALUE;



#pragma code
/**************************************************************/
/*** FONCTION : routine d'interruption de priorité basse	***/ 
/**************************************************************/
#pragma interruptlow low_isr
void low_isr(void)
{static unsigned char	Decode = 1;

    if(INTCONbits.TMR0IF)
    {
		/*** Clear Timer0 overflow flag ***/

    		/*** à compléter ! ***/  
       
		/*** pré-chargement de TMR0L + chargement automatique de TMR0H ***/

    		/*** à compléter ! ***/  
    
		/*** Signal de BALAYAGE : Mise à "1" de l'une des broches RD4-RD7 ***/

    		/*** à compléter ! ***/  
    }							
}
/*** Configuration du vecteur d'interruption de priorité basse ***/
#pragma code low_vector = 0x18
void interrupt_at_low_vector(void)
{
   _asm goto low_isr _endasm
}



#pragma code 
/******************************************************************/
/*** FONCTION : initialisation du timer0 et de l'IT associée	***/ 
/******************************************************************/
void Timer_Config(void)
{
	/*** T0CON n°1 : Timer0=OFF, mode=16bits, synchro=Tcy, prescaler=ON, prescale value=1:256 ***/

    T0CON = 0b00;

	/*** TMR0 n°2 : Initialisation des registres de pré-chargement ***/

    		/*** à compléter ! ***/  

	/*** Gestion des IT : priority mode, vecteur d'IT de priorité basse, démasquage IT TMR0, TMR0IF=0 ***/

    		/*** à compléter ! ***/  

	/*** Démarrage du Timer0 n°3 ***/

    		/*** à compléter ! ***/  

}        

/**************************************************/
/*** FONCTION : initialisation des ports B et D	***/ 
/**************************************************/
void Port_Config(void)
{
	/*** LCD config : Broches RB0 à RB5 en sortie ***/

    		/*** à compléter ! ***/  

	/*** KEYBOARD config : Broches RD4 à RD7 en sortie et RD0 à RD2 en entrée ***/

    		/*** à compléter ! ***/  

}     
  
char shared;

/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {
unsigned char	TouchNum , CodeCount = 0, latchPORTD;
unsigned int 	CodeCompare = 0;

	/*** Appel fonction de configuration des port B et D ***/

	
	/*** Appel fonction de configuration du Timer0 et des IT ***/

    		/*** à compléter ! ***/  

	/*** Initialisation LCD et affichage message d'accueil ***/

    		/*** à compléter ! ***/ 
			
	/*** Démasquage global des IT ***/

    		/*** à compléter ! ***/  
	
  while(1){
		/*** Test si l'utilisateur a appuyé sur une touche ***/
		if( ???? ){
			/*** Masquage global des IT ***/
			
    			/*** à compléter ! ***/  

			/*** Sauvegarde de la valeur sur le PORT D ***/
			latchPORTD = PORTD;
			 
			/*** n°1 : Détection de la touche frappée ***/
			switch(latchPORTD){
					case 0x11	:	TouchNum = 0x1;	break;
					case ????	:	TouchNum = 0x2;	break;	
					case ????	:	TouchNum = 0x3;	break;
					case ????	:	TouchNum = 0x4;	break;
					case ????	:	TouchNum = 0x5;	break;	
					case ????	:	TouchNum = 0x6;	break;
					case ????	:	TouchNum = 0x7;	break;
					case ????	:	TouchNum = 0x8;	break;
					case ????	:	TouchNum = 0x9;	break;
					case ????	:	TouchNum = 0xF;	break;
					case ????	:	TouchNum = 0x0;	break;
					case ????	:	TouchNum = 0xF;	break;
					default		:	TouchNum = 0xF;	
			}

			/*** n°2 : Affichage des caractères "*" et gestion du compteur de touches frappées ***/
			
    			/*** à compléter ! ***/  
			
			/*** n°3 : Effacement des "***" si touche "#" ou touche "*" frappée ***/
			
    			/*** à compléter ! ***/  

			/*** n°4 : Calcul de la valeur à comparer au CODE ***/
			
    			/*** à compléter ! ***/  

			/*** n°5 : Si code calculé = CODE et si on a appuyé sur 4 touches alors ... ***/
			
    			/*** à compléter ! ***/  

			/*** tant que l'on reste appuyé sur la touche, on ne relance pas le balayage des lignes ***/
			while(PORTD == latchPORTD);
		
			/*** Démasquage global des IT ***/
			
    			/*** à compléter ! ***/  
				
		}
	}
}

