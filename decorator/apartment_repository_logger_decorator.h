#ifndef LAB2_APARTMENT_REPOSITORY_LOGGER_DECORATOR_H
#define LAB2_APARTMENT_REPOSITORY_LOGGER_DECORATOR_H
#include "../defines.h"
#include "i_apartment_repository.h"


class_(apartment_repository_logger_decorator) {
    implements_(i_apartment_repository);
    
    i_apartment_repository *__wrappee;
};

apartment_repository_logger_decorator *new__apartment_repository_logger_decorator(
    i_apartment_repository *apartment_repository);

#endif //LAB2_APARTMENT_REPOSITORY_LOGGER_DECORATOR_H
