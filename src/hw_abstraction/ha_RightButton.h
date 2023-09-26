#ifndef HA_RIGHTBUTTON_H
#define HA_RIGHTBUTTON_H
#include "ha_Button.h"

typedef struct ha_RightButton ha_RightButton;

ha_RightButton * ha_RightButton_(void);
ha_RightButton * ha_RightButton_init(ha_RightButton * const self);
void ha_RightButton_setIntTypeBothEdges(ha_RightButton * const self);
void ha_RightButton_registerInt(ha_RightButton * const self, void (*const fun)(void));
void ha_RightButton_unregisterInt(ha_RightButton * const self);
void ha_RightButton_enableInt(ha_RightButton * const self);
void ha_RightButton_disableInt(ha_RightButton * const self);
void ha_RightButton_clearIntFlag(ha_RightButton * const self);
bool ha_RightButton_isPressed(ha_RightButton * const self);

#endif // HA_RIGHTBUTTON_H
