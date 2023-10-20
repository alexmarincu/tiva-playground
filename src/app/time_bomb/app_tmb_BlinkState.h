#ifndef APP_TMB_BLINKSTATE_H
#define APP_TMB_BLINKSTATE_H
/*............................................................................*/
typedef struct app_tmb_BlinkState app_tmb_BlinkState;
#include "app_tmb_ArmedState.h"
/*............................................................................*/
struct app_tmb_BlinkState {
    struct {
        app_tmb_ArmedState armedState;
    } _super;
};
/*............................................................................*/
app_tmb_BlinkState * app_tmb_BlinkState_(void);
app_tmb_BlinkState * app_tmb_BlinkState_init(
    app_tmb_BlinkState * const self, vsk_StateContext * const stateContext
);
#endif // APP_TMB_BLINKSTATE_H
