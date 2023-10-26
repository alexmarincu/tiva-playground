/*............................................................................*/
#include "ha_SysTickSignal.h"
/*............................................................................*/
#include <stdbool.h>
#include <stdint.h>
/*............................................................................*/
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "peripherals/ha_per_PortB.h"
/*............................................................................*/
void ha_SysTickSignal_init(void) {
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, ha_per_PortB_sysTickSignalPin);
    ha_SysTickSignal_setLow();
}
/*............................................................................*/
void ha_SysTickSignal_setHigh(void) {
    GPIOPinWrite(
        GPIO_PORTB_BASE,
        ha_per_PortB_sysTickSignalPin,
        ha_per_PortB_sysTickSignalPin
    );
}
/*............................................................................*/
void ha_SysTickSignal_setLow(void) {
    GPIOPinWrite(GPIO_PORTB_BASE, ha_per_PortB_sysTickSignalPin, 0);
}
