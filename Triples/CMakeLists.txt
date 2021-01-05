cmake_minimum_required(VERSION 3.9)
project(Triples)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME}
        src/test/Main.cpp
        src/core/CountTriples.cpp
        src/Utils.cpp
        src/test/TestTool.cpp)