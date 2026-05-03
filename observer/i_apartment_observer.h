#ifndef I_APARTMENT_OBSERVER_H
#define I_APARTMENT_OBSERVER_H
#include "../defines.h"
#include "../models/apartment.h"

vtable_for(i_apartment_observer) {
    method_(void, on_apartment_available, apartment *apt);
};

class_(i_apartment_observer) {
    i_apartment_observer__vtable *vtable;
};

#endif //I_APARTMENT_OBSERVER_H
