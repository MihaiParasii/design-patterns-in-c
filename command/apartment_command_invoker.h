#ifndef APARTMENT_COMMAND_INVOKER_H
#define APARTMENT_COMMAND_INVOKER_H
#include "../defines.h"
#include "i_apartment_command.h"

#define INVOKER_HISTORY_MAX 32

vtable_for(apartment_command_invoker) {
    method_(void, execute_command, i_apartment_command *command);

    method_(void, undo_last);
};

class_(apartment_command_invoker) {
    apartment_command_invoker__vtable *vtable;
    i_apartment_command *__history[INVOKER_HISTORY_MAX];
    int __history_size;
};

constructor(apartment_command_invoker);

#endif //APARTMENT_COMMAND_INVOKER_H
