cmake_minimum_required(VERSION 3.9)
project(Benchmark_Tower)

set(CMAKE_CXX_STANDARD 14)

find_package(benchmark REQUIRED)

add_executable(
        ${PROJECT_NAME}
        Main.cpp
        ../src/core/Tower.cpp
        ../src/core/Search.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark)