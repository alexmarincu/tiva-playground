#include "BlinkyTask.h"
#include "../evp/BlueTimeoutEvent.h"
#include "../evp/GreenTimeoutEvent.h"
#include "../evp/LButtonPressEvent.h"
#include "../evp/LButtonReleaseEvent.h"
#include "../evp/RButtonPressEvent.h"
#include "../evp/RButtonReleaseEvent.h"
#include "../evp/RedTimeoutEvent.h"

#include "../hal/hal_Led.h"

static void BlinkyTask_onRedTimeout(BlinkyTask * const self);
static void BlinkyTask_onBlueTimeout(BlinkyTask * const self);
static void BlinkyTask_onGreenTimeout(BlinkyTask * const self);
static void BlinkyTask_onLButtonPress(BlinkyTask * const self);
static void BlinkyTask_onLButtonRelease(BlinkyTask * const self);
static void BlinkyTask_onRButtonPress(BlinkyTask * const self);
static void BlinkyTask_onRButtonRelease(BlinkyTask * const self);

BlinkyTask * BlinkyTask_(void) {
    static BlinkyTask self;
    return &self;
}

BlinkyTask * BlinkyTask_init(
    BlinkyTask * const self,
    utl_Queue * const messageQueue
) {
    vsk_Task_init(&self->task, messageQueue);
    static vsk_EventClient redEventClient;
    redEventClient.task = (vsk_Task *)self,
    redEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onRedTimeout };
    vsk_Event_subscribe((vsk_Event *)RedTimeoutEvent_(), &redEventClient);
    static vsk_EventClient blueEventClient;
    blueEventClient.task = (vsk_Task *)self,
    blueEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onBlueTimeout };
    vsk_Event_subscribe((vsk_Event *)BlueTimeoutEvent_(), &blueEventClient);
    static vsk_EventClient greenEventClient;
    greenEventClient.task = (vsk_Task *)self,
    greenEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onGreenTimeout };
    vsk_Event_subscribe((vsk_Event *)GreenTimeoutEvent_(), &greenEventClient);
    static vsk_EventClient lButtonPressEventClient;
    lButtonPressEventClient.task = (vsk_Task *)self,
    lButtonPressEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onLButtonPress };
    vsk_Event_subscribe((vsk_Event *)LButtonPressEvent_(), &lButtonPressEventClient);
    static vsk_EventClient lButtonReleaseEventClient;
    lButtonReleaseEventClient.task = (vsk_Task *)self,
    lButtonReleaseEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onLButtonRelease };
    vsk_Event_subscribe((vsk_Event *)LButtonReleaseEvent_(), &lButtonReleaseEventClient);
    static vsk_EventClient rButtonPressEventClient;
    rButtonPressEventClient.task = (vsk_Task *)self,
    rButtonPressEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onRButtonPress };
    vsk_Event_subscribe((vsk_Event *)RButtonPressEvent_(), &rButtonPressEventClient);
    static vsk_EventClient rButtonReleaseEventClient;
    rButtonReleaseEventClient.task = (vsk_Task *)self,
    rButtonReleaseEventClient.message = (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onRButtonRelease };
    vsk_Event_subscribe((vsk_Event *)RButtonReleaseEvent_(), &rButtonReleaseEventClient);
    return self;
}

static void BlinkyTask_onRedTimeout(BlinkyTask * const self) {
    // hal_Led_setAllOff();
    // hal_Led_setRedOn();
}

static void BlinkyTask_onBlueTimeout(BlinkyTask * const self) {
    // hal_Led_setAllOff();
    // hal_Led_setBlueOn();
}

static void BlinkyTask_onGreenTimeout(BlinkyTask * const self) {
    // hal_Led_setAllOff();
    // hal_Led_setGreenOn();
}

static void BlinkyTask_onLButtonPress(BlinkyTask * const self) {
    hal_Led_setGreenOn();
}

static void BlinkyTask_onLButtonRelease(BlinkyTask * const self) {
    hal_Led_setGreenOff();
}

static void BlinkyTask_onRButtonPress(BlinkyTask * const self) {
    hal_Led_setRedOn();
}

static void BlinkyTask_onRButtonRelease(BlinkyTask * const self) {
    hal_Led_setRedOff();
}
