#ifndef RU_STATISTICS_SAVER_BUILDER_H
#define RU_STATISTICS_SAVER_BUILDER_H
#include "i_statistics_saver_builder.h"
#include "../defines.h"


class_(ru_statistics_saver_builder) {
    implements_(i_statistics_saver_builder);
    
    char *__full_statistics;
};

constructor(ru_statistics_saver_builder);

#endif //RU_STATISTICS_SAVER_BUILDER_H
