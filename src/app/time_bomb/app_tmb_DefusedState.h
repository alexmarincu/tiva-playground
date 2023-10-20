#ifndef APP_TMB_DEFUSEDSTATE_H
#define APP_TMB_DEFUSEDSTATE_H
/*............................................................................*/
typedef struct app_tmb_DefusedState app_tmb_DefusedState;
#include "app_tmb_TimeBombState.h"
/*............................................................................*/
struct app_tmb_DefusedState {
    struct {
        app_tmb_TimeBombState timeBombState;
    } _super;
};
/*............................................................................*/
app_tmb_DefusedState * app_tmb_DefusedState_(void);
app_tmb_DefusedState * app_tmb_DefusedState_init(
    app_tmb_DefusedState * const self, vsk_StateContext * const stateContext
);
#endif // APP_TMB_DEFUSEDSTATE_H
