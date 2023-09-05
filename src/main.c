#include <stdint.h>

#include "led.h"
#include "state.h"
#include "../lib/TivaWare/driverlib/systick.h"

void delay(void);

static void systick(void) {
  
  static STATE state = STATE_RED;
  switch(state)
        {
            case STATE_RED:
                LedSetRed();
                break;
            case STATE_GREEN:
                LedSetGreen();
                break;
            case STATE_BLUE:
                LedSetBlue();
                break;
            }
            state = StateGetNext(state);
}

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int
main(void)
{
    STATE state = STATE_RED;

    LedInit();
    SysTickIntRegister(systick);
    SysTickIntEnable();
    SysTickPeriodSet(16777216);
    SysTickEnable();

    while(1)
    {
        // Set the LED color based on the current state.
        switch(state)
        {
            case STATE_RED:
                LedSetRed();
                break;
            case STATE_GREEN:
                LedSetGreen();
                break;
            case STATE_BLUE:
                LedSetBlue();
                break;
        }

        // Delay and then turn the LED off.
        delay();
        LedSetOff();
        delay();

        // Update the state.
        state = StateGetNext(state);
    }
}

void delay(void)
{
    volatile uint32_t count;

    for(count = 0; count < 400000; count++)
    {
    }
}
