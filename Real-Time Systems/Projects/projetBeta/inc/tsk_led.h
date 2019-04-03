/**
 * @file     tsk_led.h
 * @brief    header for led handling task
 * @author   OUASSARNI Fahd
 * @date
 */

#ifndef __HEADER_LED_TASK__
#define __HEADER_LED_TASK__

#include "rts_common.h"

#include "tsk_sensor.h"

#define LED_BLINK_TEMP      38
#define LED_BLINK_PERIOD    500

void ledConfig(void);

void updateLED(void);

#endif /* end of include guard: __HEADER_LED_TASK__ */
