/*............................................................................*/
#include "app_tmb_BoomState.h"
/*............................................................................*/
#include "../../hw_abstraction/ha_RgbLed.h"
/*............................................................................*/
static void app_tmb_BoomState_onEnter(app_tmb_BoomState * const self);
/*............................................................................*/
app_tmb_BoomState * app_tmb_BoomState_(void) {
    static app_tmb_BoomState self;
    return &self;
}
/*............................................................................*/
app_tmb_BoomState * app_tmb_BoomState_init(
    app_tmb_BoomState * const self, vsk_StateContext * const stateContext
) {
    app_tmb_TimeBombState_init((app_tmb_TimeBombState *)self, stateContext);
    ((vsk_State *)self)->_onEnter = (vsk_StateOnEnter)app_tmb_BoomState_onEnter;
    return self;
}
/*............................................................................*/
static void app_tmb_BoomState_onEnter(app_tmb_BoomState * const self) {
    ha_RgbLed_setWhite();
}
