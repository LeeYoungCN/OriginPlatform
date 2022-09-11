set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/app)
set(GOOGLE_TEST_PATH        ${CMAKE_SOURCE_DIR}/google_test)
set(GTEST_LIB               ${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})
set(TEST_TARGET RunTest)

add_executable(${TEST_TARGET})
add_dependencies(${TEST_TARGET} ${LIB_NAME})

link_directories(${GOOGLE_TEST_PATH}/lib/${CMAKE_SYSTEM_NAME})
target_include_directories(${TEST_TARGET} PRIVATE ${GOOGLE_TEST_PATH})
target_link_libraries(${TEST_TARGET} ${LIB_NAME} ${GTEST_LIB}/libgtest${STATIC_LIBRARY_SUFFIX} pthread)

install(FILES ${LIB_LIST} DESTINATION ${EXECUTABLE_OUTPUT_PATH} COMPONENT ${PROJECT_NAME})

add_subdirectory(src)
