cmake_minimum_required(VERSION 3.9)
project(ReplyWorkers)

set(CMAKE_CXX_STANDARD 14)

FILE(COPY src/test/resources DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(
        ${PROJECT_NAME}
        src/test/Main.cpp
)
