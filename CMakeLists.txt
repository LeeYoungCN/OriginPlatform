project(OriginPlatform)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_SOURCE_DIR}/cmake/toolchain.cmake)
set(GOOGLE_TEST_PATH        ${CMAKE_SOURCE_DIR}/google_test)
set(GTEST_LIB               ${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/output)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_INSTALL_PREFIX    ${CMAKE_SOURCE_DIR})
set(RELEASE_APTH            ${CMAKE_SOURCE_DIR}/release)
set(HEAD_INSTALL_PATH       ${RELEASE_APTH}/inc)
set(LIB_INSTALL_PATH        ${RELEASE_APTH}/lib)

set(LIB_NAME    OriginPlatform)
set(TEST_TARGET RunTest)

set(CMAKE_CXX_STANDARD 17)

set(CODE_PATH      ${CMAKE_SOURCE_DIR}/src)
set(TEST_PATH      ${CMAKE_SOURCE_DIR}/tests)
set(CMAKE_C_FLAGS   "-Wall -g")
set(CMAKE_CXX_FLAGS "-Wall -g")

add_executable(${TEST_TARGET})
add_library(${LIB_NAME} SHARED)

add_dependencies(${TEST_TARGET} ${LIB_NAME})

add_subdirectory(${CODE_PATH})
add_subdirectory(${TEST_PATH})

link_directories(${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})
target_include_directories(${TEST_TARGET} PRIVATE ${GOOGLE_TEST_PATH})

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    file(GLOB LIB_LIST ${LIBRARY_OUTPUT_PATH}/*.dll)
    install(FILES ${LIB_LIST} DESTINATION ${LIB_INSTALL_PATH} COMPONENT ${PROJECT_NAME})
    install(FILES ${LIB_LIST} DESTINATION ${EXECUTABLE_OUTPUT_PATH} COMPONENT ${PROJECT_NAME})
else()
    install(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${LIB_INSTALL_PATH} COMPONENT ${PROJECT_NAME})
    install(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${EXECUTABLE_OUTPUT_PATH} COMPONENT ${PROJECT_NAME})
endif()

target_link_libraries(${TEST_TARGET} ${LIB_NAME} ${GTEST_LIB}/libgtest.a pthread)
