#include "en_statistics_saver_builder.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <secure/_string.h>

#include "i_statistics_saver_builder.h"
#include "static_statistics_saver_builder.h"

i_statistics_saver_builder *with_name__en(void *self, const char *name) {
    en_statistics_saver_builder *s = self;
    const size_t name_len = strlen(name);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (name_len + 2) * sizeof(char))    ;

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append,s->__full_statistics, name);
    s_call(StatisticsSaverBuilder, __append,s->__full_statistics, "\n");

    return self;
}

i_statistics_saver_builder *with_header__en(void *self, const char *header_name) {
    en_statistics_saver_builder *s = self;
    char header[256];
    snprintf(header, sizeof(header),
             "+=========================+\n"
             "|        %s        |\n"
             "+=========================+\n",
             header_name);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (strlen(header) + 1) * sizeof(char))    ;

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append,s->__full_statistics, header);

    return self;
}

i_statistics_saver_builder *with_houses_count__en(void *self, const int created_houses_count) {
    en_statistics_saver_builder *s = self;
    char count_str[64];
    snprintf(count_str, sizeof(count_str), "Created houses count: %d\n", created_houses_count);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (strlen(count_str) + 1) * sizeof(char))    ;

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append, s->__full_statistics,count_str);

    return self;
}

i_statistics_saver_builder *with_company_name__en(void *self, const char *company_name) {
    en_statistics_saver_builder *s = self;
    char company_str[256];
    snprintf(company_str, sizeof(company_str), "Company: %s\n", company_name);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (strlen(company_str) + 1) * sizeof(char))    ;

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append,s->__full_statistics, company_str);

    return self;
}

i_statistics_saver_builder *with_current_time__en(void *self, const time_t time) {
    en_statistics_saver_builder *s = self;
    char time_str[64];
    struct tm *tm_info = localtime(&time);
    strftime(time_str, sizeof(time_str), "Date: %Y-%m-%d %H:%M:%S\n", tm_info);

    s->__full_statistics = s_call(StatisticsSaverBuilder, __alloc_memory, s->__full_statistics,
                                  (strlen(time_str) + 1) * sizeof(char))    ;

    if (s->__full_statistics == NULL) {
        return NULL;
    }

    s_call(StatisticsSaverBuilder, __append,s->__full_statistics, time_str);

    return self;
}

char *get__en(void *self) {
    en_statistics_saver_builder *s = self;

    char *statistics_to_return = strdup(s->__full_statistics);
    s->__full_statistics = NULL;

    return statistics_to_return;
}


i_statistics_saver_builder__vtable v_table__en = {
    .with_name = with_name__en,
    .with_header = with_header__en,
    .with_company_name = with_company_name__en,
    .with_current_time = with_current_time__en,
    .with_houses_count = with_houses_count__en,
    .get = get__en
};


en_statistics_saver_builder *new__en_full_statistics_builder() {
    en_statistics_saver_builder *builder = malloc(sizeof(en_statistics_saver_builder));

    builder->i_statistics_saver_builder.vtable = &v_table__en;

    return builder;
}
