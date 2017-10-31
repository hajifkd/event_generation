cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(
  gtest
  test.cc
)

target_link_libraries(gtest ${GTEST_MAIN_LIBRARIES} ${GTEST_LIBRARIES} pthread)

