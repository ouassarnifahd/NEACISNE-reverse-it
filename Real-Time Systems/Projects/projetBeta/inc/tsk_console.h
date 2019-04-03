/**
 * @file     tsk_console.h
 * @brief    header for console task
 * @author   OUASSARNI Fahd
 * @date
 */

#ifndef __HEADER_CONSOLE_TASK__
#define __HEADER_CONSOLE_TASK__

#include "rts_common.h"

#include "tsk_io.h"
#include "tsk_sensor.h"

#define BUILTIN_COMMANDS_NUMBER 6

#define STREAM_WAIT_PERIOD 20

typedef struct CommandHandle * xCommandHandle;

void consoleInit(void);

xCommandHandle consoleReadCommand(void);

void consoleReply(xCommandHandle user_command);

#endif /* end of include guard: __HEADER_CONSOLE_TASK__ */
