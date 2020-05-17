cmake_minimum_required(VERSION 3.10)
project(3_connected_components)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(3_connected_components main.cpp)

include(FindPkgConfig)
find_package(Graph REQUIRED)
include_directories(${GRAPH_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GRAPH_LIBRARY})