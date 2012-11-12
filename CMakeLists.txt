cmake_minimum_required(VERSION 2.6)

project(test_fibonacii)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
message(STATUS "Compiling test_fibonacii client code")
include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_fibonacii test/test_fibonacii.cpp)

project(test_foreach)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
message(STATUS "Compiling test_for_each client code")
include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_foreach test/test_for_each.cpp)

project(test_functional)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
message(STATUS "Compiling test_functional client code")
include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_functional test/test_functional.cpp)

project(test_zip)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
message(STATUS "Compiling test_zip client code")
include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_zip test/test_zip.cpp)

