#include "apartment_deal_mediator.h"
#include <stdlib.h>
#include <stdio.h>

static void notify__apartment_deal_mediator(void *self, int offered_price) {
    apartment_deal_mediator *d =
        container_of(self, apartment_deal_mediator, i_negotiation_mediator__iface);
    printf("[Mediator] Routing offer of $%d for apartment #%d...\n",
           offered_price, d->__seller->__apartment_id);
    call(d->__seller, evaluate_offer, offered_price);
}

static i_negotiation_mediator__vtable apartment_deal_mediator_vtable = {
    .notify = notify__apartment_deal_mediator,
};

constructor(apartment_deal_mediator, seller *s, buyer *b) {
    apartment_deal_mediator *d = malloc(sizeof(apartment_deal_mediator));
    d->i_negotiation_mediator__iface.vtable = &apartment_deal_mediator_vtable;
    d->__seller = s;
    d->__buyer  = b;
    return d;
}
