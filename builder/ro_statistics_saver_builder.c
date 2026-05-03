#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <secure/_string.h>
#include "i_statistics_saver_builder.h"
#include "ro_statistics_saver_builder.h"

#include "static_statistics_saver_builder.h"

static i_statistics_saver_builder *with_name(void *self, const char *name) {
    ro_statistics_saver_builder *s = self;
    size_t name_len = strlen(name);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (name_len + 2) * sizeof(char));


    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append, s->__full_statistics, name);
    s_call(StatisticsSaverBuilder, __append, s->__full_statistics, "\n");

    return self;
}

static i_statistics_saver_builder *with_header__ro(void *self, const char *header_name) {
    ro_statistics_saver_builder *s = self;
    char header[256];
    snprintf(header, sizeof(header),
             "+=========================+\n"
             "|        %s        |\n"
             "+=========================+\n",
             header_name);

    s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics, (strlen(header) + 1) * sizeof(char));

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append, s->__full_statistics, header);
    return self;
}

static i_statistics_saver_builder *with_houses_count__ro(void *self, const int created_houses_count) {
    ro_statistics_saver_builder *s = self;
    char count_str[64];
    snprintf(count_str, sizeof(count_str), "Nr. de case create: %d\n", created_houses_count);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (strlen(count_str) + 1) * sizeof(char));

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append, s->__full_statistics, count_str);

    return self;
}

static i_statistics_saver_builder *with_company_name__ro(void *self, const char *company_name) {
    ro_statistics_saver_builder *s = self;
    char company_str[256];
    snprintf(company_str, sizeof(company_str), "Compania: %s\n", company_name);

    s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics, (strlen(company_str) + 1) * sizeof(char));

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append, s->__full_statistics, company_str);
    return self;
}

static i_statistics_saver_builder *with_current_time__ro(void *self, const time_t time) {
    ro_statistics_saver_builder *s = self;
    char time_str[64];
    const struct tm *tm_info = localtime(&time);
    strftime(time_str, sizeof(time_str), "Data executării: %Y-%m-%d %H:%M:%S\n", tm_info);

    s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics, (strlen(time_str) + 1) * sizeof(char));

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append, s->__full_statistics, time_str);

    return self;
}

static char *get__ro(void *self) {
    ro_statistics_saver_builder *s = self;
    char *statistics_to_return = strdup(s->__full_statistics);
    s->__full_statistics = NULL;

    return statistics_to_return;
}


static i_statistics_saver_builder__vtable v_table__ro = {
    .with_name = with_name,
    .with_header = with_header__ro,
    .with_company_name = with_company_name__ro,
    .with_current_time = with_current_time__ro,
    .with_houses_count = with_houses_count__ro,
    .get = get__ro
};


constructor(ro_statistics_saver_builder) {
    ro_statistics_saver_builder *builder = malloc(sizeof(ro_statistics_saver_builder));

    builder->i_statistics_saver_builder__iface.vtable = &v_table__ro;

    return builder;
}
