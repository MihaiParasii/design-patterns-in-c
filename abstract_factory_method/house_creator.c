#include "house_creator.h"

#include <stdlib.h>

void print_a_new_house(void *self) {
    base_house *house = call((house_creator *) self, construct_house);
    call(house, print_myself);
}

house_creator__vtable vtable = {
    .print_a_new_house = print_a_new_house
};

constructor(house_creator) {
    house_creator *hc = calloc(1, sizeof(house_creator));

    hc->vtable = &vtable;

    return hc;
}
