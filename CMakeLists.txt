cmake_minimum_required(VERSION 3.10)
project(parallel)

set(CMAKE_CXX_STANDARD 17)

find_package(benchmark REQUIRED)


add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark benchmark::benchmark)
