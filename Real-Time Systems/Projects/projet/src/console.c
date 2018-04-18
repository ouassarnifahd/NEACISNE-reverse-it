/**
 * @file     console.c
 * @brief    uart based console task source
 * @author   OUASSARNI Fahd
 * @date
 */

#include "console.h"
#include <FreeRTOS.h>
#include <task.h>
#include <string.h>

// TODO time + sync with sntp

#define DUMP_STATS
#define MAX_TEMP 230
#define MIN_TEMP -40

const char *builtincommands[BUILTIN_COMMANDS_NUMBER] = {
    "read", "dump", "stream", "reset", "baudrate", "help"
};

const char helpMSG[] =
    // "Builtin commands\r\n"
    // "Temperature Sensor commands:\r\n"
    "read      return last converted value\r\n"
    "dump      return hundred last converted values\r\n"
    "stream    return last converted value and update display\r\n"
    "          press ENTER to quit stream mode\r\n"
    // "\r\nNetwork Access Commands:\r\n"
    // "telnet    starts new session using telnet\r\n"
    // "          use endTelnet command to close the session\r\n"
    // "startHTTP start http server, show real time temperature graph\r\n"
    // "          use stopHTTP command to shutdown the server\r\n"
    // "getTime   returns time from internet using sntp protocol\r\n"
    // "\r\nConsole commands:\r\n"
    // "clear     clear screen command\r\n"
    "reset     software processor reset\r\n"
    "baudrate  update serial communication baudrate of processor\r\n"
    "help      return supported commands\r\n"
;

static void serverRead(void) {
    float tempValue;
    xQueueReceive(xQueueTempStream, &tempValue, 0);
    uartprintf("%2.1f°C\r\n", tempValue);
    return ;
}

static void serverDump(void) {
    float tempValue;
    int i, cpt;
    const portTickType xTimeout = 20;
    #ifdef DUMP_STATS
    float tempMoy = 0, tempMoyPow2 = 0, tempVar = 0;
    float tempMax = MIN_TEMP, tempMin = MAX_TEMP;
    #endif

    if( xMutexTempBufferAccess != NULL )
    {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait xTimeout ticks to see if it becomes free. */
        if( xSemaphoreTake( xMutexTempBufferAccess, xTimeout ) == pdTRUE )
        {
            /* We were able to obtain the semaphore and can now access the
            shared resource. */

            i = bufferIterator;
            for (cpt = 1; cpt <= MAX_SIZE_BUFFER; cpt++) {
                tempValue = tempBuffer[i];
                uartprintf("%2.1f°C   %d", tempValue, cpt);
                if (cpt == 1) uartprintf(" (Current)");
                uartprintf("\r\n");
                i  = (i != MAX_SIZE_BUFFER) ? i + 1 : 0;
                #ifdef DUMP_STATS
                tempMoy += tempValue;
                tempMoyPow2 += tempValue * tempValue;
                if (tempMax < tempValue) tempMax = tempValue;
                if (tempMin > tempValue) tempMin = tempValue;
                #endif
            }

            #ifdef DUMP_STATS
            tempMoy = tempMoy/(float)MAX_SIZE_BUFFER;
            tempMoyPow2 = tempMoyPow2/(float)MAX_SIZE_BUFFER;
            tempVar = tempMoyPow2 - tempMoy * tempMoy;
            uartprintf("\r\nDump stats: Tmax %2.1f°C Tmin %2.1f°C Tmoy %2.1f°C Tvar %2.1f°C\r\n", tempMax, tempMin, tempMoy, tempVar);
            #endif

            /* We have finished accessing the shared resource.  Release the
            semaphore. */
            xSemaphoreGive( xMutexTempBufferAccess );
        }
        else
        {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }

    return ;
}

static void serverStream(void) {
    float tempValue;
    uartprintf("freertos:~# ");
    while (uartGetC() != KEY_CR) {
        // xQueueReceive(xQueueTempStream, &tempValue, CONSOLE_TIMEOUT);
        tempValue = tempBuffer[bufferIterator];
        // Cursor restore
        uartSendEscCommand("[u");
        // Erasing to the end of line
        uartSendEscCommand("[K");
        // Cursor save
        uartSendEscCommand("[s");
        // Write temp stream
        uartprintf("%2.1f°C", tempValue);
    }
    uartprintf("\r\n");
}

static void serverReset(void) {
    vTaskDelay(20);
    SoftReset();
}

static void updateBaudrate(void) {
    unsigned int user_baudrate = UART_BPS;
    char valueBuffer[UART_MAX_STR_SIZE];
    uartprintf("Enter new baudrate\r\n");
    // uartscanf("%u", &user_baudrate); // why this doesn't work?
    uartGetS(valueBuffer);
    sscanf(valueBuffer, "%u", &user_baudrate);
    uartprintf("Baudrate value updated to %u\r\n", user_baudrate);
    uartprintf("Try a new serial connection using the new baudrate.\r\n");
    // TODO reset remote tty (for now seng SIGKILL)
    uartPutC(KEY_ETX);
    UARTSetDataRate(UART1, SYS_FREQ/PB_DIV, user_baudrate);
}

static void serverHelp(void) {
    uartPutS((char *)helpMSG);
}

static void (*builtinfunctions[BUILTIN_COMMANDS_NUMBER])(void) = {
    &serverRead, &serverDump, &serverStream, &serverReset,
    &updateBaudrate, &serverHelp
};

void consoleInit(void) {
    // tty Config: http://www.termsys.demon.co.uk/vtansi.htm
    // clear screen
    uartSendEscCommand("[2J");
    // enable scrolling
    uartSendEscCommand("[r");
    // reset all attributes
    uartSendEscCommand("[0m");
    // Hello World MSG
    uartprintf("freertos:~# Hello World\r\n");
}

int consoleReadCommand(void) {
    int id;
    char command[UART_MAX_STR_SIZE];
    uartGetS(command);
    for (id = 0; id < BUILTIN_COMMANDS_NUMBER; id++) {
        if (!strcmp(command, builtincommands[id])) {
            return id;
        }
    }
    if (!strcmp(command, "")) {
        return -1;
    } else {
        return -2;
    }
}

void consoleReply(int command) {
    void (*fcommand)(void);
    if(command >= 0) {
        fcommand = *builtinfunctions[command];
        fcommand();
    } else if (command != -1) {
        uartprintf("command not found!\r\n");
    }
}
