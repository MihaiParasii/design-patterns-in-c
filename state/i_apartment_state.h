#ifndef I_APARTMENT_STATE_H
#define I_APARTMENT_STATE_H
#include "../defines.h"

// Forward declaration breaks the circular dependency with apartment_rental_context.
typedef struct apartment_rental_context apartment_rental_context;

vtable_for(i_apartment_state) {
    method_(void,         reserve);
    method_(void,         move_in);
    method_(void,         request_maintenance);
    method_(void,         complete_maintenance);
    method_(const char *, get_name);
};

class_(i_apartment_state) {
    i_apartment_state__vtable *vtable;
};

#endif //I_APARTMENT_STATE_H
