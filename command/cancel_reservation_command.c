#include "cancel_reservation_command.h"
#include <stdlib.h>

static void execute__cancel_reservation_command(void *self) {
    cancel_reservation_command *c = container_of(self, cancel_reservation_command,
                                                 i_apartment_command__iface);
    c->__prev_tenant_name = c->__receiver->__tenant_name;
    call(c->__receiver, cancel);
}

static void undo__cancel_reservation_command(void *self) {
    cancel_reservation_command *c = container_of(self, cancel_reservation_command,
                                                 i_apartment_command__iface);
    call(c->__receiver, reserve, c->__prev_tenant_name);
}

static i_apartment_command__vtable cancel_reservation_command_vtable = {
    .execute = execute__cancel_reservation_command,
    .undo = undo__cancel_reservation_command,
};

constructor(cancel_reservation_command, apartment_booking_receiver *receiver) {
    cancel_reservation_command *c = malloc(sizeof(cancel_reservation_command));
    c->i_apartment_command__iface.vtable = &cancel_reservation_command_vtable;
    c->__receiver = receiver;
    c->__prev_tenant_name = NULL;
    return c;
}
