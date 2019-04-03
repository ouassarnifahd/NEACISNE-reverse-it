/**
 * @file     tsk_console.c
 * @brief    console task source
 * @author   OUASSARNI Fahd
 * @date
 */

#include "tsk_console.h"

// TODO time + sync with sntp

#define DUMP_STATS

struct CommandHandle {
    int id;
    int parameter;
    void* pvParameter;
} emptyCommandHandle = { -1, -1, NULL };

const char *builtincommands[BUILTIN_COMMANDS_NUMBER][2] = {
    { "read", "      return last converted value\r\n"                       },
    { "dump", "      return hundred last converted values\r\n"              },
    { "stream", "    return last converted value and update display\r\n"
                "          press ENTER to quit stream mode\r\n"             },
    { "reset", "     software processor reset\r\n"                          },
    { "baudrate", "  update serial communication baudrate of processor\r\n" },
    { "help", "      return supported commands\r\n"                         }
};

// const char helpMSG[] =
    // "Builtin commands\r\n"
    // "Temperature Sensor commands:\r\n"
    // "read      return last converted value\r\n"
    // "dump      return hundred last converted values\r\n"
    // "stream    return last converted value and update display\r\n"
    // "          press ENTER to quit stream mode\r\n"
    // "\r\nNetwork Access Commands:\r\n"
    // "telnet    starts new session using telnet\r\n"
    // "          use endTelnet command to close the session\r\n"
    // "startHTTP start http server, show real time temperature graph\r\n"
    // "          use stopHTTP command to shutdown the server\r\n"
    // "getTime   returns time from internet using sntp protocol\r\n"
    // "\r\nConsole commands:\r\n"
    // "clear     clear screen command\r\n"
    // "reset     software processor reset\r\n"
    // "baudrate  update serial communication baudrate of processor\r\n"
    // "help      return supported commands\r\n"
// ;

static void server_read(void* parameters) {
    float tempValue;
    xQueueReceive(xQueueTempStream, &tempValue, 0);
    serverprintf("%2.1f°C\r\n", tempValue);
}

static void server_dump(void* parameters) {
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
            for (cpt = 1; cpt <= TEMP_BUFFER_SIZE; cpt++) {
                tempValue = tempBuffer[i];
                serverprintf("%2.1f°C   %d", tempValue, cpt);
                if (cpt == 1) serverprintf(" (Current)");
                serverprintf("\r\n");
                i  = (i != TEMP_BUFFER_SIZE) ? i + 1 : 0;
                #ifdef DUMP_STATS
                tempMoy += tempValue;
                tempMoyPow2 += tempValue * tempValue;
                if (tempMax < tempValue) tempMax = tempValue;
                if (tempMin > tempValue) tempMin = tempValue;
                #endif
            }

            #ifdef DUMP_STATS
            tempMoy = tempMoy/(float)TEMP_BUFFER_SIZE;
            tempMoyPow2 = tempMoyPow2/(float)TEMP_BUFFER_SIZE;
            tempVar = tempMoyPow2 - tempMoy * tempMoy;
            serverprintf("\r\nDump stats:"
                    " Tmax %2.1f°C Tmin %2.1f°C Tmoy %2.1f°C Tvar %2.1f°C\r\n",
                    tempMax, tempMin, tempMoy, tempVar);
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

}

static void server_stream(void* parameters) {
    float tempValue;
    serverprintf("freertos:~# ");
    // Cursor save
    serverSendEscCommand("[s");
    while (uartGetC() != KEY_CR) {
        xQueueReceive(xQueueTempStream, &tempValue, STREAM_WAIT_PERIOD);
        // Cursor restore
        serverSendEscCommand("[u");
        // Erasing to the end of line
        serverSendEscCommand("[K");
        // Cursor save
        serverSendEscCommand("[s");
        // Write temp stream
        serverprintf("%2.1f°C", tempValue);
    }
    serverprintf("\r\n");
}

static void server_reset(void* parameters) {
    // vTaskDelay(20);
    SoftReset();
}

static void server_baudrate(void* parameters) {
    unsigned int user_baudrate = UART_BPS;
    char valueBuffer[IO_MAX_STR_SIZE];
    serverprintf("Enter new baudrate\r\n");
    // uartscanf("%u", &user_baudrate); // why this doesn't work?
    uartGetS(valueBuffer);
    sscanf(valueBuffer, "%u", &user_baudrate);
    serverprintf("Baudrate value updated to %u\r\n", user_baudrate);
    serverprintf("Try a new serial connection using the new baudrate.\r\n");
    vTaskDelay(20);
    // TODO reset remote tty (for now send SIGKILL)
    // uartPutC(KEY_ETX);
    UARTSetDataRate(UART1, SYS_FREQ/PB_DIV, user_baudrate);
}

static void server_help(void* parameters) {
    int i, id;
    if (parameters) {
        id = * (int *)parameters;
        if (0 <= id && id < BUILTIN_COMMANDS_NUMBER) {
            // serverPutS(HELP_COMMAND_MSG(id));
            serverPutS(builtincommands[id][0]);
            serverPutS(builtincommands[id][1]);
        } else {
            serverprintf("help: command not found!\r\n"
                         "Supported commands:\r\n");
            for (i = 0; i < BUILTIN_COMMANDS_NUMBER; i++) {
                // serverPutS(HELP_COMMAND_MSG(id));
                serverPutS(builtincommands[i][0]);
                serverPutS(builtincommands[i][1]);
            }
        }
    } else {
        for (i = 0; i < BUILTIN_COMMANDS_NUMBER; i++) {
            // serverPutS(HELP_COMMAND_MSG(id));
            serverPutS(builtincommands[i][0]);
            serverPutS(builtincommands[i][1]);
        }
    }
    // serverPutS((char *)helpMSG);
}

// Preprocessor expantions: open use_preprocessor.h to see the trick
static void (*builtinfunctions[BUILTIN_COMMANDS_NUMBER])(void*) = {
    // M(EVAL(WHILE(PRED, OP, builtincommands, BUILTIN_COMMANDS_NUMBER)))
    &server_read, &server_dump, &server_stream, &server_reset,
    &server_baudrate, &server_help
};

void consoleInit(void) {
    // tty Config: http://www.termsys.demon.co.uk/vtansi.htm
    // clear screen
    serverSendEscCommand("[2J");
    // enable scrolling
    serverSendEscCommand("[r");
    // reset all attributes
    serverSendEscCommand("[0m");
    // Hello World MSG
    serverprintf("freertos:~# Hello World\r\n");
    // serverprintf(M(EVAL(WHILE(PRED, OP, builtincommands, BUILTIN_COMMANDS_NUMBER))))
}

xCommandHandle consoleReadCommand(void) {
    xCommandHandle user_command = &emptyCommandHandle;
    char command[IO_MAX_STR_SIZE];
    char* argument;
    int id = 0, len_help = 4, id_help = BUILTIN_COMMANDS_NUMBER - 1;

    // get user input command
    serverGetS(command);

    // if do simple tests
    for (id = 0; id < BUILTIN_COMMANDS_NUMBER; id++) {
        if (!strncmp(command, builtincommands[id][0], strlen(command))) {
            user_command->id = id;
            user_command->parameter = -1;
            user_command->pvParameter = NULL;
            return user_command;
        }
    }

    // else test if help <command> is used
    if (!strncmp(command, builtincommands[id_help][0], len_help)) {
        user_command->id = id_help;
        if (command[len_help] == ' ') {
            argument = command + len_help; // TODO try it!
            for (id = 0; id < BUILTIN_COMMANDS_NUMBER; id++) {
                if (!strncmp(argument, builtincommands[id][0],
                    strlen(argument))) {
                    user_command->parameter = id;
                    user_command->pvParameter = &user_command->parameter;
                    return user_command;
                }
            }
        }
        user_command->parameter = -2;
        user_command->pvParameter = NULL;
        return user_command;
    }

    // if KEY_CR do nothing else command not found!
    if (!strcmp(command, "")) {
        user_command->id = -1;
        user_command->parameter = -1;
        user_command->pvParameter = NULL;
    } else {
        user_command->id = -2;
        user_command->parameter = -2;
        user_command->pvParameter = NULL;
    }
    return user_command;
}

void consoleReply(xCommandHandle command) {
    void (*fcommand)(void*);
    if(command >= 0) {
        fcommand = *builtinfunctions[command->id];
        fcommand(command->pvParameter);
    } else if (command->id != -1) {
        serverprintf("command not found!\r\n");
    }
}
