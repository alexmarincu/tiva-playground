#ifndef VSK_CRITICALSECTION_H
#define VSK_CRITICALSECTION_H
/*............................................................................*/
typedef struct vsk_CriticalSection vsk_CriticalSection;
typedef void (*vsk_CriticalSectionDisableInt)(void);
typedef void (*vsk_CriticalSectionEnableInt)(void);
#include <stdint.h>
/*............................................................................*/
struct vsk_CriticalSection {
    vsk_CriticalSectionDisableInt _disableInt;
    vsk_CriticalSectionEnableInt _enableInt;
    uint8_t volatile _nestingLevels;
};
/*............................................................................*/
vsk_CriticalSection * vsk_CriticalSection_(void);
vsk_CriticalSection * vsk_CriticalSection_init(
    vsk_CriticalSection * const self,
    vsk_CriticalSectionDisableInt const disableInt,
    vsk_CriticalSectionEnableInt const enableInt
);
void vsk_CriticalSection_enter(
    vsk_CriticalSection * const self
);
void vsk_CriticalSection_exit(
    vsk_CriticalSection * const self
);
#endif // VSK_CRITICALSECTION_H
