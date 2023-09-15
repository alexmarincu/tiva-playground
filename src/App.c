#include "App.h"
#include "hal/hal_SysClock.h"
#include "hal/hal_SysTick.h"
#include "led.h"
#include "state.h"
#include "utils/utils_Array.h"
#include "vsos/vsos_Os.h"
#include "vsos/vsos_Scheduler.h"
#include "vsos/vsos_Task.h"
#include <stdint.h>

static void task1(vsos_Task * const self) {
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
    vsos_Task_delayFromLastRun(self, 1000);
}

static void task2(vsos_Task * const self) {
    vsos_Task_delayFromLastRun(self, 100);
}

static void setupClockFrequency(void) {
    hal_SysClock_setMaxFrequency();
}

static void sysTickInt(void) {
    vsos_SysTime_sysTickInt(vsos_SysTime_(), hal_SysTick_getPeriodMillis());
}

static void setupSysTick(void) {
    hal_SysTick_intRegister(sysTickInt);
    hal_SysTick_intEnable();
    hal_SysTick_setPeriodMillis(1);
    hal_SysTick_enable();
}

void App_main(void) {
    setupClockFrequency();
    setupSysTick();
    LedInit();
    vsos_Os_init(vsos_Os_());
    vsos_Task * tasks[] = {
        vsos_Task_init(&(vsos_Task){ 0 }, task1),
        vsos_Task_init(&(vsos_Task){ 0 }, task2),
    };
    vsos_TaskArray taskArray = {
        .elements = tasks,
        .length = utils_Array_length(tasks)
    };
    vsos_Scheduler_setTaskArray(vsos_Scheduler_(), &taskArray);
    vsos_Scheduler_start(vsos_Scheduler_());
}
