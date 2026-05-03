#ifndef OCCUPIED_STATE_H
#define OCCUPIED_STATE_H
#include "../defines.h"
#include "i_apartment_state.h"

class_(occupied_state) {
    implements_(i_apartment_state);
    apartment_rental_context *__context;
};

occupied_state *new__occupied_state(apartment_rental_context *context);

#endif //OCCUPIED_STATE_H
