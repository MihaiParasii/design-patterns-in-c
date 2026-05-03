#include "available_state.h"
#include "apartment_rental_context.h"
#include "reserved_state.h"
#include "maintenance_state.h"
#include <stdlib.h>
#include <stdio.h>

static void reserve__available_state(void *self) {
    available_state *s = container_of(self, available_state, i_apartment_state__iface);
    printf("[State] Apartment reserved. -> Reserved\n");
    reserved_state *next = new__reserved_state(s->__context);
    call(s->__context, set_state, &next->i_apartment_state__iface);
}

static void move_in__available_state(void *self) {
    printf("[State] Cannot move in — apartment is not reserved yet.\n");
}

static void request_maintenance__available_state(void *self) {
    available_state *s = container_of(self, available_state, i_apartment_state__iface);
    printf("[State] Maintenance requested. -> Maintenance\n");
    maintenance_state *next = new__maintenance_state(s->__context);
    call(s->__context, set_state, &next->i_apartment_state__iface);
}

static void complete_maintenance__available_state(void *self) {
    printf("[State] No maintenance is in progress.\n");
}

static const char *get_name__available_state(void *self) {
    return "Available";
}

static i_apartment_state__vtable available_state_vtable = {
    .reserve              = reserve__available_state,
    .move_in              = move_in__available_state,
    .request_maintenance  = request_maintenance__available_state,
    .complete_maintenance = complete_maintenance__available_state,
    .get_name             = get_name__available_state,
};

available_state *new__available_state(apartment_rental_context *context) {
    available_state *s = malloc(sizeof(available_state));
    s->i_apartment_state__iface.vtable = &available_state_vtable;
    s->__context = context;
    return s;
}
