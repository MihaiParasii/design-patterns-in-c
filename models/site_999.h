#ifndef SITE_999_H
#define SITE_999_H
#include "../common/dynamic_array.h"
#include "../abstract_factory_method/house_creator.h"
#include "../defines.h"

vtable_for(site_999) {
    method_(void, print_houses);

    method_(void, add_house, const house_creator *creator);
};

class_(site_999) {
    site_999__vtable *vtable;
    dynamic_array *_houses;
};

constructor(site_999);

#endif //SITE_999_H
