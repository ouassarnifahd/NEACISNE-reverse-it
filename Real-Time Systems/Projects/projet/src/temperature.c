/**
 * @file     temperature.h
 * @brief    adc based temperature reading task source
 * @author   OUASSARNI Fahd
 * @date
 */
#include "temperature.h"

xQueueHandle xQueueTempStream;
xSemaphoreHandle xMutexTempBufferAccess;
float tempBuffer[MAX_SIZE_BUFFER];
portBASE_TYPE bufferIterator;

void xQueueTempStreamConfig(void) {

    xQueueTempStream = xQueueCreate( 1, sizeof( float ) );
    if( xQueueTempStream == NULL ) {
        /* Queue was not created and must not be used. */
        while(1);
    }

}

void xMutexTempBufferConfig(void) {

    xMutexTempBufferAccess = xSemaphoreCreateMutex();
    if( xMutexTempBufferAccess == NULL ) {
        /* There was insufficient FreeRTOS heap available for the semaphore to
        be created successfully. */
        while(1);
    }

}

float adc2temp(int adcValue) {
    return ((adcValue * 270) / (float)1023) - 40.0;
}
