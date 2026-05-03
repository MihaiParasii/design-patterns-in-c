#include "tenant_observer.h"
#include <stdlib.h>
#include <stdio.h>

static void on_apartment_available__tenant_observer(void *self, apartment *apt) {
    tenant_observer *t = container_of(self, tenant_observer, i_apartment_observer__iface);
    if (apt->floor <= t->__max_floor) {
        printf("[Tenant %s] Interested! Floor %d with %d rooms fits my criteria.\n",
               t->__name, apt->floor, apt->base_house__base.number_of_rooms);
    } else {
        printf("[Tenant %s] Floor %d is too high for me (max: %d). Skipping.\n",
               t->__name, apt->floor, t->__max_floor);
    }
}

static i_apartment_observer__vtable tenant_observer_vtable = {
    .on_apartment_available = on_apartment_available__tenant_observer,
};

constructor(tenant_observer, char *name, int max_floor) {
    tenant_observer *t = malloc(sizeof(tenant_observer));
    t->i_apartment_observer__iface.vtable = &tenant_observer_vtable;
    t->__name = name;
    t->__max_floor = max_floor;
    return t;
}
