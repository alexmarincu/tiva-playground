#ifndef HA_INTERRUPT_H
#define HA_INTERRUPT_H
/*............................................................................*/
typedef void (*ha_InterruptHandler)(void);
/*............................................................................*/
void ha_Interrupt_enableAll(void);
void ha_Interrupt_disableAll(void);
#endif // HA_INTERRUPT_H
