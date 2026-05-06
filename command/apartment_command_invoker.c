#include "apartment_command_invoker.h"
#include <stdlib.h>
#include <stdio.h>

static void execute_command(void *_self, i_apartment_command *command) {
    apartment_command_invoker *self = _self;
    call(command, execute);
    if (self->__history_size < INVOKER_HISTORY_MAX) {
        self->__history[self->__history_size++] = command;
    }
}

static void undo_last(void *_self) {
    apartment_command_invoker *self = _self;
    if (self->__history_size == 0) {
        printf("[Invoker] Nothing to undo.\n");
        return;
    }
    i_apartment_command *last = self->__history[--self->__history_size];
    call(last, undo);
}

static apartment_command_invoker__vtable vtable = {
    .execute_command = execute_command,
    .undo_last = undo_last,
};

constructor(apartment_command_invoker) {
    apartment_command_invoker *inv = malloc(sizeof(apartment_command_invoker));
    inv->vtable = &vtable;
    inv->__history_size = 0;
    return inv;
}
