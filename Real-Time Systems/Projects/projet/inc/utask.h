/**
 * @file     utask.h
 * @brief    header for user tasks and kernel config source
 * @author   OUASSARNI Fahd
 * @date
 */

#ifndef __HEADER_USER_TASKS__
#define __HEADER_USER_TASKS__

/* INCLUDES DEPENDENCIES ***************/
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "temperature.h"
#include "console.h"
#include "led.h"
/* PUBLIC DECLARATIONS ***************/

/**
 * @fn void kernelConfig(void)
 * @brief kernel configuration for no hardware dependencies
 */
void kernelConfig(void);

/**
* @fn void consoleTask( void )
* @brief console handling task
*/
void consoleTask(void *pvParameters);

/**
* @fn void sensorTask( void )
* @brief temperature acquisition task
*/
void sensorTask(void *pvParameters);

/**
* @fn void ledUpdateTask( void *pvParameters )
* @brief led hangling task
*/
void ledUpdateTask(void *pvParameters);

#endif
