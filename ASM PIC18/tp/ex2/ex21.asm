; *********************************
; @file :  ex21.asm
; @brief :
; @author :
; last modification :
; *********************************

	;*** Fichiers d'en-t�te ***
    #include <p18f4550.inc>

	;*** Configuration bits - Special Features - Fosc=48MHz   Tosc=1/Fosc=20,8ns   Tcy=4*Tosc=83,33ns ***
    CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

    ;*** d�finition des MACROS ***
	TEMPO          EQU  	0

	;*** Section de donn�es - initialized data in ACCESS mode ***
	idata_acs			; On force le compilateur � mettre nos variables en ACCESS RAM
CounterL	db		0	; Allocation d'un octet en m�moire RAM et initialisation � "0"
CounterH	db		0
CounterUH	db		0

	;*** Mise en place du vecteur d'IT li� au Reset ***
    org     0x0000				; Adresse du vecteur d'IT
RESET_V:
    goto    MAIN               	; Vecteur d'interruption li� au Reset

	;*** Section de code ***
	code
	;******************************************************
	;*** FONCTION : Temporisation logicielle
	;******************************************************
DELAY:
	;*** Initialisation de la partie haute (CounterUH) de la valeur � d�cr�menter ***

		MOVLW 0x3D
		MOVWF CounterUH

DELAY_L1:
	;*** D�cr�mentation de la valeur � d�compter ***
	DECFSZ CounterL
	GOTO DELAY_L1
	DECFSZ CounterH
	GOTO DELAY_L1
	DECFSZ CounterUH
	GOTO DELAY_L1
	return

	;***************************
	;*** Programme principal ***
	;***************************
MAIN:

	;*** Initialisation de la broche n�0 du port B ***

	BCF TRISB

	;*** Faire toujours : Allumer LED >> appel fonction DELAY >> �teindre LED >> appel fonction DELAY ... ***
MAIN_L1:

	BSF LATB,0
	CALL DELAY
	BCF LATB,0
	CALL DELAY
	
	GOTO MAIN_L1

    END
