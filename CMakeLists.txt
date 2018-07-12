cmake_minimum_required(VERSION 3.10)
project(parallel)

set(CMAKE_CXX_STANDARD 17)

find_package(benchmark REQUIRED)

add_executable(benchmark benchmark.cpp determinant.h)
target_link_libraries(benchmark benchmark::benchmark)

add_executable(tests tests.cpp catch.cpp determinant.h catch.h)