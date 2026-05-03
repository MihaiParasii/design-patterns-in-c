#ifndef STATISTICS_SAVER_DIRECTOR_H
#define STATISTICS_SAVER_DIRECTOR_H
#include "i_statistics_saver_builder.h"
#include "../defines.h"

vtable_for(statistics_saver_director) {
    method_(void, construct_short, int constructed_houses_count);

    method_(void, construct_long, int constructed_houses_count);
};


class_(statistics_saver_director) {
    statistics_saver_director__vtable *vtable;
    i_statistics_saver_builder *__builder;
};

constructor(statistics_saver_director, i_statistics_saver_builder *builder);

#endif //STATISTICS_SAVER_DIRECTOR_H
