#ifndef APP_BLK_ONSTATE_H
#define APP_BLK_ONSTATE_H
/*............................................................................*/
typedef struct app_blk_OnState app_blk_OnState;
#include "app_blk_BaseState.h"
/*............................................................................*/
struct app_blk_OnState {
    struct {
        app_blk_BaseState baseState;
    } _super;
};
/*............................................................................*/
app_blk_OnState * app_blk_OnState_(void);
app_blk_OnState * app_blk_OnState_init(
    app_blk_OnState * const self,
    vsk_StateMachine * const stateMachine
);
#endif // APP_BLK_ONSTATE_H
