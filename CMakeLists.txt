project(Platform)
cmake_minimum_required(VERSION 3.4.1)
include( ${CMAKE_SOURCE_DIR}/cmake/toolchain.cmake)
set(BUILDCACHE_PATH         ${CMAKE_SOURCE_DIR}/buildcache)
set(GOOGLE_TEST_PATH        ${CMAKE_SOURCE_DIR}/google_test)
set(CMAKE_INSTALL_PREFIX    ${CMAKE_SOURCE_DIR})

set(LIB_NAME    UserLib)
set(TEST_TARGET TestPlatform)

set(CMAKE_CXX_STANDARD 17)

set(CODE_PATH      ${CMAKE_SOURCE_DIR}/src)
set(TEST_PATH      ${CMAKE_SOURCE_DIR}/test)
set(CMAKE_C_FLAGS   "-Wall -g")
set(CMAKE_CXX_FLAGS "-Wall -g")

add_executable(${TEST_TARGET})
add_library(${LIB_NAME} STATIC)

add_subdirectory(${CODE_PATH})
add_subdirectory(${TEST_PATH})

link_directories(${LIBRARY_OUTPUT_PATH})
target_include_directories(${TEST_TARGET} PRIVATE ${GOOGLE_TEST_PATH})

install(TARGETS ${LIB_NAME} ARCHIVE DESTINATION lib)
install(TARGETS ${TEST_TARGET} RUNTIME DESTINATION output)

target_link_libraries(${TEST_TARGET} ${LIB_NAME} pthread ${GOOGLE_TEST_PATH}/lib/libgtest.a)