/*----------------------------------------------------------------------------*/
#include "ha_Uart.h"
/*----------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
/*----------------------------------------------------------------------------*/
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/pin_map.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"
#include "../../lib/TivaWare/driverlib/uart.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
/*----------------------------------------------------------------------------*/
void ha_Uart_init(void) {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTConfigSetExpClk(
        UART0_BASE,
        SysCtlClockGet(),
        115200,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)
    );
    UARTEnable(UART0_BASE);
}
/*----------------------------------------------------------------------------*/
void ha_Uart_write(char const * const str) {
    char const * _char = str;
    while (*_char) {
        UARTCharPut(UART0_BASE, *_char);
        _char++;
    }
}
