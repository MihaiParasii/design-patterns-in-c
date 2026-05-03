#include "real_estate_agent_observer.h"
#include <stdlib.h>
#include <stdio.h>

static void on_apartment_available__real_estate_agent_observer(void *self, apartment *apt) {
    real_estate_agent_observer *a = container_of(self, real_estate_agent_observer,
                                                 i_apartment_observer__iface);
    printf("[Agency %s] Logged new listing: floor %d, %d rooms. Contacting buyer pool.\n",
           a->__agency_name, apt->floor, apt->base_house__base.number_of_rooms);
}

static i_apartment_observer__vtable real_estate_agent_observer_vtable = {
    .on_apartment_available = on_apartment_available__real_estate_agent_observer,
};

constructor(real_estate_agent_observer, char *agency_name) {
    real_estate_agent_observer *a = malloc(sizeof(real_estate_agent_observer));
    a->i_apartment_observer__iface.vtable = &real_estate_agent_observer_vtable;
    a->__agency_name = agency_name;
    return a;
}
