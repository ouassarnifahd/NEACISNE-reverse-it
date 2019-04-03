/**
* @file     rts_tasks.c
* @brief    user tasks and kernel config source
* @author   OUASSARNI Fahd
* @date
*/

/* INCLUDES DEPENDENCIES ***************/
#include <rts_tasks.h>
/* include all headers dependencies into rts_tasks.h file */

/**
* @fn void kernelConfig(void)
* @brief kernel configuration
*/
void kernelConfig(void) {

    // Mutex for Sensor resources:
    // xQueueTempStreamConfig();
    xMutexTempBufferConfig();

    // Mutex for IO resources:
    serverEventsConfig();
    serverInOutConfig();

    // Calendar:
    #if configUSE_RealTimeCalendar == 1
    xTaskCreate(timeTask, "time management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
    #endif

    // network: used for TCP and STNP
    #if configUSE_NETWORK_UTILITIES == 1
    xTaskCreate(networkTask, "network management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    #endif

    // Display:
    #if configUSE_INTERNAL_DISPLAY == 1
    xTaskCreate(displayUpdateTask, "display management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    #endif

    // the main task:
    xTaskCreate(sensorTask, "sensor management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);

    // led task:
    xTaskCreate(ledUpdateTask, "led management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    // UI task:
    xTaskCreate(consoleTask, "console management", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    #ifdef __SERVER__DEBUG__
    xTaskCreate(debugTask, "debug helper task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);
    #endif

}

#if configUSE_RealTimeCalendar == 1
void timeTask(void *pvParameters) {

    for (;;) {

    }

}
#endif

#if configUSE_NETWORK_UTILITIES == 1
void networkTask(void *pvParameters) {

    for (;;) {

    }

}
#endif

#if configUSE_INTERNAL_DISPLAY == 1
void displayUpdateTask(void *pvParameters) {

    for (;;) {

    }

}
#endif

void keyEventTask(void *pvParameters) {

    char keyEventMsg;
    const portTickType xTimeout = IO_TIMEOUT;
    portBASE_TYPE IO_Mode;

    for (;;) {

        if( xMutexInOutModeAccess != NULL )
        {
            /* See if we can obtain the semaphore.  If the semaphore is not
            available wait xTimeout ticks to see if it becomes free. */
            if( xSemaphoreTake( xMutexInOutModeAccess, 0 ) == pdTRUE )
            {
                /* We were able to obtain the semaphore and can now access the
                shared resource. */

                IO_Mode = current_IO_Mode;

                /* We have finished accessing the shared resource.  Release the
                semaphore. */
                xSemaphoreGive( xMutexInOutModeAccess );
            }
            else
            {
                /* We could not obtain the semaphore and can therefore not access
                the shared resource safely. */
            }
        }

        switch (IO_Mode) {
            case INTERNAL_IO_MODE:
                // do something useful
                // here
                break;
            case UART_IO_MODE:
                keyEventMsg = uartGetC();
                break;
            case TELNET_IO_MODE:
                // do something useful
                // here
                break;
            case HTML_IO_MODE:
                // do something useful
                // here
                break;
        }
        if (keyEventMsg == KEY_CR) {
            xQueueSend( xQueueEventBuffer, &keyEventMsg, 0 );
        }

        vTaskDelay( xTimeout );
    }

}

void genericInputTask(void *pvParameters) {

    char strInMsg[IO_MAX_STR_SIZE];
    portBASE_TYPE IO_Mode;

    for (;;) {

        if( xMutexInOutModeAccess != NULL )
        {
            /* See if we can obtain the semaphore.  If the semaphore is not
            available wait xTimeout ticks to see if it becomes free. */
            if( xSemaphoreTake( xMutexInOutModeAccess, 0 ) == pdTRUE )
            {
                /* We were able to obtain the semaphore and can now access the
                shared resource. */

                IO_Mode = current_IO_Mode;

                /* We have finished accessing the shared resource.  Release the
                semaphore. */
                xSemaphoreGive( xMutexInOutModeAccess );
            }
            else
            {
                /* We could not obtain the semaphore and can therefore not access
                the shared resource safely. */
            }
        }

        switch (IO_Mode) {
            case INTERNAL_IO_MODE:
                // do something useful
                // here
                break;
            case UART_IO_MODE:
                uartGetS(strInMsg);
                break;
            case TELNET_IO_MODE:
                // do something useful
                // here
                break;
            case HTML_IO_MODE:
                // do something useful
                // here
                break;
        }

        xQueueSend( xQueueInBuffer, &strInMsg, 0 );

    }

}

void genericOutputTask(void *pvParameters) {

    char strOutMsg[IO_MAX_STR_SIZE];
    const portTickType xTimeout = IO_TIMEOUT;
    portBASE_TYPE IO_Mode;

    for (;;) {

        if( xMutexInOutModeAccess != NULL )
        {
            /* See if we can obtain the semaphore.  If the semaphore is not
            available wait xTimeout ticks to see if it becomes free. */
            if( xSemaphoreTake( xMutexInOutModeAccess, 0 ) == pdTRUE )
            {
                /* We were able to obtain the semaphore and can now access the
                shared resource. */

                IO_Mode = current_IO_Mode;

                /* We have finished accessing the shared resource.  Release the
                semaphore. */
                xSemaphoreGive( xMutexInOutModeAccess );
            }
            else
            {
                /* We could not obtain the semaphore and can therefore not access
                the shared resource safely. */
            }
        }

        if (xQueueReceive(xQueueOutBuffer, &strOutMsg, xTimeout) == pdTRUE)
        {
            switch (IO_Mode)
            {
                case INTERNAL_IO_MODE:
                    // do something useful
                    // here
                    break;
                case UART_IO_MODE:
                    uartPutS(strOutMsg);
                    break;
                case TELNET_IO_MODE:
                    // do something useful
                    // here
                    break;
                case HTML_IO_MODE:
                    // do something useful
                    // here
                    break;
            }
        }

    }

}

void sensorTask(void *pvParameters) {

    float tempStream;

    portTickType xLastWakeTime;
    const portTickType xFrequency = TEMP_SAMPLING_PERIOD;

    // Initialize the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    for(;;)
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );

        // Perform action here.
        tempStream = adc2temp(adcRead());

        xQueueSend(xQueueTempStream, &tempStream, 0);

        tempBufferPush(tempStream);
    }

}

void consoleTask(void *pvParameters) {

    xCommandHandle user_command;

    consoleInit();

    for(;;) {

        serverprintf("freertos:~# ");
        // cursor save
        serverSendEscCommand("[s");
        // interprete
        user_command = consoleReadCommand();
        // reply
        consoleReply(user_command);

    }

}

void ledUpdateTask(void *pvParameters) {

    ledConfig();

    for(;;) {
        updateLED();
        vTaskDelay(LED_BLINK_PERIOD);
    }

}

#ifdef __SERVER__DEBUG__
void debugTask(void *pvParameters) {

    for(;;) {

    }

}
#endif

/**
* @fn void vApplicationIdleHook( void )
* @brief function called by idle task
*/
void vApplicationIdleHook(void) {
    PowerSaveIdle();
    // PowerSaveSleep();
}
