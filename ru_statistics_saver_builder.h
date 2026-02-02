#ifndef RU_STATISTICS_SAVER_BUILDER_H
#define RU_STATISTICS_SAVER_BUILDER_H
#include "i_statistics_saver_builder.h"


typedef struct ru_statistics_saver_builder {
    i_statistics_saver_builder base;
} ru_statistics_saver_builder;

ru_statistics_saver_builder *new__ru_full_statistics_builder();

#endif //RU_STATISTICS_SAVER_BUILDER_H
