/*............................................................................*/
#include "app_blk_BlinkyActObj.h"
#include "../../app/events/app_ev_OffTimeoutEvent.h"
#include "../../app/events/app_ev_OnTimeoutEvent.h"
#include "app_blk_OffState.h"
#include "app_blk_OnState.h"
/*............................................................................*/
static void app_blk_BlinkyActObj_onOnTimeout(app_blk_BlinkyActObj * const self);
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
        (vsk_ActiveObject *)self, (vsk_State *)app_blk_OnState_()
    );
    app_blk_OnState_init(app_blk_OnState_(), (vsk_StateContext *)self);
    app_blk_OffState_init(app_blk_OffState_(), (vsk_StateContext *)self);
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OnTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.onTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            self,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onOnTimeout
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OffTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.offTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            self,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onOffTimeout
        )
    );
    vsk_EventTimer_init(
        &self->_eventTimers.onTimeout,
        200,
        0,
        (vsk_Event *)app_ev_OnTimeoutEvent_()
    );
    vsk_EventTimer_init(
        &self->_eventTimers.offTimeout,
        200,
        0,
        (vsk_Event *)app_ev_OffTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_blk_BlinkyActObj_onOnTimeout(
    app_blk_BlinkyActObj * const self
) {
    app_blk_BlinkyState_onOnTimeout(
        (app_blk_BlinkyState *)((vsk_StateContext *)self)->_state
    );
}
/*............................................................................*/
static void app_blk_BlinkyActObj_onOffTimeout(
    app_blk_BlinkyActObj * const self
) {
    app_blk_BlinkyState_onOffTimeout(
        (app_blk_BlinkyState *)((vsk_StateContext *)self)->_state
    );
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
