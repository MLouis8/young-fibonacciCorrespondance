cmake_minimum_required(VERSION 3.0.0)
project(young-fibonacci VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(young-fibonacci main.cpp)
add_executable(AlgoTester test/testAlgorithms.cpp)
add_executable(benchmarks benchmark/benchmark.cpp)

add_test(NAME AlgoTester COMMAND testAlgo)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(benchmark REQUIRED)
target_link_libraries(benchmarks benchmark::benchmark)

add_compile_options(-mavx2)