#ifndef RO_STATISTICS_SAVER_BUILDER_H
#define RO_STATISTICS_SAVER_BUILDER_H
#include "i_statistics_saver_builder.h"

typedef struct ro_statistics_saver_builder {
    i_statistics_saver_builder base;
} ro_statistics_saver_builder;

ro_statistics_saver_builder *new__ro_full_statistics_builder();

#endif //RO_STATISTICS_SAVER_BUILDER_H
