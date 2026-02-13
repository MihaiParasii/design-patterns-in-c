#ifndef STATISTICS_SAVER_BUILDER_H
#define STATISTICS_SAVER_BUILDER_H
#include <time.h>
#include "../defines.h"

typedef struct i_statistics_saver_builder i_statistics_saver_builder;

vtable_(i_statistics_saver_builder) {
    method_(i_statistics_saver_builder *, with_name, const char *name);

    method_(i_statistics_saver_builder *, with_header, const char *header_name);

    method_(i_statistics_saver_builder *, with_houses_count, int created_houses_count);

    method_(i_statistics_saver_builder *, with_company_name, const char *company_name);

    method_(i_statistics_saver_builder *, with_current_time, time_t time);

    method_(char *, get);
};

class_(i_statistics_saver_builder) {
    i_statistics_saver_builder__vtable *vtable;
};


#endif //STATISTICS_SAVER_BUILDER_H
