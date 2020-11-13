cmake_minimum_required(VERSION 3.9)
project(roundA_2020_Allocation)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME}
        src/MainSite.cpp
        src/Utils.cpp
        src/test/TestTool.cpp
        src/core/SolTest.cpp)