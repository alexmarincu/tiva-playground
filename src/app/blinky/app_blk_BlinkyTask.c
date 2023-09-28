#include "app_blk_BlinkyTask.h"
#include "../../app/events/app_ev_BlueTimeoutEvent.h"
#include "../../app/events/app_ev_GreenTimeoutEvent.h"
#include "../../app/events/app_ev_LeftButtonPressEvent.h"
#include "../../app/events/app_ev_LeftButtonReleaseEvent.h"
#include "../../app/events/app_ev_RedTimeoutEvent.h"
#include "../../app/events/app_ev_RightButtonPressEvent.h"
#include "../../app/events/app_ev_RightButtonReleaseEvent.h"

#include "../../hw_abstraction/ha_Led.h"

struct app_blk_BlinkyTask {
    vsk_Task task;
    struct {
        vsk_EventSubscriber redEventSubscriber;
        vsk_EventSubscriber blueEventSubscriber;
        vsk_EventSubscriber greenEventSubscriber;
        vsk_EventSubscriber leftButtonPressEventSubscriber;
        vsk_EventSubscriber leftButtonReleaseEventSubscriber;
        vsk_EventSubscriber rightButtonPressEventSubscriber;
        vsk_EventSubscriber rightButtonReleaseEventSubscriber;
    } eventSubscribers;
};

static void app_blk_BlinkyTask_setupEventSubscribers(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onRedTimeout(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onBlueTimeout(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onGreenTimeout(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onLeftButtonPress(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onLeftButtonRelease(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onRightButtonPress(app_blk_BlinkyTask * const self);
static void app_blk_BlinkyTask_onRightButtonRelease(app_blk_BlinkyTask * const self);

app_blk_BlinkyTask * app_blk_BlinkyTask_(void) {
    static app_blk_BlinkyTask self;
    return &self;
}

static void app_blk_BlinkyTask_setupEventSubscribers(app_blk_BlinkyTask * const self) {
    vsk_EventSubscriber_init(
        &self->eventSubscribers.redEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onRedTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_RedTimeoutEvent_(), &self->eventSubscribers.redEventSubscriber);
    vsk_EventSubscriber_init(
        &self->eventSubscribers.blueEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onBlueTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_BlueTimeoutEvent_(), &self->eventSubscribers.blueEventSubscriber);
    vsk_EventSubscriber_init(
        &self->eventSubscribers.greenEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onGreenTimeout }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_GreenTimeoutEvent_(), &self->eventSubscribers.greenEventSubscriber);
    vsk_EventSubscriber_init(
        &self->eventSubscribers.leftButtonPressEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onLeftButtonPress }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_LeftButtonPressEvent_(), &self->eventSubscribers.leftButtonPressEventSubscriber);
    vsk_EventSubscriber_init(
        &self->eventSubscribers.leftButtonReleaseEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onLeftButtonRelease }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_LeftButtonReleaseEvent_(), &self->eventSubscribers.leftButtonReleaseEventSubscriber);
    vsk_EventSubscriber_init(
        &self->eventSubscribers.rightButtonPressEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onRightButtonPress }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_RightButtonPressEvent_(), &self->eventSubscribers.rightButtonPressEventSubscriber);
    vsk_EventSubscriber_init(
        &self->eventSubscribers.rightButtonReleaseEventSubscriber,
        (vsk_Task *)self,
        (vsk_TaskMessage){ (vsk_TaskHandler)app_blk_BlinkyTask_onRightButtonRelease }
    );
    vsk_Event_subscribe((vsk_Event *)app_ev_RightButtonReleaseEvent_(), &self->eventSubscribers.rightButtonReleaseEventSubscriber);
}

app_blk_BlinkyTask * app_blk_BlinkyTask_init(
    app_blk_BlinkyTask * const self,
    ut_Queue * const messageQueue
) {
    vsk_Task_init(&self->task, messageQueue);
    app_blk_BlinkyTask_setupEventSubscribers(self);
    return self;
}

static void app_blk_BlinkyTask_onRedTimeout(app_blk_BlinkyTask * const self) {
    ha_Led_setAllOff();
    ha_Led_setRedOn();
}

static void app_blk_BlinkyTask_onBlueTimeout(app_blk_BlinkyTask * const self) {
    ha_Led_setAllOff();
    ha_Led_setBlueOn();
}

static void app_blk_BlinkyTask_onGreenTimeout(app_blk_BlinkyTask * const self) {
    ha_Led_setAllOff();
    ha_Led_setGreenOn();
}

static void app_blk_BlinkyTask_onLeftButtonPress(app_blk_BlinkyTask * const self) {
    ha_Led_setGreenOn();
}

static void app_blk_BlinkyTask_onLeftButtonRelease(app_blk_BlinkyTask * const self) {
    ha_Led_setGreenOff();
}

static void app_blk_BlinkyTask_onRightButtonPress(app_blk_BlinkyTask * const self) {
    ha_Led_setRedOn();
}

static void app_blk_BlinkyTask_onRightButtonRelease(app_blk_BlinkyTask * const self) {
    ha_Led_setRedOff();
}
