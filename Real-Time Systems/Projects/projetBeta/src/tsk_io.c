/**
 * @file     tsk_io.c
 * @brief    input/output handling task
 * @author   OUASSARNI Fahd
 * @date
 */

#include "tsk_io.h"

portBASE_TYPE current_IO_Mode = configDEFAULT_IO_MODE;
xSemaphoreHandle xMutexInOutModeAccess;

xQueueHandle xQueueEventBuffer;
xQueueHandle xQueueInBuffer;
xQueueHandle xQueueOutBuffer;

void serverEventsConfig(void) {

    // event config
    xQueueEventBuffer = xQueueCreate( IO_BUFFER_SIZE, sizeof( char ));
    if( xQueueEventBuffer == NULL ) {
        /* Queue was not created and must not be used. */
        while(1);
    }

}

void serverInOutConfig(void) {

    // IO_MODE Mutex Protection
    xMutexInOutModeAccess = xSemaphoreCreateMutex();
    if( xMutexInOutModeAccess == NULL ) {
        /* There was insufficient FreeRTOS heap available for the semaphore to
        be created successfully. */
        while(1);
    }

    // input config
    xQueueInBuffer = xQueueCreate( IO_BUFFER_SIZE, IO_MAX_STR_SIZE );
    if( xQueueInBuffer == NULL ) {
        /* Queue was not created and must not be used. */
        while(1);
    }

    // output config
    xQueueOutBuffer = xQueueCreate( IO_BUFFER_SIZE, IO_MAX_STR_SIZE );
    if( xQueueOutBuffer == NULL ) {
        /* Queue was not created and must not be used. */
        while(1);
    }

}

void serverPutS(const char* str) {

    xQueueSend( xQueueOutBuffer, str, 0 );

}

void serverGetS(char* str) {

    xQueueReceive( xQueueInBuffer, str, portMAX_DELAY );

}

char serverGetEvent() {
    char keyEventMsg;

    xQueueReceive( xQueueEventBuffer, &keyEventMsg, IO_TIMEOUT);

    return keyEventMsg;
}
