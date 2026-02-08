#include "external_flat_provider.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <_string.h>

const int s_flats_length = 10;
static external_flat **s_flats;

void external_flat_init_random(external_flat *flat) {
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int) time(NULL));
        seeded = 1;
    }

    const char *streets[] = {
        "Elm St", "Maple Ave", "Oak Rd", "Birch Blvd", "Pine Ln"
    };
    const int street_count = sizeof(streets) / sizeof(streets[0]);
    const int house_number = rand() % 200 + 1;
    const int street_index = rand() % street_count;

    char address[64];
    snprintf(address, sizeof(address), "%d %s", house_number, streets[street_index]);
    flat->address = strdup(address);

    flat->area = 30 + rand() % 121;

    flat->number_of_rooms = 1 + rand() % 6;
}


void _init_flats() {
    if (s_flats == NULL) {
        s_flats = malloc(s_flats_length * sizeof(external_flat *));
    }

    if (*s_flats == NULL) {
        for (int i = 0; i < s_flats_length; ++i) {
            s_flats[i] = malloc(sizeof(external_flat));
            external_flat_init_random(s_flats[i]);
        }
    }
}

external_flat **get_flats() {
    return s_flats;
}

external_flat_provider__s_vtable external_flat_provider_s_vtable = {
    .get_flats = get_flats
};


external_flat_provider *s_new__external_flat_provider() {
    _init_flats();
    external_flat_provider *provider = malloc(sizeof(external_flat_provider));
    provider->s_vtable = &external_flat_provider_s_vtable;

    provider->_s_flats = s_flats;

    return provider;
}
