#include "App.h"
#include "BlinkyTask.h"
#include "BlueEvent.h"
#include "GreenEvent.h"
#include "RedEvent.h"
#include "hal/hal_SysClock.h"
#include "hal/hal_SysTick.h"
#include "led.h"
#include "state.h"
#include "utl/utl.h"
#include "vsos/vsos_EventTimer.h"
#include "vsos/vsos_Os.h"
#include "vsos/vsos_Scheduler.h"
#include "vsos/vsos_Task.h"
#include <stdint.h>

static void setupClockFrequency(void) {
    hal_SysClock_setMaxFrequency();
}

static void sysTickInt(void) {
    vsos_Os_onSysTick(vsos_Os_());
}

static void setupSysTick(void) {
    hal_SysTick_intRegister(sysTickInt);
    hal_SysTick_intEnable();
    hal_SysTick_setPeriodMillis(1);
    hal_SysTick_enable();
}

static void setupEvents(void) {
    RedEvent_init(RedEvent_());
    BlueEvent_init(BlueEvent_());
    GreenEvent_init(GreenEvent_());
}

static void onIdle(void) {
}

static vsos_EventTimer redEventTimer;
static vsos_EventTimer blueEventTimer;
static vsos_EventTimer greenEventTimer;

static void onStart(void) {
    setupClockFrequency();
    setupSysTick();
    LedInit();
    setupEvents();
    vsos_EventTimer_arm(
        vsos_EventTimer_init(
            &redEventTimer,
            (vsos_Event *)RedEvent_(),
            (vsos_Task *)BlinkyTask_()
        ),
        1,
        3000
    );
    vsos_EventTimer_arm(
        vsos_EventTimer_init(
            &blueEventTimer,
            (vsos_Event *)BlueEvent_(),
            (vsos_Task *)BlinkyTask_()
        ),
        1000,
        3000
    );
    vsos_EventTimer_arm(
        vsos_EventTimer_init(
            &greenEventTimer,
            (vsos_Event *)GreenEvent_(),
            (vsos_Task *)BlinkyTask_()
        ),
        2000,
        3000
    );
}

void App_main(void) {
    utl_Array * taskArray = utl_Array_init(
        utl_salloc(utl_Array),
        utl_salloca(void *, 1),
        1
    );
    utl_Array_insert(
        taskArray,
        BlinkyTask_init(
            BlinkyTask_(),
            utl_Queue_init(
                utl_salloc(utl_Queue),
                utl_Array_init(
                    utl_salloc(utl_Array),
                    utl_salloca(void *, 3),
                    3
                )
            )
        ),
        0
    );
    vsos_Os_start(
        vsos_Os_init(
            vsos_Os_(),
            onStart,
            hal_SysTick_getPeriodMillis(),
            onIdle,
            taskArray
        )
    );
}
