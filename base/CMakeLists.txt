aux_source_directory(. DIR_BASE_SRCS)
MESSAGE(STATUS "This is SOURCE dir "${DIR_BASE_SRCS})

INCLUDE_DIRECTORIES(../../)

ADD_LIBRARY(myth52125_base ${DIR_BASE_SRCS})
target_link_libraries(myth52125_base pthread)