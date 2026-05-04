#ifndef OR_EXPRESSION_H
#define OR_EXPRESSION_H
#include "../defines.h"
#include "i_apartment_expression.h"

class_(or_expression) {
    implements_(i_apartment_expression);
    i_apartment_expression *__left;
    i_apartment_expression *__right;
};

constructor(or_expression, i_apartment_expression *left, i_apartment_expression *right);

#endif //OR_EXPRESSION_H
