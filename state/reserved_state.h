#ifndef RESERVED_STATE_H
#define RESERVED_STATE_H
#include "../defines.h"
#include "i_apartment_state.h"

class_(reserved_state) {
    implements_(i_apartment_state);
    apartment_rental_context *__context;
};

reserved_state *new__reserved_state(apartment_rental_context *context);

#endif //RESERVED_STATE_H
