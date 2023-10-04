/*............................................................................*/
#include "app_tmb_DefusedState.h"
#include "../../hw_abstraction/ha_Led.h"
/*............................................................................*/
static void app_tmb_DefusedState_onEntry(
    app_tmb_DefusedState * const self
);
static void app_tmb_DefusedState_onExit(
    app_tmb_DefusedState * const self
);
/*............................................................................*/
app_tmb_DefusedState * app_tmb_DefusedState_(void) {
    static app_tmb_DefusedState self;
    return &self;
}
/*............................................................................*/
app_tmb_DefusedState * app_tmb_DefusedState_init(
    app_tmb_DefusedState * const self,
    vsk_StateMachine * const stateMachine
) {
    vsk_State_init(
        &self->_state,
        stateMachine,
        (vsk_StateOnEntry)app_tmb_DefusedState_onEntry,
        (vsk_StateOnExit)app_tmb_DefusedState_onExit
    );
    return self;
}
/*............................................................................*/
static void app_tmb_DefusedState_onEntry(
    app_tmb_DefusedState * const self
) {
    ha_Led_setBlueOn();
}
/*............................................................................*/
static void app_tmb_DefusedState_onExit(
    app_tmb_DefusedState * const self
) {
}
