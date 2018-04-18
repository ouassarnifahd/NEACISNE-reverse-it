/**
* @file     adc.h
* @brief    header for adc module library for pic32 mcu architecture
* @author   hugo descoubes
* @date     august 2013
*/
#ifndef   __HEADER_ADC__
#define   __HEADER_ADC__

/* INCLUDES DEPENDENCIES ***************/
#include <p32xxxx.h>
#include <plib.h>

/* MACROS ***************/
#define SYS_FREQ            80000000    // bus matrix and cpu clock speed
#define PB_DIV              1		// periphepral bus clock speed divider
//unsigned int 16bits result, internal reference, SHA holding ...
#define PARAM1  ADC_FORMAT_INTG16 | ADC_CLK_AUTO  | ADC_SAMP_ON  | ADC_AUTO_SAMPLING_ON
// Vref+ = Vdd and Vref- = Vss, no offset calibration, no scan, 16bits words buffer, use A side								*/
#define PARAM2  ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_ALT_BUF_OFF | ADC_ALT_INPUT_OFF | ADC_SCAN_OFF
// RC internal reference, internal period reference = 15Tad
#define PARAM3  ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_15
// Microchip explorer 16 : AN4 (temperature sensor) pin enable
// Microchip explorer 16 : AN2 (potentiometer) pin enable
// Olimex PIC32 MAXI WEB : AN8 (potentiometer) pin enable
#define PARAM4	ENABLE_AN4_ANA | ENABLE_AN2_ANA | ENABLE_AN8_ANA
// no scan
#define PARAM5	0

/**
 * @fn void adcConfig(void)
 * @brief adc module configuration
 */
void adcConfig(void);

/**
 * @fn int adcRead(void)
 * @brief 10bits analog to digital data conversion on AN4 pin (0-1023 result)
 * @return return 10bits unsigned result (0-1023)
 */
int adcRead(void);

#endif 
