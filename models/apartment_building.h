#ifndef APARTMENT_BUILDING_H
#define APARTMENT_BUILDING_H
#include "../defines.h"
#include "../common/dynamic_array_house_component.h"
#include "../common/i_house_component.h"

vtable_for(apartment_building) {
    method_(void, add_child, i_house_component* apartment);
};

class_(apartment_building) {
    implements_(i_house_component);
    apartment_building__vtable *vtable;

    dynamic_array_house_component *children;
};


constructor(apartment_building);

#endif //APARTMENT_BUILDING_H
