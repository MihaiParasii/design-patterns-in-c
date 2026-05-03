#include "reserve_apartment_command.h"
#include <stdlib.h>

static void execute__reserve_apartment_command(void *self) {
    reserve_apartment_command *c = container_of(self, reserve_apartment_command,
                                                i_apartment_command__iface);
    call(c->__receiver, reserve, c->__tenant_name);
}

static void undo__reserve_apartment_command(void *self) {
    reserve_apartment_command *c = container_of(self, reserve_apartment_command,
                                                i_apartment_command__iface);
    call(c->__receiver, cancel);
}

static i_apartment_command__vtable reserve_apartment_command_vtable = {
    .execute = execute__reserve_apartment_command,
    .undo = undo__reserve_apartment_command,
};

constructor(reserve_apartment_command, apartment_booking_receiver *receiver, char *tenant_name) {
    reserve_apartment_command *c = malloc(sizeof(reserve_apartment_command));
    c->i_apartment_command__iface.vtable = &reserve_apartment_command_vtable;
    c->__receiver = receiver;
    c->__tenant_name = tenant_name;
    return c;
}
