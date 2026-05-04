#include "seller.h"
#include <stdlib.h>
#include <stdio.h>

static int evaluate_offer__seller(void *self, int offered_price) {
    seller *s = self;
    if (offered_price >= s->__min_price) {
        printf("[Seller %s] Offer of $%d accepted (min $%d).\n",
               s->__name, offered_price, s->__min_price);
        return 1;
    }
    printf("[Seller %s] Offer of $%d rejected (min is $%d).\n",
           s->__name, offered_price, s->__min_price);
    return 0;
}

static void print_listing__seller(void *self) {
    seller *s = self;
    printf("[Seller %s] Listing: Apartment #%d, asking >= $%d\n",
           s->__name, s->__apartment_id, s->__min_price);
}

static seller__vtable seller_vtable = {
    .evaluate_offer = evaluate_offer__seller,
    .print_listing  = print_listing__seller,
};

constructor(seller, char *name, int apartment_id, int min_price) {
    seller *s = malloc(sizeof(seller));
    s->vtable          = &seller_vtable;
    s->__name          = name;
    s->__apartment_id  = apartment_id;
    s->__min_price     = min_price;
    return s;
}
