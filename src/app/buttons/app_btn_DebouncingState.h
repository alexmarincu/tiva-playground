/*............................................................................*/
#ifndef APP_BTN_DEBOUNCINGSTATE_H
#define APP_BTN_DEBOUNCINGSTATE_H
/*............................................................................*/
typedef struct app_btn_DebouncingState
    app_btn_DebouncingState;
/*............................................................................*/
#include "app_btn_ButtonsState.h"
/*............................................................................*/
struct app_btn_DebouncingState {
    struct {
        app_btn_ButtonsState buttonsState;
    } _super;
};
/*............................................................................*/
app_btn_DebouncingState * app_btn_DebouncingState_init(
    app_btn_DebouncingState * const self, vsk_StateContext * const stateContext
);
#endif // APP_BTN_DEBOUNCINGSTATE_H
