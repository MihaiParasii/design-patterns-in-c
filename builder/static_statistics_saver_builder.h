#ifndef STATIC_STATISTICS_SAVER_BUILDER_H
#define STATIC_STATISTICS_SAVER_BUILDER_H

#include "../defines.h"

s_vtable_(statistics_saver_builder) {
    static_method_(char *, __alloc_memory, char *source, size_t size);

    static_method_(void, __append, char*source, const char *text);
};

static_class_(statistics_saver_builder) {
    statistics_saver_builder__s_vtable *s_vtable;
};

extern const s_statistics_saver_builder StatisticsSaverBuilder;

#endif //STATIC_STATISTICS_SAVER_BUILDER_H
