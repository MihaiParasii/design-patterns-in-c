#ifndef LAB2_APARTMENT_REPOSITORY_H
#define LAB2_APARTMENT_REPOSITORY_H
#include "../defines.h"
#include "i_apartment_repository.h"
#include "app_db_context.h"


class_(apartment_repository) {
    implements_(i_apartment_repository);
    app_db_context *__db_context;
};


constructor(apartment_repository, app_db_context *db_context);


#endif //LAB2_APARTMENT_REPOSITORY_H
