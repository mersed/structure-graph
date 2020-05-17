set(FIND_GRAPH_PATHS
        ../1.graph)

find_path(GRAPH_INCLUDE_DIR Graph.h
        PATHS ${FIND_GRAPH_PATHS})

find_library(GRAPH_LIBRARY
        NAMES graph
        PATH_SUFFIXES build
        PATHS ${FIND_GRAPH_PATHS})