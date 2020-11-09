cmake_minimum_required(VERSION 3.9)
project(SmallerValues)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME}
        src/test/Main.cpp
        src/test/TestTool.cpp
        src/Utils.cpp
        src/core/SegmentTree.cpp
        src/core/SmallerValue.cpp)