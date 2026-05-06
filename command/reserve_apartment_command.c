#include "reserve_apartment_command.h"
#include <stdlib.h>

static void execute(void *_self) {
    SELF_OF(reserve_apartment_command, i_apartment_command__iface);

    call(self->__receiver, reserve, self->__tenant_name);
}

static void undo(void *_self) {
    SELF_OF(reserve_apartment_command, i_apartment_command__iface);

    call(self->__receiver, cancel);
}

static i_apartment_command__vtable vtable = {
    .execute = execute,
    .undo = undo,
};

constructor(reserve_apartment_command, apartment_booking_receiver *receiver, char *tenant_name) {
    reserve_apartment_command *c = malloc(sizeof(reserve_apartment_command));
    c->i_apartment_command__iface.vtable = &vtable;
    c->__receiver = receiver;
    c->__tenant_name = tenant_name;
    return c;
}
