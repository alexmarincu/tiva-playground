/*............................................................................*/
#include "app_tmb_ArmedState.h"
/*............................................................................*/
#include "../../hw_abstraction/ha_RgbLed.h"
#include "app_tmb_DefusedState.h"
/*............................................................................*/
static void app_tmb_ArmedState_onRightButtonPress(
    app_tmb_ArmedState * const self
);
/*............................................................................*/
app_tmb_ArmedState * app_tmb_ArmedState_init(
    app_tmb_ArmedState * const self, vsk_StateContext * const stateContext
) {
    app_tmb_TimeBombState_init((app_tmb_TimeBombState *)self, stateContext);
    ((app_tmb_TimeBombState *)self)->_onRightButtonPress =
        (app_tmb_TimeBombStateHandler)app_tmb_ArmedState_onRightButtonPress;
    return self;
}
/*............................................................................*/
static void app_tmb_ArmedState_onRightButtonPress(
    app_tmb_ArmedState * const self
) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext, (vsk_State *)app_tmb_DefusedState_()
    );
}
