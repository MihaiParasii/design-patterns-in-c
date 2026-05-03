#include "apartment_rental_context.h"
#include "available_state.h"
#include <stdlib.h>
#include <stdio.h>

static void set_state__apartment_rental_context(void *self, i_apartment_state *state) {
    apartment_rental_context *ctx = self;
    ctx->__current_state = state;
}

static void reserve__apartment_rental_context(void *self) {
    apartment_rental_context *ctx = self;
    call(ctx->__current_state, reserve);
}

static void move_in__apartment_rental_context(void *self) {
    apartment_rental_context *ctx = self;
    call(ctx->__current_state, move_in);
}

static void request_maintenance__apartment_rental_context(void *self) {
    apartment_rental_context *ctx = self;
    call(ctx->__current_state, request_maintenance);
}

static void complete_maintenance__apartment_rental_context(void *self) {
    apartment_rental_context *ctx = self;
    call(ctx->__current_state, complete_maintenance);
}

static void print_state__apartment_rental_context(void *self) {
    apartment_rental_context *ctx = self;
    printf("[Apartment #%d] Current state: %s\n",
           ctx->apartment_id,
           call(ctx->__current_state, get_name));
}

static apartment_rental_context__vtable apartment_rental_context_vtable = {
    .set_state            = set_state__apartment_rental_context,
    .reserve              = reserve__apartment_rental_context,
    .move_in              = move_in__apartment_rental_context,
    .request_maintenance  = request_maintenance__apartment_rental_context,
    .complete_maintenance = complete_maintenance__apartment_rental_context,
    .print_state          = print_state__apartment_rental_context,
};

apartment_rental_context *new__apartment_rental_context(int apartment_id) {
    apartment_rental_context *ctx = malloc(sizeof(apartment_rental_context));
    ctx->vtable       = &apartment_rental_context_vtable;
    ctx->apartment_id = apartment_id;
    available_state *initial = new__available_state(ctx);
    ctx->__current_state = &initial->i_apartment_state__iface;
    return ctx;
}
