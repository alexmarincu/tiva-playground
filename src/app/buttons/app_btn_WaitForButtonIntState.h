/*............................................................................*/
#ifndef APP_BTN_WAITFORBUTTONINTSTATE_H
#define APP_BTN_WAITFORBUTTONINTSTATE_H
/*............................................................................*/
typedef struct app_btn_WaitForButtonIntState
    app_btn_WaitForButtonIntState;
/*............................................................................*/
#include "app_btn_ButtonsState.h"
/*............................................................................*/
struct app_btn_WaitForButtonIntState {
    struct {
        app_btn_ButtonsState buttonsState;
    } _super;
};
/*............................................................................*/
app_btn_WaitForButtonIntState * app_btn_WaitForButtonIntState_(void);
app_btn_WaitForButtonIntState * app_btn_WaitForButtonIntState_init(
    app_btn_WaitForButtonIntState * const self,
    vsk_StateContext * const stateContext
);
#endif // APP_BTN_WAITFORBUTTONINTSTATE_H
