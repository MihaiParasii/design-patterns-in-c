#ifndef BUYER_H
#define BUYER_H
#include "../defines.h"
#include "i_negotiation_mediator.h"

vtable_for(buyer) {
    method_(void, make_offer, int price);
};

class_(buyer) {
    buyer__vtable          *vtable;
    char                   *__name;
    i_negotiation_mediator *__mediator;
};

constructor(buyer, char *name, i_negotiation_mediator *mediator);

#endif //BUYER_H
