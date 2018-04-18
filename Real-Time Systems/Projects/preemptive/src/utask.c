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
#define SLOW_TIME 1


/**
* @fn void kernelConfig(void)
* @brief kernel configuration
*/
void kernelConfig(void){
   // tasks et system tools configurations
   // static unsigned char ucParameterToPass;
   // xTaskHandle xHandle;

   // Create the task, storing the handle.  Note that the passed parameter ucParameterToPass
   // must exist for the lifetime of the task, so in this case is declared static.  If it was just an
   // an automatic stack variable it might no longer exist, or at least have been corrupted, by the time
   // the new task attempts to access it.
   // xTaskCreate( vTaskCode, "NAME", STACK_SIZE, &ucParameterToPass, tskIDLE_PRIORITY, &xHandle );


   xTaskCreate(task1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
   xTaskCreate(task2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
   xTaskCreate(task3, "Task 3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

   // Use the handle to delete the task.
   // vTaskDelete(xHandle);
 }

/**
* @fn  void task1(void *pvParameters)
* @brief follow practical work
*/
void task1(void *pvParameters){

    char str[15];

    while(1){
        uartPutS("\r\ntask1 Prio, current tick value ");
        sprintf(str,"%d",xTaskGetTickCount());
        uartPutS(str);
        uartPutS("\r\n");

        // Wait 3s (3000)
        vTaskDelay(3000 / SLOW_TIME);
        // Grow Stack!!
        // task1(NULL);
    }
}

/**
* @fn  void task2(void *pvParameters)
* @brief follow practical work
*/
void task2(void *pvParameters){

    portTickType xLastWakeTime;
    const portTickType xFrequency = 1000 / SLOW_TIME;

    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    while(1){
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );

        // Perform action here.
        uartPutS("\r\ntask2\r\n");

        // // Wait 1s (1000)
        // vTaskDelay(1000);
    }
}

/**
* @fn  void task3(void *pvParameters)
* @brief follow practical work
*/
void task3(void *pvParameters){

    portTickType xLastWakeTime;
    const portTickType xFrequency = 1000 / SLOW_TIME;

    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    while(1){
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );

        // Perform action here.
        uartPutS("\r\ntask3\r\n");

        // // Wait 1s (1000)
        // vTaskDelay(1000);

        // Grow stack!!
        // task3(NULL);
    }
}
