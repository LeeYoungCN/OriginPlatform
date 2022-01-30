project(Platform)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)
set(BUILDCACHE_PATH         ${CMAKE_SOURCE_DIR}/buildcache)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/output)
set(LIB_NAME    Platform_v001)
set(TARGET_NAME TestPlatform)

set(CMAKE_CXX_STANDARD 17)

set(CODE_PATH      ${CMAKE_SOURCE_DIR}/src)
set(TEST_PATH      ${CMAKE_SOURCE_DIR}/test)
set(CMAKE_C_FLAGS   "-Wall -g")
set(CMAKE_CXX_FLAGS "-Wall -g")

add_executable(${TARGET_NAME})
add_library(${LIB_NAME})

add_subdirectory(${CODE_PATH})
add_subdirectory(${TEST_PATH})

file(GLOB LIBS ${LIBRARY_OUTPUT_PATH}/*.a)

target_link_libraries(${TARGET_NAME} ${LIBS} pthread)