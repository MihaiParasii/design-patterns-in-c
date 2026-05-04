#include "and_expression.h"
#include <stdlib.h>

static int interpret__and_expression(void *self, apartment *apt) {
    and_expression *e = container_of(self, and_expression, i_apartment_expression__iface);
    return call(e->__left, interpret, apt) && call(e->__right, interpret, apt);
}

static i_apartment_expression__vtable and_expression_vtable = {
    .interpret = interpret__and_expression,
};

constructor(and_expression, i_apartment_expression *left, i_apartment_expression *right) {
    and_expression *e = malloc(sizeof(and_expression));
    e->i_apartment_expression__iface.vtable = &and_expression_vtable;
    e->__left  = left;
    e->__right = right;
    return e;
}
