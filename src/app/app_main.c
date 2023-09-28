#include "../app/blinky/app_blk_BlinkyTask.h"

#include "events/app_ev_BlueTimeoutEvent.h"
#include "events/app_ev_GreenTimeoutEvent.h"
#include "events/app_ev_LeftButtonPressEvent.h"
#include "events/app_ev_LeftButtonReleaseEvent.h"
#include "events/app_ev_RedTimeoutEvent.h"
#include "events/app_ev_RightButtonPressEvent.h"
#include "events/app_ev_RightButtonReleaseEvent.h"

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

static void setupClockFrequency(void);
static void sysTickIntHandler(void);
static void leftButtonIntHandler(void);
static void rightButtonIntHandler(void);
static void setupSysTick(void);
static void setupLeftButton(void);
static void setupLed(void);
static void setupRightButton(void);
static void setupEvents(void);
static void onIdle(void);
static void onStart(void);
static void enterCriticalSection(void);
static void exitCriticalSection(void);

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
        vsk_Event_raise((vsk_Event *)app_ev_LeftButtonPressEvent_());
    } else {
        vsk_Event_raise((vsk_Event *)app_ev_LeftButtonReleaseEvent_());
    }
}

static void rightButtonIntHandler(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_clearIntFlag(button);
    if (ha_RightButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)app_ev_RightButtonPressEvent_());
    } else {
        vsk_Event_raise((vsk_Event *)app_ev_RightButtonReleaseEvent_());
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
    app_ev_RedTimeoutEvent_init(app_ev_RedTimeoutEvent_());
    app_ev_BlueTimeoutEvent_init(app_ev_BlueTimeoutEvent_());
    app_ev_GreenTimeoutEvent_init(app_ev_GreenTimeoutEvent_());
    app_ev_LeftButtonPressEvent_init(app_ev_LeftButtonPressEvent_());
    app_ev_LeftButtonReleaseEvent_init(app_ev_LeftButtonReleaseEvent_());
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
            (vsk_Event *)app_ev_RedTimeoutEvent_()
        ),
        1,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &blueEventTimer,
            (vsk_Event *)app_ev_BlueTimeoutEvent_()
        ),
        1000,
        3000
    );
    vsk_EventTimer_arm(
        vsk_EventTimer_init(
            &greenEventTimer,
            (vsk_Event *)app_ev_GreenTimeoutEvent_()
        ),
        2000,
        3000
    );
}

static void enterCriticalSection(void) {
    ha_Interrupt_disableAll();
}

static void exitCriticalSection(void) {
    ha_Interrupt_enableAll();
}

int app_main(void) {
    setupEvents();
    ut_Array * taskArray = ut_Array_init(
        ut_stkObj(ut_Array),
        ut_stkArr(void *, 1),
        1
    );
    ut_Array_insert(
        taskArray,
        app_blk_BlinkyTask_init(
            app_blk_BlinkyTask_(),
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
            taskArray,
            onStart,
            onIdle,
            enterCriticalSection,
            exitCriticalSection
        )
    );
    return 0;
}
