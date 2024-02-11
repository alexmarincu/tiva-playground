/*----------------------------------------------------------------------------*/
#ifndef HA_LEFTBUTTON_H
#define HA_LEFTBUTTON_H
/*----------------------------------------------------------------------------*/
typedef struct ha_LeftButton ha_LeftButton;
/*----------------------------------------------------------------------------*/
#include "ha_Button.h"
/*----------------------------------------------------------------------------*/
struct ha_LeftButton {
    struct {
        ha_Button button;
    } _super;
};
/*----------------------------------------------------------------------------*/
ha_LeftButton * ha_LeftButton_(void);
ha_LeftButton * ha_LeftButton_init(ha_LeftButton * const self);
void ha_LeftButton_setIntTypeBothEdges(ha_LeftButton * const self);
void ha_LeftButton_registerInt(
    ha_LeftButton * const self, ha_InterruptHandler const intHandler
);
void ha_LeftButton_unregisterInt(ha_LeftButton * const self);
void ha_LeftButton_enableInt(ha_LeftButton * const self);
void ha_LeftButton_disableInt(ha_LeftButton * const self);
void ha_LeftButton_clearIntFlag(ha_LeftButton * const self);
bool ha_LeftButton_isPressed(ha_LeftButton * const self);
#endif // HA_LEFTBUTTON_H
