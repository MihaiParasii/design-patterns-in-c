#ifndef APARTMENT_RENTAL_CONTEXT_H
#define APARTMENT_RENTAL_CONTEXT_H
#include "../defines.h"
#include "i_apartment_state.h"

vtable_for(apartment_rental_context) {
    method_(void, set_state,            i_apartment_state *state);
    method_(void, reserve);
    method_(void, move_in);
    method_(void, request_maintenance);
    method_(void, complete_maintenance);
    method_(void, print_state);
};

class_(apartment_rental_context) {
    apartment_rental_context__vtable *vtable;
    i_apartment_state *__current_state;
    int apartment_id;
};

apartment_rental_context *new__apartment_rental_context(int apartment_id);

#endif //APARTMENT_RENTAL_CONTEXT_H
