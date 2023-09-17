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
#include "vsk/vsk_EventTimer.h"
#include "vsk/vsk_Kernel.h"
#include "vsk/vsk_Task.h"
#include "vsk/vsk_TaskScheduler.h"
#include <stdint.h>

static void setupClockFrequency(void) {
    hal_SysClock_setMaxFrequency();
}

static void sysTickInt(void) {
    vsk_Kernel_onSysTick(vsk_Kernel_());
}

static void setupSysTick(void) {
    hal_SysTick_intRegister(sysTickInt);
    hal_SysTick_intEnable();
    hal_SysTick_setPeriodMillis(200);
    vsk_Kernel_informTickPeriodMillis(vsk_Kernel_(), hal_SysTick_getPeriodMillis());
    hal_SysTick_enable();
}

static void setupEvents(void) {
    RedEvent_init(RedEvent_());
    BlueEvent_init(BlueEvent_());
    GreenEvent_init(GreenEvent_());
}

static void onIdle(void) {
}

static vsk_EventTimer redEventTimer;
static vsk_EventTimer blueEventTimer;
static vsk_EventTimer greenEventTimer;

static void onStart(void) {
    setupClockFrequency();
    setupSysTick();
    LedInit();
    setupEvents();
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &redEventTimer,
            (vsk_Event *)RedEvent_(),
            (vsk_Task *)BlinkyTask_()
        ),
        1000,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &blueEventTimer,
            (vsk_Event *)BlueEvent_(),
            (vsk_Task *)BlinkyTask_()
        ),
        2000,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &greenEventTimer,
            (vsk_Event *)GreenEvent_(),
            (vsk_Task *)BlinkyTask_()
        ),
        3000,
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
    vsk_Kernel_start(
        vsk_Kernel_init(
            vsk_Kernel_(),
            onStart,
            onIdle,
            taskArray
        )
    );
}
