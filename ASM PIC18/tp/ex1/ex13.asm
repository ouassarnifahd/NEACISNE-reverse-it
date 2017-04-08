;**********************************
; @file :  ex13.asm
; @brief : 
; @author : 
; last modification : 
; *********************************


	;*** Fichiers d'en-tête ***
    #include <p18f4550.inc>
	
	;*** Configuration bits - Special Features ***
    CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

	;*** Section de données - initialized data in ACCESS mode ***
	idata_acs				; On force le linker à mettre notre variable en ACCESS RAM
PortCRead 	db 		0		; Allocation d'un octet en mémoire RAM et initialisation à "0"


	;*** Mise en place du vecteur d'IT lié au Reset ***
    org     0x0000				; Adresse du vecteur d'IT
RESET_V:	
    goto    MAIN               	; Vecteur d'interruption lié au Reset

	;*** Section de code ***
	code
	;******************************************************
	;*** FONCTION : Calcul 2exp(valeur RC0-RC2)	
	;*** @param	 PortCRead : valeur sir les broches RC0-RC2
	;*** @return resultat  : résultat de 2exp(valeur RC0-RC2) 			
	;******************************************************
CALCUL:

		;*** à compléter ! ***

	return						; Retour au programme principal (valeur de retour dans "W")


		
	
	;***************************
	;*** Programme principal ***
	;***************************
MAIN:

    setf    ADCON1

	;*** Initialisation du port C et du port B ***

		;*** à compléter ! ***

	;*** Récupération valeur port C >> appel fonction CALCUL  >> affichage résultat sur le port B ***

		;*** à compléter ! ***

    end




