/*----------------------------------------------------------------------------*/
#ifndef APP_TMB_WAITFORBUTTONSTATE_H
#define APP_TMB_WAITFORBUTTONSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_tmb_WaitForButtonState app_tmb_WaitForButtonState;
/*----------------------------------------------------------------------------*/
#include "app_tmb_ArmedState.h"
/*----------------------------------------------------------------------------*/
struct app_tmb_WaitForButtonState {
    struct {
        app_tmb_ArmedState armedState;
    } _super;
};
/*----------------------------------------------------------------------------*/
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_(void);
app_tmb_WaitForButtonState * app_tmb_WaitForButtonState_init(
    app_tmb_WaitForButtonState * const self,
    vsk_StateContext * const stateContext
);
#endif // APP_TMB_WAITFORBUTTONSTATE_H
