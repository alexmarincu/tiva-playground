/*............................................................................*/
#include "app_blk_BlinkyActObj.h"
#include "../../app/events/app_ev_OffTimeoutEvent.h"
#include "../../app/events/app_ev_OnTimeoutEvent.h"
#include "app_blk_OffState.h"
#include "app_blk_OnState.h"
/*............................................................................*/
static void app_blk_BlinkyActObj_onOnTimeout(
    app_blk_BlinkyActObj * const self
);
static void app_blk_BlinkyActObj_onOffTimeout(
    app_blk_BlinkyActObj * const self
);
/*............................................................................*/
app_blk_BlinkyActObj * app_blk_BlinkyActObj_(void) {
    static app_blk_BlinkyActObj self;
    return &self;
}
/*............................................................................*/
app_blk_BlinkyActObj * app_blk_BlinkyActObj_init(
    app_blk_BlinkyActObj * const self
) {
    vsk_ActiveObject_init(
        &self->_super.actObj,
        (vsk_State *)app_blk_OnState_()
    );
    app_blk_OnState_init(
        app_blk_OnState_(),
        &self->_super.actObj._super.stateMachine
    );
    app_blk_OffState_init(
        app_blk_OffState_(),
        &self->_super.actObj._super.stateMachine
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OnTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.onTimeout,
            &self->_super.actObj._inbox,
            self,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onOnTimeout
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OffTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.offTimeout,
            &self->_super.actObj._inbox,
            self,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onOffTimeout
        )
    );
    vsk_EventTimer_init(
        &self->_eventTimers.onTimeout,
        (vsk_Event *)app_ev_OnTimeoutEvent_()
    );
    vsk_EventTimer_init(
        &self->_eventTimers.offTimeout,
        (vsk_Event *)app_ev_OffTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_blk_BlinkyActObj_onOnTimeout(
    app_blk_BlinkyActObj * const self
) {
    app_blk_BaseState * baseState =
        (app_blk_BaseState *)self->_super.actObj._super.stateMachine._state;
    baseState->_onOnTimeout(baseState);
}
/*............................................................................*/
static void app_blk_BlinkyActObj_onOffTimeout(
    app_blk_BlinkyActObj * const self
) {
    app_blk_BaseState * baseState =
        (app_blk_BaseState *)self->_super.actObj._super.stateMachine._state;
    baseState->_onOffTimeout(baseState);
}
/*............................................................................*/
vsk_EventTimer * app_blk_BlinkyActObj_getOnTimeoutEventTimer(
    app_blk_BlinkyActObj * const self
) {
    return &self->_eventTimers.onTimeout;
}
/*............................................................................*/
vsk_EventTimer * app_blk_BlinkyActObj_getOffTimeoutEventTimer(
    app_blk_BlinkyActObj * const self
) {
    return &self->_eventTimers.offTimeout;
}
