#include "floor_gt_expression.h"
#include <stdlib.h>

static int interpret__floor_gt_expression(void *_self, apartment *apt) {
    SELF_OF(floor_gt_expression, i_apartment_expression__iface);
    return apt->floor > self->__threshold;
}

static i_apartment_expression__vtable vtable = {
    .interpret = interpret__floor_gt_expression,
};

constructor(floor_gt_expression, int threshold) {
    floor_gt_expression *e = malloc(sizeof(floor_gt_expression));
    e->i_apartment_expression__iface.vtable = &vtable;
    e->__threshold = threshold;
    return e;
}
