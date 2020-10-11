cmake_minimum_required(VERSION 3.9)
project(KadaneAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp
        src/core/MaxSumContiguousSubArr.cpp)