/**
* @file     uart.h
* @brief    header for uart module library for pic32 mcu architecture
* @author   hugo descoubes
* @date     august 2013
*/
#ifndef   __HEADER_UART__
#define   __HEADER_UART__

/* INCLUDES DEPENDENCIES ***************/
#include <p32xxxx.h>
#include <plib.h>

/* MACROS ***************/
#define SYS_FREQ            80000000    // bus matrix and cpu clock speed
#define PB_DIV              1		// periphepral bus clock speed divider
#define UART_BPS            9600        // uart module baud rate
#define UART_BUFFER_SIZE    200         //circular buffer size in byte

/* PUBLIC DECLARATIONS ***************/
unsigned int indexW, indexR, eltNb;
unsigned char uartBuffer[UART_BUFFER_SIZE];
char strTmp[UART_BUFFER_SIZE];          // temporary buffer for string handling

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

#endif 
