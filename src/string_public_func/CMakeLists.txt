aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CODE_SRCS)
target_sources(${LIB_NAME} PRIVATE ${CODE_SRCS})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
