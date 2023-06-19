cmake_minimum_required(VERSION 3.0.0)
project(young-fibonacci VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(young-fibonacci main.cpp)
add_executable(AlgoTester test/testAlgorithms.cpp)
add_executable(AVXTester test/testAVX.cpp)
add_executable(benchmarks benchmark/benchmarks.cpp)

add_test(NAME AlgoTester COMMAND testAlgo)
add_test(NAME AVXTester COMMAND testAVX)

find_package(benchmark REQUIRED)
target_link_libraries(benchmarks benchmark::benchmark)

target_compile_options(benchmarks PUBLIC -mavx -mavx2 -mfma -fopencilk -O3)
target_compile_options(young-fibonacci PUBLIC -mavx -mavx2 -mfma -O3)
target_compile_options(AVXTester PUBLIC -mavx -mavx2 -mfma -fopencilk -O3)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)