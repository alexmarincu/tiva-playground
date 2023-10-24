/*............................................................................*/
#include "../hw_abstraction/ha_Led.h"
#include "../hw_abstraction/ha_LeftButton.h"
#include "../hw_abstraction/ha_RightButton.h"
#include "../hw_abstraction/ha_SysClock.h"
#include "../hw_abstraction/ha_SysCtrl.h"
#include "../hw_abstraction/ha_SysTick.h"
#include "../utils/ut.h"
#include "../very_simple_kernel/vsk_Kernel.h"
#include "blinky/app_blk_BlinkyActObj.h"
#include "buttons/app_btn_ButtonsActObj.h"
#include "events/app_ev.h"
#include "events/app_ev_LeftButtonIntEvent.h"
#include "events/app_ev_LeftButtonPressEvent.h"
#include "events/app_ev_RightButtonIntEvent.h"
#include "events/app_ev_RightButtonPressEvent.h"
#include "time_bomb/app_tmb_TimeBombActObj.h"
/*............................................................................*/
#define app_buttonIntFilterMillis 20
/*............................................................................*/
static void leftButtonIntHandler(void);
static void app_setupLeftButton(void);
static void rightButtonIntHandler(void);
static void app_setupRightButton(void);
static void app_setupApps(void);
static void sysTickIntHandler(void);
static void app_setupSysTick(void);
static void onKernelStart(void);
static void onIdle(void);
static void onCriticalSectionEnter(void);
static void onCriticalSectionExit(void);
static void onAssertFail(void);
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
static void app_setupLeftButton(void) {
    ha_LeftButton * button = ha_LeftButton_();
    ha_LeftButton_init(button);
    ha_LeftButton_setIntTypeBothEdges(button);
    ha_LeftButton_registerInt(button, leftButtonIntHandler);
    ha_LeftButton_enableInt(button);
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
static void app_setupRightButton(void) {
    ha_RightButton * button = ha_RightButton_();
    ha_RightButton_init(button);
    ha_RightButton_setIntTypeBothEdges(button);
    ha_RightButton_registerInt(button, rightButtonIntHandler);
    ha_RightButton_enableInt(button);
}
/*............................................................................*/
// static void buttonsTaskOperation(void * const obj) {
//     static bool isLeftButtonPressed = false;
//     static bool isRightButtonPressed = false;
//     if (ha_LeftButton_isPressed(ha_LeftButton_())) {
//         if (!isLeftButtonPressed) {
//             isLeftButtonPressed = true;
//         }
//     } else {
//         if (isLeftButtonPressed) {
//             vsk_Event_raise((vsk_Event *)app_ev_LeftButtonPressEvent_());
//         }
//         isLeftButtonPressed = false;
//     }
//     if (ha_RightButton_isPressed(ha_RightButton_())) {
//         if (!isRightButtonPressed) {
//             isRightButtonPressed = true;
//         }
//     } else {
//         if (isRightButtonPressed) {
//             vsk_Event_raise((vsk_Event *)app_ev_RightButtonPressEvent_());
//         }
//         isRightButtonPressed = false;
//     }
// }
/*............................................................................*/
// static void activateButtonsTask(vsk_Task * const buttonsTask) {
//     vsk_Task_activate(buttonsTask);
// }
/*............................................................................*/
static void app_setupApps(void) {
    // app_blk_BlinkyActObj_init(app_blk_BlinkyActObj_());
    // static vsk_Task buttonsTask;
    // vsk_Task_init(
    //     &buttonsTask, (vsk_TaskOperation)buttonsTaskOperation, NULL
    // );
    // static vsk_Timer buttonsTaskTimer;
    // vsk_Timer_start(
    //     vsk_Timer_init(
    //         &buttonsTaskTimer,
    //         1,
    //         20,
    //         (vsk_TimerCallback)activateButtonsTask,
    //         &buttonsTask
    //     )
    // );
    app_btn_ButtonsActObj_init(app_btn_ButtonsActObj_());
    app_tmb_TimeBombActObj_init(app_tmb_TimeBombActObj_());
}
/*............................................................................*/
static void sysTickIntHandler(void) {
    vsk_Kernel_onSysTick(vsk_Kernel_());
}
/*............................................................................*/
static void app_setupSysTick(void) {
    ha_SysTick * sysTick = ha_SysTick_();
    ha_SysTick_init(sysTick);
    ha_SysTick_registerInt(sysTick, sysTickIntHandler);
    ha_SysTick_enableInt(sysTick);
    ha_SysTick_setPeriodMillis(sysTick, 1);
    vsk_Kernel_informTickPeriodMillis(
        vsk_Kernel_(), ha_SysTick_getPeriodMillis(sysTick)
    );
    ha_SysTick_enable(sysTick);
}
/*............................................................................*/
static void onKernelStart(void) {
    app_setupLeftButton();
    app_setupRightButton();
    ha_Led_init();
    app_ev_initEvents();
    app_setupApps();
    ha_SysClock_setMaxFrequency();
    app_setupSysTick();
}
/*............................................................................*/
static void onIdle(void) {
    // maybe put also peripherals in sleep / low power mode
    ha_SysCtrl_sleep();
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
    static vsk_Node nodes[20];
    vsk_Kernel_start(
        vsk_Kernel_init(
            vsk_Kernel_(),
            onKernelStart,
            onIdle,
            onCriticalSectionEnter,
            onCriticalSectionExit,
            onAssertFail,
            nodes,
            ut_lengthOf(nodes)
        )
    );
    return 0;
}
