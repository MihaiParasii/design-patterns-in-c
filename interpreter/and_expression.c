#include "and_expression.h"
#include <stdlib.h>

static int interpret__and_expression(void *_self, apartment *apt) {
    SELF_OF(and_expression, i_apartment_expression__iface);
    return call(self->__left, interpret, apt) && call(self->__right, interpret, apt);
}

static i_apartment_expression__vtable vtable = {
    .interpret = interpret__and_expression,
};

constructor(and_expression, i_apartment_expression *left, i_apartment_expression *right) {
    and_expression *e = malloc(sizeof(and_expression));
    e->i_apartment_expression__iface.vtable = &vtable;
    e->__left = left;
    e->__right = right;
    return e;
}
