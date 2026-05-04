#include "apartment_listing.h"
#include <stdlib.h>
#include <stdio.h>

static void set_price(void *self, int price) {
    apartment_listing *l = self;
    l->__price = price;
}

static void set_description(void *self, char *description) {
    apartment_listing *l = self;
    l->__description = description;
}

static listing_memento *save(void *self) {
    apartment_listing *l = self;
    printf("[Listing #%d] Saving state (price: %d, desc: \"%s\")\n",
           l->__apartment_id, l->__price, l->__description);
    return new__listing_memento(l->__price, l->__description);
}

static void restore(void *self, listing_memento *m) {
    apartment_listing *l = self;
    l->__price       = m->__price;
    l->__description = m->__description;
    printf("[Listing #%d] State restored (price: %d, desc: \"%s\")\n",
           l->__apartment_id, l->__price, l->__description);
}

static void print(void *self) {
    apartment_listing *l = self;
    printf("[Listing #%d] price: %d | \"%s\"\n",
           l->__apartment_id, l->__price, l->__description);
}

static apartment_listing__vtable apartment_listing_vtable = {
    .set_price       = set_price,
    .set_description = set_description,
    .save            = save,
    .restore         = restore,
    .print           = print,
};

constructor(apartment_listing, int apartment_id, int initial_price, char *description) {
    apartment_listing *l = malloc(sizeof(apartment_listing));
    l->vtable          = &apartment_listing_vtable;
    l->__apartment_id  = apartment_id;
    l->__price         = initial_price;
    l->__description   = description;
    return l;
}
