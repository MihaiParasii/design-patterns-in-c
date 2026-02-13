#ifndef RO_STATISTICS_SAVER_BUILDER_H
#define RO_STATISTICS_SAVER_BUILDER_H
#include "../defines.h"

class_(ro_statistics_saver_builder) {
    implements_(i_statistics_saver_builder);
    char *__full_statistics;
};

ro_statistics_saver_builder *new__ro_full_statistics_builder();

#endif //RO_STATISTICS_SAVER_BUILDER_H
