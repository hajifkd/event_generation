cmake_minimum_required(VERSION 2.8)
project(tracker)
set(CMAKE_CXX_STANDARD 14)

include(./FindPythia8.cmake)
include_directories(${PYTHIA8_INCLUDE_DIR})

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()

add_subdirectory(src)
add_subdirectory(tests)
enable_testing()

add_test(NAME gtest COMMAND ./tests/gtest)
