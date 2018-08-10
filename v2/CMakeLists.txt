cmake_minimum_required(VERSION 3.12)
project(bowling_kata_v2)

set(CMAKE_CXX_STANDARD 17)

set(${PROJECT_NAME}_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(${PROJECT_NAME}_TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

add_subdirectory(${${PROJECT_NAME}_SOURCE_DIR})
add_subdirectory(${${PROJECT_NAME}_TEST_DIR})