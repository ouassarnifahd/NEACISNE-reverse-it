/**
* @file     utask.c
* @brief    user tasks and kernel config source
* @author   OUASSARNI Fahd
* @date     29 Jan 2018
*/

/* INCLUDES DEPENDENCIES ***************/
#include <utask.h>
/* include all headers dependencies into utask.h file */

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

   xTaskCreate(task1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
   xTaskCreate(task2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
   xTaskCreate(task3, "Task 3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

   // Use the handle to delete the task.
   // vTaskDelete(xHandle);
 }

/**
* @fn  void task1(void *pvParameters)
* @brief follow practical work
*/
void task1(void *pvParameters){

    while(1){
		uartPutS("\r\nTask1\r\n");

        // Wait a few 100ms
        int i;
        for (i = 0; i < 4000; i++);
        taskYIELD();
    }
}

/**
* @fn  void task2(void *pvParameters)
* @brief follow practical work
*/
void task2(void *pvParameters){

    while(1){
        uartPutS("\r\nTask2\r\n");

        // Wait a few 100ms
        int i;
        for (i = 0; i < 4000; i++);
        taskYIELD();
    }
}

/**
* @fn  void task3(void *pvParameters)
* @brief follow practical work
*/
void task3(void *pvParameters){

    while(1){
        uartPutS("\r\nTask3\r\n");

        // Wait a few 100ms
        int i;
        for (i = 0; i < 4000; i++);
        taskYIELD();
    }
}
