#ifndef EXTERNAL_FLAT_PROVIDER_H
#define EXTERNAL_FLAT_PROVIDER_H
#include "../defines.h"
#include "external_flat.h"


s_vtable_(external_flat_provider) {
    method_(external_flat**, get_flats);
};

class_(external_flat_provider) {
    external_flat_provider__s_vtable *s_vtable;
    external_flat **_s_flats;
};

external_flat_provider *s_new__external_flat_provider();


#endif //EXTERNAL_FLAT_PROVIDER_H
