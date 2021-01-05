cmake_minimum_required(VERSION 3.9)
project(Triplets)

set(CMAKE_CXX_STANDARD 14)

# we don't want to copy if we're building in the source dir
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

    # list of files for which we add a copy rule
    set(data_SHADOW src/test/resources)

    foreach(item IN LISTS data_SHADOW)
        message(STATUS ${item})
        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
        )
    endforeach()
endif()

add_executable(
        ${PROJECT_NAME}
        src/test/Main.cpp
)

add_custom_target(data-target ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/src/test/resources")
