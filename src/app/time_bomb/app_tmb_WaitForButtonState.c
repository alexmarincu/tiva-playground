/*............................................................................*/
#include "app_tmb_WaitForButtonState.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_TimeBombActObj.h"
/*............................................................................*/
static void app_tmb_WaitForButtonState_onEnter(
    app_tmb_WaitForButtonState * const self
);
static void app_tmb_WaitForButtonState_onExit(
    app_tmb_WaitForButtonState * const self
);
static void app_tmb_WaitForButtonState_onLeftButtonPress(
    app_tmb_WaitForButtonState * const self
);
/*............................................................................*/
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_(void) {
    static app_tmb_WaitForButtonState self;
    return &self;
}
/*............................................................................*/
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_init(
    app_tmb_WaitForButtonState * const self,
    vsk_StateMachine * const stateMachine
) {
    app_tmb_ArmedState_init(
        &self->_super.armedState,
        stateMachine
    );
    self->_super.armedState._super.baseState._super.state._onEnter =
        (vsk_StateOnEnter)app_tmb_WaitForButtonState_onEnter;
    self->_super.armedState._super.baseState._super.state._onExit =
        (vsk_StateExit)app_tmb_WaitForButtonState_onExit;
    self->_super.armedState._super.baseState._onLeftButtonPress =
        (app_tmb_BaseStateHandler)app_tmb_WaitForButtonState_onLeftButtonPress;
    return self;
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_onEnter(
    app_tmb_WaitForButtonState * const self
) {
    ha_Led_setGreenOn();
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_onExit(
    app_tmb_WaitForButtonState * const self
) {
    ha_Led_setGreenOff();
}
/*............................................................................*/
static void app_tmb_WaitForButtonState_onLeftButtonPress(
    app_tmb_WaitForButtonState * const self
) {
    app_tmb_TimeBombActObj_setBlinkCounter(
        (app_tmb_TimeBombActObj *)
            self->_super.armedState._super.baseState._super.state._stateMachine,
        5
    );
    vsk_StateMachine_transition(
        self->_super.armedState._super.baseState._super.state._stateMachine,
        (vsk_State *)app_tmb_BlinkState_()
    );
}
