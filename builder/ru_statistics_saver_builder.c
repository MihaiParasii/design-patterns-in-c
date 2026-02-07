#include "ru_statistics_saver_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <secure/_string.h>

i_statistics_saver_builder *with_name__ru(void *self, const char *name) {
    ru_statistics_saver_builder *s = self;
    const size_t name_len = strlen(name);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (name_len + 2) * sizeof(char));


    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, name);
    s_call(&s->base_statistics_saver_builder__base, __append, "\n");

    return self;
}

i_statistics_saver_builder *with_header__ru(void *self, const char *header_name) {
    ru_statistics_saver_builder *s = self;
    char header[256];
    snprintf(header, sizeof(header),
             "+=========================+\n"
             "|        %s        |\n"
             "+=========================+\n",
             header_name);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(header) + 1) * sizeof(char));

    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, header);

    return self;
}

i_statistics_saver_builder *with_houses_count__ru(void *self, const int created_houses_count) {
    ru_statistics_saver_builder *s = self;
    char count_str[64];
    snprintf(count_str, sizeof(count_str), "Количество построенных домов: %d\n", created_houses_count);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(count_str) + 1) * sizeof(char));

    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, count_str);

    return self;
}

i_statistics_saver_builder *with_company_name__ru(void *self, const char *company_name) {
    ru_statistics_saver_builder *s = self;
    char company_str[256];
    snprintf(company_str, sizeof(company_str), "Кантора: %s\n", company_name);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(company_str) + 1) * sizeof(char));

    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, company_str);
    return self;
}

i_statistics_saver_builder *with_current_time__ru(void *self, const time_t time) {
    ru_statistics_saver_builder *s = self;
    char time_str[64];
    struct tm *tm_info = localtime(&time);
    strftime(time_str, sizeof(time_str), "Дата выполнения: %Y-%m-%d %H:%M:%S\n", tm_info);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(time_str) + 1) * sizeof(char));

    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, time_str);

    return self;
}

char *get__ru(void *self) {
    const ru_statistics_saver_builder *s = self;
    return s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics;
}


i_statistics_saver_builder__vtable v_table__ru = {
    .with_name = with_name__ru,
    .with_header = with_header__ru,
    .with_company_name = with_company_name__ru,
    .with_current_time = with_current_time__ru,
    .with_houses_count = with_houses_count__ru,
    .get = get__ru
};


ru_statistics_saver_builder *new__ru_full_statistics_builder() {
    ru_statistics_saver_builder *builder = malloc(sizeof(ru_statistics_saver_builder));

    builder->base_statistics_saver_builder__base = *new(base_statistics_saver_builder);

    builder->base_statistics_saver_builder__base.i_statistics_saver_builder.vtable = &v_table__ru;

    return builder;
}
