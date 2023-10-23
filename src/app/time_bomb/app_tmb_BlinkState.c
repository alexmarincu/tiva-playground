/*............................................................................*/
#include "app_tmb_BlinkState.h"
#include "../../hw_abstraction/ha_Led.h"
#include "app_tmb_PauseState.h"
#include "app_tmb_TimeBombActObj.h"
/*............................................................................*/
static void app_tmb_BlinkState_onEnter(app_tmb_BlinkState * const self);
static void app_tmb_BlinkState_onExit(app_tmb_BlinkState * const self);
static void app_tmb_BlinkState_onBlinkTimeout(app_tmb_BlinkState * const self);
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_(void) {
    static app_tmb_BlinkState self;
    return &self;
}
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_init(
    app_tmb_BlinkState * const self, vsk_StateContext * const stateContext
) {
    app_tmb_ArmedState_init((app_tmb_ArmedState *)self, stateContext);
    ((vsk_State *)self)->_onEnter =
        (vsk_StateOnEnter)app_tmb_BlinkState_onEnter;
    ((vsk_State *)self)->_onExit = (vsk_StateOnExit)app_tmb_BlinkState_onExit;
    ((app_tmb_TimeBombState *)self)->_onBlinkTimeout =
        (app_tmb_TimeBombStateHandler)app_tmb_BlinkState_onBlinkTimeout;
    return self;
}
/*............................................................................*/
static void app_tmb_BlinkState_onEnter(app_tmb_BlinkState * const self) {
    ha_Led_setRedOn();
    app_tmb_TimeBombActObj * timeBomb =
        (app_tmb_TimeBombActObj *)((vsk_State *)self)->_stateContext;
    vsk_Timer_start((vsk_Timer *)&timeBomb->eventTimers.blinkTimeout);
}
/*............................................................................*/
static void app_tmb_BlinkState_onExit(app_tmb_BlinkState * const self) {
    ha_Led_setRedOff();
}
/*............................................................................*/
static void app_tmb_BlinkState_onBlinkTimeout(app_tmb_BlinkState * const self) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext, (vsk_State *)app_tmb_PauseState_()
    );
}
