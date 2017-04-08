;**********************************
; @file :  ex12.asm
; @brief :
; @author :
; last modification :
; *********************************

	;*** Fichiers d'en-t�te ***
    #include <p18f4550.inc>

	;*** Configuration bits - Special Features ***
    CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

	;*** Section de donn�es - initialized data in ACCESS mode ***
	idata_acs				; On force le compilateur � mettre notre variable en ACCESS RAM
PortBTemp 	db 		0		; Allocation d'un octet en m�moire RAM et initialisation � "0"


	;*** Mise en place du vecteur d'IT li� au Reset ***
    org     0x0000				; Adresse du vecteur d'IT
RESET_V:
    goto    MAIN               	; Vecteur d'interruption li� au Reset



	;*** Section de code ***
	code
	;***************************
	;*** Programme principal ***
	;***************************
MAIN:

    setf    ADCON1

	;*** Initialisation du port B ***

	CLRF LATB

	MOVFF 0xF0,TRISB            ;CODING I/O

	;*** R�cup�ration valeur sur RB4-RB7 >> d�calages � droite >> Affichage sur RB0-RB3 ***

	loop:                       ;THIS IS A LOOP

		MOVLW PORTB             ;PORTB -> WREG
		RRNCF WREG              ;ROTATE RIGHT 4 TIMES (XXXX_YYYY -> YYYY_XXXX)
		RRNCF WREG              ;
		RRNCF WREG              ;
		RRNCF WREG              ;
		MOVWF LATB              ; WRITE.OUT

		GOTO loop               ;BRA loop est mieux pour les jmp proches (addresse relative)


    END
