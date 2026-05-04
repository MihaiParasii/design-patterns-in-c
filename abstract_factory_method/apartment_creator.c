#include "apartment_creator.h"
#include "../models/apartment.h"
#include "house_creator.h"
#include <stdlib.h>

constructor(apartment_creator) {
    house_creator *hc = new(house_creator);
    apartment_creator *ac = realloc(hc, sizeof(apartment_creator));
    
    house_creator__vtable *new_vtable = &(house_creator__vtable) {
        .construct_house = (base_house *(*)()) new__apartment0,
        .print_a_new_house = hc->vtable->print_a_new_house
    };

    ac->house_creator__base.vtable = new_vtable;

    return ac;
}
