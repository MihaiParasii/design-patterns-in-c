//
// Created by Mihai Parasii on 31.01.2026.
//

#ifndef EN_STATISTICS_SAVER_BUILDER_H
#define EN_STATISTICS_SAVER_BUILDER_H
#include "i_statistics_saver_builder.h"

typedef struct en_statistics_saver_builder {
    i_statistics_saver_builder base;
} en_statistics_saver_builder;

en_statistics_saver_builder *new__en_full_statistics_builder();

#endif //EN_STATISTICS_SAVER_BUILDER_H
