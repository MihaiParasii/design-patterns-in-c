//
// Created by Mihai Parasii on 31.01.2026.
//

#include "ru_statistics_saver_builder.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <secure/_string.h>

i_statistics_saver_builder *with_name__ru(i_statistics_saver_builder *self, const char *name) {
    ru_statistics_saver_builder *s = (ru_statistics_saver_builder *) self;
    const size_t name_len = strlen(name);

    if (s->base.__full_statistics == NULL) {
        s->base.__full_statistics = malloc((name_len + 2) * sizeof(char));
    } else {
        s->base.__full_statistics = realloc(s->base.__full_statistics,
                                            (strlen(s->base.__full_statistics) + name_len + 2) * sizeof(char));
    }

    if (s->base.__full_statistics == NULL) {
        return NULL;
    }

    strcat(s->base.__full_statistics, name);
    strcat(s->base.__full_statistics, "\n");

    return self;
}

i_statistics_saver_builder *with_header__ru(i_statistics_saver_builder *self, const char *header_name) {
    ru_statistics_saver_builder *s = (ru_statistics_saver_builder *) self;
    char header[256];
    snprintf(header, sizeof(header),
             "+=========================+\n"
             "|        %s        |\n"
             "+=========================+\n",
             header_name);

    if (s->base.__full_statistics == NULL) {
        s->base.__full_statistics = malloc((strlen(header) + 1) * sizeof(char));
    } else {
        s->base.__full_statistics = realloc(s->base.__full_statistics,
                                            (strlen(s->base.__full_statistics) + strlen(header) + 1) * sizeof(char));
    }

    if (s->base.__full_statistics == NULL) {
        return NULL;
    }

    strcat(s->base.__full_statistics, header);
    return self;
}

i_statistics_saver_builder *with_houses_count__ru(i_statistics_saver_builder *self, const int created_houses_count) {
    ru_statistics_saver_builder *s = (ru_statistics_saver_builder *) self;
    char count_str[64];
    snprintf(count_str, sizeof(count_str), "Количество построенных домов: %d\n", created_houses_count);

    if (s->base.__full_statistics == NULL) {
        s->base.__full_statistics = malloc((strlen(count_str) + 1) * sizeof(char));
    } else {
        s->base.__full_statistics = realloc(s->base.__full_statistics,
                                            (strlen(s->base.__full_statistics) + strlen(count_str) + 1) * sizeof(char));
    }

    if (s->base.__full_statistics == NULL) {
        return NULL;
    }

    strcat(s->base.__full_statistics, count_str);
    return self;
}

i_statistics_saver_builder *with_company_name__ru(i_statistics_saver_builder *self, const char *company_name) {
    ru_statistics_saver_builder *s = (ru_statistics_saver_builder *) self;
    char company_str[256];
    snprintf(company_str, sizeof(company_str), "Кантора: %s\n", company_name);

    if (s->base.__full_statistics == NULL) {
        s->base.__full_statistics = malloc((strlen(company_str) + 1) * sizeof(char));
    } else {
        s->base.__full_statistics = realloc(s->base.__full_statistics,
                                            (strlen(s->base.__full_statistics) + strlen(company_str) + 1) * sizeof(
                                                char));
    }
    if (s->base.__full_statistics == NULL) {
        return NULL;
    }

    strcat(s->base.__full_statistics, company_str);
    return self;
}

i_statistics_saver_builder *with_current_time__ru(i_statistics_saver_builder *self, const time_t time) {
    ru_statistics_saver_builder *s = (ru_statistics_saver_builder *) self;
    char time_str[64];
    struct tm *tm_info = localtime(&time);
    strftime(time_str, sizeof(time_str), "Дата выполнения: %Y-%m-%d %H:%M:%S\n", tm_info);

    if (s->base.__full_statistics == NULL) {
        s->base.__full_statistics = malloc((strlen(time_str) + 1) * sizeof(char));
    } else {
        s->base.__full_statistics = realloc(s->base.__full_statistics,
                                            (strlen(s->base.__full_statistics) + strlen(time_str) + 1) * sizeof(char));
    }

    if (s->base.__full_statistics == NULL) {
        return NULL;
    }

    strcat(s->base.__full_statistics, time_str);
    return self;
}

char *get__ru(void *self) {
    const ru_statistics_saver_builder *s = self;
    return s->base.__full_statistics;
}


statistics_saver_builder_vtable v_table__ru = {
    .with_name = with_name__ru,
    .with_header = with_header__ru,
    .with_company_name = with_company_name__ru,
    .with_current_time = with_current_time__ru,
    .with_houses_count = with_houses_count__ru,
    .get = get__ru
};


ru_statistics_saver_builder *new__ru_full_statistics_builder() {
    ru_statistics_saver_builder *builder = malloc(sizeof(ru_statistics_saver_builder));

    builder->base.__full_statistics = NULL;
    builder->base.vtable = &v_table__ru;

    return builder;
}
