#include "hal_Led.h"

#include "../../lib/TivaWare/inc/hw_memmap.h"
#include "../../lib/TivaWare/inc/tm4c123gh6pm.h"

#include <stdbool.h>
#include <stdint.h>

#include "../../lib/TivaWare/driverlib/gpio.h"
#include "../../lib/TivaWare/driverlib/sysctl.h"

#define hal_Led_peripheral SYSCTL_PERIPH_GPIOF
#define hal_Led_port GPIO_PORTF_BASE
#define hal_Led_redPin GPIO_PIN_1
#define hal_Led_bluePin GPIO_PIN_2
#define hal_Led_greenPin GPIO_PIN_3

void hal_Led_init(void) {
    SysCtlPeripheralEnable(hal_Led_peripheral);
    GPIOPinTypeGPIOOutput(hal_Led_port, hal_Led_redPin | hal_Led_bluePin | hal_Led_greenPin);
}

void hal_Led_setGreen(void) {
    GPIOPinWrite(hal_Led_port, hal_Led_greenPin, hal_Led_greenPin);
    GPIOPinWrite(hal_Led_port, hal_Led_redPin | hal_Led_bluePin, 0);
}

void hal_Led_setBlue(void) {
    GPIOPinWrite(hal_Led_port, hal_Led_bluePin, hal_Led_bluePin);
    GPIOPinWrite(hal_Led_port, hal_Led_redPin | hal_Led_greenPin, 0);
}

void hal_Led_setRed(void) {
    GPIOPinWrite(hal_Led_port, hal_Led_redPin, hal_Led_redPin);
    GPIOPinWrite(hal_Led_port, hal_Led_bluePin | hal_Led_greenPin, 0);
}

void hal_Led_setOff(void) {
    GPIOPinWrite(hal_Led_port, hal_Led_redPin | hal_Led_bluePin | hal_Led_greenPin, 0);
}
