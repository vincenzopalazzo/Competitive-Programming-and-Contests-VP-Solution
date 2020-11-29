cmake_minimum_required(VERSION 3.9)
project(TwoTypesOfSpells)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME}
        src/MainSite.cpp
        src/core/SolTest.cpp)