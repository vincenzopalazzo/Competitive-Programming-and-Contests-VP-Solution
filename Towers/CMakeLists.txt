cmake_minimum_required(VERSION 3.9)
project(Tower)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp
        src/core/Tower.cpp
        src/core/Search.cpp)
