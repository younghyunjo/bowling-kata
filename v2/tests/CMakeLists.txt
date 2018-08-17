cmake_minimum_required(VERSION 3.11)

set(GOOGLETEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest)

#####################################################
#Install googletest framework
include(ExternalProject)
ExternalProject_Add(GoogleTest
        PREFIX ${GOOGLETEST_DIR}
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.8.0
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GOOGLETEST_DIR}
        )

set(GOOGLETEST_INCLUDE_DIR ${GOOGLETEST_DIR}/include)
include_directories(${GOOGLETEST_INCLUDE_DIR})

set(GOOGLETEST_LIBRARY_PATH ${GOOGLETEST_DIR}/lib)
link_directories(${GOOGLETEST_LIBRARY_PATH})

set(GOOGLETEST_LIBRARY gtest gtest_main gmock gmock_main)
#####################################################



####################################################
#set (SUT_SOURCE Bowling.cpp ImmutableFrame.cpp)
include_directories(${${PROJECT_NAME}_SOURCE_DIR})
####################################################

add_executable(tests Bowling.cpp ImmutableFrame.cpp)
add_dependencies(tests GoogleTest)

target_link_libraries(tests ${GOOGLETEST_LIBRARY} pthread)

