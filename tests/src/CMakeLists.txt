aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CODE_SRCS)
target_sources(${TEST_TARGET} PRIVATE ${CODE_SRCS})
target_include_directories(${TEST_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(test_num_string_format_manager)
