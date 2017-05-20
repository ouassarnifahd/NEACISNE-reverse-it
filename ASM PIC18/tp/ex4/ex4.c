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
#define		CODE_VALUE		2569
#define		TMROHVALUE		/*** � compl�ter ! ***/
#define		TMROLVALUE		/*** � compl�ter ! ***/

/*** D�claration des variables globales ***/
char welcomeMess[] = "Saisir code :";
char clearMess[] = "                ";
char openMess[] = "Open";
 int CODE = CODE_VALUE;



#pragma code
/**************************************************************/
/*** FONCTION : routine d'interruption de priorit� basse	***/
/**************************************************************/
#pragma interruptlow low_isr
void low_isr(void)
{
    static unsigned char	Decode = 1;

    if(INTCONbits.TMR0IF)
    {
		/*** Clear Timer0 overflow flag ***/

    		INTCONbits.TMR0IF = 0;

		/*** pr�-chargement de TMR0L + chargement automatique de TMR0H ***/

            TMR0H = 0xFF;
    		TMR0L = 0x15;
			
		/*** Signal de BALAYAGE : Mise � "1" de l'une des broches RD4-RD7 ***/
                if(Decode==1){
                    LATDbits.LATD4 = 1;
                    LATDbits.LATD5 = 0;
                    LATDbits.LATD6 = 0;
                    LATDbits.LATD7 = 0;
                }
                else if(Decode==2){
                    LATDbits.LATD4 = 0;
                    LATDbits.LATD5 = 1;
                    LATDbits.LATD6 = 0;
                    LATDbits.LATD7 = 0;
                }
                else if(Decode==3){
                    LATDbits.LATD4 = 0;
                    LATDbits.LATD5 = 0;
                    LATDbits.LATD6 = 1;
                    LATDbits.LATD7 = 0;
                }
                else if(Decode==4){
                    Decode=0;
                    LATDbits.LATD4 = 0;
                    LATDbits.LATD5 = 0;
                    LATDbits.LATD6 = 0;
                    LATDbits.LATD7 = 1;
                }
                Decode++;
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

    T0CON = 0x07;

	/*** TMR0 n�2 : Initialisation des registres de pr�-chargement ***/
    TMR0H = 0xFF;
    TMR0L = 0x15;

	/*** Gestion des IT : priority mode, vecteur d'IT de priorit� basse, d�masquage IT TMR0, TMR0IF=0 ***/

    RCONbits.IPEN = 1;
    INTCON2bits.TMR0IP = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    INTCONbits.TMR0IF = 0;

	/*** D�marrage du Timer0 n�3 ***/

    T0CONbits.TMR0ON = 1;

}

/**************************************************/
/*** FONCTION : initialisation des ports B et D	***/
/**************************************************/
void Port_Config(void)
{
	/*** LCD config : Broches RB0 � RB5 en sortie ***/

            TRISB = 0xC0;

	/*** KEYBOARD config : Broches RD4 � RD7 en sortie et RD0 � RD2 en entr�e ***/

            TRISD = 0x07;

}

char shared;

/**************************
*** PROGRAMME PRINCIPAL ***
***************************/
void main() {
unsigned char	TouchNum , CodeCount = 0, latchPORTD;
unsigned int 	CodeCompare = 0;
char message[]="Saisir code :",message_Fail[]="GAME OVER";

char etoile='*';

	/*** Appel fonction de configuration des port B et D ***/

            Port_Config();

	/*** Appel fonction de configuration du Timer0 et des IT ***/

            Timer_Config();

	/*** Initialisation LCD et affichage message d'accueil ***/

            LCD_Init_User();
            LCD_String_User(message);
            LCD_Cursor_XY_User(2,1);

	/*** D�masquage global des IT ***/

            INTCONbits.GIEH = 1;
            INTCONbits.GIEL = 1;

  while(1){
		/*** Test si l'utilisateur a appuy� sur une touche ***/
		if(PORTDbits.RD0 || PORTDbits.RD1 || PORTDbits.RD2){
			/*** Masquage global des IT ***/

                        INTCONbits.GIEH = 0;
                        INTCONbits.GIEL = 0;

			/*** Sauvegarde de la valeur sur le PORT D ***/
			latchPORTD = PORTD;

			/*** n�1 : D�tection de la touche frapp�e ***/
			switch(latchPORTD){
					case 0x11	:	TouchNum = 0x1;	break;
					case 0x12	:	TouchNum = 0x2;	break;
					case 0x14	:	TouchNum = 0x3;	break;
					case 0x21	:	TouchNum = 0x4;	break;
					case 0x22	:	TouchNum = 0x5;	break;
					case 0x24   	:	TouchNum = 0x6;	break;
					case 0x41	:	TouchNum = 0x7;	break;
					case 0x42	:	TouchNum = 0x8;	break;
					case 0x44	:	TouchNum = 0x9;	break;
					case 0x81	:	TouchNum = 0xF;	break;
					case 0x82	:	TouchNum = 0x0;	break;
					case 0x84	:	TouchNum = 0xF;	break;
					default		:	TouchNum = 0xF;
			}

			/*** n�2 : Affichage des caract�res "*" et gestion du compteur de touches frapp�es ***/

                        LCD_Char_User(etoile);
            		CodeCount++;
			/*** n�3 : Effacement des "***" si touche "#" ou touche "*" frapp�e ***/

                        if(TouchNum==0xF){
                            LCD_Cursor_XY_User(2,1);
                            LCD_String_User(clearMess);
                            LCD_Cursor_XY_User(2,1);
                            CodeCompare=0;
                            CodeCount=0;
                        }

			/*** n�4 : Calcul de la valeur � comparer au CODE ***/

                        if(TouchNum!=0xF){
                            CodeCompare = TouchNum + CodeCompare * 10;
                        }
			/*** n�5 : Si code calcul� = CODE et si on a appuy� sur 4 touches alors ... ***/
                        if(CodeCount==4){
                            if(CodeCompare==CODE_VALUE){
                                LCD_Command_User(LCD_USER_COMMAND_CLEAR);
                                LCD_String_User(openMess);
                                Delay_1s();
                                LCD_Command_User(LCD_USER_COMMAND_CLEAR);
                                LCD_String_User(message);
                                LCD_Cursor_XY_User(2,1);
                            } else {
                                LCD_Command_User(LCD_USER_COMMAND_CLEAR);
                                LCD_String_User(message_Fail);
                                Delay_1s();
                                LCD_Command_User(LCD_USER_COMMAND_CLEAR);
                                LCD_String_User(message);
                                LCD_Cursor_XY_User(2,1);
                            }
                            CodeCompare=0;
                            CodeCount=0;
                        }

			/*** tant que l'on reste appuy� sur la touche, on ne relance pas le balayage des lignes ***/
			while(PORTD == latchPORTD);

			/*** D�masquage global des IT ***/

    			INTCONbits.GIEH = 1;
                        INTCONbits.GIEL = 1;

		}
	}
}
