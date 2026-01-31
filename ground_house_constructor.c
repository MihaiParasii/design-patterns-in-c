#include "ground_house_constructor.h"

#include <stdlib.h>

#include "ground_house.h"

const house_constructor_vtable ground_house_constructor_vtable = {
    .construct_house = (base_house *(*)()) new_ground_house,
    .print_a_new_house = print_a_new_house
};


ground_house_constructor *new_ground_house_constructor() {
    ground_house_constructor *ground_house_ctor = malloc(sizeof(ground_house_constructor));

    ground_house_ctor->base.vtable = &ground_house_constructor_vtable;

    return ground_house_ctor;
}
