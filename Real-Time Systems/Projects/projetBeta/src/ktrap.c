/**
* @file     ktrap.c
* @brief    kernel traps capture like stack overflow, malloc failed and kernel
* or user assertions
* @author
* @date
*/

/* INCLUDES DEPENDENCIES ***************/
#include <rts_tasks.h>
/* include all headers dependencies into rts_tasks.h file */

/**
* @fn void vApplicationStackOverflowHook( xTaskHandle xTask, signed char *pcTaskName );
* @brief kernel hook here if stack overflow detection
*/
void vApplicationStackOverflowHook( xTaskHandle xTask, signed char *pcTaskName ){
   uartPutS("error stack overflow by ");
   uartPutS(pcTaskName);
   uartPutS("    \r\n");

   // vTaskEndScheduler();
   // SoftReset();
   // S#!t, it's a trap!
   while(1);
}

/**
* @fn vApplicationMallocFailedHook()
* @brief kernel hook here if malloc allocation failed detection
*/
void vApplicationMallocFailedHook( void ){
   uartPutS("error malloc failed    \r\n");

   // vTaskEndScheduler();
   // SoftReset();
   // S#!t, it was a trap!
   while(1);
}

/**
* @fn void vAssertCalled( const char *pcFileName, unsigned long ulLine )
* @brief kernel hook here if user or kernel assertion detection
*/
void vAssertCalled( const char *pcFileName, unsigned long ulLine ){
    uartPutS("error application or kernel assertion\r\n");
    uartprintf("file: %s  line: %u\r\n", pcFileName, ulLine);

    // vTaskEndScheduler();
    // SoftReset();
    // S#!t, it's a trap!
    while(1);
}
