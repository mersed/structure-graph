cmake_minimum_required(VERSION 3.10)
project(graph)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Graph.cpp)

add_library(graph ${SOURCE_FILES})