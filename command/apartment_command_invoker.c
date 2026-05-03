#include "apartment_command_invoker.h"
#include <stdlib.h>
#include <stdio.h>

static void execute_command__apartment_command_invoker(void *self, i_apartment_command *command) {
    apartment_command_invoker *inv = self;
    call(command, execute);
    if (inv->__history_size < INVOKER_HISTORY_MAX) {
        inv->__history[inv->__history_size++] = command;
    }
}

static void undo_last__apartment_command_invoker(void *self) {
    apartment_command_invoker *inv = self;
    if (inv->__history_size == 0) {
        printf("[Invoker] Nothing to undo.\n");
        return;
    }
    i_apartment_command *last = inv->__history[--inv->__history_size];
    call(last, undo);
}

static apartment_command_invoker__vtable apartment_command_invoker_vtable = {
    .execute_command = execute_command__apartment_command_invoker,
    .undo_last = undo_last__apartment_command_invoker,
};

constructor(apartment_command_invoker) {
    apartment_command_invoker *inv = malloc(sizeof(apartment_command_invoker));
    inv->vtable = &apartment_command_invoker_vtable;
    inv->__history_size = 0;
    return inv;
}
