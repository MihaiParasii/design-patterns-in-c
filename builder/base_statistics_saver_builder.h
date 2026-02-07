#ifndef BASE_STATISTICS_SAVER_BUILDER_H
#define BASE_STATISTICS_SAVER_BUILDER_H
#include "i_statistics_saver_builder.h"
#include "../defines.h"

s_vtable_(base_statistics_saver_builder) {
    method_(void, __alloc_memory, size_t size);

    method_(void, __append, const char *text);
};

class_(base_statistics_saver_builder) {
    implements_(i_statistics_saver_builder);

    base_statistics_saver_builder__s_vtable *s_vtable;
};

base_statistics_saver_builder *new__base_statistics_saver_builder();

#endif //BASE_STATISTICS_SAVER_BUILDER_H
