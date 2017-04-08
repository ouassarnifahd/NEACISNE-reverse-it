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

/*** D�finition des Macros ***/
#define 	BUFFER_SIZE		100			/*** Taille du buffer circulaire ***/
	
/*** D�claration des variables globales - Communications PC - EUSART ***/
volatile unsigned char indexWrite=0, indexRead=0, EUSARTtmp, EUSARTbuffer[BUFFER_SIZE], flagCaracRecu = 0;
#pragma romdata
rom const unsigned 	char Menu_Message[]="Entrez une commande a envoyer au DIGICODE :\n\r\n\r  R : Reset du DIGICODE \n\r  C : Changement du CODE \n\r  M : Changement du message d'accueil du LCD \n\r";
rom const unsigned 	char Reset_Message[]="Reset du Micro-contr�leur effectu� !";
rom const unsigned 	char Error_Message[]="Erreur de saisie - Il ne s'agit pas d'une commande !";
rom const unsigned 	char Error_Size_Code_Message[]="Erreur de saisie - Entrez un code � 4 chiffres !";
rom const unsigned 	char Error_Size_LCD_Message[]="Erreur de saisie - Entrez un message de 16 caract�res maximum !";
rom const unsigned 	char Saisie_Message[]="Saisie : ";
rom const unsigned 	char Choix_Message[] =" Choix : ";
rom const unsigned 	char crx2[]="\n\r\n\r";				
rom const unsigned 	char cr[]="\n\r";



#pragma code
/*****************************************************************/
/***  ISR :  routine d'interruption de priorit� haute	 	   ***/
/*** ATTENTION : l'EUSART envoie 2 demandes d'IT distinctes    ***/
/*****************************************************************/
#pragma interrupt high_isr
void high_isr(void)
{
    		/*** � compl�ter ! ***/  						
}
/*** Configuration du vecteur d'interruption de priorit� haute ***/
#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
   _asm goto high_isr _endasm
}


#pragma code
/******************************************************************/ 
/*** FONCTION : Configuration de l'EUSART et de l'IT associ�e	***/
/******************************************************************/ 
void EUSART_Init(void)
{
	/*** Configuration des registres de transmission (TXSTA) et de r�ception (RCSTA) de l'EUSART 	***/
	/*** 						SYNC=0 (asynchrone) et  BRGH=1 (high speed)	... etc	 				***/

    		/*** � compl�ter ! ***/  

	/*** Configuration du registre BAUDCON, SPBRG et SPBRGH pour la gestion du BAUD RATE 	***/
	/*** 	BRG16=1 (16bits mode)   et   BAUD RATE - 115,2KB avec : Fosc=48MHz			 	***/

    		/*** � compl�ter ! ***/  

	/*** Configuration de l'interruption associ�e � l'USART en r�ception (d�masquage) ***/

    		/*** � compl�ter ! ***/  
}        

/**************************************************************/
/*** FONCTION : Lecture d'un charact�re entr�e depuis le PC	***/      
/*** @return keycode : code du caract�re re�u 				***/
/**************************************************************/
unsigned char EUSART_Read_Char_User(void){

    		/*** � compl�ter ! ***/  
		
return 0;
}

/**********************************************************************************/
/*** FONCTION : Lecture d'une cha�ne de charact�res entr�e depuis le PC			***/ 
/*** @param	ptString : pointeur sur la zone m�moire en RAM o� sauver la cha�ne	***/
/**********************************************************************************/
void EUSART_ReadRAM_String_User(unsigned char *ptString){

    		/*** � compl�ter ! ***/  
}

/******************************************************/
/*** FONCTION : Envoi d'un charact�re vers le PC	***/ 
/*** @param	keyCode : caract�re � envoyer			***/
/******************************************************/
void EUSART_Write_Char_User(unsigned char keyCode){

    		/*** � compl�ter ! ***/                      
}

/**************************************************************************/
/*** FONCTION : Envoi d'une cha�ne de charact�res vers le PC			***/
/*** @param	ptString : pointeur sur la cha�ne de caract�res � envoyer	***/	
/*** 		ATTENTION, la cha�ne de caract�res envoy�e est en RAM		***/     
/**************************************************************************/
void EUSART_WriteRAM_String_User(unsigned char *ptString){

    		/*** � compl�ter ! ***/  
}

/**************************************************************************/
/*** FONCTION : Envoi d'une cha�ne de charact�res vers le PC			***/
/*** @param	ptString : pointeur sur la cha�ne de caract�res � envoyer	***/	
/*** 		ATTENTION, la cha�ne de caract�res envoy�e est en ROM		***/     
/**************************************************************************/
void EUSART_WriteROM_String_User(rom unsigned char *ptString){

    		/*** � compl�ter ! ***/  
}




/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {
/*** variables locales pour la communication PC ***/
unsigned char  	keyCode;

  	CMCON 	|= 	0x07;       // turn off comparators
  	ADCON1 	|= 	0x0F;       // turn off analog inputs

	/*** Configuration de l'EUSART et de l'IT associ�e ***/

    		/*** � compl�ter ! ***/  

	/*** D�masquage global des IT - ex4.c ***/

    		/*** � compl�ter ! ***/  

  while(1){
		/*** Attente r�ception d'un caract�re depuis le PC ***/
		if( ???? ){

			/*** Lecture du caract�re arriv� ***/	

    			/*** � compl�ter ! ***/  

			/*** Envoie au PC du caract�re re�u + saut de ligne et retour chariot ***/

    			/*** � compl�ter ! ***/  
		}
}

