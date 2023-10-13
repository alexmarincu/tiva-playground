/*............................................................................*/
#include "app_tmb_ArmedState.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_DefusedState.h"
/*............................................................................*/
static void app_tmb_ArmedState_onExit(
    app_tmb_ArmedState * const self
);
static void app_tmb_ArmedState_onRightButtonPress(
    app_tmb_ArmedState * const self
);
/*............................................................................*/
app_tmb_ArmedState * app_tmb_ArmedState_init(
    app_tmb_ArmedState * const self,
    vsk_StateMachine * const stateMachine
) {
    app_tmb_BaseState_init(
        &self->_super.baseState,
        stateMachine
    );
    ((vsk_State *)self)->_onExit = (vsk_StateOnEnter)app_tmb_ArmedState_onExit;
    ((app_tmb_BaseState *)self)->_onRightButtonPress =
        (app_tmb_BaseStateHandler)app_tmb_ArmedState_onRightButtonPress;
    return self;
}
/*............................................................................*/
static void app_tmb_ArmedState_onExit(
    app_tmb_ArmedState * const self
) {
    ha_Led_setAllOff();
}
/*............................................................................*/
static void app_tmb_ArmedState_onRightButtonPress(
    app_tmb_ArmedState * const self
) {
    vsk_StateMachine_transition(
        self->_super.baseState._super.state._stateMachine,
        (vsk_State *)app_tmb_DefusedState_()
    );
}
