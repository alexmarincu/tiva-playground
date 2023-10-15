#ifndef APP_TMB_BOOMSTATE_H
#define APP_TMB_BOOMSTATE_H
/*............................................................................*/
typedef struct app_tmb_BoomState app_tmb_BoomState;
#include "app_tmb_BaseState.h"
/*............................................................................*/
struct app_tmb_BoomState {
    struct {
        app_tmb_BaseState baseState;
    } _super;
};
/*............................................................................*/
app_tmb_BoomState * app_tmb_BoomState_(void);
app_tmb_BoomState * app_tmb_BoomState_init(
    app_tmb_BoomState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_TMB_BOOMSTATE_H
