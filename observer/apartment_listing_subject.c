#include "apartment_listing_subject.h"
#include <stdlib.h>
#include <stdio.h>

static void subscribe(void *_self, i_apartment_observer *observer) {
    SELF(apartment_listing_subject);

    if (self->__observer_count == self->__observer_capacity) {
        self->__observer_capacity *= 2;
        self->__observers = realloc(self->__observers, self->__observer_capacity * sizeof(i_apartment_observer *));
    }
    self->__observers[self->__observer_count++] = observer;
}

static void unsubscribe(void *_self, i_apartment_observer *observer) {
    SELF(apartment_listing_subject);

    for (size_t i = 0; i < self->__observer_count; i++) {
        if (self->__observers[i] == observer) {
            self->__observers[i] = self->__observers[--self->__observer_count];
            return;
        }
    }
}

static void publish_new_listing(void *_self, apartment *apt) {
    SELF(apartment_listing_subject);
    printf("[Subject] New listing published: floor %d, %d rooms\n", apt->floor, apt->base_house__base.number_of_rooms);
    for (size_t i = 0; i < self->__observer_count; i++) {
        call(self->__observers[i], on_apartment_available, apt);
    }
}

static apartment_listing_subject__vtable vtable = {
    .subscribe = subscribe,
    .unsubscribe = unsubscribe,
    .publish_new_listing = publish_new_listing,
};

constructor(apartment_listing_subject) {
    apartment_listing_subject *s = malloc(sizeof(apartment_listing_subject));
    s->vtable = &vtable;
    s->__observer_capacity = 4;
    s->__observer_count = 0;
    s->__observers = malloc(s->__observer_capacity * sizeof(i_apartment_observer *));
    return s;
}
