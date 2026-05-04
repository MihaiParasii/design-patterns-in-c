#ifndef I_REPAIR_HANDLER_H
#define I_REPAIR_HANDLER_H
#include "../defines.h"

// Forward declaration needed so set_next can reference i_repair_handler* inside its own vtable.
typedef struct i_repair_handler i_repair_handler;

vtable_for(i_repair_handler) {
    method_(void, set_next, i_repair_handler *next);
    method_(void, handle,   int cost, const char *description);
};

class_(i_repair_handler) {
    i_repair_handler__vtable *vtable;
};

#endif //I_REPAIR_HANDLER_H
