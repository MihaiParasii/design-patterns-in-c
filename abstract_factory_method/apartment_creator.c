#include "apartment_creator.h"
#include "../models/apartment.h"
#include "house_creator.h"
#include <stdlib.h>


static const house_creator__vtable apartment_creator__vtable = {
    .construct_house = (base_house *(*)(void *)) new__apartment0,
    .print_a_new_house = print_a_new_house
};


constructor(apartment_creator) {
    apartment_creator *ac = malloc(sizeof(ac));

    ac->house_creator__base.vtable = &apartment_creator__vtable;

    return ac;
}
