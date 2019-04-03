/**
 * @file     utask.h
 * @brief    header for user tasks and kernel config source
 * @author
 * @date
 */

#ifndef   __HEADER_USER_TASK__
#define   __HEADER_USER_TASK__

/* INCLUDES DEPENDENCIES ***************/
#include <kuart.h>
#include <adc.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

/* PUBLIC DECLARATIONS ***************/

/**
 * @fn void kernelConfig(void)
 * @brief kernel configuration for no hardware dependencies
 */
void kernelConfig(void);

/**
 * @fn  void task1(void *pvParameters)
 * @brief follow practical work
 */
void task1(void *pvParameters);

/**
 * @fn  void task2(void *pvParameters)
 * @brief follow practical work
 */
void task2(void *pvParameters);

/**
 * @fn  void task3(void *pvParameters)
 * @brief follow practical work
 */
void task3(void *pvParameters);

#endif
