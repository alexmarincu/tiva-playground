#ifndef HAL_RBUTTON_H
#define HAL_RBUTTON_H
#include "hal_Button.h"

typedef struct hal_RButton hal_RButton;

hal_RButton * hal_RButton_(void);
hal_RButton * hal_RButton_init(hal_RButton * const self);
void hal_RButton_setIntTypeBothEdges(hal_RButton * const self);
void hal_RButton_registerInt(hal_RButton * const self, void (*const fun)(void));
void hal_RButton_unregisterInt(hal_RButton * const self);
void hal_RButton_enableInt(hal_RButton * const self);
void hal_RButton_disableInt(hal_RButton * const self);
void hal_RButton_clearIntFlag(hal_RButton * const self);
bool hal_RButton_isPressed(hal_RButton * const self);

#endif // HAL_RBUTTON_H
