/**
* @file     utask.c
* @brief    user tasks and kernel config source
* @author
* @date
*/

/* INCLUDES DEPENDENCIES ***************/
#include <utask.h>
/* include all headers dependencies into utask.h file */

// SIM_TIME
#define SLOW_TIME 100


xQueueHandle xQueue;
//portTickType idleCount;

/**
* @fn void kernelConfig(void)
* @brief kernel configuration
*/
void kernelConfig(void){

   xQueue = xQueueCreate( 1, sizeof( portTickType ) );

    if( xQueue == NULL )
    {
        /* Queue was not created and must not be used. */
        while(1);
    }

   xTaskCreate(task1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
   xTaskCreate(task2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
   xTaskCreate(task3, "Task 3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

 }

/**
* @fn  void task1(void *pvParameters)
* @brief follow practical work
*/
void task1(void *pvParameters){

    portTickType xLastWakeTime, xTickTimeUpdate;
    const portTickType xFrequency = 5000 / SLOW_TIME;

    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();
    xTickTimeUpdate = xLastWakeTime;

    while(1) {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );
        xTickTimeUpdate = xTickTimeUpdate;
        // Perform action here.
        uartPutS("\r\ntask1 Prio, message queue post for task2\r\n");

        if (xQueueSend(xQueue, &xTickTimeUpdate, 0) == pdTRUE ) {
            xTickTimeUpdate = xTaskGetTickCount();
        }
    }
}

/**
* @fn  void task2(void *pvParameters)
* @brief follow practical work
*/
void task2(void *pvParameters){

    portTickType xTickTimeQueue;
    const portTickType Timeout = 1000 / SLOW_TIME; // portMAX_DELAY;
    char sBuffer[20];

    while(1) {
        if( xQueueReceive(xQueue, &xTickTimeQueue, Timeout ) == pdTRUE ) {
            sprintf(sBuffer, "%u", xTickTimeQueue);
            taskENTER_CRITICAL();
            uartPutS("\r\ntask2, from task1 ");
            uartPutS(sBuffer) ;
            uartPutS("\r\n");
            taskEXIT_CRITICAL();
        } else {
            taskENTER_CRITICAL();
            uartPutS("\r\ntask2, timeout\r\n");
            taskEXIT_CRITICAL();
        }
    }
}

/**
* @fn  void task3(void *pvParameters)
* @brief follow practical work
*/
void task3(void *pvParameters){

    char sBuffer[20];

    while(1){

        // Perform action here.
        taskENTER_CRITICAL();
        uartPutS("\r\ntask3"); //, from idle ");
        //sprintf(sBuffer, "%u", idleCount);
        //uartPutS(sBuffer) ;
        uartPutS("\r\n");
        taskEXIT_CRITICAL();

        // Wait 1s (1000)
        vTaskDelay(1000 / SLOW_TIME);

        // Grow stack!!
        // task3(NULL);
    }
}

/**
* @fn void vApplicationIdleHook( void )
* @brief function called by idle task
*/
//void vApplicationIdleHook( void ) {
//    idleCount++;
//}
