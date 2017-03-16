cmake_minimum_required(VERSION 3.6)
project(Laba8_TISD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GraphShower.h)
add_executable(Laba8_TISD ${SOURCE_FILES})
