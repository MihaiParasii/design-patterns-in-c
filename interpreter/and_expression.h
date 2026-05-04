#ifndef AND_EXPRESSION_H
#define AND_EXPRESSION_H
#include "../defines.h"
#include "i_apartment_expression.h"

class_(and_expression) {
    implements_(i_apartment_expression);
    i_apartment_expression *__left;
    i_apartment_expression *__right;
};

constructor(and_expression, i_apartment_expression *left, i_apartment_expression *right);

#endif //AND_EXPRESSION_H
