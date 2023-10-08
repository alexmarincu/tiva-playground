/*............................................................................*/
#include "app_blk_OnState.h"
#include "../../app/events/app_ev_OnTimeoutEvent.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_blk_BlinkyActObj.h"
#include "app_blk_OffState.h"
/*............................................................................*/
static void app_blk_OnState_setupEventSubscriptions(
    app_blk_OnState * const self
);
static void app_blk_OnState_onOnTimeout(
    app_blk_OnState * const self
);
static void app_blk_OnState_onEntry(
    app_blk_OnState * const self
);
static void app_blk_OnState_onExit(
    app_blk_OnState * const self
);
/*............................................................................*/
app_blk_OnState * app_blk_OnState_(void) {
    static app_blk_OnState self;
    return &self;
}
/*............................................................................*/
static void app_blk_OnState_setupEventSubscriptions(
    app_blk_OnState * const self
) {
    vsk_Event_subscribe(
        (vsk_Event *)app_ev_OnTimeoutEvent_(),
        vsk_EventSubscription_init(
            &self->_eventSubscriptions.onTimeout,
            vsk_StateMachine_getTask(self->_super.state._stateMachine),
            self,
            (vsk_MessageHandler)app_blk_OnState_onOnTimeout
        )
    );
}
/*............................................................................*/
app_blk_OnState * app_blk_OnState_init(
    app_blk_OnState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_super.state,
        stateMachine,
        (vsk_StateOnEntry)app_blk_OnState_onEntry,
        (vsk_StateOnExit)app_blk_OnState_onExit
    );
    app_blk_OnState_setupEventSubscriptions(self);
    vsk_EventTimer_init(
        &self->_onTimeoutEventTimer,
        (vsk_Event *)app_ev_OnTimeoutEvent_()
    );
    return self;
}
/*............................................................................*/
static void app_blk_OnState_onOnTimeout(
    app_blk_OnState * const self
) {
    if (vsk_State_isActive((vsk_State *)self)) {
        vsk_StateMachine_transition(
            self->_super.state._stateMachine,
            (vsk_State *)app_blk_OffState_()
        );
    }
}
/*............................................................................*/
static void app_blk_OnState_onEntry(
    app_blk_OnState * const self
) {
    ha_Led_setBlueOn();
    vsk_EventTimer_arm(
        &self->_onTimeoutEventTimer,
        200,
        0
    );
}
/*............................................................................*/
static void app_blk_OnState_onExit(
    app_blk_OnState * const self
) {
    ha_Led_setBlueOff();
}
