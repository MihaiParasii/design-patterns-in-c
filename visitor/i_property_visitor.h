#ifndef I_PROPERTY_VISITOR_H
#define I_PROPERTY_VISITOR_H
#include "../defines.h"
#include "../models/apartment.h"
#include "../models/ground_house.h"

vtable_for(i_property_visitor) {
    method_(void, visit_apartment,    apartment    *apt);
    method_(void, visit_ground_house, ground_house *gh);
};

class_(i_property_visitor) {
    i_property_visitor__vtable *vtable;
};

#endif //I_PROPERTY_VISITOR_H
