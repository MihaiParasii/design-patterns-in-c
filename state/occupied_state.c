#include "occupied_state.h"
#include "apartment_rental_context.h"
#include "maintenance_state.h"
#include <stdlib.h>
#include <stdio.h>

static void reserve__occupied_state(void *self) {
    printf("[State] Cannot reserve — apartment is already occupied.\n");
}

static void move_in__occupied_state(void *self) {
    printf("[State] A tenant is already living here.\n");
}

static void request_maintenance__occupied_state(void *self) {
    occupied_state *s = container_of(self, occupied_state, i_apartment_state__iface);
    printf("[State] Maintenance requested by tenant. -> Maintenance\n");
    maintenance_state *next = new__maintenance_state(s->__context);
    call(s->__context, set_state, &next->i_apartment_state__iface);
}

static void complete_maintenance__occupied_state(void *self) {
    printf("[State] No maintenance is in progress.\n");
}

static const char *get_name__occupied_state(void *self) {
    return "Occupied";
}

static i_apartment_state__vtable occupied_state_vtable = {
    .reserve              = reserve__occupied_state,
    .move_in              = move_in__occupied_state,
    .request_maintenance  = request_maintenance__occupied_state,
    .complete_maintenance = complete_maintenance__occupied_state,
    .get_name             = get_name__occupied_state,
};

occupied_state *new__occupied_state(apartment_rental_context *context) {
    occupied_state *s = malloc(sizeof(occupied_state));
    s->i_apartment_state__iface.vtable = &occupied_state_vtable;
    s->__context = context;
    return s;
}
