#include "ha_Led.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

#define ha_Led_peripheral SYSCTL_PERIPH_GPIOF
#define ha_Led_port GPIO_PORTF_BASE
#define ha_Led_redPin GPIO_PIN_1
#define ha_Led_bluePin GPIO_PIN_2
#define ha_Led_greenPin GPIO_PIN_3

void ha_Led_init(void) {
    SysCtlPeripheralEnable(ha_Led_peripheral);
    GPIOPinTypeGPIOOutput(ha_Led_port, ha_Led_redPin | ha_Led_bluePin | ha_Led_greenPin);
}

void ha_Led_setGreenOn(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_greenPin, ha_Led_greenPin);
}

void ha_Led_setGreenOff(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_greenPin, 0);
}

void ha_Led_setBlueOn(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_bluePin, ha_Led_bluePin);
}

void ha_Led_setBlueOff(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_bluePin, 0);
}

void ha_Led_setRedOn(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_redPin, ha_Led_redPin);
}

void ha_Led_setRedOff(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_redPin, 0);
}

void ha_Led_setAllOn(void) {
    GPIOPinWrite(
        ha_Led_port,
        ha_Led_redPin | ha_Led_bluePin | ha_Led_greenPin,
        ha_Led_redPin | ha_Led_bluePin | ha_Led_greenPin
    );
}

void ha_Led_setAllOff(void) {
    GPIOPinWrite(ha_Led_port, ha_Led_redPin | ha_Led_bluePin | ha_Led_greenPin, 0);
}

void ha_Led_toggleRed(void) {
    GPIOPinWrite(
        ha_Led_port,
        ha_Led_redPin,
        GPIOPinRead(ha_Led_port, ha_Led_redPin) ^ ha_Led_redPin
    );
}
