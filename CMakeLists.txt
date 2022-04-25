cmake_minimum_required(VERSION 3.22)
project(DataStructures2022 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DataStructures2022
        csvrnf.c
        csvrnf.h
        sortalgos.c
        sortlagos.h
        main.c)
