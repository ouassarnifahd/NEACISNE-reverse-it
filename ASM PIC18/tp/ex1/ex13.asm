;**********************************
; @file :  ex13.asm
; @brief : 
; @author : 
; last modification : 
; *********************************


	;*** Fichiers d'en-t�te ***
    #include <p18f4550.inc>
	
	;*** Configuration bits - Special Features ***
    CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

	;*** Section de donn�es - initialized data in ACCESS mode ***
	idata_acs				; On force le linker � mettre notre variable en ACCESS RAM
PortCRead 	db 		0		; Allocation d'un octet en m�moire RAM et initialisation � "0"


	;*** Mise en place du vecteur d'IT li� au Reset ***
    org     0x0000				; Adresse du vecteur d'IT
RESET_V:	
    goto    MAIN               	; Vecteur d'interruption li� au Reset

	;*** Section de code ***
	code
	;******************************************************
	;*** FONCTION : Calcul 2exp(valeur RC0-RC2)	
	;*** @param	 PortCRead : valeur sir les broches RC0-RC2
	;*** @return resultat  : r�sultat de 2exp(valeur RC0-RC2) 			
	;******************************************************
CALCUL:

		;*** � compl�ter ! ***

	return						; Retour au programme principal (valeur de retour dans "W")


		
	
	;***************************
	;*** Programme principal ***
	;***************************
MAIN:

    setf    ADCON1

	;*** Initialisation du port C et du port B ***

		;*** � compl�ter ! ***

	;*** R�cup�ration valeur port C >> appel fonction CALCUL  >> affichage r�sultat sur le port B ***

		;*** � compl�ter ! ***

    end




