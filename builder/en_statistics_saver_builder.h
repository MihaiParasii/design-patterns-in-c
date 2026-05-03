#ifndef EN_STATISTICS_SAVER_BUILDER_H
#define EN_STATISTICS_SAVER_BUILDER_H
#include "../defines.h"
#include "i_statistics_saver_builder.h"

class_(en_statistics_saver_builder) {
    implements_(i_statistics_saver_builder);
    char *__full_statistics;
};

constructor(en_statistics_saver_builder);

#endif //EN_STATISTICS_SAVER_BUILDER_H
