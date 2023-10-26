/*............................................................................*/
#include "app_blk_BlinkyActObj.h"
/*............................................................................*/
#include "../../system_infrastructure/events/si_ev_OffTimeoutEvent.h"
#include "../../system_infrastructure/events/si_ev_OnTimeoutEvent.h"
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
        (vsk_Event *)si_ev_OnTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.onTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onOnTimeout,
            self
        )
    );
    vsk_Event_subscribe(
        (vsk_Event *)si_ev_OffTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.offTimeout,
            &((vsk_ActiveObject *)self)->_inbox,
            (vsk_MessageHandler)app_blk_BlinkyActObj_onOffTimeout,
            self
        )
    );
    vsk_EventTimer_init(
        &self->eventTimers.onTimeout,
        200,
        0,
        (vsk_Event *)si_ev_OnTimeoutEvent_()
    );
    vsk_EventTimer_init(
        &self->eventTimers.offTimeout,
        200,
        0,
        (vsk_Event *)si_ev_OffTimeoutEvent_()
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
