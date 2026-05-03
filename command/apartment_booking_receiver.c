#include "apartment_booking_receiver.h"
#include <stdlib.h>
#include <stdio.h>

static void reserve__apartment_booking_receiver(void *self, char *tenant_name) {
    apartment_booking_receiver *r = self;
    r->__is_reserved = 1;
    r->__tenant_name = tenant_name;
    printf("[Booking] Apartment (floor %d, %d rooms) reserved by %s.\n",
           r->__apartment->floor,
           r->__apartment->base_house__base.number_of_rooms,
           tenant_name);
}

static void cancel__apartment_booking_receiver(void *self) {
    apartment_booking_receiver *r = self;
    printf("[Booking] Reservation by %s (floor %d) cancelled.\n",
           r->__tenant_name, r->__apartment->floor);
    r->__is_reserved = 0;
    r->__tenant_name = NULL;
}

static void print_status__apartment_booking_receiver(void *self) {
    apartment_booking_receiver *r = self;
    if (r->__is_reserved) {
        printf("[Status] Floor %d: RESERVED by %s\n",
               r->__apartment->floor, r->__tenant_name);
    } else {
        printf("[Status] Floor %d: AVAILABLE\n", r->__apartment->floor);
    }
}

static apartment_booking_receiver__vtable apartment_booking_receiver_vtable = {
    .reserve = reserve__apartment_booking_receiver,
    .cancel = cancel__apartment_booking_receiver,
    .print_status = print_status__apartment_booking_receiver,
};

constructor(apartment_booking_receiver, apartment *apt) {
    apartment_booking_receiver *r = malloc(sizeof(apartment_booking_receiver));
    r->vtable = &apartment_booking_receiver_vtable;
    r->__apartment = apt;
    r->__tenant_name = NULL;
    r->__is_reserved = 0;
    return r;
}
