#ifndef APARTMENT_LISTING_H
#define APARTMENT_LISTING_H
#include "../defines.h"
#include "listing_memento.h"

vtable_for(apartment_listing) {
    method_(void, set_price, int price);

    method_(void, set_description, char *description);

    method_(listing_memento*, save);

    method_(void, restore, listing_memento *m);

    method_(void, print);
};

class_(apartment_listing) {
    apartment_listing__vtable *vtable;
    int __price;
    char *__description;
    int __apartment_id;
};

constructor(apartment_listing, int apartment_id, int initial_price, char *description);

#endif //APARTMENT_LISTING_H
