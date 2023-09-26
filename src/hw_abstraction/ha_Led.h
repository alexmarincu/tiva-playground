#ifndef HA_LED_H
#define HA_LED_H

void ha_Led_init(void);
void ha_Led_setGreenOn(void);
void ha_Led_setGreenOff(void);
void ha_Led_setBlueOn(void);
void ha_Led_setBlueOff(void);
void ha_Led_setRedOn(void);
void ha_Led_setRedOff(void);
void ha_Led_setAllOn(void);
void ha_Led_setAllOff(void);
void ha_Led_toggleRed(void);

#endif // HA_LED_H
