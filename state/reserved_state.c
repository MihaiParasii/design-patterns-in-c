#include "reserved_state.h"
#include "apartment_rental_context.h"
#include "occupied_state.h"
#include <stdlib.h>
#include <stdio.h>

static void reserve__reserved_state(void *self) {
    printf("[State] Apartment is already reserved.\n");
}

static void move_in__reserved_state(void *self) {
    reserved_state *s = container_of(self, reserved_state, i_apartment_state__iface);
    printf("[State] Tenant moved in. -> Occupied\n");
    occupied_state *next = new__occupied_state(s->__context);
    call(s->__context, set_state, &next->i_apartment_state__iface);
}

static void request_maintenance__reserved_state(void *self) {
    printf("[State] Cannot request maintenance — apartment is reserved, not yet occupied.\n");
}

static void complete_maintenance__reserved_state(void *self) {
    printf("[State] No maintenance is in progress.\n");
}

static const char *get_name__reserved_state(void *self) {
    return "Reserved";
}

static i_apartment_state__vtable reserved_state_vtable = {
    .reserve              = reserve__reserved_state,
    .move_in              = move_in__reserved_state,
    .request_maintenance  = request_maintenance__reserved_state,
    .complete_maintenance = complete_maintenance__reserved_state,
    .get_name             = get_name__reserved_state,
};

reserved_state *new__reserved_state(apartment_rental_context *context) {
    reserved_state *s = malloc(sizeof(reserved_state));
    s->i_apartment_state__iface.vtable = &reserved_state_vtable;
    s->__context = context;
    return s;
}
