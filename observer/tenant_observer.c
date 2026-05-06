#include "tenant_observer.h"
#include <stdlib.h>
#include <stdio.h>

static void on_apartment_available(void *_self, apartment *apt) {
    SELF_OF(tenant_observer, i_apartment_observer__iface);
    
    if (apt->floor <= self->__max_floor) {
        printf("[Tenant %s] Interested! Floor %d with %d rooms fits my criteria.\n",
               self->__name, apt->floor, apt->base_house__base.number_of_rooms);
    } else {
        printf("[Tenant %s] Floor %d is too high for me (max: %d). Skipping.\n",
        self->__name, apt->floor, self->__max_floor);
    }
}

static i_apartment_observer__vtable vtable = {
    .on_apartment_available = on_apartment_available,
};

constructor(tenant_observer, char *name, int max_floor) {
    tenant_observer *t = malloc(sizeof(tenant_observer));
    t->i_apartment_observer__iface.vtable = &vtable;
    t->__name = name;
    t->__max_floor = max_floor;
    return t;
}
