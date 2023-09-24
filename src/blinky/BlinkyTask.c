#include "BlinkyTask.h"
#include "../evp/BlueTimeoutEvent.h"
#include "../evp/GreenTimeoutEvent.h"
#include "../evp/LButtonPressEvent.h"
#include "../evp/LButtonReleaseEvent.h"
#include "../evp/RButtonPressEvent.h"
#include "../evp/RButtonReleaseEvent.h"
#include "../evp/RedTimeoutEvent.h"

#include "../hal/hal_Led.h"

struct BlinkyTask {
    vsk_Task task;
    vsk_EventSubscriber redEventSubscriber;
    vsk_EventSubscriber blueEventSubscriber;
    vsk_EventSubscriber greenEventSubscriber;
    vsk_EventSubscriber lButtonPressEventSubscriber;
    vsk_EventSubscriber lButtonReleaseEventSubscriber;
    vsk_EventSubscriber rButtonPressEventSubscriber;
    vsk_EventSubscriber rButtonReleaseEventSubscriber;
};

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
    vsk_EventSubscriber_init(
        &self->redEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onRedTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)RedTimeoutEvent_(), &self->redEventSubscriber);
    vsk_EventSubscriber_init(
        &self->blueEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onBlueTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)BlueTimeoutEvent_(), &self->blueEventSubscriber);
    vsk_EventSubscriber_init(
        &self->greenEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onGreenTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)GreenTimeoutEvent_(), &self->greenEventSubscriber);
    vsk_EventSubscriber_init(
        &self->lButtonPressEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onLButtonPress }
    );
    vsk_Event_subscribe((vsk_Event *)LButtonPressEvent_(), &self->lButtonPressEventSubscriber);
    vsk_EventSubscriber_init(
        &self->lButtonReleaseEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onLButtonRelease }
    );
    vsk_Event_subscribe((vsk_Event *)LButtonReleaseEvent_(), &self->lButtonReleaseEventSubscriber);
    vsk_EventSubscriber_init(
        &self->rButtonPressEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onRButtonPress }
    );
    vsk_Event_subscribe((vsk_Event *)RButtonPressEvent_(), &self->rButtonPressEventSubscriber);
    vsk_EventSubscriber_init(
        &self->rButtonReleaseEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)BlinkyTask_onRButtonRelease }
    );
    vsk_Event_subscribe((vsk_Event *)RButtonReleaseEvent_(), &self->rButtonReleaseEventSubscriber);
    return self;
}

static void BlinkyTask_onRedTimeout(BlinkyTask * const self) {
    hal_Led_setAllOff();
    hal_Led_setRedOn();
}

static void BlinkyTask_onBlueTimeout(BlinkyTask * const self) {
    hal_Led_setAllOff();
    hal_Led_setBlueOn();
}

static void BlinkyTask_onGreenTimeout(BlinkyTask * const self) {
    hal_Led_setAllOff();
    hal_Led_setGreenOn();
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
