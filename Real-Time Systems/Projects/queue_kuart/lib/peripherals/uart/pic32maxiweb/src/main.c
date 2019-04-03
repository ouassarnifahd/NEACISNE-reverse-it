/**
* file     main.c
* brief    uart module management on pic32 mcu architecture
* li 		XC32 C toolchain(tested with xc32 1.21)
* li 		MPLABX IDE(tested with mplabx 1.85)
* author   hugo descoubes
* date     september 2014
*/

/* CONFIGURATION BITS ***************/
// cpu, low and high speed peripherals clock 80MHz (matrix and peripheral bus)
#pragma config FWDTEN = OFF, CP = OFF, POSCMOD = XT, FNOSC = PRIPLL
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20, FPLLODIV = DIV_1, FPBDIV = DIV_1

/* INCLUDES DEPENDENCIES ***************/
#include <uart.h>

/**
* void main (void)
*/
int main(void){
    // cache cpu configuration
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

    // uart module configuration
    uartConfig();

    // interruption configuration
    interruptConfig();
    
    // welcome message
    uartPutS("\r\nHello World");

    while(1){
		uartPutS("\r\napplication echo# ");
		
        // string receiving
        uartGetS(strTmp);

        // echo received string
        uartPutS(strTmp);
    }
}
