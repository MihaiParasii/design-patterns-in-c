#ifndef EXTERNAL_FLAT_PROVIDER_H
#define EXTERNAL_FLAT_PROVIDER_H
#include "../defines.h"
#include "external_flat.h"


s_vtable_(s_external_flat_provider) {
    static_method_(external_flat**, get_external_flats);
};


static_class_(external_flat_provider) {
    s_external_flat_provider__s_vtable *s_vtable;
};

extern s_external_flat_provider ExternalFlatProvider;

#endif //EXTERNAL_FLAT_PROVIDER_H
