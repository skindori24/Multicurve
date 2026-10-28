cmake_minimum_required(VERSION 3.20)
project(multicurve VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Project code
add_library(multicurve_lib src/curve.cpp)
target_include_directories(multicurve_lib PUBLIC src)

add_executable(multicurve src/main.cpp)
target_link_libraries(multicurve PRIVATE multicurve_lib)

# Third-party libraries, downloaded on the first configure
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.18.0
    GIT_SHALLOW TRUE)
FetchContent_Declare(benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.10.0
    GIT_SHALLOW TRUE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_WERROR OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest benchmark)

# Unit tests (GoogleTest), run with ctest
enable_testing()
add_executable(multicurve_tests tests/test_curve.cpp)
target_link_libraries(multicurve_tests PRIVATE multicurve_lib GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(multicurve_tests)

# Benchmark (Google Benchmark)
add_executable(multicurve_bench bench/bench_curve.cpp)
target_link_libraries(multicurve_bench PRIVATE multicurve_lib benchmark::benchmark)
