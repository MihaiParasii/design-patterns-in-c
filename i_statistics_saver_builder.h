#ifndef STATISTICS_SAVER_BUILDER_H
#define STATISTICS_SAVER_BUILDER_H
#include <time.h>

typedef struct i_statistics_saver_builder i_statistics_saver_builder;

typedef struct statistics_saver_builder_vtable {
    i_statistics_saver_builder *(*with_name)(i_statistics_saver_builder *self, const char *name);

    i_statistics_saver_builder *(*with_header)(i_statistics_saver_builder *self, const char *header_name);

    i_statistics_saver_builder *(*with_houses_count)(i_statistics_saver_builder *self, int created_houses_count);

    i_statistics_saver_builder *(*with_company_name)(i_statistics_saver_builder *self, const char *company_name);

    i_statistics_saver_builder *(*with_current_time)(i_statistics_saver_builder *self, time_t time);

    char * (*get)(void *self);
} statistics_saver_builder_vtable;

typedef struct i_statistics_saver_builder {
    statistics_saver_builder_vtable *vtable;
    char *__full_statistics;
} i_statistics_saver_builder;


#endif //STATISTICS_SAVER_BUILDER_H
