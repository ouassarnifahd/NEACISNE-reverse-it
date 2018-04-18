/**
* @file     main.c
* @brief    adc module management on pic32 mcu architecture
* @author   hugo descoubes
* @date     august 2013
*/

/* CONFIGURATION BITS ***************/
// cpu, low and high speed peripherals clock 80MHz (matrix and peripheral bus)
#pragma config FWDTEN = OFF, CP = OFF, POSCMOD = XT, FNOSC = PRIPLL
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20, FPLLODIV = DIV_1, FPBDIV = DIV_1

/* INCLUDES DEPENDENCIES ***************/
#include <adc.h>

/**
* @fn void main (void)
* @brief main entry point
*/
int main(void){
    int data;

    // cache cpu configuration
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

    // adc module configuration
    adcConfig();

    while(1){
        // analog to digital conversion
        data = adcRead();
        
        // wait few 100ms
        Nop();      // to use breackpoint
        int i;
        for (i=0; i<4000000; i++);
    }
}
