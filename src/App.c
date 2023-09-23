#include "App.h"
#include "BlinkyTask.h"
#include "BlueTimeoutEvent.h"
#include "GreenTimeoutEvent.h"
#include "RedTimeoutEvent.h"

#include "hal/hal_Led.h"
#include "hal/hal_SysClock.h"
#include "hal/hal_SysCtrl.h"
#include "hal/hal_SysTick.h"

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
    hal_SysTick_registerInt(sysTickInt);
    hal_SysTick_enableInt();
    hal_SysTick_setPeriodMillis(200);
    vsk_Kernel_informTickPeriodMillis(vsk_Kernel_(), hal_SysTick_getPeriodMillis());
    hal_SysTick_enable();
}

static void setupEvents(void) {
    RedTimeoutEvent_init(RedTimeoutEvent_());
    BlueTimeoutEvent_init(BlueTimeoutEvent_());
    GreenTimeoutEvent_init(GreenTimeoutEvent_());
}

static void onIdle(void) {
    hal_SysCtrl_waitForInt();
}

static void onStart(void) {
    setupClockFrequency();
    setupSysTick();
    hal_Led_init();
    static vsk_EventTimer redEventTimer;
    static vsk_EventTimer blueEventTimer;
    static vsk_EventTimer greenEventTimer;
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &redEventTimer,
            (vsk_Event *)RedTimeoutEvent_()
        ),
        1000,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &blueEventTimer,
            (vsk_Event *)BlueTimeoutEvent_()
        ),
        2000,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &greenEventTimer,
            (vsk_Event *)GreenTimeoutEvent_()
        ),
        3000,
        3000
    );
}

void App_main(void) {
    setupEvents();
    utl_Array * taskArray = utl_Array_init(
        utl_stkObj(utl_Array),
        utl_stkArr(void *, 1),
        1
    );
    utl_Array_insert(
        taskArray,
        BlinkyTask_init(
            BlinkyTask_(),
            utl_Queue_init(
                utl_stkObj(utl_Queue),
                utl_Array_init(
                    utl_stkObj(utl_Array),
                    utl_stkArr(void *, 3),
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
