cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_BUILD_TYPE Debug)

set(TAG_PROJECT_NAME
    Tag
)
set(TAG_SOURCE_DIR
    src
)
set(TAG_SOURCE
    ${TAG_SOURCE_DIR}/main.cpp
)
set(TAG_LIBRARIES_DIR
    lib
)
set(TAG_LIBRARIES 
    tag_parser
)

project(${TAG_PROJECT_NAME})

###########
# Project #
###########
add_executable(${TAG_PROJECT_NAME} ${TAG_SOURCE})

foreach(LIBRARY ${TAG_LIBRARIES})
    add_subdirectory("${TAG_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${TAG_PROJECT_NAME} ${TAG_LIBRARIES})
