/**
 * @file     tsk_io.h
 * @brief    header for input/output handling task
 * @author   OUASSARNI Fahd
 * @date
 */

#ifndef __HEADER_IN_OUT_TASK__
#define __HEADER_IN_OUT_TASK__

#include "rts_common.h"

#define configDEFAULT_IO_MODE   UART_IO_MODE

#define IO_TIMEOUT              20
#define IO_MAX_STR_SIZE         64
#define IO_BUFFER_SIZE          10
// fastest — Display and boutons
#define INTERNAL_IO_MODE   (1ull << 0)
// #include <.h>

// faster — uart serial communication
#define UART_IO_MODE       (1ull << 1)
#include <kuart.h>

// fast — TCP ethernet communication
#define TELNET_IO_MODE     (1ull << 2)
// #include <.h>

// slow HTML GET/POST communication
// TODO Graphical data display on browser using javascript ...
#define HTML_IO_MODE       (1ull << 3)
// #include <.h>

extern portBASE_TYPE current_IO_Mode;
extern xSemaphoreHandle xMutexInOutModeAccess;
extern xSemaphoreHandle xMutexInEvent;

extern xQueueHandle xQueueInBuffer;
extern xQueueHandle xQueueOutBuffer;

void serverInOutConfig(void);

void serverEventsConfig(void);

void severGenericSend(const char* str, portBASE_TYPE isCommand);

#define serverPutS(MSG) severGenericSend(MSG, pdFALSE)

#define serverPutEscCommand(command) severGenericSend(MSG, pdTRUE)

void serverGetS(char* str);

char serverGetEvent(void);

// #define serverPutEscCommand(command) {                \
//     char EscCommand[10], i;                           \
//     EscCommand[0] = KEY_ESC;                          \
//     for (i = 0; command[i] != KEY_NULL; i++)          \
//         EscCommand[i + 1] = command[i];               \
//     EscCommand[i + 1] = KEY_NULL;                     \
//     serverPutS(EscCommand);                           \
// }

#define serverprintf(MSG, ...) { \
    char serverPrintfBuffer[IO_MAX_STR_SIZE]; \
    sprintf(serverPrintfBuffer, MSG, ##__VA_ARGS__); \
    serverPutS(serverPrintfBuffer); \
}

#define serverscanf(MSG, ...) { \
    char serverScanfBuffer[IO_MAX_STR_SIZE]; \
    serverGetS(serverScanfBuffer); \
    sscanf(serverScanfBuffer, MSG, ##__VA_ARGS__); \
}

#endif /* end of include guard: __HEADER_IN_OUT_TASK__ */
