#include "apartment_constructor.h"

#include <stdlib.h>

#include "apartment.h"

const house_constructor_vtable apartment_constructor_vtable = {
    .construct_house = (base_house *(*)()) new_apartment,
    .print_a_new_house = print_a_new_house
};


apartment_constructor *new_apartment_constructor() {
    apartment_constructor *apartment_ctor = malloc(sizeof(apartment_constructor));

    apartment_ctor->base.vtable = &apartment_constructor_vtable;

    return apartment_ctor;
}
