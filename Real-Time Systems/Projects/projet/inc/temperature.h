/**
 * @file     temperature.h
 * @brief    header for adc based temperature reading task
 * @author   OUASSARNI Fahd
 * @date
 */
#ifndef __HEADER_TEMPERATURE_TASK__
#define __HEADER_TEMPERATURE_TASK__

#include <adc.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <queue.h>

#define MAX_SIZE_BUFFER 100

extern xQueueHandle xQueueTempStream;
extern float tempBuffer[MAX_SIZE_BUFFER];
extern portBASE_TYPE bufferIterator;

extern xSemaphoreHandle xMutexTempBufferAccess;

void xQueueTempStreamConfig(void);

void xMutexTempBufferConfig(void);

float adc2temp(int adcValue);

#endif /* end of include guard: __HEADER_TEMPERATURE_TASK__ */
