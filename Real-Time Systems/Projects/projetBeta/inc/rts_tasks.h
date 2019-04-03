/**
 * @file     rts_tasks.h
 * @brief    header for user tasks and kernel config source
 * @author   OUASSARNI Fahd
 * @date
 */

#ifndef __HEADER_USER_TASKS__
#define __HEADER_USER_TASKS__

/* INCLUDES DEPENDENCIES ***************/
#include "rts_common.h"

#include "tsk_time.h"
#include "tsk_network.h"
#include "tsk_sensor.h"
#include "tsk_io.h"
#include "tsk_console.h"
#include "tsk_led.h"

/* PUBLIC DECLARATIONS ***************/

/**
 * @fn void kernelConfig(void)
 * @brief kernel configuration for no hardware dependencies
 */
void kernelConfig(void);

/**
* @fn void timeTask( void *pvParameters )
* @brief real time calendar task
*/
void timeTask(void *pvParameters);

/**
* @fn void networkTask( void *pvParameters )
* @brief network management task
*/
void networkTask(void *pvParameters);

/**
* @fn void displayUpdateTask( void *pvParameters )
* @brief display management task
*/
void displayUpdateTask(void *pvParameters);

/**
* @fn void keyEventTask( void *pvParameters )
* @brief key events handling task
*/
void keyEventTask(void *pvParameters);

/**
* @fn void genericInputTask( void *pvParameters )
* @brief input handling task
*/
void genericInputTask(void *pvParameters);

/**
* @fn void genericOutputTask( void *pvParameters )
* @brief output handling task
*/
void genericOutputTask(void *pvParameters);

/**
* @fn void sensorTask( void *pvParameters )
* @brief temperature acquisition task
*/
void sensorTask(void *pvParameters);

/**
* @fn void consoleTask( void *pvParameters )
* @brief console handling task
*/
void consoleTask(void *pvParameters);

/**
* @fn void displayUpdateTask( void *pvParameters )
* @brief display hangling task
*/
void displayUpdateTask(void *pvParameters);

/**
* @fn void ledUpdateTask( void *pvParameters )
* @brief led hangling task
*/
void ledUpdateTask(void *pvParameters);

#ifdef __SERVER__DEBUG__
/**
* @fn void debugTask( void *pvParameters )
* @brief debug helper task
*/
void debugTask(void *pvParameters);
#endif

#endif /* end of include guard: __HEADER_USER_TASKS__ */
