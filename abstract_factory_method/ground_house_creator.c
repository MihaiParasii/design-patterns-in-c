#include <stdlib.h>

#include "ground_house_creator.h"
#include "house_creator.h"
#include "../models/ground_house.h"

const house_creator__vtable ground_house_creator_vtable = {
    .construct_house = (base_house *(*)()) new__ground_house0,
    .print_a_new_house = print_a_new_house
};


ground_house_creator *new__ground_house_creator() {
    ground_house_creator *ghc = malloc(sizeof(ground_house_creator));

    ghc->house_creator__base.vtable = &ground_house_creator_vtable;

    return ghc;
}
