#include "floor_gt_expression.h"
#include <stdlib.h>

static int interpret__floor_gt_expression(void *self, apartment *apt) {
    floor_gt_expression *e = container_of(self, floor_gt_expression, i_apartment_expression__iface);
    return apt->floor > e->__threshold;
}

static i_apartment_expression__vtable floor_gt_expression_vtable = {
    .interpret = interpret__floor_gt_expression,
};

constructor(floor_gt_expression, int threshold) {
    floor_gt_expression *e = malloc(sizeof(floor_gt_expression));
    e->i_apartment_expression__iface.vtable = &floor_gt_expression_vtable;
    e->__threshold = threshold;
    return e;
}
