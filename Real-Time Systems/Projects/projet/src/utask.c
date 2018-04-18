/**
* @file     utask.c
* @brief    user tasks and kernel config source
* @author   OUASSARNI Fahd
* @date
*/

/* INCLUDES DEPENDENCIES ***************/
#include <utask.h>
/* include all headers dependencies into utask.h file */

/**
* @fn void kernelConfig(void)
* @brief kernel configuration
*/
void kernelConfig(void){

   xQueueTempStreamConfig();
   xMutexTempBufferConfig();

   xTaskCreate(consoleTask, "uart console management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
   xTaskCreate(sensorTask, "sensor stream management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

   // xTaskCreate(timeTask, "time management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

   // xTaskCreate(networkTask, "network access management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

   xTaskCreate(ledUpdateTask, "led management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

 }

/**
* @fn void consoleTask( void *pvParameters )
* @brief console handling task
*/
void consoleTask(void *pvParameters) {

    int user_command_id = -1;
    const portTickType xDelay = 20;

    consoleInit();

    for(;;) {
        uartprintf("freertos:~# ");
        // cursor save
        uartSendEscCommand("[s");
        // interprete
        user_command_id = consoleReadCommand();
        // reply
        consoleReply(user_command_id);
    
        vTaskDelay(xDelay);
    }

}

/**
* @fn void consoleTask( void *pvParameters )
* @brief console handling task
*/
void networkTask(void *pvParameters) {

}

/**
* @fn void sensorTask( void *pvParameters )
* @brief temperature acquisition task
*/
void sensorTask(void *pvParameters) {

    float tempStream;

    portTickType xLastWakeTime;
    const portTickType xFrequency = 20;

    // Initialize the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    for(;;)
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );

        // Perform action here.
        tempStream = adc2temp(adcRead());

        xQueueSend(xQueueTempStream, &tempStream, 0);

        if( xMutexTempBufferAccess != NULL )
        {
            /* See if we can obtain the semaphore.  If the semaphore is not
            available wait xTimeout ticks to see if it becomes free. */
            if( xSemaphoreTake( xMutexTempBufferAccess, 0 ) == pdTRUE )
            {
                /* We were able to obtain the semaphore and can now access the
                shared resource. */

                tempBuffer[bufferIterator] = tempStream;
                bufferIterator = (bufferIterator != MAX_SIZE_BUFFER) ? bufferIterator + 1 : 0;

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

}

/**
* @fn void ledUpdateTask( void *pvParameters )
* @brief led hangling task
*/
void ledUpdateTask(void *pvParameters) {

    for(;;) {
        updateLED();
        vTaskDelay(LED_BLINK_PERIOD);
    }

}

/**
* @fn void vApplicationIdleHook( void )
* @brief function called by idle task
*/
void vApplicationIdleHook(void) {
    PowerSaveIdle();
    // PowerSaveSleep();
}
