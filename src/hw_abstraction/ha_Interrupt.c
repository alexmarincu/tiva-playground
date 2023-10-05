/*............................................................................*/
#include "ha_Interrupt.h"
#include <stdbool.h>
#include <stdint.h>
//
#include "../../lib/TivaWare/driverlib/interrupt.h"
/*............................................................................*/
void ha_Interrupt_masterEnable(void) {
    IntMasterEnable();
}
/*............................................................................*/
void ha_Interrupt_masterDisable(void) {
    IntMasterDisable();
}
