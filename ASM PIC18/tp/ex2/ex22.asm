; *********************************
; @file :  ex22.asm
; @brief :
; @author :
; last modification :
; *********************************

	;*** Fichiers d'en-t�te ***
    #include <p18f4550.inc>

	;*** Configuration bits - Special Features - Fosc=48MHz   Tosc=1/Fosc=20,8ns   Tcy=4*Tosc=83,33ns ***
    CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

    ;*** d�finition des MACROS ***
COUNTH			EQU  	0
COUNTL			EQU  	0

	;*** Mise en place du vecteur d'IT li� au Reset ***
    org     0x0000				; Adresse du vecteur d'IT
RESET_V:
    goto    MAIN               	; Vecteur d'interruption li� au Reset

	;*** Mise en place du vecteur d'IT de priorit� haute ***
    org     0x0008
HPRIO_V:
    goto    TOGGLE_ISR         ;Vecteur d'interruption de priorit� haute

	;*** section programme ***
	code
	;******************************************************
	;*** ISR : routine d'interruption TOGGLE_ISR
	;*** @brief : inverse le niveau logique sur la broche n�0 du portB
	;******************************************************
TOGGLE_ISR:
	;*** Acquittement IRQ TMR0IF ***

	BCF INTCON,TMR0IF

	;*** R�-initialiser la valeur de pr�-chargement du Timer0 ***

	MOVLW 0xE4
	MOVWF TMR0L
	;MOVLW 0x48
	;MOVWF TMR0H

	;*** Inversion du niveau logique sur la broche n�0 du port B ***

	BTG LATB,0

	retfie

	;***************************
	;*** Programme principal ***
	;***************************
MAIN:
	;*** Initialisation de la broche n�0 du port B en sortie ***

	BCF TRISB,0

	;*** Initialisation puis d�marrage du Timer0 ***

	MOVLW 0x07
	MOVWF T0CON
	MOVLW 0x48
	MOVWF TMR0H
	MOVLW 0xE4
	MOVWF TMR0L
	BSF T0CON,TMR0ON

	;*** D�masquage de l'interruption li�e au Timer0 ***
	;*** ISR de priorit� haute

	BSF RCON,IPEN
	BSF INTCON2,TMR0IP

	;*** D�masquage global des interruptions ***

	BSF INTCON,TMR0IE
	BSF INTCON,GIEH
	BCF INTCON,TMR0IF

MAIN_L1:
    goto    MAIN_L1

    END
