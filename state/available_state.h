#ifndef AVAILABLE_STATE_H
#define AVAILABLE_STATE_H
#include "../defines.h"
#include "i_apartment_state.h"

class_(available_state) {
    implements_(i_apartment_state);
    apartment_rental_context *__context;
};

available_state *new__available_state(apartment_rental_context *context);

#endif //AVAILABLE_STATE_H
