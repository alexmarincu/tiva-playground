/*............................................................................*/
#include "app_tmb_BoomState.h"
#include "../../hw_abstraction/ha_Led.h"
/*............................................................................*/
static void app_tmb_BoomState_onEntry(
    app_tmb_BoomState * const self
);
static void app_tmb_BoomState_onExit(
    app_tmb_BoomState * const self
);
/*............................................................................*/
app_tmb_BoomState * app_tmb_BoomState_(void) {
    static app_tmb_BoomState self;
    return &self;
}
/*............................................................................*/
app_tmb_BoomState * app_tmb_BoomState_init(
    app_tmb_BoomState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_state,
        stateMachine,
        (vsk_StateOnEntry)app_tmb_BoomState_onEntry,
        (vsk_StateOnExit)app_tmb_BoomState_onExit
    );
    return self;
}
/*............................................................................*/
static void app_tmb_BoomState_onEntry(
    app_tmb_BoomState * const self
) {
    ha_Led_setAllOn();
}
/*............................................................................*/
static void app_tmb_BoomState_onExit(
    app_tmb_BoomState * const self
) {}
