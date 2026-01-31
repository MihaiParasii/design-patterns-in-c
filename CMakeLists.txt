cmake_minimum_required(VERSION 3.31)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c
        base_house.c
        base_house.h
        apartment.c
        apartment.h
        ground_house.c
        ground_house.h
        house_constructor.c
        house_constructor.h
        apartment_constructor.c
        apartment_constructor.h
        ground_house_constructor.c
        ground_house_constructor.h
        dynamic_array.c
        dynamic_array.h
        site_999.c
        site_999.h
        statistics.c
        statistics.h
)
