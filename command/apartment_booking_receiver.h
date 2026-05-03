#ifndef APARTMENT_BOOKING_RECEIVER_H
#define APARTMENT_BOOKING_RECEIVER_H
#include "../defines.h"
#include "../models/apartment.h"

vtable_for(apartment_booking_receiver) {
    method_(void, reserve, char *tenant_name);

    method_(void, cancel);

    method_(void, print_status);
};

class_(apartment_booking_receiver) {
    apartment_booking_receiver__vtable *vtable;
    apartment *__apartment;
    char *__tenant_name;
    int __is_reserved;
};

constructor(apartment_booking_receiver, apartment *apt);

#endif //APARTMENT_BOOKING_RECEIVER_H
