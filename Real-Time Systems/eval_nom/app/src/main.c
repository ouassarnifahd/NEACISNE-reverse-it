/**
* @file     main.c
* @brief    practical work to understand the cooperative mode
* @li 		XC32 C toolchain(tested with xc32 1.21)
* @li 		MPLABX IDE(tested with mplabx 1.85)
* @li       FreeRTOS vs 7.5.2 (2013-08)
* @author   
* @date     
*/

/* CONFIGURATION BITS ***************/
// cpu, low and high speed peripherals clock 80MHz (matrix and peripheral bus)
#pragma config FWDTEN = OFF, CP = OFF, POSCMOD = XT, FNOSC = PRIPLL
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20, FPLLODIV = DIV_1, FPBDIV = DIV_1

/* INCLUDES DEPENDENCIES ***************/
#include <utask.h>
/* include all headers dependencies into utask.h file */

/**
* @fn void main (void)
* @brief main entry point
*/
int main(void){
    // cache cpu configuration
    // ...

    // uart module configuration
    // ...

    // interruption configuration
    // ...

    // kernel configuration
    // ...

    // welcome message
    // ...

    // start kernel scheduling
    // ...

    // it's a trap
    while(1);
}
