/*............................................................................*/
#include "../app/blinky/app_blk_BlinkyActObj.h"
#include "../app/buttons/app_btn_ButtonsTask.h"
#include "../app/time_bomb/app_tmb_TimeBombActObj.h"
#include "../hw_abstraction/ha_Led.h"
#include "../hw_abstraction/ha_LeftButton.h"
#include "../hw_abstraction/ha_RightButton.h"
#include "../hw_abstraction/ha_SysClock.h"
#include "../hw_abstraction/ha_SysCtrl.h"
#include "../hw_abstraction/ha_SysTick.h"
#include "../utils/ut.h"
#include "../very_simple_kernel/vsk_Kernel.h"
#include "events/app_ev_BlinkTimeoutEvent.h"
#include "events/app_ev_LeftButtonDebounceTimeoutEvent.h"
#include "events/app_ev_LeftButtonIntEvent.h"
#include "events/app_ev_LeftButtonPressEvent.h"
#include "events/app_ev_OffTimeoutEvent.h"
#include "events/app_ev_OnTimeoutEvent.h"
#include "events/app_ev_PauseTimeoutEvent.h"
#include "events/app_ev_RightButtonDebounceTimeoutEvent.h"
#include "events/app_ev_RightButtonIntEvent.h"
#include "events/app_ev_RightButtonPressEvent.h"
/*............................................................................*/
#define app_buttonIntFilterMillis 20
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
static void onKernelStart(void);
static void onCriticalSectionEnter(void);
static void onCriticalSectionExit(void);
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
    static uint32_t lastMillisCount = 0;
    uint32_t millisCount = vsk_Time_getMillisCount(vsk_Time_());
    uint32_t timeElapsed = millisCount - lastMillisCount;
    if (millisCount < lastMillisCount) {
        timeElapsed = (UINT32_MAX - lastMillisCount + 1) + millisCount;
    }
    if (timeElapsed > app_buttonIntFilterMillis) {
        vsk_Event_raise((vsk_Event *)app_ev_LeftButtonIntEvent_());
        lastMillisCount = millisCount;
    }
    ha_LeftButton_clearIntFlag(button);
}
/*............................................................................*/
static void rightButtonIntHandler(void) {
    ha_RightButton * button = ha_RightButton_();
    static uint32_t lastMillisCount = 0;
    uint32_t millisCount = vsk_Time_getMillisCount(vsk_Time_());
    uint32_t timeElapsed = millisCount - lastMillisCount;
    if (millisCount < lastMillisCount) {
        timeElapsed = (UINT32_MAX - lastMillisCount + 1) + millisCount;
    }
    if (timeElapsed > app_buttonIntFilterMillis) {
        vsk_Event_raise((vsk_Event *)app_ev_RightButtonIntEvent_());
        lastMillisCount = millisCount;
    }
    ha_RightButton_clearIntFlag(button);
}
/*............................................................................*/
static void setupSysTick(void) {
    ha_SysTick * sysTick = ha_SysTick_();
    ha_SysTick_init(sysTick);
    ha_SysTick_registerInt(sysTick, sysTickIntHandler);
    ha_SysTick_enableInt(sysTick);
    ha_SysTick_setPeriodMillis(sysTick, 1);
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
    app_ev_LeftButtonIntEvent_init(app_ev_LeftButtonIntEvent_());
    app_ev_LeftButtonDebounceTimeoutEvent_init(
        app_ev_LeftButtonDebounceTimeoutEvent_()
    );
    app_ev_PauseTimeoutEvent_init(app_ev_PauseTimeoutEvent_());
    app_ev_RightButtonPressEvent_init(app_ev_RightButtonPressEvent_());
    app_ev_RightButtonIntEvent_init(app_ev_RightButtonIntEvent_());
    app_ev_RightButtonDebounceTimeoutEvent_init(
        app_ev_RightButtonDebounceTimeoutEvent_()
    );
    app_ev_OnTimeoutEvent_init(app_ev_OnTimeoutEvent_());
    app_ev_OffTimeoutEvent_init(app_ev_OffTimeoutEvent_());
}
/*............................................................................*/
static void onIdle(void) {
    // maybe put also peripherals in sleep / low power mode
    ha_SysCtrl_sleep();
}
/*............................................................................*/
static void onKernelStart(void) {
    setupClockFrequency();
    setupSysTick();
    setupLeftButton();
    setupRightButton();
}
/*............................................................................*/
static void onCriticalSectionEnter(void) {
    ha_Interrupt_masterDisable();
}
/*............................................................................*/
static void onCriticalSectionExit(void) {
    ha_Interrupt_masterEnable();
}
/*............................................................................*/
static void onAssertFail(void) {
    ha_Interrupt_masterDisable();
    ha_Led_setAllOff();
    ha_Led_setRedOn();
    ha_Led_setBlueOn();
    while (1) {
    }
}
/*............................................................................*/
int app_main(void) {
    static vsk_Node nodes[18];
    vsk_Kernel_init(
        vsk_Kernel_(),
        onKernelStart,
        onIdle,
        onCriticalSectionEnter,
        onCriticalSectionExit,
        onAssertFail,
        nodes,
        ut_lengthOf(nodes)
    );
    setupLeds();
    setupEvents();
    // app_blk_BlinkyActObj_init(app_blk_BlinkyActObj_());
    app_btn_ButtonsTask_init(app_btn_ButtonsTask_());
    app_tmb_TimeBombActObj_init(app_tmb_TimeBombActObj_());
    vsk_Kernel_start(vsk_Kernel_());
    return 0;
}
