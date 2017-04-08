/*********************************
 @file :  ex5a.c
 @brief : Communications PC via EUSART
 @author : 
 last modification : 
*********************************/

/*** Configuration bits - Special Features - TCY = 83,2ns ***/
#pragma config PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, WDT=OFF, MCLRE=ON, LVP = OFF

/*** Includes files ***/
#include <p18f4550.h>

/*** Définition des Macros ***/
#define 	BUFFER_SIZE		100			/*** Taille du buffer circulaire ***/
	
/*** Déclaration des variables globales - Communications PC - EUSART ***/
volatile unsigned char indexWrite=0, indexRead=0, EUSARTtmp, EUSARTbuffer[BUFFER_SIZE], flagCaracRecu = 0;
#pragma romdata
rom const unsigned 	char Menu_Message[]="Entrez une commande a envoyer au DIGICODE :\n\r\n\r  R : Reset du DIGICODE \n\r  C : Changement du CODE \n\r  M : Changement du message d'accueil du LCD \n\r";
rom const unsigned 	char Reset_Message[]="Reset du Micro-contrôleur effectué !";
rom const unsigned 	char Error_Message[]="Erreur de saisie - Il ne s'agit pas d'une commande !";
rom const unsigned 	char Error_Size_Code_Message[]="Erreur de saisie - Entrez un code à 4 chiffres !";
rom const unsigned 	char Error_Size_LCD_Message[]="Erreur de saisie - Entrez un message de 16 caractères maximum !";
rom const unsigned 	char Saisie_Message[]="Saisie : ";
rom const unsigned 	char Choix_Message[] =" Choix : ";
rom const unsigned 	char crx2[]="\n\r\n\r";				
rom const unsigned 	char cr[]="\n\r";



#pragma code
/*****************************************************************/
/***  ISR :  routine d'interruption de priorité haute	 	   ***/
/*** ATTENTION : l'EUSART envoie 2 demandes d'IT distinctes    ***/
/*****************************************************************/
#pragma interrupt high_isr
void high_isr(void)
{
    		/*** à compléter ! ***/  						
}
/*** Configuration du vecteur d'interruption de priorité haute ***/
#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
   _asm goto high_isr _endasm
}


#pragma code
/******************************************************************/ 
/*** FONCTION : Configuration de l'EUSART et de l'IT associée	***/
/******************************************************************/ 
void EUSART_Init(void)
{
	/*** Configuration des registres de transmission (TXSTA) et de réception (RCSTA) de l'EUSART 	***/
	/*** 						SYNC=0 (asynchrone) et  BRGH=1 (high speed)	... etc	 				***/

    		/*** à compléter ! ***/  

	/*** Configuration du registre BAUDCON, SPBRG et SPBRGH pour la gestion du BAUD RATE 	***/
	/*** 	BRG16=1 (16bits mode)   et   BAUD RATE - 115,2KB avec : Fosc=48MHz			 	***/

    		/*** à compléter ! ***/  

	/*** Configuration de l'interruption associée à l'USART en réception (démasquage) ***/

    		/*** à compléter ! ***/  
}        

/**************************************************************/
/*** FONCTION : Lecture d'un charactère entrée depuis le PC	***/      
/*** @return keycode : code du caractère reçu 				***/
/**************************************************************/
unsigned char EUSART_Read_Char_User(void){

    		/*** à compléter ! ***/  
		
return 0;
}

/**********************************************************************************/
/*** FONCTION : Lecture d'une chaîne de charactères entrée depuis le PC			***/ 
/*** @param	ptString : pointeur sur la zone mémoire en RAM où sauver la chaîne	***/
/**********************************************************************************/
void EUSART_ReadRAM_String_User(unsigned char *ptString){

    		/*** à compléter ! ***/  
}

/******************************************************/
/*** FONCTION : Envoi d'un charactère vers le PC	***/ 
/*** @param	keyCode : caractère à envoyer			***/
/******************************************************/
void EUSART_Write_Char_User(unsigned char keyCode){

    		/*** à compléter ! ***/                      
}

/**************************************************************************/
/*** FONCTION : Envoi d'une chaîne de charactères vers le PC			***/
/*** @param	ptString : pointeur sur la chaîne de caractères à envoyer	***/	
/*** 		ATTENTION, la chaîne de caractères envoyée est en RAM		***/     
/**************************************************************************/
void EUSART_WriteRAM_String_User(unsigned char *ptString){

    		/*** à compléter ! ***/  
}

/**************************************************************************/
/*** FONCTION : Envoi d'une chaîne de charactères vers le PC			***/
/*** @param	ptString : pointeur sur la chaîne de caractères à envoyer	***/	
/*** 		ATTENTION, la chaîne de caractères envoyée est en ROM		***/     
/**************************************************************************/
void EUSART_WriteROM_String_User(rom unsigned char *ptString){

    		/*** à compléter ! ***/  
}




/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {
/*** variables locales pour la communication PC ***/
unsigned char  	keyCode;

  	CMCON 	|= 	0x07;       // turn off comparators
  	ADCON1 	|= 	0x0F;       // turn off analog inputs

	/*** Configuration de l'EUSART et de l'IT associée ***/

    		/*** à compléter ! ***/  

	/*** Démasquage global des IT - ex4.c ***/

    		/*** à compléter ! ***/  

  while(1){
		/*** Attente réception d'un caractère depuis le PC ***/
		if( ???? ){

			/*** Lecture du caractère arrivé ***/	

    			/*** à compléter ! ***/  

			/*** Envoie au PC du caractère reçu + saut de ligne et retour chariot ***/

    			/*** à compléter ! ***/  
		}
}

