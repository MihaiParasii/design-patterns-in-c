#include <stdlib.h>
#include <string.h>
#include "static_statistics_saver_builder.h"


static char *__alloc_memory(char *source, const size_t size) {
    if (source == NULL) {
        source = malloc(size);
    } else {
        source = realloc(source, strlen(source) + size);
    }

    return source;
}

static void __append(char *source, const char *text) {
    strcat(source, text);
}

static statistics_saver_builder__s_vtable statistics_saver_builder_s_vtable = {
    .__append = __append,
    .__alloc_memory = __alloc_memory
};

const s_statistics_saver_builder StatisticsSaverBuilder = {
    .s_vtable = &statistics_saver_builder_s_vtable
};
