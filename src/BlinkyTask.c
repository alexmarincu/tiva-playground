#include "BlinkyTask.h"
#include "BlueTimeoutEvent.h"
#include "GreenTimeoutEvent.h"
#include "RedTimeoutEvent.h"

#include "hal/hal_Led.h"

static void BlinkyTask_onRedTimeout(BlinkyTask * const self);
static void BlinkyTask_onBlueTimeout(BlinkyTask * const self);
static void BlinkyTask_onGreenTimeout(BlinkyTask * const self);

BlinkyTask * BlinkyTask_(void) {
    static BlinkyTask self;
    return &self;
}

BlinkyTask * BlinkyTask_init(
    BlinkyTask * const self,
    utl_Queue * const messageQueue
) {
    vsk_Task_init(&self->task, messageQueue);
    static vsk_TaskMessage redMessage;
    redMessage.receiver = (vsk_Task *)self,
    redMessage.handler = (vsk_TaskHandler)BlinkyTask_onRedTimeout;
    vsk_Event_register((vsk_Event *)RedTimeoutEvent_(), &redMessage);
    static vsk_TaskMessage blueMessage;
    blueMessage.receiver = (vsk_Task *)self,
    blueMessage.handler = (vsk_TaskHandler)BlinkyTask_onBlueTimeout;
    vsk_Event_register((vsk_Event *)BlueTimeoutEvent_(), &blueMessage);
    static vsk_TaskMessage greenMessage;
    greenMessage.receiver = (vsk_Task *)self,
    greenMessage.handler = (vsk_TaskHandler)BlinkyTask_onGreenTimeout;
    vsk_Event_register((vsk_Event *)GreenTimeoutEvent_(), &greenMessage);
    return self;
}

static void BlinkyTask_onRedTimeout(BlinkyTask * const self) {
    hal_Led_setRed();
}

static void BlinkyTask_onBlueTimeout(BlinkyTask * const self) {
    hal_Led_setBlue();
}

static void BlinkyTask_onGreenTimeout(BlinkyTask * const self) {
    hal_Led_setGreen();
}
