/*............................................................................*/
#include "../app/time_bomb/app_tmb_TimeBombTask.h"
#include "../hw_abstraction/ha_Led.h"
#include "../hw_abstraction/ha_LeftButton.h"
#include "../hw_abstraction/ha_RightButton.h"
#include "../hw_abstraction/ha_SysClock.h"
#include "../hw_abstraction/ha_SysCtrl.h"
#include "../hw_abstraction/ha_SysTick.h"
#include "../utils/ut.h"
#include "../very_simple_kernel/vsk_Kernel.h"
#include "events/app_ev_BlinkTimeoutEvent.h"
#include "events/app_ev_LeftButtonPressEvent.h"
#include "events/app_ev_OnStartEvent.h"
#include "events/app_ev_PauseTimeoutEvent.h"
#include "events/app_ev_RightButtonPressEvent.h"
/*............................................................................*/
static void setupClockFrequency(void);
static void sysTickIntHandler(void);
static void leftButtonIntHandler(void);
static void rightButtonIntHandler(void);
static void setupSysTick(void);
static void setupLeftButton(void);
static void setupLeds(void);
static void setupRightButton(void);
static void setupEvents(void);
static void onIdle(void);
static void onStart(void);
static void disableInt(void);
static void enableInt(void);
/*............................................................................*/
static void setupClockFrequency(void) {
    ha_SysClock_setMaxFrequency();
}
/*............................................................................*/
static void sysTickIntHandler(void) {
    vsk_Kernel_onSysTick(vsk_Kernel_());
}
/*............................................................................*/
static void leftButtonIntHandler(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_clearIntFlag(button);
    if (ha_LeftButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)app_ev_LeftButtonPressEvent_());
    }
}
/*............................................................................*/
static void rightButtonIntHandler(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_clearIntFlag(button);
    if (ha_RightButton_isPressed(button)) {
        vsk_Event_raise((vsk_Event *)app_ev_RightButtonPressEvent_());
    }
}
/*............................................................................*/
static void setupSysTick(void) {
    ha_SysTick * sysTick = ha_SysTick_();
    ha_SysTick_init(sysTick);
    ha_SysTick_registerInt(sysTick, sysTickIntHandler);
    ha_SysTick_enableInt(sysTick);
    ha_SysTick_setPeriodMillis(sysTick, 100);
    vsk_Kernel_informTickPeriodMillis(
        vsk_Kernel_(),
        ha_SysTick_getPeriodMillis(sysTick)
    );
    ha_SysTick_enable(sysTick);
}
/*............................................................................*/
static void setupLeftButton(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_init(button);
    ha_LeftButton_setIntTypeBothEdges(button);
    ha_LeftButton_registerInt(button, leftButtonIntHandler);
    ha_LeftButton_enableInt(button);
}
/*............................................................................*/
static void setupLeds(void) {
    ha_Led_init();
}
/*............................................................................*/
static void setupRightButton(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_init(button);
    ha_RightButton_setIntTypeBothEdges(button);
    ha_RightButton_registerInt(button, rightButtonIntHandler);
    ha_RightButton_enableInt(button);
}
/*............................................................................*/
static void setupEvents(void) {
    app_ev_BlinkTimeoutEvent_init(app_ev_BlinkTimeoutEvent_());
    app_ev_LeftButtonPressEvent_init(app_ev_LeftButtonPressEvent_());
    app_ev_PauseTimeoutEvent_init(app_ev_PauseTimeoutEvent_());
    app_ev_OnStartEvent_init(app_ev_OnStartEvent_());
    app_ev_RightButtonPressEvent_init(app_ev_RightButtonPressEvent_());
}
/*............................................................................*/
static void onIdle(void) {
    ha_SysCtrl_sleep();
}
/*............................................................................*/
static void onStart(void) {
    setupClockFrequency();
    setupSysTick();
    setupLeftButton();
    setupRightButton();
    vsk_Event_raise((vsk_Event *)app_ev_OnStartEvent_());
}
/*............................................................................*/
static void disableInt(void) {
    ha_Interrupt_masterDisable();
}
/*............................................................................*/
static void enableInt(void) {
    ha_Interrupt_masterEnable();
}
/*............................................................................*/
static void onAssert(void) {
    disableInt();
    ha_Led_setAllOff();
    ha_Led_setRedOn();
    ha_Led_setBlueOn();
    while (1) {
    }
}
/*............................................................................*/
int app_main(void) {
    static vsk_Node nodes[7];
    vsk_Kernel_init(
        vsk_Kernel_(),
        onStart,
        onIdle,
        disableInt,
        enableInt,
        onAssert,
        nodes,
        ut_lengthOf(nodes)
    );
    setupLeds();
    setupEvents();
    ut_Array * taskArray = ut_Array_init(
        ut_stkObj(ut_Array),
        ut_stkArr(void *, 1),
        1
    );
    ut_Array_insert(
        taskArray,
        app_tmb_TimeBombTask_init(app_tmb_TimeBombTask_()),
        0
    );
    vsk_Kernel_start(
        vsk_Kernel_(),
        taskArray
    );
    return 0;
}
