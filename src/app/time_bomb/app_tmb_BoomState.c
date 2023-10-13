/*............................................................................*/
#include "app_tmb_BoomState.h"
#include "../../hw_abstraction/ha_Led.h"
/*............................................................................*/
static void app_tmb_BoomState_onEnter(
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
    app_tmb_BaseState_init(
        &self->_super.baseState,
        stateMachine
    );
    self->_super.baseState._super.state._onEnter =
        (vsk_StateOnEnter)app_tmb_BoomState_onEnter;
    return self;
}
/*............................................................................*/
static void app_tmb_BoomState_onEnter(
    app_tmb_BoomState * const self
) {
    ha_Led_setAllOn();
}
