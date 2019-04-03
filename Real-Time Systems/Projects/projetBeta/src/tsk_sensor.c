/**
 * @file     tsk_sensor.c
 * @brief    adc based temperature reading task source
 * @author   OUASSARNI Fahd
 * @date
 */
#include "tsk_sensor.h"

xQueueHandle xQueueTempStream;
xSemaphoreHandle xMutexTempBufferAccess;
float tempBuffer[TEMP_BUFFER_SIZE];
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

void tempBufferPush(float tempValue) {

    if( xMutexTempBufferAccess != NULL )
    {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait xTimeout ticks to see if it becomes free. */
        if( xSemaphoreTake( xMutexTempBufferAccess, 0 ) == pdTRUE )
        {
            /* We were able to obtain the semaphore and can now access the
            shared resource. */

            tempBuffer[bufferIterator] = tempValue;
            bufferIterator = (bufferIterator != TEMP_BUFFER_SIZE) ? bufferIterator + 1 : 0;

            /* We have finished accessing the shared resource.  Release the
            semaphore. */
            xSemaphoreGive( xMutexTempBufferAccess );
        }
        else
        {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }
}

float tempBufferPop(void) {

    float tempValue;

    if( xMutexTempBufferAccess != NULL )
    {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait xTimeout ticks to see if it becomes free. */
        if( xSemaphoreTake( xMutexTempBufferAccess, 0 ) == pdTRUE )
        {
            /* We were able to obtain the semaphore and can now access the
            shared resource. */

            tempValue = tempBuffer[bufferIterator];

            /* We have finished accessing the shared resource.  Release the
            semaphore. */
            xSemaphoreGive( xMutexTempBufferAccess );
        }
        else
        {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }

    return tempValue;
}

float adc2temp(int adcValue) {
    return ((adcValue * (MAX_TEMP - MIN_TEMP)) / (float)MAX_ADC_VALUE)
            + MIN_TEMP;
}
