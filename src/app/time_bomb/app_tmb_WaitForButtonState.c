/*............................................................................*/
#include "app_tmb_WaitForButtonState.h"
/*............................................................................*/
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
    vsk_StateContext * const stateContext
) {
    app_tmb_ArmedState_init((app_tmb_ArmedState *)self, stateContext);
    ((vsk_State *)self)->_onEnter =
        (vsk_StateOnEnter)app_tmb_WaitForButtonState_onEnter;
    ((vsk_State *)self)->_onExit =
        (vsk_StateOnExit)app_tmb_WaitForButtonState_onExit;
    ((app_tmb_TimeBombState *)self)->_onLeftButtonPress =
        (app_tmb_TimeBombStateHandler)
            app_tmb_WaitForButtonState_onLeftButtonPress;
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
    app_tmb_TimeBombActObj * timeBomb =
        (app_tmb_TimeBombActObj *)((vsk_State *)self)->_stateContext;
    timeBomb->blinkCounter = 5;
    vsk_StateContext_transition(
        (vsk_StateContext *)timeBomb, (vsk_State *)app_tmb_BlinkState_()
    );
}
