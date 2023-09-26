#include "blk_BlinkyTask.h"
#include "../events/ev_BlueTimeoutEvent.h"
#include "../events/ev_GreenTimeoutEvent.h"
#include "../events/ev_LeftButtonPressEvent.h"
#include "../events/ev_LeftButtonReleaseEvent.h"
#include "../events/ev_RedTimeoutEvent.h"
#include "../events/ev_RightButtonPressEvent.h"
#include "../events/ev_RightButtonReleaseEvent.h"

#include "../hw_abstraction/ha_Led.h"

struct blk_BlinkyTask {
    vsk_Task task;
    vsk_EventSubscriber redEventSubscriber;
    vsk_EventSubscriber blueEventSubscriber;
    vsk_EventSubscriber greenEventSubscriber;
    vsk_EventSubscriber lButtonPressEventSubscriber;
    vsk_EventSubscriber lButtonReleaseEventSubscriber;
    vsk_EventSubscriber rButtonPressEventSubscriber;
    vsk_EventSubscriber rButtonReleaseEventSubscriber;
};

static void blk_BlinkyTask_onRedTimeout(blk_BlinkyTask * const self);
static void blk_BlinkyTask_onBlueTimeout(blk_BlinkyTask * const self);
static void blk_BlinkyTask_onGreenTimeout(blk_BlinkyTask * const self);
static void blk_BlinkyTask_onLButtonPress(blk_BlinkyTask * const self);
static void blk_BlinkyTask_onLButtonRelease(blk_BlinkyTask * const self);
static void blk_BlinkyTask_onRButtonPress(blk_BlinkyTask * const self);
static void blk_BlinkyTask_onRButtonRelease(blk_BlinkyTask * const self);

blk_BlinkyTask * blk_BlinkyTask_(void) {
    static blk_BlinkyTask self;
    return &self;
}

blk_BlinkyTask * blk_BlinkyTask_init(
    blk_BlinkyTask * const self,
    ut_Queue * const messageQueue
) {
    vsk_Task_init(&self->task, messageQueue);
    vsk_EventSubscriber_init(
        &self->redEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onRedTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)ev_RedTimeoutEvent_(), &self->redEventSubscriber);
    vsk_EventSubscriber_init(
        &self->blueEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onBlueTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)ev_BlueTimeoutEvent_(), &self->blueEventSubscriber);
    vsk_EventSubscriber_init(
        &self->greenEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onGreenTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)ev_GreenTimeoutEvent_(), &self->greenEventSubscriber);
    vsk_EventSubscriber_init(
        &self->lButtonPressEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onLButtonPress }
    );
    vsk_Event_subscribe((vsk_Event *)ev_LeftButtonPressEvent_(), &self->lButtonPressEventSubscriber);
    vsk_EventSubscriber_init(
        &self->lButtonReleaseEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onLButtonRelease }
    );
    vsk_Event_subscribe((vsk_Event *)ev_LeftButtonReleaseEvent_(), &self->lButtonReleaseEventSubscriber);
    vsk_EventSubscriber_init(
        &self->rButtonPressEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onRButtonPress }
    );
    vsk_Event_subscribe((vsk_Event *)ev_RightButtonPressEvent_(), &self->rButtonPressEventSubscriber);
    vsk_EventSubscriber_init(
        &self->rButtonReleaseEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)blk_BlinkyTask_onRButtonRelease }
    );
    vsk_Event_subscribe((vsk_Event *)ev_RightButtonReleaseEvent_(), &self->rButtonReleaseEventSubscriber);
    return self;
}

static void blk_BlinkyTask_onRedTimeout(blk_BlinkyTask * const self) {
    ha_Led_setAllOff();
    ha_Led_setRedOn();
}

static void blk_BlinkyTask_onBlueTimeout(blk_BlinkyTask * const self) {
    ha_Led_setAllOff();
    ha_Led_setBlueOn();
}

static void blk_BlinkyTask_onGreenTimeout(blk_BlinkyTask * const self) {
    ha_Led_setAllOff();
    ha_Led_setGreenOn();
}

static void blk_BlinkyTask_onLButtonPress(blk_BlinkyTask * const self) {
    ha_Led_setGreenOn();
}

static void blk_BlinkyTask_onLButtonRelease(blk_BlinkyTask * const self) {
    ha_Led_setGreenOff();
}

static void blk_BlinkyTask_onRButtonPress(blk_BlinkyTask * const self) {
    ha_Led_setRedOn();
}

static void blk_BlinkyTask_onRButtonRelease(blk_BlinkyTask * const self) {
    ha_Led_setRedOff();
}
