/**
* @file     uart.h
* @brief    header for uart module library for pic32 mcu architecture
* @author   hugo descoubes
* @date     august 2013
*/
#ifndef   __HEADER_UART__
#define   __HEADER_UART__

/* INCLUDES DEPENDENCIES ***************/
<<<<<<< HEA
<<<<<<< HEA
#include <stdio.h>
======
>>>>>>> 161295374c548df9d50fa617d9516e231939313
======
>>>>>>> origin/maste
#include <string.h>
#include <p32xxxx.h>
#include <plib.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <queue.h>

/* MACROS ***************/
#define SYS_FREQ            80000000    // bus matrix and cpu clock speed
#define PB_DIV              1		    // periphepral bus clock speed divider
#define UART_BPS            9600        // uart module baud rate
#define UART_BUFFER_SIZE    200         // circular buffer size in byte
#define UART_HISTORY_DEPTH  10
#define UART_MAX_STR_SIZE   64

<<<<<<< HEA
<<<<<<< HEA
// beta feature with some nasty bugs!!
#define configUSE_UART_HISTORY 0

======
>>>>>>> 161295374c548df9d50fa617d9516e231939313
======
>>>>>>> origin/maste
/* SPECIAL KEYS ***************/
// http://www.theasciicode.com.ar/extended-ascii-code/non-breaking-space-no-break-space-ascii-code-255.html
// Null character
#define KEY_NULL            0
// Start of Header
#define KEY_SOH             1
// Start of Text
#define KEY_STX             2
// End of Text
#define KEY_ETX             3
// End of Transmission
#define KEY_EOT             4
// Enquiry
#define KEY_ENQ             5
// Acknowledgement
#define KEY_ACK             6
// Bell
#define KEY_BEL             7
// Backspace
#define KEY_BS              8
// Horizontal Tab
#define KEY_HT              9
// Line feed
#define KEY_LF              10
// Vertical Tab
#define KEY_VT              11
// Form feed
#define KEY_FF              12
// Carriage return
#define KEY_CR              13
// Shift Out
#define KEY_SO              14
// Shift In
#define KEY_SI              15
// Data link escape
#define KEY_DLE             16
// Device control 1
#define KEY_DC1             17
// Device control 2
#define KEY_DC2             18
// Device control 3
#define KEY_DC3             19
// Device control 4
#define KEY_DC4             20
// Negative-acknowledge
#define KEY_NAK             21
// Synchronous idle
#define KEY_SYN             22
// End of trans. block
#define KEY_ETB             23
// Cancel
#define KEY_CAN             24
// End of medium
#define KEY_EM              25
// Substitute
#define KEY_SUB             26
// Escape
#define KEY_ESC             27
// File separator
#define KEY_FS              28
// Group separator
#define KEY_GS              29
// Record separator
#define KEY_RS              30
// Unit separator
#define KEY_US              31
// Delete
#define KEY_DEL             127

<<<<<<< HEA
<<<<<<< HEA
#define UTF_8_LIMIT         0xFF

======
>>>>>>> 161295374c548df9d50fa617d9516e231939313
======
>>>>>>> origin/maste
/**
 * @fn void uartConfig(void)
 * @brief uart module configuration
 */
void uartConfig(void);

/**
 * @fn void interruptConfig(void)
 * @brief system interruption configuration
 */
void interruptConfig(void);

/**
 * @fn void uartPutC(char dataToSend)
 * @brief uart sending 8bits payload by polling
 * @param 8bits payload to send
 */
void uartPutC(char dataToSend);

/**
 * @fn void uartPutS(char* stringToSend)
 * @brief uart sending string by polling
 * @param pointer on string to send
 */
void uartPutS(char* stringToSend);

/**
 * @fn void uartSendEscCommand(char* command)
 * @brief uart send escape command
 * @param pointer on command to send
 */
#define uartSendEscCommand(command) {               \
    char EscCommand[5], i;                          \
    EscCommand[0] = KEY_ESC;                        \
    for (i = 0; command[i] != KEY_NULL; i++)        \
        EscCommand[i + 1] = command[i];             \
    EscCommand[i + 1] = KEY_NULL;                   \
    uartPutS(EscCommand);                           \
}

/**
 * @fn char uartGetC(void)
 * @brief uart receiving 8bits payload by interruption and circular buffer
 * @return received 8bits data
 */
char uartGetC(void) ;

/**
 * @fn void uartGetS(char* rxString)
 * @brief uart receiving string by interruption and circular buffer
 * @param pointer on local mcu string to save received string
 */
void uartGetS(char* stringToSave);

// very useful macros
#define uartprintf(MSG, ...) { \
    char uartPrintfBuffer[UART_MAX_STR_SIZE]; \
    sprintf(uartPrintfBuffer, MSG, ##__VA_ARGS__); \
    uartPutS(uartPrintfBuffer); \
}

#define uartscanf(MSG, ...) { \
    char uartScanfBuffer[UART_MAX_STR_SIZE]; \
    uartGetS(uartScanfBuffer); \
    sscanf(uartScanfBuffer, MSG, ##__VA_ARGS__); \
}

#endif
