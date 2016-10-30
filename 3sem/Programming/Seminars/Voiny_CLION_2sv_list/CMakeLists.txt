cmake_minimum_required(VERSION 3.6)
project(Voiny_CLION_2sv_list)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES main.c)
add_executable(Voiny_CLION_2sv_list ${SOURCE_FILES})
