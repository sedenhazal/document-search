cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeIndexTest index_test.cpp)
target_link_libraries(executeIndexTest ${GTEST_LIBRARIES} pthread)

add_executable(executeSearchTest search_test.cpp)
target_link_libraries(executeSearchTest ${GTEST_LIBRARIES} pthread)

