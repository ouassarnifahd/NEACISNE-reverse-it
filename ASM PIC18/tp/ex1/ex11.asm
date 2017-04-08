;**********************************
; @file :  ex11.asm
; @brief :
; @author :
; last modification :
; *********************************

	;*** Fichiers d'en-t�te ***
    #include <p18f4550.inc>

	;*** Configuration bits - Special Features ***
    CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

	;*** Mise en place du vecteur d'IT li� au Reset ***
    org     0x0000				; Adresse du vecteur d'IT
RESET_V:
    goto    MAIN               	; Vecteur d'interruption li� au Reset

	;*** section programme ***
	code
	;***************************
	;*** Programme principal ***
	;***************************
MAIN:

    setf    ADCON1

	;*** Initialisation du port B ***

    CLRF LATB                   ;INIT WRITE.O REG

    MOVLW 0xFA                  ;Imediat: b'1111_1010' -> WREG
    MOVWF TRISB                 ;Direct: WREG -> TRISB

    MOVFF b'11111010',TRISB     ;b'1111_1010' -> TRISB

    BSF LATB,0                  ;SET bit 0 IN LATB TO 1
    BSF LATB,2                  ;SET bit 2 IN LATB TO 1

MAIN_L1:
    goto    MAIN_L1       ; bouclage sur l'adresse courante

    END
