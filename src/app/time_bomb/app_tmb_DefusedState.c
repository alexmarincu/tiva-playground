/*............................................................................*/
#include "app_tmb_DefusedState.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_WaitForButtonState.h"
/*............................................................................*/
static void app_tmb_DefusedState_onEnter(app_tmb_DefusedState * const self);
static void app_tmb_DefusedState_onExit(app_tmb_DefusedState * const self);
static void app_tmb_DefusedState_onRightButtonPress(
    app_tmb_DefusedState * const self
);
/*............................................................................*/
app_tmb_DefusedState * app_tmb_DefusedState_(void) {
    static app_tmb_DefusedState self;
    return &self;
}
/*............................................................................*/
app_tmb_DefusedState * app_tmb_DefusedState_init(
    app_tmb_DefusedState * const self, vsk_StateContext * const stateContext
) {
    app_tmb_TimeBombState_init((app_tmb_TimeBombState *)self, stateContext);
    ((vsk_State *)self)->_onEnter =
        (vsk_StateOnEnter)app_tmb_DefusedState_onEnter;
    ((vsk_State *)self)->_onExit =
        (vsk_StateOnEnter)app_tmb_DefusedState_onExit;
    ((app_tmb_TimeBombState *)self)->_onRightButtonPress =
        (app_tmb_TimeBombStateHandler)app_tmb_DefusedState_onRightButtonPress;
    return self;
}
/*............................................................................*/
static void app_tmb_DefusedState_onEnter(app_tmb_DefusedState * const self) {
    ha_Led_setBlueOn();
}
/*............................................................................*/
static void app_tmb_DefusedState_onExit(app_tmb_DefusedState * const self) {
    ha_Led_setBlueOff();
}
/*............................................................................*/
static void app_tmb_DefusedState_onRightButtonPress(
    app_tmb_DefusedState * const self
) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext,
        (vsk_State *)app_tmb_WaitForButtonState_()
    );
}
