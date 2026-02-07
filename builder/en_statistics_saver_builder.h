#ifndef EN_STATISTICS_SAVER_BUILDER_H
#define EN_STATISTICS_SAVER_BUILDER_H
#include "base_statistics_saver_builder.h"
#include "../defines.h"

class_(en_statistics_saver_builder) {
    extends_(base_statistics_saver_builder);
};

en_statistics_saver_builder *new__en_full_statistics_builder();

#endif //EN_STATISTICS_SAVER_BUILDER_H
