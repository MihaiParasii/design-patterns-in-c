#ifndef ROOMS_GTE_EXPRESSION_H
#define ROOMS_GTE_EXPRESSION_H
#include "../defines.h"
#include "i_apartment_expression.h"

class_(rooms_gte_expression) {
    implements_(i_apartment_expression);
    int __threshold;
};

constructor(rooms_gte_expression, int threshold);

#endif //ROOMS_GTE_EXPRESSION_H
