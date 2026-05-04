#include "visitable_ground_house.h"
#include <stdlib.h>

static void accept__visitable_ground_house(void *self, i_property_visitor *visitor) {
    visitable_ground_house *vg =
        container_of(self, visitable_ground_house, i_visitable_property__iface);
    call(visitor, visit_ground_house, vg->__ground_house);
}

static i_visitable_property__vtable visitable_ground_house_vtable = {
    .accept = accept__visitable_ground_house,
};

constructor(visitable_ground_house, ground_house *gh) {
    visitable_ground_house *vg = malloc(sizeof(visitable_ground_house));
    vg->i_visitable_property__iface.vtable = &visitable_ground_house_vtable;
    vg->__ground_house = gh;
    return vg;
}
