#ifndef HOUSE_CREATOR_H
#define HOUSE_CREATOR_H
#include "../models/base_house.h"
#include "../defines.h"

vtable_(house_creator) {
    method_(base_house*, construct_house);

    method_(void, print_a_new_house);
};

class_(house_creator) {
    const house_creator__vtable *vtable;
};

void print_a_new_house(void *self);

#endif //HOUSE_CREATOR_H
