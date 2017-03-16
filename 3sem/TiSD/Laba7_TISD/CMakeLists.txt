cmake_minimum_required(VERSION 3.6)
project(Tisd7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp AVL.cpp AVL.h library.h BST.cpp BST.h HashTableClose.cpp HashTableClose.h HashTableOpen.cpp HashTableOpen.h)
add_executable(Tisd7 ${SOURCE_FILES})