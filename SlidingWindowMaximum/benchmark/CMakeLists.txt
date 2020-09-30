cmake_minimum_required(VERSION 3.9)
project(Benchmark_MaximumInSumArrays)

set(CMAKE_CXX_STANDARD 14)

find_package(benchmark REQUIRED)

add_executable(
        ${PROJECT_NAME}
        Main.cpp
        ../src/core/MaxSubArrayPos.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark)
