#include "apartment_repository.h"

#include <stdlib.h>


static dynamic_array *get_apartments__apartment_repository(void *self) {
    apartment_repository *ar = self;

    return call(ar->__db_context, get_apartments);
}

static void add_apartment__apartment_repository(void *self, apartment *apartment) {
    apartment_repository *ar = self;
    call(ar->__db_context, add_apartment, apartment);

    call(ar->__db_context, save_changes);
}

static i_apartment_repository__vtable apartment_repository_vtable = {
    .get_apartments = get_apartments__apartment_repository,
    .add_apartment = add_apartment__apartment_repository
};

constructor(apartment_repository, app_db_context *db_context) {
    apartment_repository *repo = malloc(sizeof(apartment_repository));
    repo->__db_context = db_context;
    repo->i_apartment_repository__iface.vtable = &apartment_repository_vtable;

    return repo;
}
