#include <stdlib.h>
#include <string.h>
#include "base_statistics_saver_builder.h"

void __alloc_memory(void *self, const size_t size) {
    i_statistics_saver_builder *s = self;

    if (s->__full_statistics == NULL) {
        s->__full_statistics = malloc(size);
    } else {
        s->__full_statistics = realloc(s->__full_statistics, strlen(s->__full_statistics) + size);
    }
}

void __append(void *self, const char *text) {
    const i_statistics_saver_builder *s = self;
    strcat(s->__full_statistics, text);
}

base_statistics_saver_builder__s_vtable base_statistics_saver_builder_s_vtable = {
    .__append = __append,
    .__alloc_memory = __alloc_memory
};

base_statistics_saver_builder *new__base_statistics_saver_builder() {
    base_statistics_saver_builder *builder = malloc(sizeof(base_statistics_saver_builder));

    builder->s_vtable = &base_statistics_saver_builder_s_vtable;

    builder->i_statistics_saver_builder.__full_statistics = NULL;

    return builder;
}
