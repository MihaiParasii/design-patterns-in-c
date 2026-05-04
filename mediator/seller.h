#ifndef SELLER_H
#define SELLER_H
#include "../defines.h"

vtable_for(seller) {
    method_(int,  evaluate_offer, int offered_price);
    method_(void, print_listing);
};

class_(seller) {
    seller__vtable *vtable;
    char           *__name;
    int             __apartment_id;
    int             __min_price;
};

constructor(seller, char *name, int apartment_id, int min_price);

#endif //SELLER_H
