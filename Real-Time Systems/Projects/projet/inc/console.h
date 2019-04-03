/**
 * @file     console.h
 * @brief    header for uart based console task
 * @author   OUASSARNI Fahd
 * @date
 */

#ifndef __HEADER_CONSOLE_TASK__
#define __HEADER_CONSOLE_TASK__

#include <kuart.h>
#include "temperature.h"

// Uart history.
// this is a beta feature. Put the following line in kuart.h to use it.
// #define configUSE_UART_HISTORY 1

#define BUILTIN_COMMANDS_NUMBER 6

#define CONSOLE_TIMEOUT 20

void consoleInit(void);

int consoleReadCommand(void);

void consoleReply(int command);

#endif /* end of include guard: __HEADER_CONSOLE_TASK__ */
