#include "../blinky/BlinkyTask.h"
#include "../evp/BlueTimeoutEvent.h"
#include "../evp/GreenTimeoutEvent.h"
#include "../evp/LButtonPressEvent.h"
#include "../evp/LButtonReleaseEvent.h"
#include "../evp/RButtonPressEvent.h"
#include "../evp/RButtonReleaseEvent.h"
#include "../evp/RedTimeoutEvent.h"

#include "../hal/hal_LButton.h"
#include "../hal/hal_Led.h"
#include "../hal/hal_RButton.h"
#include "../hal/hal_SysClock.h"
#include "../hal/hal_SysCtrl.h"
#include "../hal/hal_SysTick.h"

#include "../utl/utl.h"

#include "../vsk/vsk_EventTimer.h"
#include "../vsk/vsk_Kernel.h"
#include "../vsk/vsk_Task.h"
#include "../vsk/vsk_TaskScheduler.h"

#include <stdint.h>

static void setupClockFrequency(void) {
    hal_SysClock_setMaxFrequency();
}

static void sysTickInt(void) {
    vsk_Kernel_onSysTick(vsk_Kernel_());
}

static void lButtonInt(void) {
    hal_LButton * button = hal_LButton_();
    hal_LButton_clearIntFlag(button);
    if (hal_LButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)LButtonPressEvent_());
    } else {
        vsk_Event_raise((vsk_Event *)LButtonReleaseEvent_());
    }
}

static void rButtonInt(void) {
    hal_RButton * button = hal_RButton_();
    hal_RButton_clearIntFlag(button);
    if (hal_RButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)RButtonPressEvent_());
    } else {
        vsk_Event_raise((vsk_Event *)RButtonReleaseEvent_());
    }
}

static void setupSysTick(void) {
    hal_SysTick_registerInt(sysTickInt);
    hal_SysTick_enableInt();
    hal_SysTick_setPeriodMillis(200);
    vsk_Kernel_informTickPeriodMillis(vsk_Kernel_(), hal_SysTick_getPeriodMillis());
    hal_SysTick_enable();
}

static void setupLButton(void) {
    hal_LButton * button = hal_LButton_();
    hal_LButton_init(button);
    hal_LButton_setIntTypeBothEdges(button);
    hal_LButton_registerInt(button, lButtonInt);
    hal_LButton_enableInt(button);
}

static void setupRButton(void) {
    hal_RButton * button = hal_RButton_();
    hal_RButton_init(button);
    hal_RButton_setIntTypeBothEdges(button);
    hal_RButton_registerInt(button, rButtonInt);
    hal_RButton_enableInt(button);
}

static void setupEvents(void) {
    RedTimeoutEvent_init(RedTimeoutEvent_());
    BlueTimeoutEvent_init(BlueTimeoutEvent_());
    GreenTimeoutEvent_init(GreenTimeoutEvent_());
    LButtonPressEvent_init(LButtonPressEvent_());
    LButtonReleaseEvent_init(LButtonReleaseEvent_());
}

static void onIdle(void) {
    hal_SysCtrl_waitForInt();
}

static void onStart(void) {
    setupClockFrequency();
    setupSysTick();
    hal_Led_init();
    setupLButton();
    setupRButton();
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

int bsp_main(void) {
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
    return 0;
}
