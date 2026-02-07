#include <stdlib.h>
#include "statistics_saver_director.h"

void construct_short__director(void *self, const int constructed_houses_count) {
    const statistics_saver_director *director = self;

    // call(director->__builder, with_name, "Test name");
    // call(director->__builder, with_header, "Fancy header");
    // call(director->__builder, with_houses_count, constructed_houses_count);

    director->__builder->vtable->with_name(director->__builder, "Test name")
            ->vtable->with_header(director->__builder, "Fancy header")
            ->vtable->with_houses_count(director->__builder, constructed_houses_count);
}

void construct_long__director(void *self, const int constructed_houses_count) {
    time_t current_time;
    time(&current_time);

    const statistics_saver_director *director = self;

    director->__builder->vtable->with_name(director->__builder, "Test name")
            ->vtable->with_header(director->__builder, "Fancy header")
            ->vtable->with_company_name(director->__builder, "OOO Naebalovo")
            ->vtable->with_houses_count(director->__builder, constructed_houses_count)
            ->vtable->with_current_time(director->__builder, current_time);
}


statistics_saver_director__vtable vtable__director = {
    .construct_long = construct_long__director,
    .construct_short = construct_short__director
};


statistics_saver_director *new__statistics_saver_director(i_statistics_saver_builder *builder) {
    statistics_saver_director *director = malloc(sizeof(statistics_saver_director));

    director->vtable = &vtable__director;
    director->__builder = builder;

    return director;
}
