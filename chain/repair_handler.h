#ifndef REPAIR_HANDLER_H
#define REPAIR_HANDLER_H
#include "../defines.h"
#include "i_repair_handler.h"

class_(repair_handler) {
    implements_(i_repair_handler);
    i_repair_handler *__next;
    int               __budget_limit;
    const char       *__role;
};

constructor(repair_handler, const char *role, int budget_limit);

#endif //REPAIR_HANDLER_H
