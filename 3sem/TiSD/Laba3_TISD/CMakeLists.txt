cmake_minimum_required(VERSION 3.6)
project(Laba3_TISD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Book.h Book.cpp Table_key.cpp)
add_executable(Laba3_TISD ${SOURCE_FILES})
