/*----------------------------------------------------------------------------*/
#ifndef APP_TMB_TIMEBOMBSTATE_H
#define APP_TMB_TIMEBOMBSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_tmb_TimeBombState app_tmb_TimeBombState;
/*----------------------------------------------------------------------------*/
#include "../../very_simple_kernel/vsk_State.h"
/*----------------------------------------------------------------------------*/
typedef void (*app_tmb_TimeBombStateHandler)(
    app_tmb_TimeBombState * const self
);
/*----------------------------------------------------------------------------*/
struct app_tmb_TimeBombState {
    struct {
        vsk_State state;
    } _super;
    app_tmb_TimeBombStateHandler _onBlinkTimeout;
    app_tmb_TimeBombStateHandler _onPauseTimeout;
    app_tmb_TimeBombStateHandler _onRightButtonPress;
    app_tmb_TimeBombStateHandler _onLeftButtonPress;
};
/*----------------------------------------------------------------------------*/
app_tmb_TimeBombState * app_tmb_TimeBombState_init(
    app_tmb_TimeBombState * const self, vsk_StateContext * const stateContext
);
void app_tmb_TimeBombState_onBlinkTimeout(app_tmb_TimeBombState * const self);
void app_tmb_TimeBombState_onPauseTimeout(app_tmb_TimeBombState * const self);
void app_tmb_TimeBombState_onRightButtonPress(
    app_tmb_TimeBombState * const self
);
void app_tmb_TimeBombState_onLeftButtonPress(
    app_tmb_TimeBombState * const self
);
#endif // APP_TMB_TIMEBOMBSTATE_H
