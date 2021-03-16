cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME
    TagParser
)
set(LIBRARY_NAME
    tag_parser
)
set(LIBRARY_HEADERS_DIR
    include/tag_parser
)
set(LIBRARY_SOURCE_DIR
    src
)

project(${PROJECT_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS_DIR}/tag_parser.hpp
    ${LIBRARY_HEADERS_DIR}/csv_reader.hpp
    ${LIBRARY_HEADERS_DIR}/utils.hpp
    ${LIBRARY_SOURCE_DIR}/tag_parser.cpp
    ${LIBRARY_SOURCE_DIR}/csv_reader.cpp
    ${LIBRARY_SOURCE_DIR}/utils.cpp
)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# add_subdirectory(test)