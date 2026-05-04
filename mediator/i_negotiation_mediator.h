#ifndef I_NEGOTIATION_MEDIATOR_H
#define I_NEGOTIATION_MEDIATOR_H
#include "../defines.h"

vtable_for(i_negotiation_mediator) {
    method_(void, notify, int offered_price);
};

class_(i_negotiation_mediator) {
    i_negotiation_mediator__vtable *vtable;
};

#endif //I_NEGOTIATION_MEDIATOR_H
