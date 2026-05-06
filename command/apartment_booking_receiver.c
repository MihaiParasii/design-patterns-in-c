#include "apartment_booking_receiver.h"
#include <stdlib.h>
#include <stdio.h>

static void reserve(void *_self, char *tenant_name) {
    SELF(apartment_booking_receiver);
    self->__is_reserved = 1;
    self->__tenant_name = tenant_name;
    printf("[Booking] Apartment (floor %d, %d rooms) reserved by %s.\n",
           self->__apartment->floor,
           self->__apartment->base_house__base.number_of_rooms,
           tenant_name);
}

static void cancel(void *_self) {
    SELF(apartment_booking_receiver);
    printf("[Booking] Reservation by %s (floor %d) cancelled.\n", self->__tenant_name, self->__apartment->floor);
    self->__is_reserved = 0;
    self->__tenant_name = NULL;
}

static void print_status(void *_self) {
    SELF(apartment_booking_receiver);
    if (self->__is_reserved) {
        printf("[Status] Floor %d: RESERVED by %s\n", self->__apartment->floor, self->__tenant_name);
    } else {
        printf("[Status] Floor %d: AVAILABLE\n", self->__apartment->floor);
    }
}

static apartment_booking_receiver__vtable vtable = {
    .reserve = reserve,
    .cancel = cancel,
    .print_status = print_status
};

constructor(apartment_booking_receiver, apartment *apt) {
    apartment_booking_receiver *r = malloc(sizeof(apartment_booking_receiver));
    r->vtable = &vtable;
    r->__apartment = apt;
    r->__tenant_name = NULL;
    r->__is_reserved = 0;
    return r;
}
