set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)
set(GOOGLE_TEST_PATH        ${CMAKE_SOURCE_DIR}/google_test)
set(GTEST_LIB               ${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})
set(TEST_TARGET test_origin)

add_executable(${TEST_TARGET})
add_dependencies(${TEST_TARGET} ${LIB_NAME})

target_include_directories(${TEST_TARGET} PRIVATE
    ${GOOGLE_TEST_PATH}
    ${HEAD_FILE_INSTALL_PATH}
)

target_link_directories(${TEST_TARGET} PRIVATE
    ${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME}
    ${LIB_INSTALL_PATH}
)
target_link_libraries(${TEST_TARGET} ${LIB_NAME} ${GTEST_LIB}/libgtest${STATIC_LIBRARY_SUFFIX} pthread)

add_subdirectory(src)
