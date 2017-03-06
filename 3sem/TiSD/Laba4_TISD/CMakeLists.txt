cmake_minimum_required(VERSION 3.6)
project(Laba4_TISD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CQueue_array.cpp CQueue_array.h CQueue_list.cpp CQueue_list.h library.h)
add_executable(Laba4_TISD ${SOURCE_FILES})
