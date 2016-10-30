cmake_minimum_required(VERSION 3.6)
project(Laba2_TISD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Stack.cpp)
add_executable(Laba2_TISD ${SOURCE_FILES})
