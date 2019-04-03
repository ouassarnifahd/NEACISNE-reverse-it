;PIC18 ASSEMBLY TP:
;    ISA: (Instruction Set Architecture)
;    MCU: ADVANCED-8BIT-MCU
;    DEVICE: PIC18F4550
;    SONDE: ICD3
;    TOOLCHAIN: C18
;
;   GPIO : General purpose Input Output
;       LATx : WRITE TO OUT REG
;       PORTx: READ FROM OUT REG
;       TRISx: I|O INCODING REG
;
;   Modes D'adressage:
;       Literal:    MOV cte(16-bit), Reg    CPU
;       Registre:   MOV RegA, RegB          CPU <-> CPU
;       Direct:     MOV Add(bcp), Reg       MEM <-> CPU (pas utilisé)
;       Indirect:   MOV RegCPU, RegCPU      LD|ST


#include<p18f4550.inc>

CONFIG WDT=OFF, LVP=OFF, PLLDIV=2, CPUDIV=OSC1_PLL2, FOSC=HSPLL_HS, BOR=OFF, MCLRE=ON

idata_acs
    PortBTemp   db      0

    org     0x0000
RESET_V:
    GOTO    MAIN

MAIN:
    


MAIN_L1:

		GOTO MAIN_L1

    END
