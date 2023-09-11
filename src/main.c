#include "led.h"
#include "os/os_Os.h"
#include "os/os_Scheduler.h"
#include "os/os_Task.h"
#include "state.h"
#include <stdint.h>

void delay(void);

static void task1(os_Task * const self) {
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
    os_Task_delayFromLastRun(self, 100);
}

static void task2(os_Task * const self) {
    os_Task_delayFromLastRun(self, 100);
}

void app_main(void) {
    LedInit();
    os_Task tasks[2];
    os_Task_init(&tasks[0], task1);
    os_Task_init(&tasks[1], task2);
    os_Os_main(os_Os_init(os_Os_(), tasks, 2));
}

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int main(void) {
    app_main();
    return 0;
}

void delay(void) {
    volatile uint32_t count;
    for (count = 0; count < 400000; count++) {
    }
}
