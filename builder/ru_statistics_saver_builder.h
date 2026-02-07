#ifndef RU_STATISTICS_SAVER_BUILDER_H
#define RU_STATISTICS_SAVER_BUILDER_H
#include "base_statistics_saver_builder.h"
#include "../defines.h"


class_(ru_statistics_saver_builder) {
    extends_(base_statistics_saver_builder);
};

ru_statistics_saver_builder *new__ru_full_statistics_builder();

#endif //RU_STATISTICS_SAVER_BUILDER_H
