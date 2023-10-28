/*............................................................................*/
#include "ha_RgbLed.h"
/*............................................................................*/
#include <stdbool.h>
#include <stdint.h>
/*............................................................................*/
#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "peripherals/ha_per_PortF.h"
/*............................................................................*/
void ha_RgbLed_init(void) {
    ha_per_PortF_init(ha_per_PortF_());
    GPIOPinTypeGPIOOutput(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin         //
            | ha_per_PortF_greenLedPin //
            | ha_per_PortF_blueLedPin
    );
}
/*............................................................................*/
void ha_RgbLed_setGreen(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin         //
            | ha_per_PortF_greenLedPin //
            | ha_per_PortF_blueLedPin,
        0 | ha_per_PortF_greenLedPin | 0
    );
}
/*............................................................................*/
void ha_RgbLed_setBlue(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin         //
            | ha_per_PortF_greenLedPin //
            | ha_per_PortF_blueLedPin,
        0 | 0 | ha_per_PortF_blueLedPin
    );
}
/*............................................................................*/
void ha_RgbLed_setRed(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin         //
            | ha_per_PortF_greenLedPin //
            | ha_per_PortF_blueLedPin,
        ha_per_PortF_redLedPin | 0 | 0
    );
}
/*............................................................................*/
void ha_RgbLed_setWhite(void) {
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
void ha_RgbLed_setMagenta(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin        //
            | ha_per_PortF_blueLedPin //
            | ha_per_PortF_greenLedPin,
        ha_per_PortF_redLedPin | ha_per_PortF_blueLedPin | 0
    );
}
/*............................................................................*/
void ha_RgbLed_setOff(void) {
    GPIOPinWrite(
        GPIO_PORTF_BASE,
        ha_per_PortF_redLedPin        //
            | ha_per_PortF_blueLedPin //
            | ha_per_PortF_greenLedPin,
        0 | 0 | 0
    );
}
