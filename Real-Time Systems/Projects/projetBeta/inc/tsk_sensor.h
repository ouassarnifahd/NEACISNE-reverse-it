/**
 * @file     tsk_sensor.h
 * @brief    header for adc based temperature sensor task
 * @author   OUASSARNI Fahd
 * @date
 */
#ifndef __HEADER_SENSOR_TASK__
#define __HEADER_SENSOR_TASK__

#include "rts_common.h"

#include <adc.h>

#define TEMP_SAMPLING_PERIOD 20
#define TEMP_BUFFER_SIZE 100
// A 100 * 20 Temp Samples. 2 sec of temp buffer data

#define ADC_NUM_BITS 10
// max adc value = 2^ADC_NUM_BITS - 1
#define MAX_ADC_VALUE ((1ull << ADC_NUM_BITS) - 1)

// temp when adc = MAX_ADC_VALUE
#define MAX_TEMP 230
// temp when adc = 0
#define MIN_TEMP -40

// extern xQueueHandle xQueueTempStream;

extern float tempBuffer[TEMP_BUFFER_SIZE];
extern portBASE_TYPE bufferIterator;

extern xSemaphoreHandle xMutexTempBufferAccess;

// void xQueueTempStreamConfig(void);

void xMutexTempBufferConfig(void);

void tempBufferPush(float tempValue);

float tempBufferPeek(portTickType peekTimeout);

float adc2temp(int adcValue);

#endif /* end of include guard: __HEADER_SENSOR_TASK__ */
