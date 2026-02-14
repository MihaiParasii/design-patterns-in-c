#ifndef LAB2_I_APARTMENT_REPOSITORY_H
#define LAB2_I_APARTMENT_REPOSITORY_H
#include "../defines.h"
#include "../models/apartment.h"
#include "../common/dynamic_array.h"

vtable_for(i_apartment_repository) {
    method_(dynamic_array *, get_apartments);

    method_(void, add_apartment, apartment* apartment);
};


class_(i_apartment_repository) {
    i_apartment_repository__vtable *vtable;
};

#endif //LAB2_I_APARTMENT_REPOSITORY_H
