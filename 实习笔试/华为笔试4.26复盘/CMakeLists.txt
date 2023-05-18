cmake_minimum_required(VERSION 3.0.0)
project(TOP101 VERSION 0.1.0)

include(CTest)
enable_testing()

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
add_executable(test1 1.cpp)
add_executable(test2 2.cpp)
add_executable(test3 3.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
