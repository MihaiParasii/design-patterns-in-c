#include "ro_statistics_saver_builder.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <secure/_string.h>

i_statistics_saver_builder *with_name__ro(i_statistics_saver_builder *self, const char *name) {
    ro_statistics_saver_builder *s = (ro_statistics_saver_builder *) self;
    size_t name_len = strlen(name);

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

i_statistics_saver_builder *with_header__ro(i_statistics_saver_builder *self, const char *header_name) {
    ro_statistics_saver_builder *s = (ro_statistics_saver_builder *) self;
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

i_statistics_saver_builder *with_houses_count__ro(i_statistics_saver_builder *self, const int created_houses_count) {
    ro_statistics_saver_builder *s = (ro_statistics_saver_builder *) self;
    char count_str[64];
    snprintf(count_str, sizeof(count_str), "Nr. de case create: %d\n", created_houses_count);

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

i_statistics_saver_builder *with_company_name__ro(i_statistics_saver_builder *self, const char *company_name) {
    ro_statistics_saver_builder *s = (ro_statistics_saver_builder *) self;
    char company_str[256];
    snprintf(company_str, sizeof(company_str), "Compania: %s\n", company_name);

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

i_statistics_saver_builder *with_current_time__ro(i_statistics_saver_builder *self, const time_t time) {
    ro_statistics_saver_builder *s = (ro_statistics_saver_builder *) self;
    char time_str[64];
    const struct tm *tm_info = localtime(&time);
    strftime(time_str, sizeof(time_str), "Data executării: %Y-%m-%d %H:%M:%S\n", tm_info);

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

char *get__ro(void *self) {
    const ro_statistics_saver_builder *s = self;
    return s->base.__full_statistics;
}


statistics_saver_builder_vtable v_table__ro = {
    .with_name = with_name__ro,
    .with_header = with_header__ro,
    .with_company_name = with_company_name__ro,
    .with_current_time = with_current_time__ro,
    .with_houses_count = with_houses_count__ro,
    .get = get__ro
};


ro_statistics_saver_builder *new__ro_full_statistics_builder() {
    ro_statistics_saver_builder *builder = malloc(sizeof(ro_statistics_saver_builder));

    builder->base.__full_statistics = NULL;
    builder->base.vtable = &v_table__ro;

    return builder;
}
