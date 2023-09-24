#include "../src/hal/hal_Led.h"
#include "unity.h"

#include "driverlib/pin_map.h"

#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"

#include "mock_gpio.h"
#include "mock_sysctl.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_whenLedsAreInitialized_thenGpioPortFIsEnabledAndLedPinsAreSetAsOutputs(void) {
    SysCtlPeripheralEnable_Expect(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    hal_Led_init();
}

void test_whenLedSetToGreen_thenGreenPinIsSetHighAndOtherSignalsAreSetLow(void) {
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2, 0);
    hal_Led_setGreenOn();
}

void test_whenLedSetToBlue_thenBluePinIsSetHighAndOtherSignalsAreSetLow(void) {
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_3, 0);
    hal_Led_setBlueOn();
}

void test_whenLedSetToRed_thenRedPinIsSetHighAndOtherSignalsAreSetLow(void) {
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2 | GPIO_PIN_3, 0);
    hal_Led_setRedOn();
}

void test_whenLedTurnedOff_thenAllLedPinsAreSetLow(void) {
    GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
    hal_Led_setAllOff();
}
