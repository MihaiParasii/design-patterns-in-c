#include "or_expression.h"
#include <stdlib.h>

static int interpret__or_expression(void *self, apartment *apt) {
    or_expression *e = container_of(self, or_expression, i_apartment_expression__iface);
    return call(e->__left, interpret, apt) || call(e->__right, interpret, apt);
}

static i_apartment_expression__vtable or_expression_vtable = {
    .interpret = interpret__or_expression,
};

constructor(or_expression, i_apartment_expression *left, i_apartment_expression *right) {
    or_expression *e = malloc(sizeof(or_expression));
    e->i_apartment_expression__iface.vtable = &or_expression_vtable;
    e->__left  = left;
    e->__right = right;
    return e;
}
