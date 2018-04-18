/**
* @file     uadc.c
* @brief    adc module library for pic32 mcu architecture
* @author   hugo descoubes
* @date     august 2013
*/

/* INCLUDES DEPENDENCIES ***************/
#include "adc.h"

/**
 * @fn void adcConfig(void)
 * @brief adc module configuration
 */
void adcConfig(void) {
    // adc module configuration
    OpenADC10( PARAM1, PARAM2, PARAM3, PARAM4, PARAM5 );

    // enable adc module
    EnableADC10();
}

/**
 * @fn int adcRead(void)
 * @brief 10bits analog to digital data conversion on AN4 pin (0-1023 result)
 */
int adcRead(void){
    // adc input mulplexer configuration for potentiometer AN8 pin conversion
    SetChanADC10( ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN8 );

    // start conversion
    ConvertADC10();

    // wait for conversion complete
    while ( BusyADC10() == 0);

    // return result
    return ReadADC10(0);
}



