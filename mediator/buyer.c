#include "buyer.h"
#include <stdlib.h>
#include <stdio.h>

static void make_offer__buyer(void *self, int price) {
    buyer *b = self;
    printf("[Buyer %s] Submitting offer of $%d via mediator\n", b->__name, price);
    call(b->__mediator, notify, price);
}

static buyer__vtable buyer_vtable = {
    .make_offer = make_offer__buyer,
};

constructor(buyer, char *name, i_negotiation_mediator *mediator) {
    buyer *b = malloc(sizeof(buyer));
    b->vtable      = &buyer_vtable;
    b->__name      = name;
    b->__mediator  = mediator;
    return b;
}
