/*............................................................................*/
#include "vsk_InboxSupervisor.h"
/*............................................................................*/
vsk_InboxSupervisor * vsk_InboxSupervisor_(void) {
    static vsk_InboxSupervisor self;
    return &self;
}
/*............................................................................*/
vsk_InboxSupervisor * vsk_InboxSupervisor_init(
    vsk_InboxSupervisor * const self
) {
    vsk_LinkedList_init(&self->_inboxes);
    return self;
}
/*............................................................................*/
void vsk_InboxSupervisor_register(
    vsk_InboxSupervisor * const self, vsk_Inbox * const inbox
) {
    vsk_LinkedList_addFirst(&self->_inboxes, inbox);
}
/*............................................................................*/
static void activateTask(vsk_Inbox * const inbox) {
    if (!vsk_Inbox_isEmpty(inbox)) {
        vsk_Task_activate(inbox->task);
    }
}
/*............................................................................*/
void vsk_InboxSupervisor_onSysTick(vsk_InboxSupervisor * const self) {
    vsk_LinkedList_forEach(
        &self->_inboxes, (vsk_LinkedListForEachOperation)activateTask
    );
}
