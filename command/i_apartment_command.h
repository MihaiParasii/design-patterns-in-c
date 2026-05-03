#ifndef I_APARTMENT_COMMAND_H
#define I_APARTMENT_COMMAND_H
#include "../defines.h"

vtable_for(i_apartment_command) {
    method_(void, execute);
    method_(void, undo);
};

class_(i_apartment_command) {
    i_apartment_command__vtable *vtable;
};

#endif //I_APARTMENT_COMMAND_H
