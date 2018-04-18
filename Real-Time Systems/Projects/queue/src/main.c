/**
* @file     main.c
* @brief    practical work to understand the cooperative mode
* @li 		XC32 C toolchain(tested with xc32 1.21)
* @li 		MPLABX IDE(tested with mplabx 1.85)
* @li       FreeRTOS vs 7.5.2 (2013-08)
* @author   OUASSARNI - JAN
* @date     29 Jan 2018
*/

/* CONFIGURATION BITS ***************/
// cpu, low and high speed peripherals clock 80MHz (matrix and peripheral bus)
#pragma config FWDTEN = OFF, CP = OFF, POSCMOD = XT, FNOSC = PRIPLL
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20, FPLLODIV = DIV_1, FPBDIV = DIV_1

/* INCLUDES DEPENDENCIES ***************/
#include <utask.h>
/* include all headers dependencies into utask.h file */

char* gblMsg = "\r\nHello World!\r\n";

/**
* @fn void main (void)
* @brief main entry point
*/
int main(void){
    // cache cpu configuration
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

    // uart module configuration
    uartConfig();

    // interruption configuration
    interruptConfig();

    // kernel configuration
    kernelConfig();

    // Global welcome message
    uartPutS(gblMsg);

    // char* mainMsg = "\r\n2 plus 2 is four minus 1 thats 3, Quick Mathsss!\r\n";

    // Main welcome message
    // uartPutS(mainMsg);

    // start kernel scheduling
    vTaskStartScheduler();

    // it's a trap
    while(1);
}
