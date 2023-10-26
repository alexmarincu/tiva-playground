/*............................................................................*/
#include "ha_Led.h"
/*............................................................................*/
#include <stdbool.h>
#include <stdint.h>
/*............................................................................*/
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "peripherals/ha_per_PortF.h"
/*............................................................................*/
void ha_Led_init(void) {
    ha_per_PortF_init(ha_per_PortF_());
    GPIOPinTypeGPIOOutput(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin        //
            | ha_per_PortF_blueLedPin //
            | ha_per_PortF_greenLedPin
    );
}
/*............................................................................*/
void ha_Led_setGreenOn(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE, ha_per_PortF_greenLedPin, ha_per_PortF_greenLedPin
    );
}
/*............................................................................*/
void ha_Led_setGreenOff(void) {
    GPIOPinWrite(GPIO_PORTF_BASE, ha_per_PortF_greenLedPin, 0);
}
/*............................................................................*/
void ha_Led_setBlueOn(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE, ha_per_PortF_blueLedPin, ha_per_PortF_blueLedPin
    );
}
/*............................................................................*/
void ha_Led_setBlueOff(void) {
    GPIOPinWrite(GPIO_PORTF_BASE, ha_per_PortF_blueLedPin, 0);
}
/*............................................................................*/
void ha_Led_setRedOn(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE, ha_per_PortF_redLedPin, ha_per_PortF_redLedPin
    );
}
/*............................................................................*/
void ha_Led_setRedOff(void) {
    GPIOPinWrite(GPIO_PORTF_BASE, ha_per_PortF_redLedPin, 0);
}
/*............................................................................*/
void ha_Led_setAllOn(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin        //
            | ha_per_PortF_blueLedPin //
            | ha_per_PortF_greenLedPin,
        ha_per_PortF_redLedPin        //
            | ha_per_PortF_blueLedPin //
            | ha_per_PortF_greenLedPin
    );
}
/*............................................................................*/
void ha_Led_setAllOff(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin        //
            | ha_per_PortF_blueLedPin //
            | ha_per_PortF_greenLedPin,
        0
    );
}
/*............................................................................*/
void ha_Led_toggleRed(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin,
        GPIOPinRead(GPIO_PORTF_BASE, ha_per_PortF_redLedPin) //
            ^ ha_per_PortF_redLedPin
    );
}
