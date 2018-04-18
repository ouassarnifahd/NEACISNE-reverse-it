/**
* file     uart.c
* brief    uart module library for pic32 mcu architecture 
* and PIC32-MAXI-WEB board from Olimex
* author   hugo descoubes
* date     september 2014
*/

/* INCLUDES DEPENDENCIES ***************/
#include <uart.h>

/**
* void __ISR(_UART_1_VECTOR, IPL2SOFT) IntUart1Handler(void)
*/
void __ISR(_UART_1_VECTOR, IPL2SOFT) IntUart1Handler(void) {

    // check for data receiving
    if ( INTGetFlag(INT_SOURCE_UART_RX(UART1)) ) {

        // save data in circular buffer if is not full
        if( eltNb < UART_BUFFER_SIZE) {
             // flush uart receiving buffer
            uartBuffer[indexW] = UARTGetDataByte(UART1);

            // clear uart receiving flag (always after uart buffer flushing)
            INTClearFlag(INT_SOURCE_UART_RX(UART1));
            
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
    UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY);

    // serial frame configuration
    UARTSetLineControl(UART1,  UART_DATA_SIZE_8_BITS | \
                                UART_PARITY_NONE |      \
                                UART_STOP_BITS_1);

    // data rate configuration
    UARTSetDataRate(UART1, SYS_FREQ/PB_DIV  , UART_BPS);

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


