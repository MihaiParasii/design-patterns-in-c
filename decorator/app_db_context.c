#include "app_db_context.h"

#include <stdlib.h>
#include <string.h>

const char *apartments_file_location = "apartments.txt";

dynamic_array *get_apartments__app_db_context(void *self) {
    FILE *fptr = fopen(apartments_file_location, "r");

    dynamic_array *array = new(dynamic_array, 1);

    if (!fptr) {
        return array;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fptr)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        apartment *apt = new(apartment, buffer);
        call(array, add_back, &apt->base_house__base);
    }

    fclose(fptr);
    return array;
}

void add_apartment__app_db_context(void *self, apartment *apartment) {
    app_db_context *s = self;
    s->__count_modified++;

    char *json = call(&apartment->base_house__base.i_as_json__iface, to_json);

    s->__in_memory_saving = realloc(s->__in_memory_saving, sizeof(char) * (strlen(json) + 1));
    strcat(s->__in_memory_saving, json);
    strcat(s->__in_memory_saving, "\n");
}

int save_changes__app_db_context(void *self) {
    app_db_context *s = self;

    FILE *fptr = fopen(apartments_file_location, "a");
    if (!fptr) {
        return -1;
    }

    fprintf(fptr, "%s", s->__in_memory_saving);
    fclose(fptr);
    free(s->__in_memory_saving);

    return s->__count_modified;
}

app_db_context__vtable app_db_context__v_table = {
    .save_changes = save_changes__app_db_context,
    .add_apartment = add_apartment__app_db_context,
    .get_apartments = get_apartments__app_db_context
};

constructor(app_db_context) {
    app_db_context *context = malloc(sizeof(app_db_context));
    context->vtable = &app_db_context__v_table;
    context->__in_memory_saving = malloc(1);
    context->__in_memory_saving[0] = '\0';
    context->__count_modified = 0;

    return context;
}
