#include "maintenance_state.h"
#include "apartment_rental_context.h"
#include "available_state.h"
#include <stdlib.h>
#include <stdio.h>

static void reserve__maintenance_state(void *self) {
    printf("[State] Cannot reserve — apartment is under maintenance.\n");
}

static void move_in__maintenance_state(void *self) {
    printf("[State] Cannot move in — apartment is under maintenance.\n");
}

static void request_maintenance__maintenance_state(void *self) {
    printf("[State] Maintenance is already in progress.\n");
}

static void complete_maintenance__maintenance_state(void *self) {
    maintenance_state *s = container_of(self, maintenance_state, i_apartment_state__iface);
    printf("[State] Maintenance completed. -> Available\n");
    available_state *next = new__available_state(s->__context);
    call(s->__context, set_state, &next->i_apartment_state__iface);
}

static const char *get_name__maintenance_state(void *self) {
    return "Maintenance";
}

static i_apartment_state__vtable maintenance_state_vtable = {
    .reserve              = reserve__maintenance_state,
    .move_in              = move_in__maintenance_state,
    .request_maintenance  = request_maintenance__maintenance_state,
    .complete_maintenance = complete_maintenance__maintenance_state,
    .get_name             = get_name__maintenance_state,
};

maintenance_state *new__maintenance_state(apartment_rental_context *context) {
    maintenance_state *s = malloc(sizeof(maintenance_state));
    s->i_apartment_state__iface.vtable = &maintenance_state_vtable;
    s->__context = context;
    return s;
}
