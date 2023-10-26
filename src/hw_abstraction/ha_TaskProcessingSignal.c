/*............................................................................*/
#include "ha_TaskProcessingSignal.h"
/*............................................................................*/
#include <stdbool.h>
#include <stdint.h>
/*............................................................................*/
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "peripherals/ha_per_PortB.h"
/*............................................................................*/
void ha_TaskProcessingSignal_init(void) {
    GPIOPinTypeGPIOOutput(
        GPIO_PORTB_BASE, ha_per_PortB_taskProcessingSignalPin
    );
    ha_TaskProcessingSignal_setHigh();
}
/*............................................................................*/
void ha_TaskProcessingSignal_setHigh(void) {
    GPIOPinWrite(
        GPIO_PORTB_BASE,
        ha_per_PortB_taskProcessingSignalPin,
        ha_per_PortB_taskProcessingSignalPin
    );
}
/*............................................................................*/
void ha_TaskProcessingSignal_setLow(void) {
    GPIOPinWrite(GPIO_PORTB_BASE, ha_per_PortB_taskProcessingSignalPin, 0);
}
