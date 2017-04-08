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

/*** D�finition des Macros ***/
#define	Delay_200ms()		Delay10KTCYx(240)	/*** 240.10000.TCY 	~ 200ms ***/

#define	Delay_1s()								\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240);	\
							Delay10KTCYx(240)	
#define		CODE_VALUE		1492
#define		TMROHVALUE		/*** � compl�ter ! ***/
#define		TMROLVALUE		/*** � compl�ter ! ***/

/*** D�claration des variables globales ***/
char welcomeMess[] = "Saisir code :";
char clearMess[] = "    ";
char openMess[] = "Open";
 int CODE = CODE_VALUE;



#pragma code
/**************************************************************/
/*** FONCTION : routine d'interruption de priorit� basse	***/ 
/**************************************************************/
#pragma interruptlow low_isr
void low_isr(void)
{static unsigned char	Decode = 1;

    if(INTCONbits.TMR0IF)
    {
		/*** Clear Timer0 overflow flag ***/

    		/*** � compl�ter ! ***/  
       
		/*** pr�-chargement de TMR0L + chargement automatique de TMR0H ***/

    		/*** � compl�ter ! ***/  
    
		/*** Signal de BALAYAGE : Mise � "1" de l'une des broches RD4-RD7 ***/

    		/*** � compl�ter ! ***/  
    }							
}
/*** Configuration du vecteur d'interruption de priorit� basse ***/
#pragma code low_vector = 0x18
void interrupt_at_low_vector(void)
{
   _asm goto low_isr _endasm
}



#pragma code 
/******************************************************************/
/*** FONCTION : initialisation du timer0 et de l'IT associ�e	***/ 
/******************************************************************/
void Timer_Config(void)
{
	/*** T0CON n�1 : Timer0=OFF, mode=16bits, synchro=Tcy, prescaler=ON, prescale value=1:256 ***/

    T0CON = 0b00;

	/*** TMR0 n�2 : Initialisation des registres de pr�-chargement ***/

    		/*** � compl�ter ! ***/  

	/*** Gestion des IT : priority mode, vecteur d'IT de priorit� basse, d�masquage IT TMR0, TMR0IF=0 ***/

    		/*** � compl�ter ! ***/  

	/*** D�marrage du Timer0 n�3 ***/

    		/*** � compl�ter ! ***/  

}        

/**************************************************/
/*** FONCTION : initialisation des ports B et D	***/ 
/**************************************************/
void Port_Config(void)
{
	/*** LCD config : Broches RB0 � RB5 en sortie ***/

    		/*** � compl�ter ! ***/  

	/*** KEYBOARD config : Broches RD4 � RD7 en sortie et RD0 � RD2 en entr�e ***/

    		/*** � compl�ter ! ***/  

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

    		/*** � compl�ter ! ***/  

	/*** Initialisation LCD et affichage message d'accueil ***/

    		/*** � compl�ter ! ***/ 
			
	/*** D�masquage global des IT ***/

    		/*** � compl�ter ! ***/  
	
  while(1){
		/*** Test si l'utilisateur a appuy� sur une touche ***/
		if( ???? ){
			/*** Masquage global des IT ***/
			
    			/*** � compl�ter ! ***/  

			/*** Sauvegarde de la valeur sur le PORT D ***/
			latchPORTD = PORTD;
			 
			/*** n�1 : D�tection de la touche frapp�e ***/
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

			/*** n�2 : Affichage des caract�res "*" et gestion du compteur de touches frapp�es ***/
			
    			/*** � compl�ter ! ***/  
			
			/*** n�3 : Effacement des "***" si touche "#" ou touche "*" frapp�e ***/
			
    			/*** � compl�ter ! ***/  

			/*** n�4 : Calcul de la valeur � comparer au CODE ***/
			
    			/*** � compl�ter ! ***/  

			/*** n�5 : Si code calcul� = CODE et si on a appuy� sur 4 touches alors ... ***/
			
    			/*** � compl�ter ! ***/  

			/*** tant que l'on reste appuy� sur la touche, on ne relance pas le balayage des lignes ***/
			while(PORTD == latchPORTD);
		
			/*** D�masquage global des IT ***/
			
    			/*** � compl�ter ! ***/  
				
		}
	}
}

