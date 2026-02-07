#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <secure/_string.h>
#include "i_statistics_saver_builder.h"
#include "ro_statistics_saver_builder.h"

i_statistics_saver_builder *with_name__ro(void *self, const char *name) {
    ro_statistics_saver_builder *s = self;
    size_t name_len = strlen(name);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (name_len + 2) * sizeof(char));


    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, name);
    s_call(&s->base_statistics_saver_builder__base, __append, "\n");

    return self;
}

i_statistics_saver_builder *with_header__ro(void *self, const char *header_name) {
    ro_statistics_saver_builder *s = self;
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

i_statistics_saver_builder *with_houses_count__ro(void *self, const int created_houses_count) {
    ro_statistics_saver_builder *s = self;
    char count_str[64];
    snprintf(count_str, sizeof(count_str), "Nr. de case create: %d\n", created_houses_count);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(count_str) + 1) * sizeof(char));

    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, count_str);

    return self;
}

i_statistics_saver_builder *with_company_name__ro(void *self, const char *company_name) {
    ro_statistics_saver_builder *s = self;
    char company_str[256];
    snprintf(company_str, sizeof(company_str), "Compania: %s\n", company_name);

    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(company_str) + 1) * sizeof(char));
    
    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, company_str);
    return self;
}

i_statistics_saver_builder *with_current_time__ro(void *self, const time_t time) {
    ro_statistics_saver_builder *s = self;
    char time_str[64];
    const struct tm *tm_info = localtime(&time);
    strftime(time_str, sizeof(time_str), "Data executării: %Y-%m-%d %H:%M:%S\n", tm_info);
    
    s_call(&s->base_statistics_saver_builder__base, __alloc_memory, (strlen(time_str) + 1) * sizeof(char));

    if (s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics == NULL) {
        return NULL;
    }

    s_call(&s->base_statistics_saver_builder__base, __append, time_str);

    return self;
}

char *get__ro(void *self) {
    const ro_statistics_saver_builder *s = self;
    return s->base_statistics_saver_builder__base.i_statistics_saver_builder.__full_statistics;
}


i_statistics_saver_builder__vtable v_table__ro = {
    .with_name = with_name__ro,
    .with_header = with_header__ro,
    .with_company_name = with_company_name__ro,
    .with_current_time = with_current_time__ro,
    .with_houses_count = with_houses_count__ro,
    .get = get__ro
};


ro_statistics_saver_builder *new__ro_full_statistics_builder() {
    ro_statistics_saver_builder *builder = malloc(sizeof(ro_statistics_saver_builder));

    builder->base_statistics_saver_builder__base = *new(base_statistics_saver_builder);

    builder->base_statistics_saver_builder__base.i_statistics_saver_builder.vtable = &v_table__ro;

    return builder;
}
