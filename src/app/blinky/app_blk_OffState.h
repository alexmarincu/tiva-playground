/*............................................................................*/
#ifndef APP_BLK_OFFSTATE_H
#define APP_BLK_OFFSTATE_H
/*............................................................................*/
typedef struct app_blk_OffState app_blk_OffState;
/*............................................................................*/
#include "app_blk_BlinkyState.h"
/*............................................................................*/
struct app_blk_OffState {
    struct {
        app_blk_BlinkyState blinkyState;
    } _super;
};
/*............................................................................*/
app_blk_OffState * app_blk_OffState_(void);
app_blk_OffState * app_blk_OffState_init(
    app_blk_OffState * const self, vsk_StateContext * const stateMachine
);
#endif // APP_BLK_OFFSTATE_H
