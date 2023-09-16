#include "App.h"
#include "BlinkyTask.h"
#include "BlueEvent.h"
#include "GreenEvent.h"
#include "RedEvent.h"
#include "hal/hal_SysClock.h"
#include "hal/hal_SysTick.h"
#include "led.h"
#include "state.h"
#include "utils/utils.h"
#include "vsos/vsos_Os.h"
#include "vsos/vsos_Scheduler.h"
#include "vsos/vsos_Task.h"
#include "vsos/vsos_TimeEvent.h"
#include <stdint.h>

static void setupClockFrequency(void) {
    hal_SysClock_setMaxFrequency();
}

static void sysTickInt(void) {
    vsos_Os_onSysTick(vsos_Os_(), hal_SysTick_getPeriodMillis());
}

static void setupSysTick(void) {
    hal_SysTick_intRegister(sysTickInt);
    hal_SysTick_intEnable();
    hal_SysTick_setPeriodMillis(1);
    hal_SysTick_enable();
}

static void setupEvents(void) {
    RedEvent_init(RedEvent_());
    BlueEvent_init(BlueEvent_());
    GreenEvent_init(GreenEvent_());
}

static void onIdle(void) {
}

void App_main(void) {
    setupClockFrequency();
    setupSysTick();
    LedInit();
    setupEvents();
    utils_Array * taskArray = utils_Array_init(
        utils_salloc(utils_Array),
        utils_salloca(void *, 1),
        1
    );
    utils_Array_insert(
        taskArray,
        BlinkyTask_init(
            BlinkyTask_(),
            utils_Queue_init(
                utils_salloc(utils_Queue),
                utils_Array_init(
                    utils_salloc(utils_Array),
                    utils_salloca(void *, 3),
                    3
                )
            )
        ),
        0
    );
    vsos_TimeEvent_arm(
        vsos_TimeEvent_init(
            utils_salloc(vsos_TimeEvent),
            (vsos_Event *)RedEvent_(),
            (vsos_Task *)BlinkyTask_()
        ),
        1,
        3000
    );
    vsos_TimeEvent_arm(
        vsos_TimeEvent_init(
            utils_salloc(vsos_TimeEvent),
            (vsos_Event *)BlueEvent_(),
            (vsos_Task *)BlinkyTask_()
        ),
        1000,
        3000
    );
    vsos_TimeEvent_arm(
        vsos_TimeEvent_init(
            utils_salloc(vsos_TimeEvent),
            (vsos_Event *)GreenEvent_(),
            (vsos_Task *)BlinkyTask_()
        ),
        2000,
        3000
    );
    vsos_Os_start(vsos_Os_init(vsos_Os_(), taskArray, onIdle));
}
