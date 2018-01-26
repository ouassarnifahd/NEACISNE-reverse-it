/*
    FreeRTOS V7.5.2 - Copyright (C) 2013 Real Time Engineers Ltd.

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that has become a de facto standard.             *
     *                                                                       *
     *    Help yourself get started quickly and support the FreeRTOS         *
     *    project by purchasing a FreeRTOS tutorial book, reference          *
     *    manual, or both from: http://www.FreeRTOS.org/Documentation        *
     *                                                                       *
     *    Thank you!                                                         *
     *                                                                       *
    ***************************************************************************

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

    >>! NOTE: The modification to the GPL is included to allow you to distribute
    >>! a combined work that includes FreeRTOS without being obliged to provide
    >>! the source code for proprietary components outside of the FreeRTOS
    >>! kernel.

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available from the following
    link: http://www.freertos.org/a00114.html

    1 tab == 4 spaces!

    ***************************************************************************
     *                                                                       *
     *    Having a problem?  Start by reading the FAQ "My application does   *
     *    not run, what could be wrong?"                                     *
     *                                                                       *
     *    http://www.FreeRTOS.org/FAQHelp.html                               *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org - Documentation, books, training, latest versions,
    license and Real Time Engineers Ltd. contact details.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.OpenRTOS.com - Real Time Engineers ltd license FreeRTOS to High
    Integrity Systems to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <p32xxxx.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION							0
// hardware optimisation depend of MCU architecture
#define configUSE_PORT_OPTIMISED_TASK_SELECTION         1
#define configUSE_IDLE_HOOK								0
#define configUSE_TICK_HOOK								0
// TODO port.c modification
#define configTICK_RATE_HZ								( ( portTickType ) 1000 )
#define configCPU_CLOCK_HZ								( 80000000UL )
#define configPERIPHERAL_CLOCK_HZ						( 80000000UL )
#define configMAX_PRIORITIES							( 5UL )
#define configMINIMAL_STACK_SIZE						( 400 )
#define configISR_STACK_SIZE							( 1000 )
#define configTOTAL_HEAP_SIZE							( ( size_t ) 28000 )
#define configMAX_TASK_NAME_LEN							( 8 )
#define configUSE_TRACE_FACILITY						0
#define configUSE_16_BIT_TICKS							0
#define configIDLE_SHOULD_YIELD							0
#define configUSE_MUTEXES               				0
#define configCHECK_FOR_STACK_OVERFLOW     				0
#define configQUEUE_REGISTRY_SIZE						0
#define configUSE_RECURSIVE_MUTEXES						0
#define configUSE_MALLOC_FAILED_HOOK                	0
#define configUSE_APPLICATION_TASK_TAG           		0
#define configUSE_COUNTING_SEMAPHORES              		0
#define configGENERATE_RUN_TIME_STATS              		0

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES         					0
#define configMAX_CO_ROUTINE_PRIORITIES       			( 2 )

/* Software timer definitions. */
#define configUSE_TIMERS                         		0
#define configTIMER_TASK_PRIORITY     					( 2 )
#define configTIMER_QUEUE_LENGTH            			5
#define configTIMER_TASK_STACK_DEPTH            		( configMINIMAL_STACK_SIZE * 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet             			0
#define INCLUDE_uxTaskPriorityGet          				0
#define INCLUDE_vTaskDelete								0
#define INCLUDE_vTaskCleanUpResources  					0
#define INCLUDE_vTaskSuspend          					0
#define INCLUDE_vTaskDelayUntil            				0
#define INCLUDE_vTaskDelay								0
#define INCLUDE_uxTaskGetStackHighWaterMark  			0

/* Prevent C specific syntax being included in assembly files. */
#ifndef __LANGUAGE_ASSEMBLY
	void vAssertCalled( const char *pcFileName, unsigned long ulLine );
	#define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )
#endif

/* The priority at which the tick interrupt runs.  This should probably be
kept at 1. */
#define configKERNEL_INTERRUPT_PRIORITY					0x01

/* The maximum interrupt priority from which FreeRTOS.org API functions can
be called.  Only API functions that end in ...FromISR() can be used within
interrupts. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY   			0x05


#endif /* FREERTOS_CONFIG_H */
