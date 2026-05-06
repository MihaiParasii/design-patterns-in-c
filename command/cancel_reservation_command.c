#include "cancel_reservation_command.h"
#include <stdlib.h>

static void execute(void *_self) {
    SELF_OF(cancel_reservation_command, i_apartment_command__iface);

    self->__prev_tenant_name = self->__receiver->__tenant_name;
    call(self->__receiver, cancel);
}

static void undo(void *_self) {
    SELF_OF(cancel_reservation_command, i_apartment_command__iface);

    call(self->__receiver, reserve, self->__prev_tenant_name);
}

static i_apartment_command__vtable vtable = {
    .execute = execute,
    .undo = undo,
};

constructor(cancel_reservation_command, apartment_booking_receiver *receiver) {
    cancel_reservation_command *c = malloc(sizeof(cancel_reservation_command));
    c->i_apartment_command__iface.vtable = &vtable;
    c->__receiver = receiver;
    c->__prev_tenant_name = NULL;
    return c;
}
