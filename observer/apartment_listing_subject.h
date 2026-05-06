#ifndef APARTMENT_LISTING_SUBJECT_H
#define APARTMENT_LISTING_SUBJECT_H
#include "../defines.h"
#include "i_apartment_observer.h"

vtable_for(apartment_listing_subject) {
    method_(void, subscribe, i_apartment_observer *observer);

    method_(void, unsubscribe, i_apartment_observer *observer);

    method_(void, publish_new_listing, apartment *apt);
};

class_(apartment_listing_subject) {
    apartment_listing_subject__vtable *vtable;
    i_apartment_observer **__observers;
    size_t __observer_count;
    size_t __observer_capacity;
};

constructor(apartment_listing_subject);

#endif //APARTMENT_LISTING_SUBJECT_H
