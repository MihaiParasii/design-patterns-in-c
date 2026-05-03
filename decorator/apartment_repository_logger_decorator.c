#include "apartment_repository_logger_decorator.h"

#include <stdlib.h>

#include "../common/dynamic_array.h"

static dynamic_array *get_apartments__apartment_repository_logger_decorator(void *self) {
    apartment_repository_logger_decorator *decorator = self;

    printf("Logging: Start executing get_apartments method.\n");
    dynamic_array *result = call(decorator->__wrappee, get_apartments);

    printf("Logging: Finished executing get_apartments method.\n");
    return result;
}

static void add_apartment__apartment_repository_logger_decorator(void *self, apartment *apartment) {
    apartment_repository_logger_decorator *decorator = self;

    printf("Logging: Start executing add_apartment method.\n");
    call(decorator->__wrappee, add_apartment, apartment);
    printf("Logging: Finished executing add_apartment method.\n");
}

static i_apartment_repository__vtable apartment_repository_logger_decorator__vtable = {
    .get_apartments = get_apartments__apartment_repository_logger_decorator,
    .add_apartment = add_apartment__apartment_repository_logger_decorator
};

constructor(apartment_repository_logger_decorator, i_apartment_repository *apartment_repository) {
    apartment_repository_logger_decorator *decorator = malloc(sizeof(apartment_repository_logger_decorator));

    decorator->__wrappee = apartment_repository;
    decorator->i_apartment_repository__iface.vtable = &apartment_repository_logger_decorator__vtable;

    return decorator;
}
