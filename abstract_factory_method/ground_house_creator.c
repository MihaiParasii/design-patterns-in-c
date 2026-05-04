#include <stdlib.h>

#include "ground_house_creator.h"
#include "house_creator.h"
#include "../models/ground_house.h"

constructor(ground_house_creator) {
    house_creator *hc = new(house_creator);
    ground_house_creator *ac = realloc(hc, sizeof(ground_house_creator));
    
    house_creator__vtable *new_vtable = &(house_creator__vtable) {
        .construct_house = (base_house *(*)()) new__ground_house0,
        .print_a_new_house = hc->vtable->print_a_new_house
    };

    ac->house_creator__base.vtable = new_vtable;

    return ac;
}
