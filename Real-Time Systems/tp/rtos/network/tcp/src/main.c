/**
* @file     main.c
* @brief    microchip TCPIP stack application. TCP server to UART application
* @li       XC32 C toolchain(tested with xc32 1.21)
* @li       MPLABX IDE(tested with mplabx 1.85)
* @li       Microchip TCP/IP stack (tested with TCP/IP stack 5.42.08)
* @author
* @date     september 2013
*/

/* CONFIGURATION BITS ***************/
// cpu, low and high speed peripherals clock 80MHz (matrix and peripheral bus)
// cf.  HWP PIC32_ETH_SK_ETH795.h file
#define THIS_IS_STACK_APPLICATION

/* INCLUDES DEPENDENCIES ***************/
// ...

/* LOCAL PROTOTYPES ***************/
APP_CONFIG AppConfig;   // Microchip TCP/IP stack data structure for application
void displayIP(IP_ADDR IPVal);
// ...

/**
* @fn void main (void)
* @brief main entry point
*/
int main(void) {
    // build application IP value
    AppConfig.MyIPAddr.Val =    MY_DEFAULT_IP_ADDR_BYTE1        |    \
                                MY_DEFAULT_IP_ADDR_BYTE2<<8ul   |    \
                                MY_DEFAULT_IP_ADDR_BYTE3<<16ul  |    \
                                MY_DEFAULT_IP_ADDR_BYTE4<<24ul;

    // enable multi-vectored interrupts
    // ...

    // cache cpu configuration
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

    // tick timer configuration for stack timing
    // ...

    // initialize core stack layers (MAC, ARP, TCP, UDP ...) and
    // application modules (HTTP, SNMP ...)
    // ...

    // uart configuration et IP display
    uartConfig() ;
    uartPutS("\r\nHello Word\r\n");
    displayIP( AppConfig.MyIPAddr );
    
    while(1){
        // performs normal stack task including checking
        // for incoming packet, type of packet and calling
        // appropriate stack entity to process it.
        // ...

        // invokes each of the core stack application tasks
        // ...

        // application tcp server
        // ...
    }
}

/**
 * @fn void displayIP(IP_ADDR ipValue)
 * @brief display IP application value
 */
void displayIP(IP_ADDR ipValue){
    BYTE ipDigit[4];
    BYTE i;

    for(i = 0; i < 4; i++){ // 4 is IP address pattern data length
        uitoa((WORD)ipValue.v[i], ipDigit);
        uartPutS((char *) ipDigit);
        if(i == 3) {
            uartPutS("\r\n");
            break;
        }           
        uartPutC('.');
    }
}