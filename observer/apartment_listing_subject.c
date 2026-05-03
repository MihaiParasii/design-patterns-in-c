#include "apartment_listing_subject.h"
#include <stdlib.h>
#include <stdio.h>

static void subscribe__apartment_listing_subject(void *self, i_apartment_observer *observer) {
    apartment_listing_subject *s = self;
    if (s->__observer_count == s->__observer_capacity) {
        s->__observer_capacity *= 2;
        s->__observers = realloc(s->__observers,
                                 s->__observer_capacity * sizeof(i_apartment_observer *));
    }
    s->__observers[s->__observer_count++] = observer;
}

static void unsubscribe__apartment_listing_subject(void *self, i_apartment_observer *observer) {
    apartment_listing_subject *s = self;
    for (size_t i = 0; i < s->__observer_count; i++) {
        if (s->__observers[i] == observer) {
            s->__observers[i] = s->__observers[--s->__observer_count];
            return;
        }
    }
}

static void publish_new_listing__apartment_listing_subject(void *self, apartment *apt) {
    apartment_listing_subject *s = self;
    printf("[Subject] New listing published: floor %d, %d rooms\n",
           apt->floor, apt->base_house__base.number_of_rooms);
    for (size_t i = 0; i < s->__observer_count; i++) {
        call(s->__observers[i], on_apartment_available, apt);
    }
}

static apartment_listing_subject__vtable apartment_listing_subject_vtable = {
    .subscribe = subscribe__apartment_listing_subject,
    .unsubscribe = unsubscribe__apartment_listing_subject,
    .publish_new_listing = publish_new_listing__apartment_listing_subject,
};

constructor(apartment_listing_subject) {
    apartment_listing_subject *s = malloc(sizeof(apartment_listing_subject));
    s->vtable = &apartment_listing_subject_vtable;
    s->__observer_capacity = 4;
    s->__observer_count = 0;
    s->__observers = malloc(s->__observer_capacity * sizeof(i_apartment_observer *));
    return s;
}
