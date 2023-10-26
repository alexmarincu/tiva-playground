/*............................................................................*/
#include "../app/blinky/app_blk_BlinkyActObj.h"
#include "../app/buttons/app_btn_ButtonsActObj.h"
#include "../app/time_bomb/app_tmb_TimeBombActObj.h"
#include "../hw_abstraction/ha.h"
#include "../hw_abstraction/ha_Led.h"
#include "../hw_abstraction/ha_LeftButton.h"
#include "../hw_abstraction/ha_RightButton.h"
#include "../hw_abstraction/ha_SysClock.h"
#include "../hw_abstraction/ha_SysCtrl.h"
#include "../hw_abstraction/ha_SysTick.h"
#include "../hw_abstraction/ha_SysTickSignal.h"
#include "../hw_abstraction/ha_TaskProcessingSignal.h"
#include "../system_infrastructure/events/si_ev.h"
#include "../system_infrastructure/events/si_ev_LeftButtonIntEvent.h"
#include "../system_infrastructure/events/si_ev_LeftButtonPressEvent.h"
#include "../system_infrastructure/events/si_ev_RightButtonIntEvent.h"
#include "../system_infrastructure/events/si_ev_RightButtonPressEvent.h"
#include "../utils/ut.h"
#include "../very_simple_kernel/vsk.h"
#include "../very_simple_kernel/vsk_Time.h"
/*............................................................................*/
#define si_buttonIntFilterMillis 20
#define si_tickPeriodMillis 10
/*............................................................................*/
static void si_leftButtonIntHandler(void);
static void si_setupLeftButton(void);
static void si_rightButtonIntHandler(void);
static void si_setupRightButton(void);
// static void si_buttonsTaskOperation(void * const obj);
// static void si_activateButtonsTask(vsk_Task * const buttonsTask);
// static void si_setupButtonsTask(void);
static void si_setupApps(void);
static void si_sysTickIntHandler(void);
static void si_setupSysTick(void);
static void si_onStart(void);
static void si_onIdle(void);
static void si_onCriticalSectionEnter(void);
static void si_onCriticalSectionExit(void);
static void si_onAssertFail(void);
/*............................................................................*/
static void si_leftButtonIntHandler(void) {
    ha_LeftButton * button = ha_LeftButton_();
    static uint32_t lastMillisCount = 0;
    uint32_t millisCount = vsk_Time_getMillisCount(vsk_Time_());
    uint32_t timeElapsed = millisCount - lastMillisCount;
    if (millisCount < lastMillisCount) {
        timeElapsed = (UINT32_MAX - lastMillisCount + 1) + millisCount;
    }
    if (timeElapsed > si_buttonIntFilterMillis) {
        vsk_Event_raise((vsk_Event *)si_ev_LeftButtonIntEvent_());
        lastMillisCount = millisCount;
    }
    ha_LeftButton_clearIntFlag(button);
}
/*............................................................................*/
static void si_setupLeftButton(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_setIntTypeBothEdges(button);
    ha_LeftButton_registerInt(button, si_leftButtonIntHandler);
    ha_LeftButton_enableInt(button);
}
/*............................................................................*/
static void si_rightButtonIntHandler(void) {
    ha_RightButton * button = ha_RightButton_();
    static uint32_t lastMillisCount = 0;
    uint32_t millisCount = vsk_Time_getMillisCount(vsk_Time_());
    uint32_t timeElapsed = millisCount - lastMillisCount;
    if (millisCount < lastMillisCount) {
        timeElapsed = (UINT32_MAX - lastMillisCount + 1) + millisCount;
    }
    if (timeElapsed > si_buttonIntFilterMillis) {
        vsk_Event_raise((vsk_Event *)si_ev_RightButtonIntEvent_());
        lastMillisCount = millisCount;
    }
    ha_RightButton_clearIntFlag(button);
}
/*............................................................................*/
static void si_setupRightButton(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_setIntTypeBothEdges(button);
    ha_RightButton_registerInt(button, si_rightButtonIntHandler);
    ha_RightButton_enableInt(button);
}
/*............................................................................*/
// static void si_buttonsTaskOperation(void * const obj) {
//     static uint8_t leftButtonDebounceCount = 0;
//     static uint8_t rightButtonDebounceCount = 0;
//     if (ha_LeftButton_isPressed(ha_LeftButton_())) {
//         leftButtonDebounceCount++;
//         if (leftButtonDebounceCount == 2) {
//             vsk_Event_raise((vsk_Event *)si_ev_LeftButtonPressEvent_());
//         }
//     } else {
//         leftButtonDebounceCount = 0;
//     }
//     if (ha_RightButton_isPressed(ha_RightButton_())) {
//         rightButtonDebounceCount++;
//         if (rightButtonDebounceCount == 2) {
//             vsk_Event_raise((vsk_Event *)si_ev_RightButtonPressEvent_());
//         }
//     } else {
//         rightButtonDebounceCount = 0;
//     }
// }
// /*............................................................................*/
// static void si_activateButtonsTask(vsk_Task * const buttonsTask) {
//     vsk_Task_activate(buttonsTask);
// }
// /*............................................................................*/
// static void si_setupButtonsTask(void) {
//     static vsk_Task buttonsTask;
//     vsk_Task_init(
//         &buttonsTask, (vsk_TaskOperation)si_buttonsTaskOperation, NULL
//     );
//     static vsk_Timer buttonsTaskTimer;
//     vsk_Timer_start(
//         vsk_Timer_init(
//             &buttonsTaskTimer,
//             0,
//             10,
//             (vsk_TimerCallback)si_activateButtonsTask,
//             &buttonsTask
//         )
//     );
// }
/*............................................................................*/
static void si_setupApps(void) {
    // app_blk_BlinkyActObj_init(app_blk_BlinkyActObj_());
    // si_setupButtonsTask();
    app_btn_ButtonsActObj_init(app_btn_ButtonsActObj_());
    app_tmb_TimeBombActObj_init(app_tmb_TimeBombActObj_());
}
/*............................................................................*/
static void si_sysTickIntHandler(void) {
    ha_SysTickSignal_setHigh();
    vsk_onSysTick();
    ha_SysTickSignal_setLow();
}
/*............................................................................*/
static void si_setupSysTick(void) {
    ha_SysTick * sysTick = ha_SysTick_();
    ha_SysTick_registerInt(sysTick, si_sysTickIntHandler);
    ha_SysTick_enableInt(sysTick);
    ha_SysTick_setPeriodMillis(sysTick, si_tickPeriodMillis);
    ha_SysTick_enable(sysTick);
}
/*............................................................................*/
static void si_onStart(void) {
    ha_init();
    si_setupLeftButton();
    si_setupRightButton();
    si_ev_initEvents();
    ha_SysClock_setMaxFrequency();
    si_setupSysTick();
    si_setupApps();
}
/*............................................................................*/
static void si_onIdle(void) {
    ha_TaskProcessingSignal_setLow();
    // maybe put also peripherals in sleep / low power mode
    ha_SysCtrl_sleep();
    ha_TaskProcessingSignal_setHigh();
}
/*............................................................................*/
static void si_onCriticalSectionEnter(void) {
    ha_Interrupt_masterDisable();
}
/*............................................................................*/
static void si_onCriticalSectionExit(void) {
    ha_Interrupt_masterEnable();
}
/*............................................................................*/
static void si_onAssertFail(void) {
    ha_Interrupt_masterDisable();
    ha_Led_setAllOff();
    ha_Led_setRedOn();
    ha_Led_setBlueOn();
    while (1) {
    }
}
/*............................................................................*/
int si_main(void) {
    static vsk_Node nodes[20];
    vsk_start(
        si_tickPeriodMillis,
        si_onStart,
        si_onIdle,
        si_onCriticalSectionEnter,
        si_onCriticalSectionExit,
        si_onAssertFail,
        nodes,
        ut_lengthOf(nodes)
    );
    return 0;
}
