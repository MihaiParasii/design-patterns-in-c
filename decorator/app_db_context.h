#ifndef LAB2_APP_DB_CONTEXT_H
#define LAB2_APP_DB_CONTEXT_H
#include "../defines.h"
#include "../models/apartment.h"
#include "../common/dynamic_array.h"

vtable_for(app_db_context) {
    method_(dynamic_array*, get_apartments);

    method_(void, add_apartment, apartment* apartment);

    method_(int, save_changes);
};

class_(app_db_context) {
    app_db_context__vtable *vtable;
    char *__in_memory_saving;
    int __count_modified;
};

app_db_context *new__app_db_context();

#endif //LAB2_APP_DB_CONTEXT_H
