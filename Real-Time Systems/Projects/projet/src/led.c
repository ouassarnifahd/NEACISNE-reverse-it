/**
 * @file     led.c
 * @brief    led handling task source
 * @author   OUASSARNI Fahd
 * @date
 */

#include "led.h"

void ledConfig(void) {
    PORTSetPinsDigitalOut(IOPORT_B, BIT_10);    // YELLOW
    PORTSetPinsDigitalOut(IOPORT_D, BIT_1);     // GREEN
    PORTSetPinsDigitalOut(IOPORT_D, BIT_2);     // RED
    return ;
}

void updateLED(void) {
    float lastTemp;
    const portTickType xLedTimeout = 50;
    static portBASE_TYPE LED_WAS_ON;

    xQueueReceive(xQueueTempStream, &lastTemp, xLedTimeout);

    if (lastTemp > 38.0) {
        // LED ON
        PORTSetBits(IOPORT_B, BIT_10);
        PORTSetBits(IOPORT_D, BIT_1);
        PORTSetBits(IOPORT_D, BIT_2);
        LED_WAS_ON = 1;
    } else {
        // LED ON/OFF 2 Hz ... CALL THE POOOOLIIICE!
        PORTToggleBits(IOPORT_B, BIT_10);
        if (LED_WAS_ON)
            PORTClearBits(IOPORT_D, BIT_1);
        PORTToggleBits(IOPORT_D, BIT_1);
        PORTToggleBits(IOPORT_D, BIT_2);
        LED_WAS_ON = 0;
    }
}
