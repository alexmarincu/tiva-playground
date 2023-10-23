/*............................................................................*/
#include "app_tmb_PauseState.h"
#include "app_tmb_BlinkState.h"
#include "app_tmb_BoomState.h"
#include "app_tmb_TimeBombActObj.h"
/*............................................................................*/
static void app_tmb_PauseState_onEnter(app_tmb_PauseState * const self);
static void app_tmb_PauseState_onPauseTimeout(app_tmb_PauseState * const self);
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_(void) {
    static app_tmb_PauseState self;
    return &self;
}
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_init(
    app_tmb_PauseState * const self, vsk_StateContext * const stateContext
) {
    app_tmb_ArmedState_init((app_tmb_ArmedState *)self, stateContext);
    ((vsk_State *)self)->_onEnter =
        (vsk_StateOnEnter)app_tmb_PauseState_onEnter;
    ((app_tmb_TimeBombState *)self)->_onPauseTimeout =
        (app_tmb_TimeBombStateHandler)app_tmb_PauseState_onPauseTimeout;
    return self;
}
/*............................................................................*/
static void app_tmb_PauseState_onEnter(app_tmb_PauseState * const self) {
    app_tmb_TimeBombActObj * timeBomb =
        (app_tmb_TimeBombActObj *)((vsk_State *)self)->_stateContext;
    vsk_Timer_start((vsk_Timer *)&timeBomb->eventTimers.pauseTimeout);
}
/*............................................................................*/
static void app_tmb_PauseState_onPauseTimeout(app_tmb_PauseState * const self) {
    app_tmb_TimeBombActObj * timeBomb =
        (app_tmb_TimeBombActObj *)((vsk_State *)self)->_stateContext;
    timeBomb->blinkCounter--;
    if (timeBomb->blinkCounter > 0) {
        vsk_StateContext_transition(
            (vsk_StateContext *)timeBomb,
            (vsk_State *)app_tmb_BlinkState_()
        );
    } else {
        vsk_StateContext_transition(
            (vsk_StateContext *)timeBomb,
            (vsk_State *)app_tmb_BoomState_()
        );
    }
}
