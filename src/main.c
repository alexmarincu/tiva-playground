#include "led.h"
#include "state.h"
#include <stdint.h>
#include "os/os_Task.h"
#include "os/os_Scheduler.h"
#include "os/os_Os.h"

void delay(void);

static void task100Millis(void) {
    static STATE state = STATE_RED;
    switch (state) {
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
int main(void) {
    // STATE state = STATE_RED;

    LedInit();
    // hal_SysTick_intRegister(systick);
    // hal_SysTick_intEnable();
    // hal_SysTick_setPeriodMillis(100);
    // hal_SysTick_enable();

     while (1) {
        // Set the LED color based on the current state.
        // switch(state)
        // {
        //     case STATE_RED:
        //         LedSetRed();
        //         break;
        //     case STATE_GREEN:
        //         LedSetGreen();
        //         break;
        //     case STATE_BLUE:
        //         LedSetBlue();
        //         break;
        // }

        // // Delay and then turn the LED off.
        // delay();
        // LedSetOff();
        // delay();

    // // Update the state.
    // state = StateGetNext(state);
      os_Task tasks[1];
    os_Task_init(&tasks[0], 1000, task100Millis);
    os_Scheduler_setTasks(tasks, 1);
    os_Os_main(os_Os_init(os_Os_ref()));
     }

   
}

void delay(void) {
    volatile uint32_t count;
    for (count = 0; count < 400000; count++) {
    }
}
