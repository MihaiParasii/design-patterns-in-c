//
// Created by Mihai Parasii on 31.01.2026.
//

#ifndef STATISTICS_SAVER_DIRECTOR_H
#define STATISTICS_SAVER_DIRECTOR_H
#include "i_statistics_saver_builder.h"

typedef struct statistics_saver_director_vtable {
    void (*construct_short)(void *self, int constructed_houses_count);

    void (*construct_long)(void *self, int constructed_houses_count);
} statistics_saver_director_vtable;


typedef struct statistics_saver_director {
    statistics_saver_director_vtable *vtable;
    i_statistics_saver_builder *__builder;
} statistics_saver_director;

statistics_saver_director *new__statistics_saver_director(i_statistics_saver_builder *builder);

#endif //STATISTICS_SAVER_DIRECTOR_H
