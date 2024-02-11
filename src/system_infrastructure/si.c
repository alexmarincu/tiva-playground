/*----------------------------------------------------------------------------*/
#include "../app/blinky/app_blk_BlinkyActObj.h"
#include "../app/buttons/app_btn_ButtonsActObj.h"
#include "../app/time_bomb/app_tmb_TimeBombActObj.h"
#include "../hw_abstraction/ha.h"
#include "../hw_abstraction/ha_LeftButton.h"
#include "../hw_abstraction/ha_RgbLed.h"
#include "../hw_abstraction/ha_RightButton.h"
#include "../hw_abstraction/ha_SysClock.h"
#include "../hw_abstraction/ha_SysCtrl.h"
#include "../hw_abstraction/ha_SysTick.h"
#include "../hw_abstraction/ha_SysTickSignal.h"
#include "../hw_abstraction/ha_TaskProcessingSignal.h"
#include "../hw_abstraction/ha_Uart.h"
#include "../system_infrastructure/events/si_ev.h"
#include "../system_infrastructure/events/si_ev_LeftButtonIntEvent.h"
#include "../system_infrastructure/events/si_ev_LeftButtonPressEvent.h"
#include "../system_infrastructure/events/si_ev_RightButtonIntEvent.h"
#include "../system_infrastructure/events/si_ev_RightButtonPressEvent.h"
#include "../utils/ut.h"
#include "../very_simple_kernel/vsk.h"
/*----------------------------------------------------------------------------*/
#define si_app_blk 0
#define si_app_tmb 1
#define si_app si_app_tmb
#define si_classicDebounce false
#define si_tickPeriodMillis 1
/*----------------------------------------------------------------------------*/
#if (si_classicDebounce == false)
static void si_leftButtonIntHandler(void);
static void si_setupLeftButton(void);
static void si_rightButtonIntHandler(void);
static void si_setupRightButton(void);
#else
static void si_buttonsTaskOperation(void * const obj);
static void si_activateButtonsTask(vsk_Task * const buttonsTask);
static void si_setupButtonsTask(void);
#endif
static void si_setupApps(void);
static void si_sysTickIntHandler(void);
static void si_setupSysTick(void);
static void si_onStart(void);
static void si_onIdle(void);
static void si_onCriticalSectionEnter(void);
static void si_onCriticalSectionExit(void);
static void si_onAssertFail(void);
#if (si_classicDebounce == false)
/*----------------------------------------------------------------------------*/
static void si_leftButtonIntHandler(void) {
    vsk_Event_raise((vsk_Event *)si_ev_LeftButtonIntEvent_());
    ha_LeftButton_clearIntFlag(ha_LeftButton_());
}
/*----------------------------------------------------------------------------*/
static void si_setupLeftButton(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_setIntTypeBothEdges(button);
    ha_LeftButton_registerInt(button, si_leftButtonIntHandler);
    ha_LeftButton_enableInt(button);
}
/*----------------------------------------------------------------------------*/
static void si_rightButtonIntHandler(void) {
    vsk_Event_raise((vsk_Event *)si_ev_RightButtonIntEvent_());
    ha_RightButton_clearIntFlag(ha_RightButton_());
}
/*----------------------------------------------------------------------------*/
static void si_setupRightButton(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_setIntTypeBothEdges(button);
    ha_RightButton_registerInt(button, si_rightButtonIntHandler);
    ha_RightButton_enableInt(button);
}
#else
/*----------------------------------------------------------------------------*/
static void si_buttonsTaskOperation(void * const obj) {
    static uint8_t leftButtonDebounceCount = 0;
    static uint8_t rightButtonDebounceCount = 0;
    if (ha_LeftButton_isPressed(ha_LeftButton_())) {
        leftButtonDebounceCount++;
        if (leftButtonDebounceCount == 2) {
            vsk_Event_raise((vsk_Event *)si_ev_LeftButtonPressEvent_());
        }
    } else {
        leftButtonDebounceCount = 0;
    }
    if (ha_RightButton_isPressed(ha_RightButton_())) {
        rightButtonDebounceCount++;
        if (rightButtonDebounceCount == 2) {
            vsk_Event_raise((vsk_Event *)si_ev_RightButtonPressEvent_());
        }
    } else {
        rightButtonDebounceCount = 0;
    }
}
/*----------------------------------------------------------------------------*/
static void si_activateButtonsTask(vsk_Task * const buttonsTask) {
    vsk_Task_activate(buttonsTask);
}
/*----------------------------------------------------------------------------*/
static void si_setupButtonsTask(void) {
    static vsk_Task buttonsTask;
    vsk_Task_init(
        &buttonsTask, (vsk_TaskOperation)si_buttonsTaskOperation, NULL
    );
    static vsk_Timer buttonsTaskTimer;
    vsk_Timer_start(
        vsk_Timer_init(
            &buttonsTaskTimer, 0, 20,
            (vsk_TimerCallback)si_activateButtonsTask, &buttonsTask
        )
    );
}
#endif
/*----------------------------------------------------------------------------*/
static void si_setupApps(void) {
#if (si_app == si_app_blk)
    app_blk_BlinkyActObj_init(app_blk_BlinkyActObj_());
#elif (si_app == si_app_tmb)
#if (si_classicDebounce == true)
    si_setupButtonsTask();
#else
    app_btn_ButtonsActObj_init(app_btn_ButtonsActObj_());
#endif
    app_tmb_TimeBombActObj_init(app_tmb_TimeBombActObj_());
#endif
}
/*----------------------------------------------------------------------------*/
static void si_sysTickIntHandler(void) {
    ha_SysTickSignal_setHigh();
    vsk_onSysTick();
    ha_SysTickSignal_setLow();
}
/*----------------------------------------------------------------------------*/
static void si_setupSysTick(void) {
    ha_SysTick * sysTick = ha_SysTick_();
    ha_SysTick_registerInt(sysTick, si_sysTickIntHandler);
    ha_SysTick_enableInt(sysTick);
    ha_SysTick_setPeriodMillis(sysTick, si_tickPeriodMillis);
    ha_SysTick_enable(sysTick);
}
/*----------------------------------------------------------------------------*/
static void si_onStart(void) {
    ha_init();
    ha_Uart_write("onStart\n");
#if (si_classicDebounce == false)
    si_setupLeftButton();
    si_setupRightButton();
#endif
    si_ev_init();
    ha_SysClock_setMaxFrequency();
    si_setupSysTick();
    si_setupApps();
}
/*----------------------------------------------------------------------------*/
static void si_onIdle(void) {
    ha_TaskProcessingSignal_setLow();
    // maybe put also peripherals in sleep / low power mode
    ha_SysCtrl_sleep();
    ha_TaskProcessingSignal_setHigh();
}
/*----------------------------------------------------------------------------*/
static void si_onCriticalSectionEnter(void) {
    ha_Interrupt_masterDisable();
}
/*----------------------------------------------------------------------------*/
static void si_onCriticalSectionExit(void) {
    ha_Interrupt_masterEnable();
}
/*----------------------------------------------------------------------------*/
static void si_onAssertFail(void) {
    ha_Interrupt_masterDisable();
    ha_RgbLed_setMagenta();
    while (1) {
    }
}
/*----------------------------------------------------------------------------*/
int si_main(void) {
    static vsk_Node nodes[20];
    vsk_start(
        si_tickPeriodMillis,
        si_onStart, si_onIdle,
        si_onCriticalSectionEnter, si_onCriticalSectionExit,
        si_onAssertFail,
        nodes, ut_lengthOf(nodes)
    );
    return 0;
}
