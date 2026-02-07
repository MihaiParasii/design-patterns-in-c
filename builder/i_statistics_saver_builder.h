#ifndef STATISTICS_SAVER_BUILDER_H
#define STATISTICS_SAVER_BUILDER_H
#include <time.h>
#include "../defines.h"

typedef struct i_statistics_saver_builder i_statistics_saver_builder;

vtable_(i_statistics_saver_builder) {
    
    i_statistics_saver_builder * (*with_name)(void *self,const char* name);

    method_(i_statistics_saver_builder *, with_header, const char *header_name);

    method_(i_statistics_saver_builder *, with_houses_count, int created_houses_count);

    method_(i_statistics_saver_builder *, with_company_name, const char *company_name);

    method_(i_statistics_saver_builder *, with_current_time, time_t time);

    method_(char *, get);

    method_(void, __alloc_memory, size_t size);

    method_(void, __append, const char *text);
};

class_(i_statistics_saver_builder) {
    i_statistics_saver_builder__vtable *vtable;
    char *__full_statistics;
};


#endif //STATISTICS_SAVER_BUILDER_H
