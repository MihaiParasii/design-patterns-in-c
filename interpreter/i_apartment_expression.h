#ifndef I_APARTMENT_EXPRESSION_H
#define I_APARTMENT_EXPRESSION_H
#include "../defines.h"
#include "../models/apartment.h"

vtable_for(i_apartment_expression) {
    method_(int, interpret, apartment *apt);
};

class_(i_apartment_expression) {
    i_apartment_expression__vtable *vtable;
};

#endif //I_APARTMENT_EXPRESSION_H
