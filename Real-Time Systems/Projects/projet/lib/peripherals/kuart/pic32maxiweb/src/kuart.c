/**
* file     uart.c
* brief    uart module library for pic32 mcu architecture
* and PIC32-MAXI-WEB board from Olimex
* author   hugo descoubes
* date     september 2014
*/

/* INCLUDES DEPENDENCIES ***************/
#include <kuart.h>

/* PRIVATE DECLARATIONS ***************/
xQueueHandle xQueueUartBuffer;
xSemaphoreHandle xMutexUartPutS;

// it should be a better way to do this!
int written_char = 0;
int cursor_char = 0;

// ARROWS EVENT
enum {
    ARROW_UP,
    ARROW_DOWN,
    ARROW_RIGHT,
    ARROW_LEFT,
    ARROW_NULL
} key_Event = ARROW_NULL;

#if configUSE_UART_HISTORY == 1

// command history
int history_current = 0;
int history_oldest  = 0;
int history_cursor  = 0;
char history_uartRx[UART_HISTORY_DEPTH][UART_MAX_STR_SIZE];
#endif

/**
* void __ISR(_UART_1_VECTOR, IPL2SOFT) IntUart1Handler(void)
*/
void __ISR(_UART_1_VECTOR, IPL2SOFT) IntUart1Handler(void) {

    portBASE_TYPE xHigherPriorityTaskWoken;
    char char_container;

    // check for data receiving
    if ( INTGetFlag(INT_SOURCE_UART_RX(UART1)) ) {

        // flush uart receiving buffer CRITICAL!!
        // portENTER_CRITICAL();
        char_container = UARTGetDataByte(UART1);
        // portEXIT_CRITICAL();

        // Queue new char from uart
        if(xQueueSendFromISR( xQueueUartBuffer, &char_container,
                              &xHigherPriorityTaskWoken )) {
            // clear uart receiving flag (always after uart buffer flushing)
            INTClearFlag(INT_SOURCE_UART_RX(UART1));
        }

        portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
    }
}

/**
 * void uartConfig(unsigned int baudrate)
 */
void uartConfig(void) {
    // Queue buffer initialization
    xQueueUartBuffer = xQueueCreate( UART_BUFFER_SIZE, sizeof( char ) );
    if( xQueueUartBuffer == NULL ) {
        /* Queue was not created and must not be used. */
        while(1);
    }

    // Mutex UartPutS init
    xMutexUartPutS = xSemaphoreCreateMutex();
    if( xMutexUartPutS == NULL ) {
        /* There was insufficient FreeRTOS heap available for the semaphore to
        be created successfully. */
        while(1);
    }

    // standard mode without hardware handshaking
    UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY);

    // serial frame configuration
    UARTSetLineControl(UART1,  UART_DATA_SIZE_8_BITS | \
                                UART_PARITY_NONE |      \
                                UART_STOP_BITS_1);

    // data rate configuration
    UARTSetDataRate(UART1, SYS_FREQ/PB_DIV, UART_BPS);

    // enable module
    UARTEnable(UART1,  UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

    // uart module interruption configuration
    INTClearFlag(INT_U1RX);
    INTEnable(INT_SOURCE_UART_RX(UART1), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART1), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART1), INT_SUB_PRIORITY_LEVEL_0);
}

/**
 * void interruptConfig(void)
 */
void interruptConfig(void) {
  // system interruption configuration
  INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

  // global interruption enable
  INTEnableInterrupts();
}

/**
 * void uartPutC(char dataToSend)
 */
void uartPutC(char dataToSend) {
    // wait while transmitter is not ready
    while( !UARTTransmitterIsReady(UART1) );

    UARTSendDataByte(UART1, dataToSend);
}

/**
 * void uartPutS(char* stringToSend)
 */
void uartPutS(char* stringToSend) {
    int i;
    const portTickType uartPutS_timeout = 10;

    if( xMutexUartPutS != NULL )
    {
        /* See if we can obtain the semaphore.  If the semaphore is not
        available wait uartPutS_timeout ticks to see if it becomes free. */
        if( xSemaphoreTake( xMutexUartPutS, uartPutS_timeout ) == pdTRUE )
        {
            /* We were able to obtain the semaphore and can now access the
            shared resource. */

            for (i=0; stringToSend[i] != '\0'; i++)
                uartPutC( stringToSend[i] );

            /* We have finished accessing the shared resource.  Release the
            semaphore. */
            xSemaphoreGive( xMutexUartPutS );
        }
        else
        {
            /* We could not obtain the semaphore and can therefore not access
            the shared resource safely. */
        }
    }

}

/**
 * char uartGetC(void)
 */

#include "console.h"

char uartGetC(void) {
    char tmp = KEY_NULL;

    // Events Flags
    static int key_Event_Flag;

    // Recieve char from isr with a non blocking Queue
    const portTickType uartGetC_timeout = 20;
    xQueueReceive(xQueueUartBuffer, &tmp,  uartGetC_timeout);

    // debug
    // if (tmp) {
    //     uartprintf("\r\nchar debug: '%c' == 0x%x\r\n", tmp, (unsigned int)tmp);
    // }

    // character echo with connected device
    switch (tmp) {
        case KEY_NULL:
        case KEY_SOH:
        case KEY_STX:
        case KEY_EOT:
        case KEY_ENQ:
        case KEY_ACK:
        case KEY_BEL:
        case KEY_BS:
        case KEY_LF:
        case KEY_VT:
        case KEY_FF:
        case KEY_SO:
        case KEY_SI:
        case KEY_DLE:
        case KEY_DC1:
        case KEY_DC2:
        case KEY_DC3:
        case KEY_DC4:
        case KEY_NAK:
        case KEY_SYN:
        case KEY_ETB:
        case KEY_CAN:
        case KEY_EM:
        case KEY_SUB:
        case KEY_FS:
        case KEY_GS:
        case KEY_RS:
        case KEY_US:
            // For now all upward keys do nothing!
            // INVISIBLE KEY
            tmp = KEY_NULL;
            break;
        case KEY_CR:
        case KEY_ETX:
            // New Line
            cursor_char = 0;
            written_char = 0;
            written_char = 0;
            // history bug fix
            if (key_Event == ARROW_UP || key_Event == ARROW_DOWN) {
                tmp = KEY_NULL;
            }
            break;
        case KEY_DEL:
            // KEY_BACKSPACE | KEY_DEL
            if (written_char-- > 0) {
                if (cursor_char > written_char)
                    cursor_char--;
                uartSendEscCommand("[D");
                uartSendEscCommand("[K");
            } else {
                // this is fun!
                uartPutC(KEY_BEL);
            }
            break;
        case KEY_ESC:
            // First escape caracter
            key_Event_Flag = 1;
            // INVISIBLE KEY
            tmp = KEY_NULL;
            break;
        case KEY_HT:
            // TAB
            // do something useful (show hint)
            // here
            // INVISIBLE KEY
            tmp = KEY_NULL;
            break;
        case '[':
            // Second escape caracter
            if (key_Event_Flag == 1) {
                key_Event_Flag = 2;
                tmp = KEY_NULL;
                break;
            }
        case 'A':
            if (key_Event_Flag == 2) {
                // UP_ARROW
                #if configUSE_UART_HISTORY == 1
                if (history_oldest != history_cursor) {
                    // look for last command
                    history_cursor = (history_cursor - 1) % UART_HISTORY_DEPTH;
                    // cursor restore
                    uartSendEscCommand("[u");
                    // clear line
                    uartSendEscCommand("[K");
                    // cursor save
                    uartSendEscCommand("[s");
                    // put history ...
                    uartPutS(history_uartRx[history_cursor]);
                    // resolve written caracters
                    for (written_char = 0;
                         history_uartRx[history_cursor][written_char] != KEY_NULL;
                         written_char++);
                    cursor_char = written_char;

                } else
                #endif
                {
                    // this is fun!
                    uartPutC(KEY_BEL);
                }
                // Event
                key_Event = ARROW_UP;
                // INVISIBLE KEY
                tmp = KEY_NULL;
                break;
            }
        case 'B':
            if (key_Event_Flag == 2) {
                // DOWN_ARROW
                #if configUSE_UART_HISTORY == 1
                if (history_current != history_cursor) {
                    // look for last command
                    history_cursor = (history_cursor + 1) % UART_HISTORY_DEPTH;
                    // cursor restore
                    uartSendEscCommand("[u");
                    // clear line
                    uartSendEscCommand("[K");
                    // cursor save
                    uartSendEscCommand("[s");
                    // put history ...
                    uartPutS(history_uartRx[history_cursor]);
                    // resolve written caracters
                    for (written_char = 0;
                         history_uartRx[history_cursor][written_char] != KEY_NULL;
                         written_char++);
                    cursor_char = written_char;
                } else
                #endif
                {
                    // this is fun!
                    uartPutC(KEY_BEL);
                }
                // Event
                key_Event = ARROW_DOWN;
                // INVISIBLE KEY
                tmp = KEY_NULL;
                break;
            }
        case 'C':
            if (key_Event_Flag == 2) {
                // RIGHT_ARROW
                // if (cursor_char < written_char) {
                //     cursor_char++;
                //     uartSendEscCommand("[C");
                // } else {
                    // this is fun!
                    uartPutC(KEY_BEL);
                // }
                // Event
                key_Event = ARROW_RIGHT;
                // INVISIBLE KEY
                tmp = KEY_NULL;
                break;
            }
        case 'D':
            if (key_Event_Flag == 2) {
                // LEFT_ARROW
                // if (cursor_char > 0) {
                //     cursor_char--;
                //     uartSendEscCommand("[D");
                // } else {
                    // this is fun!
                    uartPutC(KEY_BEL);
                // }
                // Event
                key_Event = ARROW_LEFT;
                // INVISIBLE KEY
                tmp = KEY_NULL;
                break;
            }
        default:
            // reset flags
            key_Event_Flag = 0;
            key_Event = ARROW_NULL;
            // doesnt work. why?
            if (tmp <= UTF_8_LIMIT) {
                cursor_char++;
                written_char++;
                uartPutC( tmp );
            } else {
                tmp = KEY_NULL;
            }
            key_Event_Flag = 0;
            written_char++;
            uartPutC( tmp );

    }

    return tmp;
}

/**
 * void uartGetS(char* rxString)
 */
void uartGetS(char* rxString) {
    char tmp;
    int i = 0;

    // wait for data receiving and check for ENTER key ascii code
    for (tmp = KEY_NULL; tmp != KEY_CR; tmp = uartGetC()) {
        // ctrl + c event!
        if (tmp == KEY_ETX) {
            i = 0;
            break;
        }

        // cursor and history sync
        switch (key_Event) {
            case ARROW_RIGHT:
            case ARROW_LEFT:
                // update cursor
                i = cursor_char;
                break;
            case ARROW_UP:
            case ARROW_DOWN:
                #if configUSE_UART_HISTORY == 1
                // resolve written caracters
                for (i = 0; history_uartRx[history_cursor][i] != KEY_NULL; i++);
                // sync history with rxString
                memcpy(rxString, history_uartRx[history_cursor], i);
                #endif
                break;
        }
        // rxString handling
        switch (tmp) {
            case KEY_NULL:
                break;
            case KEY_DEL:
                i = (i != 0) ? i - 1 : 0;
                break;
            default:
                if (tmp <= UTF_8_LIMIT)
                    rxString[i++] = tmp;

        // if (tmp == KEY_NULL && key_Event == ARROW_RIGHT) {
        //     i = (i != UART_MAX_STR_SIZE) ? i + 1 : i;
        // } else if (tmp == KEY_NULL && key_Event == ARROW_LEFT) {
        //     i = (i != 0) ? i - 1 : 0;
        // }
        if (tmp == KEY_DEL) {
            i = (i != 0) ? i - 1 : 0;
        } else if (tmp == KEY_ETX) {
            i = 0;
            break;
        } else if (tmp != KEY_NULL && tmp < 0x100) {
            rxString[i++] = tmp;
            // rxString[i] = KEY_NULL;
            // uartprintf("\r\nstr debug: %s, last index %d\r\n", rxString, i - 1);
        }
    }

    // replace ENTER key ascii code
    rxString[i] = KEY_NULL;

    #if configUSE_UART_HISTORY == 1
    // history updated with text received
    if (i != 0 && rxString[0] != KEY_CR) {
        memcpy(history_uartRx[history_current], rxString, UART_MAX_STR_SIZE);
        // update iterators
        history_current = (history_current + 1) % UART_HISTORY_DEPTH;
        if (history_current == history_oldest) {
            history_oldest = (history_oldest + 1) % UART_HISTORY_DEPTH;
            history_uartRx[history_oldest][0] = KEY_NULL;
        }
    }

    // command sent save
    history_cursor = history_current;
    #endif

    // history updated with text received
    if (rxString[0] != KEY_NULL) {
        // if (history_current != history_cursor) {
            // memcpy(history_uartRx[history_current], history_uartRx[history_cursor], UART_MAX_STR_SIZE);
        // } else {
            memcpy(history_uartRx[history_current], rxString, UART_MAX_STR_SIZE);
        // }
        history_current = (history_current + 1) % UART_HISTORY_DEPTH;
        if (history_current == history_oldest)
            history_oldest = (history_oldest + 1) % UART_HISTORY_DEPTH;
    }

    // command sent
    if (key_Event == ARROW_UP || key_Event == ARROW_DOWN) {
        memcpy(rxString, history_uartRx[history_cursor], UART_MAX_STR_SIZE);
        history_cursor = history_current;
    }

    // uartprintf("\r\nstr debug: %s \r\n", rxString);
    uartPutS("\r\n");
}
