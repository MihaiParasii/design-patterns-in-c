cmake_minimum_required(VERSION 3.31)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c
        models/base_house.h
        models/apartment.c
        models/apartment.h
        models/ground_house.c
        models/ground_house.h
        abstract_factory_method/house_creator.c
        abstract_factory_method/house_creator.h
        abstract_factory_method/apartment_creator.c
        abstract_factory_method/apartment_creator.h
        abstract_factory_method/ground_house_creator.c
        abstract_factory_method/ground_house_creator.h
        common/dynamic_array.c
        common/dynamic_array.h
        models/site_999.c
        models/site_999.h
        models/statistics.c
        models/statistics.h
        builder/i_statistics_saver_builder.h
        builder/ro_statistics_saver_builder.c
        builder/ro_statistics_saver_builder.h
        builder/ru_statistics_saver_builder.c
        builder/ru_statistics_saver_builder.h
        builder/en_statistics_saver_builder.c
        builder/en_statistics_saver_builder.h
        builder/statistics_saver_director.c
        builder/statistics_saver_director.h
        defines.h
        common/i_prototype.h
        trash.c
        models/base_house.c
        common/i_as_json.h
        adapter/external_flat_json_adapter.c
        adapter/external_flat_json_adapter.h
        adapter/external_flat.h
        adapter/external_flat_provider.c
        adapter/external_flat_provider.h
        builder/static_statistics_saver_builder.c
        builder/static_statistics_saver_builder.h
)
