/*----------------------------------------------------------------------------*/
#ifndef HA_INTERRUPT_H
#define HA_INTERRUPT_H
/*----------------------------------------------------------------------------*/
typedef void (*ha_InterruptHandler)(void);
/*----------------------------------------------------------------------------*/
void ha_Interrupt_masterEnable(void);
void ha_Interrupt_masterDisable(void);
#endif // HA_INTERRUPT_H
