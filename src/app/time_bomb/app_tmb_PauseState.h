#ifndef APP_TMB_PAUSESTATE_H
#define APP_TMB_PAUSESTATE_H
/*............................................................................*/
typedef struct app_tmb_PauseState app_tmb_PauseState;
#include "app_tmb_ArmedState.h"
/*............................................................................*/
struct app_tmb_PauseState {
    struct {
        app_tmb_ArmedState armedState;
    } _super;
};
/*............................................................................*/
app_tmb_PauseState * app_tmb_PauseState_(void);
app_tmb_PauseState * app_tmb_PauseState_init(
    app_tmb_PauseState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_PAUSESTATE_H
