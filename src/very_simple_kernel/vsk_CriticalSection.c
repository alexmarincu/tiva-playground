#include "vsk_CriticalSection.h"

struct vsk_CriticalSection {
    vsk_CriticalSectionEnter enter;
    vsk_CriticalSectionExit exit;
};

vsk_CriticalSection * vsk_CriticalSection_(void) {
    static vsk_CriticalSection self;
    return &self;
}

vsk_CriticalSection * vsk_CriticalSection_init(
    vsk_CriticalSection * const self,
    vsk_CriticalSectionEnter const enter,
    vsk_CriticalSectionExit const exit
) {
    self->enter = enter;
    self->exit = exit;
    return self;
}

void vsk_CriticalSection_enter(vsk_CriticalSection * const self) {
    self->enter();
}

void vsk_CriticalSection_exit(vsk_CriticalSection * const self) {
    self->exit();
}
