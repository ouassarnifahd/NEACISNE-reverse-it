/**
* file     uart.c
* brief    uart module library for pic32 mcu architecture and explorer 16 board
* author   hugo descoubes
* date     august 2013
*/

/* INCLUDES DEPENDENCIES ***************/
#include "uart.h"

/**
* void __ISR(_UART_3A_VECTOR, IPL2SOFT) IntUart3AHandler(void)
*/
void __ISR(_UART_3A_VECTOR, IPL2SOFT) IntUart3AHandler(void) {

    // check for data receiving
    if ( INTGetFlag(INT_SOURCE_UART_RX(UART3A)) ) {

        // save data in circular buffer if is not full
        if( eltNb < UART_BUFFER_SIZE) {
             // flush uart receiving buffer
            uartBuffer[indexW] = UARTGetDataByte(UART3A);

            // clear uart receiving flag (always after uart buffer flushing)
            INTClearFlag(INT_SOURCE_UART_RX(UART3A));
            
            // increase element counter of circular buffer
            eltNb++;

            // circular buffer processing
            if ( indexW > UART_BUFFER_SIZE)
                indexW = 0;
            else
                indexW++;
        }    
    }
}

/**
 * void uartConfig(void)
 */
void uartConfig(void) {
    // circular buffer initialization
    indexW=0;
    indexR=0;
    eltNb=0;

    // standard mode without hardware handshaking
    UARTConfigure(UART3A, UART_ENABLE_PINS_TX_RX_ONLY);

    // serial frame configuration
    UARTSetLineControl(UART3A,  UART_DATA_SIZE_8_BITS | \
                                UART_PARITY_NONE |      \
                                UART_STOP_BITS_1);

    // data rate configuration
    UARTSetDataRate(UART3A, SYS_FREQ/PB_DIV  , UART_BPS);

    // enable module
    UARTEnable(UART3A,  UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

    // uart module interruption configuration
    INTClearFlag(INT_U3ARX);
    INTEnable(INT_SOURCE_UART_RX(UART3A), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART3A), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART3A), INT_SUB_PRIORITY_LEVEL_0);
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
    while( !UARTTransmitterIsReady(UART3A) );

    UARTSendDataByte(UART3A, dataToSend);
}

/**
 * void uartPutS(char* stringToSend)
 */
void uartPutS(char* stringToSend) {
    int i;

    for (i=0; stringToSend[i] != '\0'; i++)
        uartPutC( stringToSend[i] );
}

/**
 * char uartGetC(void)
 */
char uartGetC(void) {
    char tmp;
    
    // wait for data receiving
    while( eltNb == 0 );

    // character echo with connected device
    tmp = uartBuffer[indexR];
    uartPutC( tmp );
            
    // circular mode processing
    eltNb--;
    if ( indexR > UART_BUFFER_SIZE)
        indexR = 0;
    else
        indexR++;

    return tmp;
}

/**
 * void uartGetS(char* rxString)
 */
void uartGetS(char* rxString) {
    char tmp;
    int i=0;

    // wait for data receiving and check for ENTER key ascii code
    while ( (tmp = uartGetC()) != '\r')
        rxString[i++] = tmp;
        
    // replace ENTER key ascii code
    rxString[i] = '\0';
    uartPutS("\r\n");
}


