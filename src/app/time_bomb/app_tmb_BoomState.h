/*----------------------------------------------------------------------------*/
#ifndef APP_TMB_BOOMSTATE_H
#define APP_TMB_BOOMSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_tmb_BoomState app_tmb_BoomState;
/*----------------------------------------------------------------------------*/
#include "app_tmb_TimeBombState.h"
/*----------------------------------------------------------------------------*/
struct app_tmb_BoomState {
    struct {
        app_tmb_TimeBombState timeBombState;
    } _super;
};
/*----------------------------------------------------------------------------*/
app_tmb_BoomState * app_tmb_BoomState_(void);
app_tmb_BoomState * app_tmb_BoomState_init(
    app_tmb_BoomState * const self, vsk_StateContext * const stateContext
);
#endif // APP_TMB_BOOMSTATE_H
