#ifndef FLOOR_GT_EXPRESSION_H
#define FLOOR_GT_EXPRESSION_H
#include "../defines.h"
#include "i_apartment_expression.h"

class_(floor_gt_expression) {
    implements_(i_apartment_expression);
    int __threshold;
};

constructor(floor_gt_expression, int threshold);

#endif //FLOOR_GT_EXPRESSION_H
