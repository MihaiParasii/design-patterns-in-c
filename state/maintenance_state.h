#ifndef MAINTENANCE_STATE_H
#define MAINTENANCE_STATE_H
#include "../defines.h"
#include "i_apartment_state.h"

class_(maintenance_state) {
    implements_(i_apartment_state);
    apartment_rental_context *__context;
};

maintenance_state *new__maintenance_state(apartment_rental_context *context);

#endif //MAINTENANCE_STATE_H
