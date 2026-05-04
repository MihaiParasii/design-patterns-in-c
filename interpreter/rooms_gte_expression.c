#include "rooms_gte_expression.h"
#include <stdlib.h>

static int interpret__rooms_gte_expression(void *self, apartment *apt) {
    rooms_gte_expression *e =
        container_of(self, rooms_gte_expression, i_apartment_expression__iface);
    return apt->base_house__base.number_of_rooms >= e->__threshold;
}

static i_apartment_expression__vtable rooms_gte_expression_vtable = {
    .interpret = interpret__rooms_gte_expression,
};

constructor(rooms_gte_expression, int threshold) {
    rooms_gte_expression *e = malloc(sizeof(rooms_gte_expression));
    e->i_apartment_expression__iface.vtable = &rooms_gte_expression_vtable;
    e->__threshold = threshold;
    return e;
}
