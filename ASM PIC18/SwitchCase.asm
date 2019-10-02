; CPU specific features Assembleur PIC18
CONFIG PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS
CONFIG BOR=OFF, MCLRE=ON, WDT=OFF, LVP=OFF

;PIC18F4550 specific aliases
#include <p18f4550.inc>

;private declaration and aliases
    idata_acs
    state   db  0
TASK_TOGGLE equ 1
TASK_SET    equ 2
TASK_CLEAR  equ 3

; reset interrupt vector
    org 0x0000

reset_v: GOTO main

;application entry point
main:
    MOVLW TASK_TOGGLE
    MOVWF state
    MOVLW 0x00
    MOVWF LATD
    MOVLW 0xF7
    MOVWF TRISD

main_l1:
;   Switch(state){
;       case 1:
;
;           break;
;       case 2:
;
;           break;
;       case 3:
;
;           break;
;   }
    MOVF state, w
    XORLW TASK_TOGGLE
    BZ main_c1

    MOVF state, w
    XORLW TASK_SET
    BZ main_c2

    MOVF state, w
    XORLW s3
    BZ main_c3

main_c1:
    CALL task_toggle_led
    BRA main_e1

main_c2:
    CALL task_toggle_led
    BRA main_e1

main_c3:
    CALL task_toggle_led
    BRA main_e1

main_e1:
    MOVLW TASK_CLEAR
    SUBWF state,w
    BNZ main_l2
    MOVLW 0x00
    MOVWF state

main_l2:
    INCF state
    BRA main_l1

;toggle LED state
task_toggle_led:
    BTG LATD, LATD3
    RETURN

; activate LED state
task_set_led:
    MOVLW 0x08
    IORWF LATD,f
    RETURN ; inactivate LED sate
task_clear_led:
    BCF LATD, LATD3
    RETURN

END
