#ifndef BLOCK_OF_APARTMENT_BUILDINGS_H
#define BLOCK_OF_APARTMENT_BUILDINGS_H
#include "apartment_building.h"
#include "../defines.h"
#include "../common/dynamic_array_house_component.h"

vtable_for(block_of_apartment_buildings) {
    method_(void, add_child, i_house_component* building);
};

class_(block_of_apartment_buildings) {
    implements_(i_house_component);
    block_of_apartment_buildings__vtable *vtable;

    dynamic_array_house_component *children;
};

constructor(block_of_apartment_buildings);


#endif //BLOCK_OF_APARTMENT_BUILDINGS_H
