#include "visitable_apartment.h"
#include <stdlib.h>

static void accept(void *self, i_property_visitor *visitor) {
    visitable_apartment *va = container_of(self, visitable_apartment, i_visitable_property__iface);
    call(visitor, visit_apartment, va->__apartment);
}

static i_visitable_property__vtable visitable_apartment_vtable = {
    .accept = accept,
};

constructor(visitable_apartment, apartment *apt) {
    visitable_apartment *va = malloc(sizeof(visitable_apartment));
    va->i_visitable_property__iface.vtable = &visitable_apartment_vtable;
    va->__apartment = apt;
    return va;
}
