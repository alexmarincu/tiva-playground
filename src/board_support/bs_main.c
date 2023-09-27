#include "../blinky/blk_BlinkyTask.h"
#include "../events/ev_BlueTimeoutEvent.h"
#include "../events/ev_GreenTimeoutEvent.h"
#include "../events/ev_LeftButtonPressEvent.h"
#include "../events/ev_LeftButtonReleaseEvent.h"
#include "../events/ev_RedTimeoutEvent.h"
#include "../events/ev_RightButtonPressEvent.h"
#include "../events/ev_RightButtonReleaseEvent.h"

#include "../hw_abstraction/ha_Led.h"
#include "../hw_abstraction/ha_LeftButton.h"
#include "../hw_abstraction/ha_RightButton.h"
#include "../hw_abstraction/ha_SysClock.h"
#include "../hw_abstraction/ha_SysCtrl.h"
#include "../hw_abstraction/ha_SysTick.h"

#include "../utils/ut.h"

#include "../very_simple_kernel/vsk_EventTimer.h"
#include "../very_simple_kernel/vsk_Kernel.h"
#include "../very_simple_kernel/vsk_Task.h"
#include "../very_simple_kernel/vsk_TaskScheduler.h"

#include <stdint.h>

static void setupClockFrequency(void) {
    ha_SysClock_setMaxFrequency();
}

static void sysTickIntHandler(void) {
    vsk_Kernel_onSysTick(vsk_Kernel_());
}

static void leftButtonIntHandler(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_clearIntFlag(button);
    if (ha_LeftButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)ev_LeftButtonPressEvent_());
    } else {
        vsk_Event_raise((vsk_Event *)ev_LeftButtonReleaseEvent_());
    }
}

static void rightButtonIntHandler(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_clearIntFlag(button);
    if (ha_RightButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)ev_RightButtonPressEvent_());
    } else {
        vsk_Event_raise((vsk_Event *)ev_RightButtonReleaseEvent_());
    }
}

static void setupSysTick(void) {
    ha_SysTick_registerInt(sysTickIntHandler);
    ha_SysTick_enableInt();
    ha_SysTick_setPeriodMillis(10);
    vsk_Kernel_informTickPeriodMillis(vsk_Kernel_(), ha_SysTick_getPeriodMillis());
    ha_SysTick_enable();
}

static void setupLeftButton(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_init(button);
    ha_LeftButton_setIntTypeBothEdges(button);
    ha_LeftButton_registerInt(button, leftButtonIntHandler);
    ha_LeftButton_enableInt(button);
}

static void setupLed(void) {
    ha_Led_init();
}

static void setupRightButton(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_init(button);
    ha_RightButton_setIntTypeBothEdges(button);
    ha_RightButton_registerInt(button, rightButtonIntHandler);
    ha_RightButton_enableInt(button);
}

static void setupEvents(void) {
    ev_RedTimeoutEvent_init(ev_RedTimeoutEvent_());
    ev_BlueTimeoutEvent_init(ev_BlueTimeoutEvent_());
    ev_GreenTimeoutEvent_init(ev_GreenTimeoutEvent_());
    ev_LeftButtonPressEvent_init(ev_LeftButtonPressEvent_());
    ev_LeftButtonReleaseEvent_init(ev_LeftButtonReleaseEvent_());
}

static void onIdle(void) {
    ha_SysCtrl_waitForInt();
}

static void onStart(void) {
    setupClockFrequency();
    setupSysTick();
    setupLed();
    setupLeftButton();
    setupRightButton();
    static vsk_EventTimer redEventTimer;
    static vsk_EventTimer blueEventTimer;
    static vsk_EventTimer greenEventTimer;
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &redEventTimer,
            (vsk_Event *)ev_RedTimeoutEvent_()
        ),
        1,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &blueEventTimer,
            (vsk_Event *)ev_BlueTimeoutEvent_()
        ),
        1000,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &greenEventTimer,
            (vsk_Event *)ev_GreenTimeoutEvent_()
        ),
        2000,
        3000
    );
}

int bs_main(void) {
    setupEvents();
    ut_Array * taskArray = ut_Array_init(
        ut_stkObj(ut_Array),
        ut_stkArr(void *, 1),
        1
    );
    ut_Array_insert(
        taskArray,
        blk_BlinkyTask_init(
            blk_BlinkyTask_(),
            ut_Queue_init(
                ut_stkObj(ut_Queue),
                ut_Array_init(
                    ut_stkObj(ut_Array),
                    ut_stkArr(void *, 3),
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
    return 0;
}
