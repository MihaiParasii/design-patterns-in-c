#include "external_flat_provider.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <_string.h>


static void external_flat_init_random(external_flat *flat) {
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

const int s_flats_length = 10;
external_flat **flats = NULL;

static external_flat **_get_flats() {
    if (flats) {
        return flats;
    }

    flats = malloc(s_flats_length * sizeof(external_flat *));
    if (flats == NULL) {
        return NULL;
    }

    if (*flats == NULL) {
        for (int i = 0; i < s_flats_length; ++i) {
            flats[i] = malloc(sizeof(external_flat));
            external_flat_init_random(flats[i]);
        }
    }

    return flats;
}

s_external_flat_provider__s_vtable s_vtable = {
    .get_external_flats = _get_flats
};

s_external_flat_provider ExternalFlatProvider = {
    .s_vtable = &s_vtable
};
